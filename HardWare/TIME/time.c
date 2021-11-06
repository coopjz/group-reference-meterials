#include "time.h"
#include "Init.h"




void TIM7_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7,ENABLE);  ///使能TIM7时钟
	
  TIM_TimeBaseInitStructure.TIM_Period = arr; 	//自动重装载值
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM7,&TIM_TimeBaseInitStructure);//初始化TIM7
	
	TIM_ITConfig(TIM7,TIM_IT_Update,ENABLE); //允许定时器7更新中断
	TIM_Cmd(TIM7,ENABLE); //使能定时器7
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM7_IRQn; //定时器7中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

//定时器7中断服务函数
void TIM7_IRQHandler(void)
{
	extern int Encoder_Date[],Target_Speed[],PWM[];
	if(TIM_GetITStatus(TIM7,TIM_IT_Update)==SET) //溢出中断
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
	TIM_ClearITPendingBit(TIM7,TIM_IT_Update);  //清除中断标志位
}


