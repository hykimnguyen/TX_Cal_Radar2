#define ANALOG_INPUT_TABLE_ROW			16 // 80
#define ANALOG_INPUT_TABLE_COLUMN		10
#define ANALOG_OUTPUT_TABLE_ROW			0 
#define ANALOG_OUTPUT_TABLE_COLUMN		10
#define MDIO_TABLE_ROW					24
#define MDIO_TABLE_COLUMN				10


int			DYN_TABLE_AI_CONFIG, DYN_TABLE_AO_CONFIG, 
	        DYN_TABLE_MDIO_CONFIG, DYN_TABLE_MISC_CONFIG; 
int			DYN_TABLE_AI_CONFIG_2, DYN_TABLE_AO_CONFIG_2, 
	        DYN_TABLE_MDIO_CONFIG_2, DYN_TABLE_MISC_CONFIG_2;  

void CreateAnalogInputConfigurationTable(void);
void CreateAnalogOutputConfigurationTable(void);
void CreateMDigitalIOConfigurationTable(void);
void CreateMDigitalIOConfigurationTable2(void);
void CreateAnalogOutputConfigurationTable2(void);
void CreateAnalogInputConfigurationTable2(void);

void CreateMiscConfigurationTable(void);
void __stdcall DisplayMIOControl(int firstTab, int editConfig);
void __stdcall DisplayMIOControl2(int firstTab, int editConfig);

