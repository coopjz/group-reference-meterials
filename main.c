#include "sys.h"
#include "Init.h"
#include "pwm.h"
extern short int Dis_Forword,Dis_Back;
/*
���� ����ʹ���� 7����ʱ��

T2~5  Ϊ4·������
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






