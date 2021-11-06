 #include "Moter.h"
#define PWM_MAX   500
#define PWM_MIN  -500

 float Kp= 0.5,Ki=0.1,Kd = 0.5;
 
 
float K_Speed_Move = 7,K_Speed_Turn = 5;
#define a_PARAMETER          (0.64f)               
#define b_PARAMETER          (0.52f)     

#define Target_Max  1200
void Moter_Target_limit(short int *A,short int *B,short int *C,short int *D)
{
	short int Max,temp[4];
	u8 i;
	if(*A  > Target_Max || *B  > Target_Max || *C  > Target_Max || *D >Target_Max)  
	{//当计算出来的目标值过大时需要进行限制
		temp[0] = *A;
		temp[1] = *B;
		temp[2] = *C;
		temp[3] = *D;
		Max = temp[0];
		for(i =1 ; i < 4 ; i++) // 找出最大值
		{
			if(temp[i] > Max)
			{
				Max = temp[i];
			}
		}
		*A = temp[0] * (float)(Target_Max/Max);
		*B = temp[1] * (float)(Target_Max/Max);
		*C = temp[2] * (float)(Target_Max/Max);
		*D = temp[3] * (float)(Target_Max/Max);		
	}
}


/**************************************************************************
函数功能：小车运动数学模型
入口参数：X Y Z 三轴速度或者位置
返回  值：无
**************************************************************************/
void Kinematic_Analysis(float Vx,float Vy,float Vz)
{
		short int temp[4];
		temp[0]   = -Vx+Vy-Vz*(a_PARAMETER+b_PARAMETER);
		temp[1]   = +Vx+Vy-Vz*(a_PARAMETER+b_PARAMETER);
		temp[2]   = -Vx+Vy+Vz*(a_PARAMETER+b_PARAMETER);
		temp[3]   = +Vx+Vy+Vz*(a_PARAMETER+b_PARAMETER);
		Moter_Target_limit(temp,temp+1,temp+2,temp+3);	
		Target_A = temp[0];
		Target_B = temp[1];
		Target_C = temp[2];
		Target_D = temp[3];
}
 
int MotorA_PID(int Encoder,int Target)
{ 
	 static int Bias,Pwm,Last_bias,Last_Last_bias;
	 Bias=Encoder-Target;  
	Pwm+=Kp*(Bias-Last_bias)+Ki*Bias+Kd*(Bias-2*Last_bias+Last_Last_bias);
	Last_Last_bias = Last_bias;
	 Last_bias=Bias;	  
	 Pwm = Moter_PWM_Limit(Pwm);
	 return Pwm;  
}

int MotorB_PID(int Encoder,int Target)
{ 
	 static int Bias,Pwm,Last_bias,Last_Last_bias;
	 Bias=Encoder-Target;  
	Pwm+=Kp*(Bias-Last_bias)+Ki*Bias+Kd*(Bias-2*Last_bias+Last_Last_bias);
	Last_Last_bias = Last_bias;
	 Last_bias=Bias;	  
	 Pwm = Moter_PWM_Limit(Pwm);
	 return Pwm;  
}
int MotorC_PID(int Encoder,int Target)
{ 
	 static int Bias,Pwm,Last_bias,Last_Last_bias;
	 Bias=Encoder-Target;  
	Pwm+=Kp*(Bias-Last_bias)+Ki*Bias+Kd*(Bias-2*Last_bias+Last_Last_bias);
	Last_Last_bias = Last_bias;
	 Last_bias=Bias;	  
	 Pwm = Moter_PWM_Limit(Pwm);
	 return Pwm;  
}
int MotorD_PID(int Encoder,int Target)
{ 
	 static int Bias,Pwm,Last_bias,Last_Last_bias;
	 Bias=Encoder-Target;  
	Pwm+=Kp*(Bias-Last_bias)+Ki*Bias+Kd*(Bias-2*Last_bias+Last_Last_bias);
	Last_Last_bias = Last_bias;
	 Last_bias=Bias;	  
	 Pwm = Moter_PWM_Limit(Pwm);
	 return Pwm;  
}



void Moter_GO(u8 Dir,unsigned int Speed)          //小车行进控制
{
	#define  Accele  100
	static int Speed_Now = 0;
	static u8  Dir_Last;
	extern int Target_Speed[];
	if(Dir_Last != Dir ) Speed_Now = 0;
	Dir_Last = Dir;
	switch(Dir)
	{
		case Dir_Stop:
		{
					Moter_A_1 = 0;
					Moter_A_2 = 0;
					Moter_B_1 = 0;
					Moter_B_2 = 0;
					Moter_C_1 = 0;
					Moter_C_2 = 0;
					Moter_D_1 = 0;
					Moter_D_2 = 0;
					break;
    }
		case Dir_Forword:           
		{
				Moter_A_1 = 1;
				Moter_A_2 = 0;
				Moter_B_1 = 1;
				Moter_B_2 = 0;
				Moter_C_1 = 1;
				Moter_C_2 = 0;
				Moter_D_1 = 1;
				Moter_D_2 = 0;			
				break;
		}
		case Dir_Back:              
		{
				Moter_A_1 = 0;
				Moter_A_2 = 1;
				Moter_B_1 = 0;
				Moter_B_2 = 1;
				Moter_C_1 = 0;
				Moter_C_2 = 1;
				Moter_D_1 = 0;
				Moter_D_2 = 1;
				break;
		}
		case Dir_Right:              
		{
				Moter_A_1 = 0;
				Moter_A_2 = 1;
				Moter_B_1 = 1;
				Moter_B_2 = 0;
				Moter_C_1 = 1;
				Moter_C_2 = 0;
				Moter_D_1 = 0;
				Moter_D_2 = 1;			
			break;
		}
		case Dir_Left:             
		{
				Moter_A_1 = 1;
				Moter_A_2 = 0;
				Moter_B_1 = 0;
				Moter_B_2 = 1;
				Moter_C_1 = 0;
				Moter_C_2 = 1;
				Moter_D_1 = 1;
				Moter_D_2 = 0;					
			break;
		}
		case Dir_FL:
		{
				Moter_A_1 = 1;
				Moter_A_2 = 0;
				Moter_B_1 = 0;
				Moter_B_2 = 0;
				Moter_C_1 = 0;
				Moter_C_2 = 0;
				Moter_D_1 = 1;
				Moter_D_2 = 0;			
			break;
		}
		case Dir_FR:
		{
				Moter_A_1 = 0;
				Moter_A_2 = 0;
				Moter_B_1 = 1;
				Moter_B_2 = 0;
				Moter_C_1 = 1;
				Moter_C_2 = 0;
				Moter_D_1 = 0;
				Moter_D_2 = 0;	
			break;
		}
		
		case Dir_BR:
		{
				Moter_A_1 = 0;
				Moter_A_2 = 1;
				Moter_B_1 = 0;
				Moter_B_2 = 0;
				Moter_C_1 = 0;
				Moter_C_2 = 0;
				Moter_D_1 = 0;
				Moter_D_2 = 1;						
			break;
		}
		case Dir_BL:
		{
				Moter_A_1 = 0;
				Moter_A_2 = 0;
				Moter_B_1 = 0;
				Moter_B_2 = 1;
				Moter_C_1 = 0;
				Moter_C_2 = 1;
				Moter_D_1 = 0;
				Moter_D_2 = 0;	
			break;
		}
		case Turn_R:
		{
				Moter_A_1 = 1;
				Moter_A_2 = 0;
				Moter_B_1 = 0;
				Moter_B_2 = 1;
				Moter_C_1 = 1;
				Moter_C_2 = 0;
				Moter_D_1 = 0;
				Moter_D_2 = 1;	
			break;
		}
		case Turn_L:
		{
				Moter_A_1 = 0;
				Moter_A_2 = 1;
				Moter_B_1 = 1;
				Moter_B_2 = 0;
				Moter_C_1 = 0;
				Moter_C_2 = 1;
				Moter_D_1 = 1;
				Moter_D_2 = 0;	
				break;
		}
		default:;
	}
	
	if(Speed_Now < Speed) Speed_Now += Accele;
	if(Speed_Now > Speed) Speed_Now -= Accele;
	if(Speed_Now <=0) Speed_Now =0;	
	Target_Speed[0] = Speed_Now;
	Target_Speed[1] = Speed_Now;
	Target_Speed[2] = Speed_Now;
	Target_Speed[3] = Speed_Now;
}

void Caculate_Encoder(int temp[])       //关于编码器
{
	extern int Encoder_Date[];
	if(TIM1->CR1&0x10)
		{
			Encoder_Date[0] = 0xffffffff - TIM2->CNT;
			TIM1->CNT = 0xffffffff;
		}
		else 
		{
			Encoder_Date[0] = TIM2->CNT;
			TIM1->CNT = 0;
			
		}
		if(TIM3->CR1&0x10)
		{
			Encoder_Date[1] = 0xffff - TIM3->CNT;
			TIM3->CNT = 0xffff;
		}
		else 
		{
			Encoder_Date[1] = TIM3->CNT;
			TIM3->CNT = 0;
			
		}if(TIM4->CR1&0x10)
		{
			Encoder_Date[2] = 0xffff - TIM4->CNT;
			TIM4->CNT = 0xffff;
		}
		else 
		{
			Encoder_Date[2] = TIM4->CNT;
			TIM4->CNT = 0;
			
		}if(TIM5->CR1&0x10)
		{
			Encoder_Date[3] = 0xffffffff - TIM5->CNT;
			TIM5->CNT = 0xffffffff;
		}
		else 
		{
			Encoder_Date[3] = TIM5->CNT;
			TIM5->CNT = 0;
			
		}
}
int Moter_PWM_Limit(int PWM)   //pid计算出的pwm与最大最小值比较
{
	if(PWM > PWM_MAX ) PWM = PWM_MAX;
	if(PWM < PWM_MIN ) PWM = PWM_MIN;
	return  PWM;
}

void Moter_Init(void)         //电机总初始化（包含下面三个函数）
{
	Moter_PWMs_Init();
	Moter_IOs_Init();
	Moter_Encoders_Init();
}

void Moter_IOs_Init(void)   //初始化四个电机的IN1 IN2
{
	GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD|RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOC, ENABLE);//使能GPIOD时钟

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;
  GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
  GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化	
}
void Moter_PWMs_Init(void)         //初始化pwm输出
{
	TIM9_PWM_Init(1000-1,10-1);
	TIM12_PWM_Init(1000-1,10-1);
	TIM10_PWM_Init(1000-1,10-1);
	TIM_SetCompare1(TIM12,0);
	TIM_SetCompare1(TIM10,0);
	TIM_SetCompare1(TIM9,0);
	TIM_SetCompare2(TIM9,0);
}
void Moter_Encoders_Init(void)     //初始化编码器IO口
{
	TIM1_ENC_Init();
	TIM3_ENC_Init();
	TIM4_ENC_Init();
	TIM2_ENC_Init();
}



