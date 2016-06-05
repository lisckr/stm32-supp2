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




/* ---------------------------------------------------------------------------*/

//ADC 初始化
void ADC_Config(void)
{
   
  GPIO_InitTypeDef GPIO_InitStructure;
  ADC_InitTypeDef  ADC_InitStructure;
    
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1 ,ENABLE); 
  RCC_ADCCLKConfig(RCC_PCLK2_Div6);

	
  GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_Init(GPIOA,&GPIO_InitStructure);
	
  
  ADC_InitStructure.ADC_Mode               = ADC_Mode_Independent;
  ADC_InitStructure.ADC_DataAlign          = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_ScanConvMode       = DISABLE;
  ADC_InitStructure.ADC_NbrOfChannel       = 1;
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
  ADC_InitStructure.ADC_ExternalTrigConv   = ADC_ExternalTrigConv_None;
  ADC_Init(ADC1,&ADC_InitStructure);

	
	ADC_RegularChannelConfig(ADC1,ADC_Channel_1,1,ADC_SampleTime_239Cycles5);
	
  ADC_Cmd(ADC1,ENABLE);
	
  ADC_ResetCalibration(ADC1);	  	 
	while(ADC_GetResetCalibrationStatus(ADC1));	
	
	ADC_StartCalibration(ADC1);	
	while(ADC_GetCalibrationStatus(ADC1));	 
}




/* ------------------------------------------------------------------------- */

// 读取 A/D转换
u16 readVal(void)
{
	
  ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
	
  return ADC_GetConversionValue(ADC1);
}












/* -------------------------------  end code  --------------------------------*/


