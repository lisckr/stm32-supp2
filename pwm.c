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







/* -----------------------------  PWM配置函数  -------------------------------*/

//
void PWM_Config(u16 period,u16 scale)
{
  
  GPIO_InitTypeDef  GPIO_InitStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;
  TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 ,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
 
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA,&GPIO_InitStructure);
  
  
  TIM_TimeBaseInitStructure.TIM_Prescaler = scale;               //预分频值         区间 0 - 65535
  TIM_TimeBaseInitStructure.TIM_Period    = period;              //自动重装周期
  TIM_TimeBaseInitStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
  
  
  TIM_OCInitStructure.TIM_OCMode       = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState  = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_OCPolarity   = TIM_OCPolarity_High;
  TIM_OC1Init(TIM2,&TIM_OCInitStructure);  
  TIM_Cmd(TIM2,ENABLE);
  
}





/* ---------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------*/
//









/* -------------------------------  end code  --------------------------------*/
