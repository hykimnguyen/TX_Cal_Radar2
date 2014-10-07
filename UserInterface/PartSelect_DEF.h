int PartSelectIsOn;


int loadTableFromDatabase(char DSN[100],char UserID[100],char Password[100]);
int SaveToAppConfig(void);
char *GetFileName( char *path) ;
int LoadSelectedRecipe(void);
void LoadLocalRecipe(void);
