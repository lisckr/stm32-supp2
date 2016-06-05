#ifndef _DEVIL_H
#define _DEVIL_H



/* ------------------------------------------------------------------------- */


#include "stm32f10x.h"
#include  "stdio.h"
#include "string.h"


#define USART1_ENABLE   1    //串口一 启/停 标志  开启：1  关闭： 0
#define USART2_ENABLE   0    //串口二 启/停 标志  开启：1  关闭： 0
#define USART3_ENABLE   0    //串口三 启/停 标志  开启：1  关闭： 0


#define   SPI1_ENABLE   1   
#define   SPI2_ENABLE   0  
#define   SPI3_ENABLE   0 

  
void SPI1_Config(void);
void SPI2_Config(void);
void SPI3_Config(void);



u8 SPI1_Communication(u8 TxData);
u8 SPI2_Communication(u8 TxData);
u8 SPI3_Communication(u8 TxData);


void delayus(u32 sec);
void delayms(u32 sec);



void delay_init(void);
void delay_us(u32 nus);
void delay_ms(u32 nms);


void NVIC_Config(void);


void EXIT_Config(void);


void PWM_Config(u16 period,u16 scale);


void USART1_Config(u32 bound);
void USART1_Send(u8 data);
void USART1_Print(char *str);
void USART1_Println(char *str);


void USART2_Config(u32 bound);
void USART2_Send(u8 data);
void USART2_Print(char *str);
void USART2_Println(char *str);


void USART3_Config(u32 bound);
void USART3_Send(u8 data);
void USART3_Print(char *str);
void USART3_Println(char *str);




void I2C1_Config(void);
void I2C1_Write(u8 id,u8 address,u8 byte);
u8 I2C1_Read(u8 id,u8 address);


void SPI1_Init(void);
u8 SPI1_Send(u8 Data);
u8 SPI1_Rece(u8 Buff);
  
void ADC_Config(void);  
u16 readVal(void);






#endif

