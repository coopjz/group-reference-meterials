#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//定时器 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/6/16
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

void TIM12_PWM_Init(u32 arr,u32 psc);// 
void TIM13_PWM_Init(u32 arr,u32 psc);//  
void TIM14_PWM_Init(u32 arr,u32 psc);//
void M_Init(void);
void LED_Init(void);

#define M_L1 PBout(3)
#define M_L2 PBout(4)
#define M_R1 PBout(9)
#define M_R2 PBout(10)

#endif
