#include "sys.h"
#include "Init.h"
#include "pwm.h"
extern short int Dis_Forword,Dis_Back;
/*
本次 麦轮使用了 7个定时器

T2~5  为4路编码器
T12  T13   T14  pwm

*/


int Encoder_Date[4],Target_Speed[4] ={0} ,PWM[4];
short int Speed_All = 500;
int main()
{
	extern u8 Data[];
	Sys_Init();

	while(1)
	{
		Center_Control();
	}
}






