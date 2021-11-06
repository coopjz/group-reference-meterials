#include "time.h"
#include "Init.h"




void TIM7_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7,ENABLE);  ///ʹ��TIM7ʱ��
	
  TIM_TimeBaseInitStructure.TIM_Period = arr; 	//�Զ���װ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM7,&TIM_TimeBaseInitStructure);//��ʼ��TIM7
	
	TIM_ITConfig(TIM7,TIM_IT_Update,ENABLE); //����ʱ��7�����ж�
	TIM_Cmd(TIM7,ENABLE); //ʹ�ܶ�ʱ��7
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM7_IRQn; //��ʱ��7�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //��ռ���ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

//��ʱ��7�жϷ�����
void TIM7_IRQHandler(void)
{
	extern int Encoder_Date[],Target_Speed[],PWM[];
	if(TIM_GetITStatus(TIM7,TIM_IT_Update)==SET) //����ж�
	{
		
		Caculate_Encoder(Encoder_Date);
	
		PWM[0] =  MotorA_PID(Encoder_Date[0],Target_Speed[0]);
		PWM[1] =  MotorB_PID(Encoder_Date[1],Target_Speed[1]);
		PWM[2] =  MotorC_PID(Encoder_Date[2],Target_Speed[2]);
		PWM[3] =  MotorD_PID(Encoder_Date[3],Target_Speed[3]);
		TIM_SetCompare1(TIM9,500-PWM[0]);	
		TIM_SetCompare2(TIM9,500-PWM[1]);
		TIM_SetCompare1(TIM12,500-PWM[2]);
		TIM_SetCompare1(TIM10,500-PWM[3]);
		//DataScope();
	}
	TIM_ClearITPendingBit(TIM7,TIM_IT_Update);  //����жϱ�־λ
}


