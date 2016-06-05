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

static u8  fac_us=0;
static u16 fac_ms=0;





/* ------------------------------  粗略型延时  -------------------------------*/


//微秒 延时
void delayus(u32 sec)
{
  u16 i=0;
  while(sec--)
  {
    i=10;
    while(i--);
  }  
}




//毫秒 延时
void delayms(u32 sec)
{
  u16 i=0;
  while(sec--)
    {
      i=12000;
      while(i--);
    }
}



/* -----------------------------  滴答时钟延时  ------------------------------*/



//延迟函数/初始化
void delay_init(void)	 
{

	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	  
	fac_us=SystemCoreClock/8000000;	                        
	fac_ms=(u16)fac_us*1000;  
}								    




//微秒级 延时
void delay_us(u32 nus)
{		
	u32 temp;	    	 
	SysTick->LOAD=nus*fac_us;                             	 
	SysTick->VAL=0x00;                                    
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;               
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));                       
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;              
	SysTick->VAL =0X00;                                    
}




//毫秒级 延时
void delay_ms(u32 nms)
{	 		  	  
	u32 temp;		   
	SysTick->LOAD=(u32)nms*fac_ms;                       
	SysTick->VAL =0x00;                                   
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;              
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));                    
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;              
	SysTick->VAL =0X00;                                   	    
} 




/* -------------------------------  end code  --------------------------------*/



