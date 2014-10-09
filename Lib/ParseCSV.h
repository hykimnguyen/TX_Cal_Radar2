/********************************************//**
 *  parses the CSV file provided
 ***********************************************/
int ParseCSV(char *FilePath);  
/********************************************//**
 *  Takes the PartNumber and point as input and returns the Min, max,paramater and required coloumn that was loaded into structure from csv.
 ***********************************************/
int getUnitInfo(char * PartNumber,int Point, char *min, char *max, char *parameter, char *requirement);  
int getUnitInfoByRequirement(char *requirement, char *min, char *max, char *parameter, char *Point, char*Unit);
void setPartNumber (char *partnumber);
char * getProductType(char * PartNumber);
