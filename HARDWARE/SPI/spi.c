#include "spi.h"  

#define simulation 0 //使用模拟

void SPI1_Init(void)  
{	 
  GPIO_InitTypeDef  GPIO_InitStructure;
  SPI_InitTypeDef   SPI_InitStructure;
	
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_8|GPIO_Pin_9; //6:cs 7:so 8:si 9:clk
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//输出
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
  
	//硬spi
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5; //3:clk  4:so  5:si
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource3,GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource4,GPIO_AF_SPI1); 
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource5,GPIO_AF_SPI1); 

	RCC_APB2PeriphResetCmd(RCC_APB2Periph_SPI1,ENABLE);
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_SPI1,DISABLE);

	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;		
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;		
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;	
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;		
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;		
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;	
	SPI_InitStructure.SPI_CRCPolynomial = 7;	
	SPI_Init(SPI1, &SPI_InitStructure);
 
	SPI_Cmd(SPI1, ENABLE); 

	SPI1_ReadWriteByte(0xff);

}  
//SPI1速度设置函数
//SpeedSet:0~7
//SPI速度=fAPB2/2^(SpeedSet+1)
//fAPB2时钟一般为84Mhz
void SPI1_SetSpeed(u8 SPI_BaudRatePrescaler)
{
  	assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_BaudRatePrescaler));
	SPI1->CR1&=0XFFC7;
	SPI1->CR1|=SPI_BaudRatePrescaler;	//设置SPI1速度 
	SPI_Cmd(SPI1,ENABLE);  
} 
//SPI1 读写一个字节
//TxData:要写入的字节
//返回值:读取到的字节
u8 SPI1_ReadWriteByte(u8 TxData)
{		 			 
 
  while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET){}//等待发送区空  
	
	SPI_I2S_SendData(SPI1, TxData); //通过外设SPIx发送一个byte  数据
		
  while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET){} //等待接收完一个byte  
 
	return SPI_I2S_ReceiveData(SPI1); //返回通过SPIx最近接收的数据	
 		    
}



/***********************
*      模拟spi
***********************/
void zk_init(void)
{
  Rom_csH;
  MOSIH;
  Rom_sckH;
}

 void Send_Byte(unsigned char out)
  {	
	unsigned char i=0;
	
	for(i=0;i<8;i++)
	{
	  Rom_sckL;  
	  if(((out<<i)&0x80)==0)
	      MOSIL;   
	  else
	      MOSIH;
	  Rom_sckH;
      }
   }
 

  unsigned char Get_Byte(void)         
  {
	unsigned char i;
	unsigned char read_dat;

	Rom_sckH;
	for(i=0;i<8;i++)
	{
		Rom_sckL;
		read_dat=read_dat<<1;
		if(MISO)				
			read_dat|=0x01;
		else
			read_dat&=0xfe;
		Rom_sckH;
	}
	return(read_dat);
}



void SPI_Address(unsigned char AddH,unsigned char AddM,unsigned char AddL) 
{
	Send_Byte(AddH);
	Send_Byte(AddM);
	Send_Byte(AddL);
}

unsigned  char  r_dat_bat(unsigned long  ReadAddr,unsigned int  NumByteToRead,unsigned char* pBuffer)   
{ 
#ifdef simulation 
	
 	  u16 i;   										    
	  _CS=0;                            
    SPI1_ReadWriteByte(0x03);          
    SPI1_ReadWriteByte((u8)((ReadAddr)>>16));    
    SPI1_ReadWriteByte((u8)((ReadAddr)>>8));   
    SPI1_ReadWriteByte((u8)ReadAddr);  
	
    for(i=0;i<NumByteToRead;i++)
	 { 
        pBuffer[i]=SPI1_ReadWriteByte(0XFF);
   }
	  _CS=1;
#else
	unsigned char i;
  unsigned char addrHigh;
  unsigned char addrMid;
  unsigned char addrLow;
  addrHigh=ReadAddr>>16;
  addrMid=ReadAddr>>8;
  addrLow=(unsigned char)ReadAddr;
  
	_CS=0;          
	Send_Byte(0x03);	
	SPI_Address(addrHigh,addrMid,addrLow);	
	for(i=0;i<NumByteToRead;i++)
	*(pBuffer+i)=Get_Byte();
	_CS=1;
#endif
   return  pBuffer[0];	 
}


unsigned   long  r_dat(unsigned long  ReadAddr)   
{ 
#ifdef simulation 
// 	  u16 i;   		
    unsigned  long	pBuffer=0;
	  _CS=0;                             
    SPI1_ReadWriteByte(0x03);          
    SPI1_ReadWriteByte((u8)((ReadAddr)>>16));   
    SPI1_ReadWriteByte((u8)((ReadAddr)>>8));   
    SPI1_ReadWriteByte((u8)ReadAddr);  
	  pBuffer=SPI1_ReadWriteByte(0XFF);   
    _CS=1;  
#else	
	
		u8 buff;
		Rom_csL;
		Send_Byte(ReadAddr); 
		buff = Get_Byte();	
		Rom_csH;
#endif
   	return  pBuffer;		
}


