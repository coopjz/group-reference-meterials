#ifndef MOTER_H_
#define MOTER_H_
#include "Init.h"


#define Moter_A_1   PBout(12)
#define Moter_A_2   PBout(13)
#define Moter_B_1   PDout(8)
#define Moter_B_2   PDout(9)
#define Moter_C_1   PCout(0)
#define Moter_C_2   PCout(1)
#define Moter_D_1   PCout(2)
#define Moter_D_2   PCout(3)

#define Encoder_A  0
#define Encoder_B  1
#define Encoder_C  2
#define Encoder_D  3

#define Dir_Forword  0
#define Dir_Back     1
#define Dir_Right    2
#define Dir_Left     3
#define Dir_Stop     4
#define Dir_FR       5
#define Dir_FL       6
#define Dir_BR       7
#define Dir_BL       8
#define Turn_R       9
#define Turn_L     10

#define PWM_A PWM[0] 
#define PWM_B PWM[1]
#define PWM_C PWM[2]
#define PWM_D PWM[3]

extern int Target_Speed[];
#define Target_A Target_Speed[0]
#define Target_B Target_Speed[1]
#define Target_C Target_Speed[2]
#define Target_D Target_Speed[3]




void Moter_Target_limit(short int *A,short int *B,short int *C,short int *D);

int Moter_PWM_Limit(int a);
void Caculate_Encoder(int temp[]);
void Kinematic_Analysis(float Vx,float Vy,float Vz);

void Moter_GO(u8 Dir,unsigned int Speed);
void Moter_IOs_Init(void);
void Moter_PWMs_Init(void);
void Moter_Encoders_Init(void);
void Moter_Init(void);
void TIM9_PWM_Init(u32 arr,u32 psc);
void TIM12_PWM_Init(u32 arr,u32 psc);
void TIM10_PWM_Init(u32 arr,u32 psc);
int MotorA_PID(int Encoder, int Target);
int MotorB_PID(int Encoder, int Target);
int MotorC_PID(int Encoder, int Target);
int MotorD_PID(int Encoder, int Target);

#endif


