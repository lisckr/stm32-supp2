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

char USART1_Buff[256];
u8   USART1_Rx_STATUS;
u16  size1 = 0;

char USART2_Buff[256];
u8   USART2_Rx_STATUS;
u16  size2 = 0;

char USART3_Buff[256];
u8   USART3_Rx_STATUS;
u16  size3 = 0;





/* ------------------------------  支持 printf  ------------------------------*/



//勾选 Use MicroLIB   支持 printf 函数

int fputc(int ch, FILE *f)
{
	USART_SendData(USART1, (uint8_t) ch);

	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET) {}

    return ch;
}



/* ------------------------------- 串口  配置 ------------------------------- */

//串口一配置
#if USART1_ENABLE

void USART1_Config(u32 bound)
{

  GPIO_InitTypeDef  GPIO_InitStructure;
  NVIC_InitTypeDef  NVIC_InitStructure;
  USART_InitTypeDef USART_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1,ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;      //GPIO初始化  GPIOA->9  Mode->AF_PP  SPEED->50MHz
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA,&GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;      //GPIO初始化  GPIOA->10 Mode->IN_FLOATING
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA,&GPIO_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;      //NVIC初始化
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  USART_InitStructure.USART_BaudRate = bound;                  //USART初始化  WordLength->8   HardwareFlow->None
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;  //   Mode->Tx/Rx  Parity->None  StopBit->1
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;

  USART_Init(USART1,&USART_InitStructure);
  USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
  USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);
  USART_Cmd(USART1,ENABLE);

}

#endif



//串口二配置
#if USART2_ENABLE

void USART2_Config(u32 bound)
{

  GPIO_InitTypeDef  GPIO_InitStructure;
  NVIC_InitTypeDef  NVIC_InitStructure;
  USART_InitTypeDef USART_InitStructure;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA ,ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA,&GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA,&GPIO_InitStructure);


  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  USART_InitStructure.USART_BaudRate = bound;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;

  USART_Init(USART2,&USART_InitStructure);
  USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
  USART_ITConfig(USART2, USART_IT_IDLE, ENABLE);
  USART_Cmd(USART2,ENABLE);

}

#endif



//串口三配置
#if USART3_ENABLE

void USART3_Config(u32 bound)
{

  GPIO_InitTypeDef  GPIO_InitStructure;
  NVIC_InitTypeDef  NVIC_InitStructure;
  USART_InitTypeDef USART_InitStructure;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB ,ENABLE);

  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB,&GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOB,&GPIO_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  USART_InitStructure.USART_BaudRate = bound;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;

  USART_Init(USART3,&USART_InitStructure);
  USART_ITConfig(USART3,USART_IT_RXNE,ENABLE);
  USART_ITConfig(USART3, USART_IT_IDLE, ENABLE);
  USART_Cmd(USART3,ENABLE);

}

#endif





/* ------------------------------- 中断处理函数 ------------------------------ */

//串口1中断接收
#if USART1_ENABLE


void USART1_IRQHandler(void)
{
  u8 idle = idle;
  if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
	{ 	
		 USART1_Buff[size1++]= USART_ReceiveData(USART1);
	} 
	else 
  {
    if(USART_GetITStatus(USART1, USART_IT_IDLE) != RESET)
    {
      idle=USART1->SR;
      idle=USART1->DR;
      USART1_Rx_STATUS = 1;
    }
  }
}


void USART1_Irq(void)
{
  u8  i = 0;
  if(USART1_Rx_STATUS == 1)
  {
    i = 0;
    USART1_Rx_STATUS = 0;
    while(size1--)
    {
			USART_SendData(USART1,USART1_Buff[i++]);
      while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);      
    }
    memset(USART1_Buff,0,sizeof(USART1_Buff));
    size1 = 0;
  } 
  
}


#endif


/* ------------------------------------------------------------------------- */

//串口2中断接收
#if USART2_ENABLE

void USART2_IRQHandler(void)
{
  u8 idle = idle;
  if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
	{ 	
		 USART1_Buff[size2++]= USART_ReceiveData(USART2);
	} 
	else 
  {
    if(USART_GetITStatus(USART2, USART_IT_IDLE) != RESET)
    {
      idle=USART2->SR;
      idle=USART2->DR;
      USART2_Rx_STATUS = 1;
    }
  }
}


void USART2_Irq(void)
{
  u8  i = 0;
  if(USART2_Rx_STATUS == 1)
  {
    i = 0;
    USART1_Rx_STATUS = 0;
    while(size2--)
    {
			USART_SendData(USART2,USART2_Buff[i++]);
      while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);      
    }
    memset(USART2_Buff,0,sizeof(USART2_Buff));
    size2 = 0;
  } 
  
}

#endif



/* ------------------------------------------------------------------------- */

//串口3中断接收
#if USART3_ENABLE

void USART3_IRQHandler(void)
{
  u8 idle = idle;
  if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
	{ 	
		 USART3_Buff[size3++]= USART_ReceiveData(USART3);
	} 
	else 
  {
    if(USART_GetITStatus(USART3, USART_IT_IDLE) != RESET)
    {
      idle=USART3->SR;
      idle=USART3->DR;
      USART3_Rx_STATUS = 1;
    }
  }
}


void USART3_Irq(void)
{
  u8  i = 0;
  if(USART3_Rx_STATUS == 1)
  {
    i = 0;
    USART3_Rx_STATUS = 0;
    while(size3--)
    {
			USART_SendData(USART3,USART3_Buff[i++]);
      while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);
      memset(USART3_Buff,0,sizeof(USART3_Buff));
      size3 = 0;
    }

  } 
  
}

#endif



/* ----------------------------  数据 发送/接收  -----------------------------*/

//USART1 单字节发送
void USART1_Send(u8 data)
{
  USART_ClearFlag(USART1,USART_FLAG_TC);
  USART_SendData(USART1,data);
  while( USART_GetFlagStatus(USART1,USART_FLAG_TC) == RESET);
}


//USART2 单字节发送
void USART2_Send(u8 data)
{
  USART_ClearFlag(USART2,USART_FLAG_TC);
  USART_SendData(USART2,data);
  while( USART_GetFlagStatus(USART2,USART_FLAG_TC) == RESET);
}


//USART3 单字节发送
void USART3_Send(u8 data)
{
  USART_ClearFlag(USART3,USART_FLAG_TC);
  USART_SendData(USART3,data);
  while( USART_GetFlagStatus(USART3,USART_FLAG_TC) == RESET);
}


/* ------------------------------------------------------------------------- */

//USART1 发送字符串
void USART1_Print(char *str)
{
  while(*str)
  {
    USART1_Send(*str++);
  }
}

//USART2 发送字符串
void USART2_Print(char *str)
{
  while(*str)
  {
    USART2_Send(*str++);
  }
}

//USART3 发送字符串
void USART3_Print(char *str)
{
  while(*str)
  {
    USART3_Send(*str++);
  }
}


/* ------------------------------------------------------------------------- */

//USART1 发送字符串 结束换行
void USART1_Println(char *str)
{
  while(*str)
  {
    USART1_Send(*str++);
  }
  USART1_Send('\n');
}


//USART2 发送字符串 结束换行
void USART2_Println(char *str)
{
  while(*str)
  {
    USART2_Send(*str++);
  }
  USART2_Send('\n');
}


//USART3 发送字符串 结束换行
void USART3_Println(char *str)
{
  while(*str)
  {
    USART3_Send(*str++);
  }
  USART3_Send('\n');
}










/* -------------------------------  end code  --------------------------------*/
