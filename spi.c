/**
  ******************************************************************************
  * @file
  * @author  lisck
  * @version V1.0.0
  * @date    2016-01-01
  * @brief
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */


//  _Includes

#include "devil.h"


//  _Declare






//SPI 数据通讯
//u8 SPI1_Communication(u8 TxData)
//{

//  while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);

//  SPI_I2S_SendData(SPI1, TxData);

//  while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);

//  return SPI_I2S_ReceiveData(SPI1);
//}




/* ------------------------------- SPI  配置 ------------------------------- */

//SPI1配置
#if SPI1_ENABLE

void SPI1_Config(void)
{
  
  SPI_InitTypeDef  SPI_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
 
  
  // FUNC : SCK
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;                 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  
  // FUNC : MISO
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;                
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  
  // FUNC : MOSI
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;                
  GPIO_Init(GPIOA, &GPIO_InitStructure);


  // FUNC : CS
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;                
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);


  GPIO_SetBits(GPIOA, GPIO_Pin_2);


  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_Init(SPI1, &SPI_InitStructure);


  SPI_Cmd(SPI1, ENABLE);
  
}




#endif



/* ------------------------------------------------------------------------- */

//SPI2配置
#if SPI2_ENABLE

void SPI2_Config(void)
{
  
  SPI_InitTypeDef  SPI_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI2, ENABLE);
 
  
  // FUNC : SCK
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;                 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  
  // FUNC : MISO
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;                
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  
  // FUNC : MOSI
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;                
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  // FUNC : CS
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;                
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_SetBits(GPIOB, GPIO_Pin_12);


  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_Init(SPI2, &SPI_InitStructure);


  SPI_Cmd(SPI2, ENABLE);
  
}



#endif


/* ------------------------------------------------------------------------- */


//SPI3配置
#if SPI3_ENABLE

void SPI3_Config(void)
{
  
  SPI_InitTypeDef  SPI_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI3, ENABLE);
 
  
  // FUNC : SCK
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;                 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  
  // FUNC : MISO
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;                
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  
  // FUNC : MOSI
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;                
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  // FUNC : CS
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;                
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_SetBits(GPIOB, GPIO_Pin_2);


  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_Init(SPI3, &SPI_InitStructure);


  SPI_Cmd(SPI3, ENABLE);
  
}





#endif














/* -------------------------------  end code  --------------------------------*/
