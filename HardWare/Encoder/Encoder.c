#include "Encoder.h"

//��������������
void TIM4_ENC_Init(void)  //Moter_C
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); //ʹ��TIM4ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//ʹ��GPIOBʱ��

	/* Configure PC.06,07 as encoder input */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//����ٶ�Ϊ100MHz
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;		//���Ÿ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;		//��©���
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;		//����
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOD,GPIO_PinSource12,GPIO_AF_TIM4);//��PB6��������ΪTIM4
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource13,GPIO_AF_TIM4);//��PB7��������ΪTIM4
	
	//�������ӿ�����
	TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI1, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);

	TIM_Cmd(TIM4, ENABLE); 
}


void TIM1_ENC_Init(void)  //Moter_D
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); //ʹ��TIM5ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//ʹ��GPIOAʱ��

	/* Configure PA0,A1 as encoder input */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//����ٶ�Ϊ100MHz
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;		//���Ÿ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;		//��©���
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;		//����
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOA,GPIO_PinSource0,GPIO_AF_TIM1);//��PA0��������ΪTIM5
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource1,GPIO_AF_TIM1);//��PA1��������ΪTIM5
	
	//�������ӿ�����
	TIM_EncoderInterfaceConfig(TIM1, TIM_EncoderMode_TI1, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
	TIM_Cmd(TIM1, ENABLE); 
}



void TIM2_ENC_Init(void)  //Moter_A
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //ʹ��TIM5ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);//ʹ��GPIOAʱ��
	//RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);//ʹ��GPIOAʱ��

	/* Configure PA0,A1 as encoder input */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//����ٶ�Ϊ100MHz
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;		//���Ÿ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;		//��©���
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;		//����
	GPIO_Init(GPIOB, &GPIO_InitStructure);
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOB,GPIO_PinSource10,GPIO_AF_TIM2);//��PA0��������ΪTIM5
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource11,GPIO_AF_TIM2);//��PA1��������ΪTIM5
	
	//�������ӿ�����
	TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI1, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);

	TIM_Cmd(TIM2, ENABLE); 
}


void TIM3_ENC_Init(void)  //Moter_B
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //ʹ��TIM3ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);//ʹ��GPIOAʱ��

	/* Configure PA0,A1 as encoder input */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//����ٶ�Ϊ100MHz
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;		//���Ÿ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;		//��©���
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;		//����
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOC,GPIO_PinSource6,GPIO_AF_TIM3);//��PA0��������ΪTIM5
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource7,GPIO_AF_TIM3);//��PA1��������ΪTIM5
	
	//�������ӿ�����
	TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI1, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
	TIM_Cmd(TIM3, ENABLE); 
}







