#define MAXCHARARRAYLENGTH 512
#define MAXTESTCOUNT 200
#define MAXC5UNITS 50
#define MAXCHARPERLINE 2048
#define MAXNUMOFLINE 200

#include "Windows.h"
#include "toolbox.h"
#include "WinBase.h"
#include <formatio.h>
#include <ansi_c.h>
#include <string.h>
#include "ParseCSV.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


enum { NOMEM = -2 };          

static char *line    = NULL;  
static char *sline   = NULL; 
static int  maxline  = 0;     
static char **field  = NULL;  
static int  maxfield = 0;     
static int  nfield   = 0;     

static char fieldsep[] = ","; 

static char *advquoted(char *);
static int split(void);
typedef struct
{ 
	char		Requirement[MAXCHARARRAYLENGTH];
	char   		Parameter[MAXCHARARRAYLENGTH];
	char   		Unit[MAXCHARARRAYLENGTH];	
	char   		Points[MAXCHARARRAYLENGTH];
	char   		SCORCC[MAXCHARARRAYLENGTH]; 
	char   		Min[MAXCHARARRAYLENGTH];
	char   		Max[MAXCHARARRAYLENGTH]; 
 }C5CalTests;

typedef struct
{ 
	char		PartNum[MAXCHARARRAYLENGTH];
	char   		Type[MAXCHARARRAYLENGTH];
	char   		FilterFile[MAXCHARARRAYLENGTH]; 
	C5CalTests  Tests[MAXTESTCOUNT];	

 }C5CalUnit;

C5CalUnit C5Unit[MAXC5UNITS];

static char PartNumberStatic[100]={0};

static int endofline(FILE *fin, int c) ;
char * remove_spaces(char * source, char * target);
/********************************************//**
 *  endofline: check for and consume \r, \n, \r\n, or EOF 
 ***********************************************/
static int endofline(FILE *fin, int c);
/********************************************//**
 * set variables back to starting values
 ***********************************************/
static void reset(void);
/********************************************//**
 * csvgetline:  get one line, grow as needed
 ***********************************************/
char *csvgetline(FILE *fin);
/********************************************//**
 * split line into fields
 ***********************************************/
static int split(void);
/********************************************//**
 *  quoted field; return pointer to next separator
 ***********************************************/
static char *advquoted(char *p);
/********************************************//**
 *   return number of fields
 ***********************************************/
int csvnfield(void);
/********************************************//**
 *  return pointer to n-th field
 ***********************************************/
char *csvfield(int n);
/********************************************//**
 *   Removes all LF that are without a CR
 ***********************************************/
int RemoveLineFeed(char * buf);


/**

int main (int argc, char *argv[])
{
	ParseCSV("C:\\Users\\engineer\\Desktop\\NB_Test_Prameters_updating.csv"); 
	char min[100];
	char max[100];
	char parameter[100];
	char requirement[100];
	getC5UnitInfo("626626002A",1792, min, max, parameter, requirement); 
	return 0;
}**/ 
/********************************************//**
 *  parses the CSV file provided
 ***********************************************/
int ParseCSV(char *FilePath)
{
	int PartNumCnt=0;
	char *line;
	
	char CSVFile[MAXCHARPERLINE * MAXNUMOFLINE];
	//open and read the file to buffer
	int fileHandle = OpenFile(FilePath,VAL_READ_ONLY,VAL_OPEN_AS_IS, VAL_BINARY );
	ReadFile (fileHandle, CSVFile, sizeof(CSVFile));
	CloseFile(fileHandle);
	//Remove all LF that are without cariage return \\NO LF within a cell suported
	RemoveLineFeed(CSVFile);
	char TempPath[512]={0};
	GetTempPath(512,TempPath);
	strcat(TempPath,"tempCSVFile.csv");
	//write the buffer without lf into a temp file
	DeleteFile (TempPath);
	FILE *fp = fopen(TempPath,"w");
	fwrite(CSVFile,strlen(CSVFile),1,fp);
	fclose(fp);
	//open the tempfile  and read it line by line
	fp = fopen(TempPath,"r"); 

	//Read all PartNumbers from first row
	line = csvgetline(fp);
	for (int i = 5; i < csvnfield(); i=i+2)
	{
		strcpy(C5Unit[((i-5)/2)].PartNum,csvfield(i));
		PartNumCnt++;
	}
	line = csvgetline(fp); 
	line = csvgetline(fp); 
	//Read all Type from third row   
	for (int i = 5; i < csvnfield(); i=i+2)
	{
		strcpy(C5Unit[((i-5)/2)].Type,csvfield(i));
	}

	line = csvgetline(fp);
	//Read all Filter file from forth row
	for (int i = 5; i < csvnfield(); i=i+2)
	{
		strcpy(C5Unit[((i-5)/2)].FilterFile,csvfield(i));
	}

	//Read all remaining line and assume there are for all tests
	int lineCnt=0; 
	while ((line = csvgetline(fp)) != NULL) 
	{
		//Read the first 4 columns and load int to structre for all part numbers
		//since all part numbers have same tests.
		
		for(int i=0;i<PartNumCnt;i++)
			strcpy(C5Unit[i].Tests[lineCnt].Requirement,csvfield(0));
		for(int i=0;i<PartNumCnt;i++)
			strcpy(C5Unit[i].Tests[lineCnt].Parameter,csvfield(1)); 
		for(int i=0;i<PartNumCnt;i++)
			strcpy(C5Unit[i].Tests[lineCnt].Unit,csvfield(2)); 
		for(int i=0;i<PartNumCnt;i++)
			strcpy(C5Unit[i].Tests[lineCnt].Points,csvfield(3)); 
		for(int i=0;i<PartNumCnt;i++)
			strcpy(C5Unit[i].Tests[lineCnt].SCORCC,csvfield(4)); 
		//Read all columns starting at 5 all odd ones are min,and even are max 
		for (int i = 5; i < csvnfield(); i++)
		{
			if(i%2)
				strcpy(C5Unit[((i-5)/2)].Tests[lineCnt].Min,csvfield(i));
			else
				strcpy(C5Unit[((i-5)/2)].Tests[lineCnt].Max,csvfield(i));
		}
		lineCnt++;
	}
	fclose(fp);
	reset();
	return 0;	
}
/********************************************//**
 *  Takes the PartNumber and point as input and returns the Min, max,paramater and required coloumn that was loaded into structure from csv.
 ***********************************************/
int getUnitInfo(char * PartNumber,int Point, char *min, char *max, char *parameter, char *requirement)
{
	char PartNumNospaces[50]={0};
	char inputPartNumNospaces[50]={0};  
	for(int i=0;i<MAXC5UNITS;i++)
	{
		sprintf(inputPartNumNospaces,"%s", remove_spaces(PartNumber, inputPartNumNospaces)); 
		sprintf(PartNumNospaces,"%s", remove_spaces(C5Unit[i].PartNum, PartNumNospaces));
		if(!stricmp(PartNumber,PartNumNospaces))
		{
			for(int j=0;j<MAXTESTCOUNT;j++)
			{
				if(Point == atoi(C5Unit[i].Tests[j].Points))
				{
					sprintf(min,"%s",C5Unit[i].Tests[j].Min);
					sprintf(max,"%s",C5Unit[i].Tests[j].Max);
					sprintf(parameter,"%s",C5Unit[i].Tests[j].Parameter);
					sprintf(requirement,"%s",C5Unit[i].Tests[j].Requirement);
					return 0;
				}
			}
		}
	}
	
	return -1;
}
char * remove_spaces(char * source, char * target)
{
    int i=0;
	int j=0;
	while(source[i])
     {
        if (!isspace(source[i])) 
		{
			target[j] = source[i];
			j++;
		}
		i++;
     }
	 target[j] = 0;	 
     return target;
}

/********************************************//**
 *  endofline: check for and consume \r, \n, \r\n, or EOF 
 ***********************************************/
static int endofline(FILE *fin, int c)
{
	int eol;

	eol = (c=='\r' || c=='\n');
	if (c == '\r') {
		c = getc(fin);
		if (c != '\n' && c != EOF)
			ungetc(c, fin);	// read too far; put c back 
	}
	return eol;
}
/********************************************//**
 * set variables back to starting values
 ***********************************************/
static void reset(void)
{
	free(line);	
	free(sline);
	free(field);
	line = NULL;
	sline = NULL;
	field = NULL;
	maxline = maxfield = nfield = 0;
}

/********************************************//**
 * csvgetline:  get one line, grow as needed
 ***********************************************/
char *csvgetline(FILE *fin)
{	
	int i, c;
	char *newl, *news;

	if (line == NULL) {			
		maxline = maxfield = 1;
		line = (char *) malloc(maxline);
		sline = (char *) malloc(maxline);
		field = (char **) malloc(maxfield*sizeof(field[0]));
		if (line == NULL || sline == NULL || field == NULL) {
			reset();
			return NULL;		
		}
	}
	for (i=0; (c=getc(fin))!=EOF && !endofline(fin,c); i++) {
		if (i >= maxline-1) {	// grow line 
			maxline *= 2;		// double current size 
			newl = (char *) realloc(line, maxline);
			if (newl == NULL) {
				reset();
				return NULL;
			}
			line = newl;
			news = (char *) realloc(sline, maxline);
			if (news == NULL) {
				reset();
				return NULL;
			}
			sline = news;


		}
		line[i] = (char)c;
	}
	line[i] = '\0';
	if (split() == NOMEM) {
		reset();
		return NULL;		
	}
	return (c == EOF && i == 0) ? NULL : line;
}

/********************************************//**
 * split line into fields
 ***********************************************/
static int split(void)
{
	char *p, **newf;
	char *sepp; // pointer to temporary separator character 
	int sepc;   // temporary separator character 

	nfield = 0;
	if (line[0] == '\0')
		return 0;
	strcpy(sline, line);
	p = sline;

	do {
		if (nfield >= maxfield) {
			maxfield *= 2;			// double current size 
			newf = (char **) realloc(field, 
						maxfield * sizeof(field[0]));
			if (newf == NULL)
				return NOMEM;
			field = newf;
		}
		if (*p == '"')
			sepp = advquoted(++p);	// skip initial quote 
		else
			sepp = p + strcspn(p, fieldsep);
		sepc = sepp[0];
		sepp[0] = '\0';				// terminate field 
		field[nfield++] = p;
		p = sepp + 1;
	} while (sepc == ',');

	return nfield;
}

/********************************************//**
 *  quoted field; return pointer to next separator
 ***********************************************/
static char *advquoted(char *p)
{
	int i, j;

	for (i = j = 0; p[j] != '\0'; i++, j++) {
		if (p[j] == '"' && p[++j] != '"') {
			// copy up to next separator or \0 
			int k = strcspn(p+j, fieldsep);
			memmove(p+i, p+j, k);
			i += k;
			j += k;
			break;
		}
		p[i] = p[j];
	}
	p[i] = '\0';
	return p + j;
}

/********************************************//**
 *  return pointer to n-th field
 ***********************************************/
char *csvfield(int n)
{
	if (n < 0 || n >= nfield)
		return NULL;
	return field[n];
}
/********************************************//**
 *   return number of fields
 ***********************************************/
int csvnfield(void)
{
	return nfield;
}
/********************************************//**
 *   Removes all LF that are without a CR
 ***********************************************/
int RemoveLineFeed(char * buf)
{
	int arraySize = MAXCHARPERLINE * MAXNUMOFLINE;
	char * temp = malloc(arraySize*sizeof(char)); 
	char * newString = malloc(arraySize*sizeof(char));
	
	memset(temp,0,sizeof(char)*arraySize);
	memset(newString,0,sizeof(char)*arraySize);
	sprintf(temp,"%s",buf); 
	char * tok = strtok(temp,"\x0A");
	while(tok)
	{
		if(strstr(tok,"\x0D"))
		{
			CopyString(newString,strlen(newString),tok,0,strlen(tok)-1);
			sprintf(newString,"%s\x0A",newString);
		}
		else
		{
			CopyString(newString,strlen(newString),tok,0,strlen(tok)-1); 
		}
		tok = strtok(NULL,"\x0A");
	}
	sprintf(buf,"%s",newString);
	free(temp);
	free(newString);
	return 0;
}
//kim added/********************************************//** *  Takes the PartNumber and point as input and returns the Min, max,paramater and required coloumn that was loaded into structure from csv. ***********************************************/int getUnitInfoByRequirement(char *requirement, char *min, char *max, char *parameter, char *Point, char *Unit){	char PartNumNospaces[50]={0};	char inputPartNumNospaces[50]={0};  		char inputRequirementNospaces[50]={0}; 		for(int i=0;i<MAXC5UNITS;i++)	{		sprintf(inputPartNumNospaces,"%s", remove_spaces(PartNumberStatic, inputPartNumNospaces)); 		sprintf(PartNumNospaces,"%s", remove_spaces(C5Unit[i].PartNum, PartNumNospaces));		if(!stricmp(PartNumberStatic,PartNumNospaces))		{			for(int j=0;j<MAXTESTCOUNT;j++)			{				sprintf(inputRequirementNospaces,"%s", remove_spaces(C5Unit[i].Tests[j].Requirement, inputRequirementNospaces));				if(!stricmp(requirement,inputRequirementNospaces))				{					sprintf(Point,"%s",C5Unit[i].Tests[j].Points); 										sprintf(min,"%s",C5Unit[i].Tests[j].Min);					sprintf(max,"%s",C5Unit[i].Tests[j].Max);					sprintf(parameter,"%s",C5Unit[i].Tests[j].Parameter);					sprintf(Unit,"%s",C5Unit[i].Tests[j].Unit);					//sprintf(requirement,"%s",CalParamUnit[i].Tests[j].Requirement);					return 0;				}			}		}	}		return -1;}/********************************************//** *  Takes the PartNumber and point as input and returns the Min, max,paramater and required coloumn that was loaded into structure from csv. ***********************************************/int getPointByRequirement(char *requirement, char *Point){	char PartNumNospaces[50]={0};	char inputPartNumNospaces[50]={0};  		char inputRequirementNospaces[50]={0}; 		for(int i=0;i<MAXC5UNITS;i++)	{		sprintf(inputPartNumNospaces,"%s", remove_spaces(PartNumberStatic, inputPartNumNospaces)); 		sprintf(PartNumNospaces,"%s", remove_spaces(C5Unit[i].PartNum, PartNumNospaces));		if(!stricmp(PartNumberStatic,PartNumNospaces))		{			for(int j=0;j<MAXTESTCOUNT;j++)			{				sprintf(inputRequirementNospaces,"%s", remove_spaces(C5Unit[i].Tests[j].Requirement, inputRequirementNospaces));								if(!stricmp(requirement,inputRequirementNospaces))				{					sprintf(Point,"%s",C5Unit[i].Tests[j].Points); 					return 0;				}			}		}	}		return -1;}void setPartNumber (char *partnumber){	strcpy(PartNumberStatic,partnumber);	}/********************************************//***  return product type associated with fixture***********************************************/char * getProductType(char * PartNumber){	char PartNumNospaces[50]={0};	char inputPartNumNospaces[50]={0};  		char TypeNospaces[50]={0};		for(int i=0;i<MAXC5UNITS;i++)	{		sprintf(inputPartNumNospaces,"%s", remove_spaces(PartNumber, inputPartNumNospaces)); 		sprintf(PartNumNospaces,"%s", remove_spaces(C5Unit[i].PartNum, PartNumNospaces));		if(!stricmp(PartNumber,PartNumNospaces))		{			sprintf(TypeNospaces,"%s", remove_spaces(C5Unit[i].Type, TypeNospaces));			return TypeNospaces; 		}	}		return "Unknown Type";}		 //gm fxt = 3, gauge = 4
