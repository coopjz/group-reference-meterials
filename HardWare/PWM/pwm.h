#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//��ʱ�� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/6/16
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
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
