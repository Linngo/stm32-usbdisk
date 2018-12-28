/******************************************************************************
//┌────────────────────────────────────────┐
//│         高通科技版权所有  						 │
//│      GENITOP RESEARCH CO.,LTD.         │
//│        created on 2015.7.27            │
//└────────────────────────────────────────┘
******************************************************************************/


extern unsigned char r_dat_bat(unsigned long address,unsigned long byte_long,unsigned char *p_arr);

#define ASCII_5X7              1      //ASCII编码5X7点阵
#define ASCII_7X8              2      //ASCII编码7X8点阵
#define ASCII_6X12             3      //ASCII编码6X12点阵
#define ASCII_12_A 	           4      //ASCII编码12x12点阵不等宽Arial风格字符（具体字形看规格书）
#define ASCII_8X16             5      //ASCII编码8X16点阵
#define ASCII_12X24_A          6      //ASCII编码12X24点阵Arial风格字符（具体字形看规格书）
#define ASCII_12X24_P          7      //ASCII编码12X24点阵打印体风格字符（具体字形看规格书）
#define ASCII_16X32            8      //ASCII编码16X32点阵
#define ASCII_16_A             9      //ASCII编码16X16点阵Arial风格字符（具体字形看规格书）
#define ASCII_24_B            10      //ASCII编码24X24点阵不等宽Arial风格字符（具体字形看规格书）
#define ASCII_32_B            11      //ASCII编码32X32点阵不等宽Arial风格字符（具体字形看规格书）

//code page 种类
#define CP_437            0      //CODEPAGE 437部分  codepage种类cpsel选项值
#define CP_737            1      //CODEPAGE 737部分  codepage种类cpsel选项值
#define CP_775            2      //CODEPAGE 775部分  codepage种类cpsel选项值
#define CP_850            3      //CODEPAGE 850部分  codepage种类cpsel选项值
#define CP_850            4      //CODEPAGE 850部分  codepage种类cpsel选项值
#define CP_855            5      //CODEPAGE 855部分  codepage种类cpsel选项值
#define CP_857            6      //CODEPAGE 857部分  codepage种类cpsel选项值
#define CP_858            7      //CODEPAGE 858部分  codepage种类cpsel选项值
#define CP_860            8      //CODEPAGE 860部分  codepage种类cpsel选项值
#define CP_862            9      //CODEPAGE 862部分  codepage种类cpsel选项值
#define CP_863            10     //CODEPAGE 863部分  codepage种类cpsel选项值
#define CP_864            11     //CODEPAGE 864部分  codepage种类cpsel选项值
#define CP_865            12     //CODEPAGE 865部分  codepage种类cpsel选项值
#define CP_866            13     //CODEPAGE 866部分  codepage种类cpsel选项值
#define CP_1251           14     //CODEPAGE 1251部分  codepage种类cpsel选项值
#define CP_1252           15     //CODEPAGE 1252部分  codepage种类cpsel选项值
#define CP_1253           16     //CODEPAGE 1253部分  codepage种类cpsel选项值
#define CP_1254           17     //CODEPAGE 1254部分  codepage种类cpsel选项值
#define CP_1255           18     //CODEPAGE 1255部分  codepage种类cpsel选项值
#define CP_1256           19     //CODEPAGE 1256部分  codepage种类cpsel选项值
#define CP_1257           20     //CODEPAGE 1257部分  codepage种类cpsel选项值
#define CP_928            21     //CODEPAGE 928部分  codepage种类cpsel选项值
#define CP_HEBREW         22     //CODEPAGE HEBREW部分  codepage种类cpsel选项值
#define CP_KATAKANA       23     //CODEPAGE KATAKANA部分  codepage种类cpsel选项值

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
    ASCII_GetData(0x41,ASCII_5X7,DZ_Data);      //读取5X7点阵 ASCII 编码A的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为8 BYTE
	  ASCII_GetData(0x41,ASCII_7X8,DZ_Data);      //读取7X8点阵 ASCII 编码A的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为8 BYTE
	  ASCII_GetData(0x41,ASCII_6X12,DZ_Data);     //读取6X12点阵 ASCII 编码A的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为12 BYTE
	  ASCII_GetData(0x41,ASCII_12_A,DZ_Data);   	//读取12X12点阵 ASCII 编码A的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为26 BYTE
	  ASCII_GetData(0x41,ASCII_8X16,DZ_Data);     //读取8X16点阵 ASCII 编码A的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为16 BYTE
		ASCII_GetData(0x41,ASCII_12X24_A,DZ_Data);  //读取12X24点阵 ASCII 编码A的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为48 BYTE
		ASCII_GetData(0x41,ASCII_12X24_P,DZ_Data);  //读取12X24点阵 ASCII 编码A的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为48 BYTE
	  ASCII_GetData(0x41,ASCII_16_A,DZ_Data);     //读取16X16点阵 ASCII 编码A的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为32 BYTE
	  ASCII_GetData(0x41,ASCII_16X32,DZ_Data);		//读取16X32点阵 ASCII 编码A的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为64 BYTE
	  ASCII_GetData(0x41,ASCII_24_B,DZ_Data);			//读取24X24点阵 ASCII 编码A的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为74 BYTE
	  ASCII_GetData(0x41,ASCII_32_B,DZ_Data);			//读取32X32点阵 ASCII 编码A的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为128 BYTE
*************************************************************/
unsigned char  ASCII_GetData(unsigned char ASCIICode,unsigned long ascii_kind,unsigned char* DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
    gt_12_GetData(0xb0,0xa1,DZ_Data); //读取12X12点阵 汉字“啊”的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为24 BYTE
*************************************************************/
void gt_12_GetData (unsigned char MSB,unsigned char LSB,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
    gt_16_GetData(0xb0,0xa1,DZ_Data); //读取16X16点阵 汉字“啊”的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为32 BYTE
*************************************************************/
void gt_16_GetData (unsigned char MSB,unsigned char LSB,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
    GBK_24_GetData(0xb0,0xa1,DZ_Data); //读取24X24点阵 汉字“啊”的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为72 BYTE
*************************************************************/
unsigned long GBK_24_GetData (unsigned char c1, unsigned char c2,unsigned char *DZ_Data) ;

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
    GB18030_24_GetData(0x81,0x39,0xef,0x38,DZ_Data); //读取24X24点阵 扩展汉字“㐉”的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为72 BYTE
*************************************************************/
unsigned long GB18030_24_GetData (unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
    Shift_Jis_8X16_GetData(0xCC,DZ_Data); //读取8X16点阵 日文半角假名shift-jis编码0xCC的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为16 BYTE
说明：日文半角假名 		
*************************************************************/
unsigned long Shift_Jis_8X16_GetData(unsigned int CODE,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
    Unicode_Shift_Jis_GetData(0xFF8C,DZ_Data); //读取8X16点阵 日文半角假名unicode编码0xFF8C的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为16 BYTE
说明：日文半角假名 unicode调用		
*************************************************************/
unsigned long Unicode_Shift_Jis_GetData(unsigned int CODE,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
    JIS0208_16X16_GetData(0x04,0x01,DZ_Data); //读取16X16点阵 JIS-0208编码0x0401的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为32 BYTE
*************************************************************/
unsigned long JIS0208_16X16_GetData(unsigned char MSB,unsigned char LSB,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
    JIS0208_24X24_GetData(0x04,0x01,DZ_Data); //读取24X24点阵 JIS-0208编码0x0401的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为72 BYTE
*************************************************************/
unsigned long JIS0208_24X24_GetData(unsigned char MSB,unsigned char LSB,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
    KSC5601_F_16_GetData(0xb0,0xA1,DZ_Data); //读取16X16点阵 KSC5601编码0xb0a1的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为32 BYTE
*************************************************************/
unsigned long KSC5601_F_16_GetData(unsigned char MSB,unsigned char LSB,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
    KSC5601_F_24_GetData(0xb0,0xA1,DZ_Data); //读取24X24点阵 KSC5601编码0xb0a1的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为72 BYTE
*************************************************************/
unsigned long KSC5601_F_24_GetData(unsigned char MSB,unsigned char LSB,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
    LATIN_8X16_GetData(0xa5,DZ_Data); //读取8X16点阵 拉丁文编码0xa5的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为16 BYTE
*************************************************************/
unsigned long LATIN_8X16_GetData(unsigned int FontCode,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  GREECE_8X16_GetData(0x375,DZ_Data);  //读取8X16点阵希腊文编码0x375的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为16 BYTE
*************************************************************/
unsigned long GREECE_8X16_GetData(unsigned int FontCode,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
    CYRILLIC_8X16_GetData(0x405,DZ_Data); //读取8X16点阵西里尔文编码0x405的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为16 BYTE
*************************************************************/
unsigned long CYRILLIC_8X16_GetData(unsigned int FontCode,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  HEBREW_8X16_GetData(0x595,DZ_Data);  //读取8X16点阵希伯来文编码0x375的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为16 BYTE
*************************************************************/
unsigned long HEBREW_8X16_GetData(unsigned int FontCode,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
    THAILAND_8X16_GetData(0xe05,DZ_Data);  //读取8X16点阵不等宽希腊文编码0xe05的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为16 BYTE
*************************************************************/
unsigned long THAILAND_8X16_GetData(unsigned int FontCode,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  LATIN_16_GetData(0xA1,DZ_Data);  //读取16X16点阵拉丁文编码0xA1的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为32 BYTE
*************************************************************/
unsigned long LATIN_16_GetData(unsigned int FontCode,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  GREECE_16_GetData(0x375,DZ_Data);  //读取16X16点阵希腊文编码0x375的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为32 BYTE
*************************************************************/
unsigned long GREECE_16_GetData(unsigned int FontCode,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
    CYRILLIC_16_GetData(0x405,DZ_Data); //读取16X16点阵西里尔文编码0x405的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为32 BYTE
*************************************************************/
unsigned long CYRILLIC_16_GetData(unsigned int FontCode,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  ALB_16_GetData(0x632,DZ_Data); //读取16X16点阵阿拉伯文编码0x632的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为32 BYTE
*************************************************************/
unsigned long ALB_16_GetData(unsigned int unicode_alb,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  Indic_16_GetData(0x0905,DZ_Data); //读取16X16点阵阿拉伯文编码0x0905的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为32 BYTE
*************************************************************/
unsigned long Indic_16_GetData(unsigned int FontCode,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  LATIN_12X24_GetData(0xA1,DZ_Data);  //读取12X24点阵拉丁文编码0xA1的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为48 BYTE
*************************************************************/
unsigned long LATIN_12X24_GetData(unsigned int FontCode,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  GREECE_12X24_GetData(0x375,DZ_Data);  //读取12X24点阵希腊文编码0x375的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为32 BYTE
*************************************************************/
unsigned long GREECE_12X24_GetData(unsigned int FontCode,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
    CYRILLIC_12X24_GetData(0x405,DZ_Data); //读取12X24点阵西里尔文编码0x405的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为32 BYTE
*************************************************************/
unsigned long CYRILLIC_12X24_GetData(unsigned int FontCode,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  HEBREW_12X24_GetData(0x595,DZ_Data);  //读取12X24点阵希伯来文编码0x375的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为48 BYTE
*************************************************************/
unsigned long HEBREW_12X24_GetData(unsigned int FontCode,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
    THAILAND_16X24_GetData(0xe05,DZ_Data);  //读取16X24点阵不等宽希腊文编码0xe05的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为16 BYTE
*************************************************************/
unsigned long THAILAND_16X24_GetData(unsigned int FontCode,unsigned char *DZ_Data);

/*************************************************************
不等宽阿拉伯文
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  ALB_24_GetData(0x632,DZ_Data); //读取24X24点阵阿拉伯文编码0x632的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为72 BYTE
*************************************************************/
unsigned long ALB_24_GetData(unsigned int UNICODE_alb,unsigned char *DZ_Data);

/*************************************************************
不等宽高棉文
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  Khmer_24_GetData(0x19e0,DZ_Data); //读取24X24点阵不等宽高棉文编码0x19e0的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为72 BYTE
*************************************************************/
unsigned long Khmer_24_GetData(unsigned int FontCode,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned long Unicode;
	  Unicode = CodePage_UC(0x00A1,CP_437); //读取codepage 437对应的unicode编码
*************************************************************/
unsigned long CodePage_UC(unsigned char CODE,unsigned char cpsel); 
unsigned long ICCS_Addr(unsigned char Icode,unsigned long BaseAddr);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  Katakana_GetData(0xA1,DZ_Data); //读取日文片假名编码0xA1编码的点阵数据，并将点阵数据存在DZ_Data，数据长度为72 BYTE
注意：编码
		0x80-0x9F和0xE0-0xFF ：点阵大小为24X24
		0xA1-0xDF：点阵大小为12X24
*************************************************************/
unsigned long Katakana_GetData(unsigned char CODE,unsigned char *DZ_Data);
//unsigned long CodePage_patch(unsigned int code,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  CP_Patch_8X16_GetData(0x003d,DZ_Data); //读取codepage新增字符的点阵数据，并将点阵数据存在DZ_Data，数据长度为16 BYTE
	  CP_Patch_8X16_GetData(0x0192,DZ_Data); //读取codepage新增字符的点阵数据，并将点阵数据存在DZ_Data，数据长度为16 BYTE
*************************************************************/
unsigned long CP_Patch_8X16_GetData(unsigned int code,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  CP_Patch_16X16_GetData(0x20a7,DZ_Data); //读取codepage新增字符的点阵数据，并将点阵数据存在DZ_Data，数据长度为32 BYTE
	  CP_Patch_16X16_GetData(0x20aa,DZ_Data); //读取codepage新增字符的点阵数据，并将点阵数据存在DZ_Data，数据长度为32 BYTE
*************************************************************/
unsigned long CP_Patch_16X16_GetData(unsigned int code,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  CP_P_KATAKANA_16X16_GetData(0xe0,DZ_Data); //读取codepage KATAKANA的点阵数据，并将点阵数据存在DZ_Data，数据长度为32 BYTE 
*************************************************************/
unsigned long CP_P_KATAKANA_16X16_GetData(unsigned int code,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  CP_P_KATAKANA_12X24_UniCode_GetData(0x0393,DZ_Data); //读取codepage 补丁unicode调用点阵数据，并将点阵数据存在DZ_Data，数据长度为48 BYTE 
*************************************************************/
unsigned long CP_P_KATAKANA_12X24_UniCode_GetData(unsigned int code,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  ISO8859_8X16_GetData(0xa2,1,DZ_Data); //读取 8X16 点阵ISO8859-1编码0xa2的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为 16 BYTE
	  ISO8859_8X16_GetData(0xa2,2,DZ_Data); //读取 8X16 点阵ISO8859-2编码0xa2的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为 16 BYTE
	  ISO8859_8X16_GetData(0xa2,3,DZ_Data); //读取 8X16 点阵ISO8859-3编码0xa2的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为 16 BYTE
	  ISO8859_8X16_GetData(0xa2,4,DZ_Data); //读取 8X16 点阵ISO8859-4编码0xa2的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为 16 BYTE
	  ISO8859_8X16_GetData(0xa2,5,DZ_Data); //读取 8X16 点阵ISO8859-5编码0xa2的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为 16 BYTE
	  ISO8859_8X16_GetData(0xa2,6,DZ_Data); //读取 8X16 点阵ISO8859-6编码0xa2的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为 16 BYTE
	  ISO8859_8X16_GetData(0xa2,7,DZ_Data); //读取 8X16 点阵ISO8859-7编码0xa2的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为 16 BYTE
	  ISO8859_8X16_GetData(0xa2,8,DZ_Data); //读取 8X16 点阵ISO8859-8编码0xa2的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为 16 BYTE
	  ISO8859_8X16_GetData(0xa2,9,DZ_Data); //读取 8X16 点阵ISO8859-9编码0xa2的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为 16 BYTE
	  ISO8859_8X16_GetData(0xa2,10,DZ_Data); //读取 8X16 点阵ISO8859-10编码0xa2的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为 16 BYTE
	  ISO8859_8X16_GetData(0xa2,11,DZ_Data); //读取 8X16 点阵ISO8859-11编码0xa2的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为 16 BYTE
	  ISO8859_8X16_GetData(0xa2,12,DZ_Data); //读取 8X16 点阵ISO8859-12编码0xa2的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为 16 BYTE
	  ISO8859_8X16_GetData(0xa2,13,DZ_Data); //读取 8X16 点阵ISO8859-13编码0xa2的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为 16 BYTE
	  ISO8859_8X16_GetData(0xa2,14,DZ_Data); //读取 8X16 点阵ISO8859-14编码0xa2的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为 16 BYTE
	  ISO8859_8X16_GetData(0xa2,15,DZ_Data); //读取 8X16 点阵ISO8859-15编码0xa2的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为 16 BYTE
	  ISO8859_8X16_GetData(0xa2,16,DZ_Data); //读取 8X16 点阵ISO8859-16编码0xa2的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为 16 BYTE
ISO8859说明20h-7Fh请参考8X16 ASCII
*************************************************************/ 
unsigned long ISO8859_8X16_GetData(unsigned int FontCode,unsigned char Num,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  U2J_GetData(0x3005,DZ_Data); //读取16X16点阵unicode编码获取jis0108的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为32 BYTE
*************************************************************/
unsigned long U2J_GetData_16x16(unsigned int Unicode,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  U2J_GetData(0x3005,DZ_Data); //读取24X24点阵unicode编码获取jis0108的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为32 BYTE
*************************************************************/
unsigned long U2J_GetData_24x24(unsigned int Unicode,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned long JISCode;
	  JISCode = Shift_JIS_TO_JIS0208(0x818E); //读取shift-jis对应的jis0208编码，并将点阵数据存在变量JISCode中；
*************************************************************/
unsigned long Shift_JIS_TO_JIS0208(unsigned int Code16);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  U2K_GetData_16X16(0x33dd,DZ_Data); //读取16X16点阵unicode编码获取KSC5601的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为32 BYTE
*************************************************************/
unsigned long U2K_GetData_16X16(unsigned int Unicode,unsigned char *DZ_Data);

/*************************************************************
函数用法：
    unsigned char DZ_Data[数组长度客户自定义];
	  U2K_GetData_24X24(0x33dd,DZ_Data); //读取16X16点阵unicode编码获取KSC5601的点阵数据，并将点阵数据存在DZ_Data数组中；数据长度为32 BYTE
*************************************************************/
unsigned long U2K_GetData_24X24(unsigned int Unicode,unsigned char *DZ_Data)

/*************************************************************
函数用法：
         unsigned  int  GBK_CODE;
        GBK_CODE=BIG5_GBK(0xb0,0xda);//将“啊”字的BIG5编码转换成GB国标编码，存在GBK_CODE中.如例GBK_CODE=0xb0a1  
       
   *************************************************************/

unsigned int BIG5_GBK( unsigned char h,unsigned char l); //BIG5转GBK 

/*************************************************************
函数用法：
    unsigned int GB_CODE;
    GB_CODE= U2G(0x554a);//将“啊”字的UNICODE编码转换成GB国标编码，存在GB_CODE中.如例GB_CODE=0xb0a1
*************************************************************/
unsigned int U2G(unsigned int UN_CODE);//Unicode 转 GB18030

/*************************************************************
函数用法：

     unsigned char DZ_Data[数组长度客户自定义];

    CP_12X24_GetData(0x80,CP_437,DZ_Data);//读取codepage12X24的CP_437的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_737,DZ_Data);//读取codepage12X24的CP_737的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_775,DZ_Data);//读取codepage12X24的CP_775的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_850,DZ_Data);//读取codepage12X24的CP_850的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_855,DZ_Data);//读取codepage12X24的CP_855的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_857,DZ_Data);//读取codepage12X24的CP_857的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_858,DZ_Data);//读取codepage12X24的CP_858的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_860,DZ_Data);//读取codepage12X24的CP_860的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_862,DZ_Data);//读取codepage12X24的CP_862的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_863,DZ_Data);//读取codepage12X24的CP_863的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_864,DZ_Data);//读取codepage12X24的CP_864的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_865,DZ_Data);//读取codepage12X24的CP_865的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_866,DZ_Data);//读取codepage12X24的CP_866的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_1251,DZ_Data);//读取codepage12X24的CP_1251的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_1252,DZ_Data);//读取codepage12X24的CP_1252的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_1253,DZ_Data);//读取codepage12X24的CP_1253的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_1254,DZ_Data);//读取codepage12X24的CP_1254的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_1255,DZ_Data);//读取codepage12X24的CP_1255的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_1256,DZ_Data);//读取codepage12X24的CP_1256的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_1257,DZ_Data);//读取codepage12X24的CP_1257的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_928,DZ_Data);//读取codepage12X24的CP_928的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_HEBREW,DZ_Data);//读取codepage12X24的CP_HEBREW的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    CP_12X24_GetData(0x80,CP_KATAKANA);//读取codepage12X24的CP_KATAKANA的字符
*************************************************************/
void CP_12X24_GetData(unsigned int code,unsigned char cpsel,unsigned char *DZ_data);
/*************************************************************
函数用法：
	//unsigned  char Icode[12]={0x23UL,0x24UL,0x40UL,0x5bUL,0x5cUL,  //第一个参数Icode的值 
	//0x5dUL,0x5eUL,0x60UL,0x7bUL,0x7cUL,0x7dUL,0x7eUL};

     unsigned char DZ_Data[数组长度客户自定义];

    INTERNATIONAL_CHARACTER_12X24(0x23,USA,DZ_Data);        //读取INTERNATIONAL_CHARACTER_12X24的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    INTERNATIONAL_CHARACTER_12X24(0x23,FRANCE,DZ_Data);    //读取INTERNATIONAL_CHARACTER_12X24的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    INTERNATIONAL_CHARACTER_12X24(0x23,GERMANY,DZ_Data);    //读取INTERNATIONAL_CHARACTER_12X24的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    INTERNATIONAL_CHARACTER_12X24(0x23,UK,DZ_Data);         //读取INTERNATIONAL_CHARACTER_12X24的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    INTERNATIONAL_CHARACTER_12X24(0x23,DENMARK,DZ_Data);    //INTERNATIONAL_CHARACTER_12X24的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    INTERNATIONAL_CHARACTER_12X24(0x23,SWEDEN,DZ_Data);    //读取INTERNATIONAL_CHARACTER_12X24的字符,,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    INTERNATIONAL_CHARACTER_12X24(0x23,LTALY,DZ_Data);     //读取INTERNATIONAL_CHARACTER_12X24的字符,,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    INTERNATIONAL_CHARACTER_12X24(0x23,SPAIN,DZ_Data);     //读取INTERNATIONAL_CHARACTER_12X24的字符,,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    INTERNATIONAL_CHARACTER_12X24(0x23,JAPAN,DZ_Data);     //读取INTERNATIONAL_CHARACTER_12X24的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    INTERNATIONAL_CHARACTER_12X24(0x23,NORWAY,DZ_Data);    //读取INTERNATIONAL_CHARACTER_12X24的字符,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    INTERNATIONAL_CHARACTER_12X24(0x23,DENMARK_II,DZ_Data);//读取INTERNATIONAL_CHARACTER_12X24的字符,,并将点阵数据存在DZ_Data数组中；数据长度为 48BYTE
    
*************************************************************/
void INTERNATIONAL_CHARACTER_12X24(unsigned char Icode,unsigned long INTERNATIONAL_CHARACTER,unsigned char  *DZ_Data);















