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




/* -----------------------------  中断分组设置  -------------------------------*/


//设置NVIC中断分组2
void NVIC_Config(void)
{
  
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	
                                                    
}





/* -------------------------------  end code  --------------------------------*/
