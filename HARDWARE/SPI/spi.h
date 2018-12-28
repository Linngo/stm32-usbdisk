#ifndef __SPI_H
#define __SPI_H
#include "sys.h"


#define	_CS 		PBout(6)  
#define	_SO 		PBin(7) 
#define	_SI 		PBout(8) 
#define	_CLK 		PBout(9) 
#define Rom_csH  PBout(6)=1
#define Rom_csL  PBout(6)=0
#define MOSIH    PBout(8)=1
#define MOSIL    PBout(8)=0
#define Rom_sckH  PBout(9)=1
#define Rom_sckL  PBout(9)=0
#define MISO   GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)//PBin(7)//
 			  	    													  
void SPI1_Init(void);			 //��ʼ��SPI1��
void SPI1_SetSpeed(u8 SpeedSet); //����SPI1�ٶ�   
u8 SPI1_ReadWriteByte(u8 TxData);//SPI1���߶�дһ���ֽ�

void zk_init(void);
		 
#endif

