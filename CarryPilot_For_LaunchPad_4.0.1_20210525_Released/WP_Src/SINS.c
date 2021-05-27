/* Copyright (c)  2019-2025 Wuhan Nameless Innovation Technology Co.,Ltd. All rights reserved.*/
/*----------------------------------------------------------------------------------------------------------------------/
                ��Դ����������ѣ������ߵ���ʷ�Ѿ�֤�����ڹ�����������£���������Ŀ�Դ������������˰����ߣ��Է��ز�����
								Ŀ���Ƶķ�ʽ�в�ͨ���õĿ�Դ��Ŀ��Ҫ��רְ��Ա�����ۺ�����ְ��ֽ�ѧ��ͳ���û�����������ʵ������ɶԲ�
								Ʒ��һ�δ���������������������ۺϿ��ǣ������ɿؿ�Դ�����У������������˾���漤��ܴ��룬�汾������ʵ��
								���ܣ����ڹ�˾��Ʒ���������������Ӱ��ͻ�ѧϰ���������ȫ�����Ÿ��ͻ�ѧϰ���ͻ���ֲ�Ͷ��ο��������뱣����
								���Ȩ��
-----------------------------------------------------------------------------------------------------------------------/
*               ������ֻ��������ѧϰʹ�ã���Ȩ����Ȩ���������ƴ��Ŷӣ������ƴ��Ŷӽ��ɿس���Դ���ṩ�������ߣ�
*               ������ҪΪ�����ƴ��Ŷ��ṩ������δ��������ɣ����ý�Դ�����ṩ�����ˣ����ý�Դ����ŵ����Ϲ�����������أ� 
*               �������Դ�����Ĳ�����緢��������Ϊ�������ƴ��Ŷӽ���֮�Է��ɽ��������
-----------------------------------------------------------------------------------------------------------------------
*                                                 Ϊʲôѡ���������£�
*                                         �ж����ļ۸�������׵Ŀ�Դ�ɿأ�
*                                         ����ҵ������֮������µ��ۺ����
*                                         ׷�����û����飬��Ч����ѧϰ֮·��
*                                         ���²��ٹµ�������������տ�Դ�߶ȣ�
*                                         ��Ӧ���ҷ�ƶ���٣��ٽ��������ƹ�ƽ��
*                                         ��ʱ���ܶ�����ʣ����������˹�ͬ�塣 
-----------------------------------------------------------------------------------------------------------------------
*               ������Ϣ���ܶ���ֹ��ǰ�����������˳���������
*               ��Դ���ף���ѧ����ϧ��ף������Ϯ�����׳ɹ�������
*               ѧϰ�����ߣ��������Ƽ���DJI��ZEROTECH��XAG��AEE��GDU��AUTEL��EWATT��HIGH GREAT�ȹ�˾��ҵ
*               ��ְ�����뷢�ͣ�15671678205@163.com���豸ע��ְ����λ����λ��������
*               �����ƴ���Դ�ɿ�QQȺ��2��Ⱥ465082224��1��Ⱥ540707961����Ա������
*               CSDN���ͣ�http://blog.csdn.net/u011992534
*               �ſ�ID��NamelessCotrun����С��
*               Bվ��ѧ��Ƶ��https://space.bilibili.com/67803559/#/video
*               �ͻ�ʹ���ĵá��Ľ������������http://www.openedv.com/forum.php?mod=viewthread&tid=234214&extra=page=1
*               �Ա����̣�https://shop348646912.taobao.com/?spm=2013.1.1000126.2.5ce78a88ht1sO2
*               �ٶ�����:�����ƴ���Դ�ɿ�
*               ��˾����:www.nameless.tech
*               �������¹����׿�TI��Դ�ɿ���Ƴ��ԡ�֪��ר��:https://zhuanlan.zhihu.com/p/54471146
*               �޸�����:2021/03/20                  
*               �汾����Ӯ��PRO����CarryPilot_V3.0.4
*               ��Ȩ���У�����ؾ���
*               Copyright(C) 2019-2025 �人�������¿Ƽ����޹�˾ 
*               All rights reserved
-----------------------------------------------------------------------------------------------------------------------
*               ��Ҫ��ʾ��
*               �����Ա�����ת�ֵķɿء��������ѡ�����ѧ�ܵĶ����Խ��ۺ�Ⱥѧϰ������
*               ����ֱ�����������������������ϣ��������´�����������Ȩ�����˲��ý�
*               ���ϴ��봫���Ϲ��������أ�������ı��ΪĿ���������ϴ��룬�����д˲�
*               ���ߣ���˾����ǰ��֪����1���ڼ�ʱ�����������ѧУ����λ����������
*               ������ַ��Ϣ�ᱻ�����ڹ�˾�������ٷ�΢�Ź���ƽ̨���ٷ��������͡�֪��
*               ר���Լ��Ա�������ҳ���Թ�ʾ���棬����������Ϊ�����Ϊ�����۵㣬Ӱ��
*               ��ѧ���ҹ���������������ܿ�ͺ������˻����������������ء�
*               �����Ϊ����˾����ش���ʧ�ߣ����Է���;���������л���ĺ�����лл������
----------------------------------------------------------------------------------------------------------------------*/
#include "Headfile.h"
#include "Earth_Declination.h"
#include "SINS.h"


#define Altitute_Kalman_Filter_Enable 1


/***********************************************************
@��������Vector_From_BodyFrame2EarthFrame
@��ڲ�����Vector3f *bf,Vector3f *ef
@���ڲ�������
��������������ϵ�򵼺�ϵת��
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void Vector_From_BodyFrame2EarthFrame(Vector3f *bf,Vector3f *ef)
{
  ef->x=rMat[0][0]*bf->x+rMat[0][1]*bf->y+rMat[0][2]*bf->z;
  ef->y=rMat[1][0]*bf->x+rMat[1][1]*bf->y+rMat[1][2]*bf->z;
  ef->z=rMat[2][0]*bf->x+rMat[2][1]*bf->y+rMat[2][2]*bf->z;
}

/***********************************************************
@��������Vector_From_EarthFrame2BodyFrame
@��ڲ�����Vector3f *ef,Vector3f *bf
@���ڲ�������
��������������ϵ������ϵת��
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void Vector_From_EarthFrame2BodyFrame(Vector3f *ef,Vector3f *bf)
{
  bf->x=rMat[0][0]*ef->x+rMat[1][0]*ef->y+rMat[2][0]*ef->z;
  bf->y=rMat[0][1]*ef->x+rMat[1][1]*ef->y+rMat[2][1]*ef->z;
  bf->z=rMat[0][2]*ef->x+rMat[1][2]*ef->y+rMat[2][2]*ef->z;
}

SINS NamelessQuad;
SINS Origion_NamelessQuad;
Butter_BufferData accel_feedback_filter_buf[3];
float Acceleration_Feedback[3];
Vector2f SINS_Accel_Body={0,0};
/***********************************************************
@��������SINS_Prepare
@��ڲ�������
@���ڲ�������
�����������ߵ����ٶ�׼��
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void  SINS_Prepare(void)
{
  Vector2f SINS_Accel_Earth={0,0};
  Vector3f Body_Frame,Earth_Frame;
  /*Z-Y-Xŷ����ת�������Ҿ���
  //Pitch Roll  Yaw �ֱ��Ӧ�� �� ��  
  X����ת����
  R������
  {1      0        0    }
  {0      cos��    sin��}
  {0    -sin��    cos�� }
  
  Y����ת����
  R���ȣ�
  {cos��     0        -sin��}
  {0         1        0     }
  {sin��     0        cos��}
  
  Z����ת����
  R���ȣ�
  {cos��      sin��       0}
  {-sin��     cos��       0}
  {0          0           1 }
  
  ��Z-Y-X˳����:
  ��������ϵ����������ϵ����ת����R(b2n)
  R(b2n) =R(��)^T*R(��)^T*R(��)^T
  
  R=
  {cos��*cos��     -cos��*sin��+sin��*sin��*cos��        sin��*sin��+cos��*sin��*cos��}
  {cos��*sin��     cos��*cos�� +sin��*sin��*sin��       -cos��*sin��+cos��*sin��*sin��}
  {-sin��          cos��sin ��                          cos��cos��                   }
  */
  Body_Frame.x=ins_accel_filter.x;
  Body_Frame.y=ins_accel_filter.y;
  Body_Frame.z=ins_accel_filter.z;
  Vector_From_BodyFrame2EarthFrame(&Body_Frame,&Earth_Frame);
  Origion_NamelessQuad.Acceleration[_YAW]=Earth_Frame.z;
  Origion_NamelessQuad.Acceleration[_PITCH]=Earth_Frame.x;
  Origion_NamelessQuad.Acceleration[_ROLL]=Earth_Frame.y;
  
  
  Origion_NamelessQuad.Acceleration[_YAW]*=AcceGravity/AcceMax;
  Origion_NamelessQuad.Acceleration[_YAW]-=AcceGravity;//��ȥ�������ٶ�
  Origion_NamelessQuad.Acceleration[_YAW]*=100;//���ٶ�cm/s^2
  
  Origion_NamelessQuad.Acceleration[_PITCH]*=AcceGravity/AcceMax;
  Origion_NamelessQuad.Acceleration[_PITCH]*=100;//���ٶ�cm/s^2
  
  Origion_NamelessQuad.Acceleration[_ROLL]*=AcceGravity/AcceMax;
  Origion_NamelessQuad.Acceleration[_ROLL]*=100;//���ٶ�cm/s^2
  
  /******************************************************************************/
  //�����˻��ڵ�������ϵ�µ���������������������˶����ٶ���ת����ǰ������˶����ٶ�:��ͷ(����)+���
  
  SINS_Accel_Earth.x=Origion_NamelessQuad.Acceleration[_PITCH];//�ص�������ϵ�����������˶����ٶ�,��λΪCM
  SINS_Accel_Earth.y=Origion_NamelessQuad.Acceleration[_ROLL];//�ص�������ϵ�����������˶����ٶ�,��λΪCM
  
  SINS_Accel_Body.x= SINS_Accel_Earth.x*Cos_Yaw+SINS_Accel_Earth.y*Sin_Yaw;  //��������˶����ٶ�  X������
  SINS_Accel_Body.y=-SINS_Accel_Earth.x*Sin_Yaw+SINS_Accel_Earth.y*Cos_Yaw; //��ͷ�����˶����ٶ�  Y������
  

  Body_Frame.x=LPButterworth(accel.x,&accel_feedback_filter_buf[0],&Butter_5HZ_Parameter_Acce);//30
  Body_Frame.y=LPButterworth(accel.y,&accel_feedback_filter_buf[1],&Butter_5HZ_Parameter_Acce);
  Body_Frame.z=LPButterworth(accel.z,&accel_feedback_filter_buf[2],&Butter_5HZ_Parameter_Acce);
	
  Vector_From_BodyFrame2EarthFrame(&Body_Frame,&Earth_Frame);
  Acceleration_Feedback[_YAW]=Earth_Frame.z;
  Acceleration_Feedback[_PITCH]=Earth_Frame.x;
  Acceleration_Feedback[_ROLL]=Earth_Frame.y;
  Acceleration_Feedback[_YAW]*=AcceGravity/AcceMax;
  Acceleration_Feedback[_YAW]-=AcceGravity;//��ȥ�������ٶ�
  Acceleration_Feedback[_YAW]*=100;//���ٶ�cm/s^2
  Acceleration_Feedback[_PITCH]*=AcceGravity/AcceMax;
  Acceleration_Feedback[_PITCH]*=100;//���ٶ�cm/s^2
  Acceleration_Feedback[_ROLL]*=AcceGravity/AcceMax;
  Acceleration_Feedback[_ROLL]*=100;//���ٶ�cm/s^2
}



/*****************�㷨�������ͽ���***************************************************
1����������ƪ֮�ߵ����ٶ�+�ٶ�+λ�����׻����ںϷ���:
http://blog.csdn.net/u011992534/article/details/61924200
2��������ߵ��ں�֮�۲⴫�����ͺ���������������˹��ͨ�˲������
����ѹ��MS5611��GPSģ��M8N����������PX4FLOW�ȣ�:
http://blog.csdn.net/u011992534/article/details/73743955
3����APMԴ�����GPS����ѹ�ƹߵ��ں�
http://blog.csdn.net/u011992534/article/details/78257684
**********************************************************************************/
float pos_correction[3]={0,0,0};
float acc_correction[3]={0,0,0};
float vel_correction[3]={0,0,0};
float SpeedDealt[3]={0};
/****��ѹ�����׻����˲����������ο���Դ�ɿ�APM****/
#define TIME_CONTANST_ZER    2.0f
#define K_ACC_ZER 	        (1.0f / (TIME_CONTANST_ZER * TIME_CONTANST_ZER * TIME_CONTANST_ZER))//1
#define K_VEL_ZER	          (3.0f / (TIME_CONTANST_ZER * TIME_CONTANST_ZER))//3
#define K_POS_ZER           (3.0f / TIME_CONTANST_ZER)//3
void Strapdown_INS_High()
{
	static uint16 Speed_Sync_Cnt=0,Pos_Sync_Cnt=0;
	uint16 Cnt=0;
	float Delta_Time,Altitude_Dealt=0;
	Testime SINS_High_Delta;
  Test_Period(&SINS_High_Delta);
  Delta_Time=SINS_High_Delta.Time_Delta/1000.0f;
  if(Delta_Time>2*WP_Duty_Dt||Delta_Time<WP_Duty_Dt||isnan(Delta_Time)!=0)   Delta_Time=WP_Duty_Dt;   
	//�ɹ۲�������ѹ�ƣ��õ�״̬���
	Altitude_Dealt=constrain_float(Observation_Altitude-NamelessQuad.Pos_History[_YAW][High_Delay_Cnt],-Observation_Err_Max,Observation_Err_Max);//��ѹ��(������)��SINS�������Ĳ��λcm
  //��·���ַ����������ߵ�
  acc_correction[_YAW] +=Altitude_Dealt* K_ACC_ZER*Delta_Time ;//���ٶȽ�����
  vel_correction[_YAW] +=Altitude_Dealt* K_VEL_ZER*Delta_Time ;//�ٶȽ�����
  pos_correction[_YAW] +=Altitude_Dealt* K_POS_ZER*Delta_Time ;//λ�ý�����
  //���ٶȼƽ��������
  NamelessQuad.Last_Acceleration[_YAW]=NamelessQuad.Acceleration[_YAW];//��һ�μ��ٶ���
  NamelessQuad.Acceleration[_YAW]=Origion_NamelessQuad.Acceleration[_YAW]+acc_correction[_YAW];
  //�ٶ�������������£����ڸ���λ��,���ڲ���h=0.005,��Խϳ���
  //������ö����������������΢�ַ��̣��������ø��߽ף���Ϊ���ٶ��źŷ�ƽ��
  SpeedDealt[_YAW]=(NamelessQuad.Last_Acceleration[_YAW]
                    +NamelessQuad.Acceleration[_YAW])*Delta_Time/2.0f;
  //ԭʼλ�ø���
  Origion_NamelessQuad.Position[_YAW]+=(NamelessQuad.Speed[_YAW]+0.5f*SpeedDealt[_YAW])*Delta_Time;
  //λ�ý��������
  NamelessQuad.Position[_YAW]=Origion_NamelessQuad.Position[_YAW]+pos_correction[_YAW];
  //ԭʼ�ٶȸ���
  Origion_NamelessQuad.Speed[_YAW]+=SpeedDealt[_YAW];
  //�ٶȽ��������
  NamelessQuad.Speed[_YAW]=Origion_NamelessQuad.Speed[_YAW]+vel_correction[_YAW]; 
	
	Pos_Sync_Cnt++;
	if(Pos_Sync_Cnt>=2)//10ms����һ��
	{
		for(Cnt=Num-1;Cnt>0;Cnt--)
		{
			NamelessQuad.Pos_History[_YAW][Cnt]=NamelessQuad.Pos_History[_YAW][Cnt-1];
		}
		Pos_Sync_Cnt=0;
	}
	NamelessQuad.Pos_History[_YAW][0]=NamelessQuad.Position[_YAW];
	
	
	Speed_Sync_Cnt++;
	if(Speed_Sync_Cnt>=2)//10ms����һ��
	{
		for(Cnt=Num-1;Cnt>0;Cnt--)
		{
			NamelessQuad.Vel_History[_YAW][Cnt]=NamelessQuad.Vel_History[_YAW][Cnt-1];
		}
		Speed_Sync_Cnt=0;
	}
	NamelessQuad.Vel_History[_YAW][0]=NamelessQuad.Speed[_YAW];
}



#define Ra  1.0f//1.0
#define KALMAN_DT (Baro_Update_Dt*0.001f)
float Q[2]={0.5f*Ra*KALMAN_DT*KALMAN_DT,Ra*KALMAN_DT};
float R_Baro=35;//75  150  100
float R_Ground=5;
float R_VL53L1X=0.05;
float R_TOFSENSOR=5;
float R=5;
float Acce_Bias_Gain_Kp={
  0.0f,//0.3   0.1~0.75
};
float Acce_Bias_Gain_Ki={
  0.005,//0.005
};
float Pre_conv[4]=
{
  1.10,0.83,//4.95 2.83								//0.18,0.1,
  0.83,1.33	//2.83 3.49								//0.1,0.18
};//��һ��Э����
float kalman_k[2]={0};//�������
/***********************************************************
@��������KalmanFilter
@��ڲ�����float Observation,//λ�ù۲���
					 uint16 Pos_Delay_Cnt,//�۲⴫������ʱ��
					 SINS *Ins_Kf,//�ߵ��ṹ��
					 float System_drive,//ϵͳԭʼ���������ߵ����ٶ�
					 float *Q,
					 float R,
					 float dt,
					 uint16 N,
					 uint8_t update_flag
@���ڲ�������
�����������߶ȷ���ߵ��������˲�
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
float observation_div=0;
float last_observation=0;
float observation_acc;
uint8_t observation_reset_flag=0;
float observation_div_err[10]={0};
float observation_div_rmse[10]={0};

float observation_err[10]={0};
float observation_rmse[10]={0};

float observation_acc_err[10]={0};
float observation_acc_rmse[10]={0};
void  KalmanFilter(float Observation,//λ�ù۲���
                   uint16 Pos_Delay_Cnt,//�۲⴫������ʱ��
                   SINS *Ins_Kf,//�ߵ��ṹ��
                   float System_drive,//ϵͳԭʼ���������ߵ����ٶ�
                   float *Q,
                   float R,
                   float dt,
                   uint16 N,
                   uint8_t *update_flag)
{
  uint16 Cnt=0;
  static uint16 Speed_Sync_Cnt=0,Pos_Sync_Cnt=0;
	static int16_t Unusual_Protect_Flag=0;
	static int16_t Unusual_Protect_Cnt=0;
	static uint8_t update_bias=0;
	float R_Temp=0;
  float Temp_conv[4]={0};//����Э����
  float Conv_Z=0,Z_Cor=0;
  float Ctemp=0;
  float rmse_temp1=0,rmse_temp2,rmse_temp3;
	//if(Unusual_Protect_Flag>0)  Unusual_Protect_Flag--;
	
	R_Temp=constrain_float(R,0,10000);
  //����״̬
  Ins_Kf->Acceleration[N]=System_drive;
  Ins_Kf->Acceleration[N]=Ins_Kf->Acce_Bias_All[N]+Ins_Kf->Acceleration[N];
  Ins_Kf->Position[N] +=Ins_Kf->Speed[N]*dt+(Ins_Kf->Acceleration[N]*dt*dt)/2.0f;
  Ins_Kf->Speed[N]+=Ins_Kf->Acceleration[N]*dt;
  if(*update_flag==1)
  {
		for(uint16_t i=9;i>0;i--)//�����׼��
		{
		  observation_div_err[i]=observation_div_err[i-1];
			observation_div_rmse[i]=observation_div_rmse[i-1];
		  observation_err[i]=observation_err[i-1];
			observation_rmse[i]=observation_rmse[i-1];
			observation_acc_err[i]=observation_acc_err[i-1];
			observation_acc_rmse[i]=observation_acc_rmse[i-1];
		}
		observation_div_err[0]=Butterworth_Buffer_Baro.Output_Butter[2]-Ins_Kf->Vel_History[N][8*Pos_Delay_Cnt];
	  observation_err[0]=Observation-Ins_Kf->Pos_History[N][2*Pos_Delay_Cnt];
		observation_acc_err[0]=Butterworth_Buffer_Baro_Acc.Output_Butter[2]-Ins_Kf->Acce_History[N][8*Pos_Delay_Cnt];
	
		for(int16_t i=9;i>=0;i--)//������������
		{
		  rmse_temp1+=observation_div_err[i]*observation_div_err[i];
			rmse_temp2+=observation_err[i]*observation_err[i];
			rmse_temp3+=observation_acc_err[i]*observation_acc_err[i];
		}
		observation_div_rmse[0]=safe_sqrt(rmse_temp1/10.0f);
		observation_rmse[0]=safe_sqrt(rmse_temp2/10.0f);
		observation_acc_rmse[0]=safe_sqrt(rmse_temp3/10.0f);
		
		if(   observation_acc>20000	 //40g��1g=1000cm/s^2 50000cm/s^2Լ����30g���ٶȣ���������װ�ﲻ��
				||observation_acc<-15000//-30gʧ���������1g��������
				//||(ABS(observation_div)>20*ABS(Ins_Kf->Vel_History[N][2*Pos_Delay_Cnt])	
		  )
		{
			Observation=Ins_Kf->Pos_History[N][Pos_Delay_Cnt];
			update_bias=0;
			Unusual_Protect_Flag=1;//N ms�۲��쳣�������ڣ�������bias
			Unusual_Protect_Cnt=0;
		}
		else  
		{
			last_observation=Observation;
			update_bias=1;
		}
		
		//last_observation=Observation;
		//update_bias=1;
		
    //����Э����
    Ctemp=Pre_conv[1]+Pre_conv[3]*KALMAN_DT;
    Temp_conv[0]=Pre_conv[0]+Pre_conv[2]*KALMAN_DT+Ctemp*KALMAN_DT+Q[0];
    Temp_conv[1]=Ctemp;
    Temp_conv[2]=Pre_conv[2]+Pre_conv[3]*KALMAN_DT;;
    Temp_conv[3]=Pre_conv[3]+Q[1];
    //���㿨��������
    Conv_Z=Temp_conv[0]+R_Temp;
    kalman_k[0]=Temp_conv[0]/Conv_Z;
    kalman_k[1]=Temp_conv[2]/Conv_Z;
    //�ں��������
		Z_Cor=constrain_float(Observation-Ins_Kf->Pos_History[N][Pos_Delay_Cnt],-Observation_Err_Max,Observation_Err_Max);	
    /*
		if(Observation_Update_Type==1
			&&(observation_rmse[0]>=50
			||observation_div_rmse[0]>100
		  ||observation_acc_rmse[0]>2000)) 
		Z_Cor/=5; 
		*/
    Ins_Kf->Position[N] +=kalman_k[0]*Z_Cor;
    Ins_Kf->Speed[N] +=kalman_k[1]*Z_Cor;
		
		if(update_bias==1||Unusual_Protect_Flag==0)
		{
			Ins_Kf->Acce_Bias[N]+=Acce_Bias_Gain_Ki*Z_Cor;
		  Ins_Kf->Acce_Bias[N]=constrain_float(Ins_Kf->Acce_Bias[N],-200,200);
		  Ins_Kf->Acce_Bias_All[N]=Acce_Bias_Gain_Kp*Z_Cor+Ins_Kf->Acce_Bias[N];			
		}

    //����״̬Э�������
    Pre_conv[0]=(1-kalman_k[0])*Temp_conv[0];
    Pre_conv[1]=(1-kalman_k[0])*Temp_conv[1];
    Pre_conv[2]=Temp_conv[2]-kalman_k[1]*Temp_conv[0];
    Pre_conv[3]=Temp_conv[3]-kalman_k[1]*Temp_conv[1]; 
		*update_flag=0;
				
		//if(ABS(Z_Cor)<=50&&Unusual_Protect_Flag==1) Unusual_Protect_Cnt++;
		if(Unusual_Protect_Flag==1) Unusual_Protect_Cnt++;
	  if(Unusual_Protect_Cnt>=2&&Unusual_Protect_Flag==1)//100ms
		{
			Unusual_Protect_Flag=0;
		  Unusual_Protect_Cnt=0;
		}
	}	
	
	
	Pos_Sync_Cnt++;
	if(Pos_Sync_Cnt>=2)//10ms����һ��
	{
		for(Cnt=Num-1;Cnt>0;Cnt--)
		{
			Ins_Kf->Pos_History[N][Cnt]=Ins_Kf->Pos_History[N][Cnt-1];
		}
		Pos_Sync_Cnt=0;
  }
	Ins_Kf->Pos_History[N][0]=Ins_Kf->Position[N];
	
	
  Speed_Sync_Cnt++;
  if(Speed_Sync_Cnt>=2)//10ms����һ��
  {
    for(Cnt=Num-1;Cnt>0;Cnt--)
    {
      Ins_Kf->Vel_History[N][Cnt]=Ins_Kf->Vel_History[N][Cnt-1];
    }
    Speed_Sync_Cnt=0;
  }
  Ins_Kf->Vel_History[N][0]=Ins_Kf->Speed[N];
}


void Alt_SINS_Init(void)
{
	uint16_t _cnt=0;
	if(Sensor_Flag.Ground_Health==1)
	{
		NamelessQuad.Position[_YAW]=GD_Distance;
		for(_cnt=Num-1;_cnt>0;_cnt--){NamelessQuad.Pos_History[_YAW][_cnt]=GD_Distance;}
		NamelessQuad.Pos_History[_YAW][0]=GD_Distance;
		Total_Controller.High_Position_Control.Expect=GD_Distance;//���ߵ��߶�����Ϊ�����߶ȣ����ҽ�����һ��
		
		Origion_NamelessQuad.Position[_YAW]=GD_Distance;
		Origion_NamelessQuad.Speed[_YAW]=0;
	}
	else
	{
		NamelessQuad.Position[_YAW]=WP_Sensor.baro_altitude;
		for(_cnt=Num-1;_cnt>0;_cnt--){NamelessQuad.Pos_History[_YAW][_cnt]=WP_Sensor.baro_altitude;}
		NamelessQuad.Pos_History[_YAW][0]=WP_Sensor.baro_altitude;
		Total_Controller.High_Position_Control.Expect=GD_Distance;//���ߵ��߶�����Ϊ�����߶ȣ����ҽ�����һ��
		Origion_NamelessQuad.Position[_YAW]=WP_Sensor.baro_altitude;
		Origion_NamelessQuad.Speed[_YAW]=0;
	}
}


#ifdef Altitute_Kalman_Filter_Enable
	uint16_t SPL06_Sync_Cnt=6;
	uint16_t HCSR04_Sync_Cnt=5;
  uint16_t VL53L1_Sync_Cnt=0;
	uint16_t TOF_Sync_Cnt=5;
#else
	uint16_t SPL06_Sync_Cnt=0;
	uint16_t HCSR04_Sync_Cnt=10;
	uint16_t VL53L1_Sync_Cnt=20;
	uint16_t TOF_Sync_Cnt=10;
#endif


uint16 High_Delay_Cnt=0;
uint8_t Observation_Update_Flag=0;
float Observation_Altitude=0;
uint8_t altitude_updtate_flag=0;
/***********************************************************
@��������Observation_Tradeoff
@��ڲ�����uint8_t HC_SR04_Enable
@���ڲ�������
�����������߶ȷ���۲⴫���������л�
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void Observation_Tradeoff(uint8_t ground_enable)
{
  static uint8_t observation_flag=2,last_observation_flag=2;
  uint16 Cnt=0;
  last_observation_flag=observation_flag;
  if(ground_enable==0)//�޳�����/�Եش���������
  {
    Observation_Altitude=WP_Sensor.baro_altitude;//�߶ȹ۲���
    High_Delay_Cnt=SPL06_Sync_Cnt;
		observation_div=WP_Sensor.baro_altitude_div;
		observation_acc=WP_Sensor.baro_altitude_acc;
		if(WP_Sensor.baro_updtate_flag==1)
		{
			altitude_updtate_flag=WP_Sensor.baro_updtate_flag;
			WP_Sensor.baro_updtate_flag=0;
		}
     R=R_Baro;
  }
  else//�г�����/�Եش���������
  {
		if(Ground_Sensor_Now_Mode==US100)
		{	
				if(Sensor_Flag.Ground_Health==1)
				{
					Observation_Altitude=GD_Distance;
					High_Delay_Cnt=HCSR04_Sync_Cnt;
					observation_flag=2;
					observation_div=GD_Distance_Div;
					observation_acc=GD_Distance_Acc;
					if(WP_Sensor.us100_updtate_flag==1)
					{
						altitude_updtate_flag=WP_Sensor.us100_updtate_flag;
						WP_Sensor.us100_updtate_flag=0;
					}
					R=R_Ground;
				}
				else
				{
					Observation_Altitude=WP_Sensor.baro_altitude;//�߶ȹ۲���
					High_Delay_Cnt=SPL06_Sync_Cnt;
					observation_div=WP_Sensor.baro_altitude_div;
					observation_acc=WP_Sensor.baro_altitude_acc;
					if(WP_Sensor.baro_updtate_flag==1)
					{
						altitude_updtate_flag=WP_Sensor.baro_updtate_flag;
						WP_Sensor.baro_updtate_flag=0;
					}
					R=R_Baro;
				} 
		}
		else if(Ground_Sensor_Now_Mode==TFMINI)
		{	
				if(Sensor_Flag.Ground_Health==1)
				{
					Observation_Altitude=GD_Distance;
					High_Delay_Cnt=5;
					observation_flag=2;
					observation_div=GD_Distance_Div;
					observation_acc=GD_Distance_Acc;
					if(WP_Sensor.tfmini_updtate_flag==1)
					{
						altitude_updtate_flag=WP_Sensor.tfmini_updtate_flag;
						WP_Sensor.tfmini_updtate_flag=0;
					}
					R=R_Ground;
				}
				else
				{
					Observation_Altitude=WP_Sensor.baro_altitude;//�߶ȹ۲���
					High_Delay_Cnt=SPL06_Sync_Cnt;
					observation_div=WP_Sensor.baro_altitude_div;
					observation_acc=WP_Sensor.baro_altitude_acc;
					if(WP_Sensor.baro_updtate_flag==1)
					{
						altitude_updtate_flag=WP_Sensor.baro_updtate_flag;
						WP_Sensor.baro_updtate_flag=0;
					}
					R=R_Baro;
				} 
		}
		else if(Ground_Sensor_Now_Mode==TOFSENSOR)
		{	
				if(Sensor_Flag.Ground_Health==1)
				{
					Observation_Altitude=GD_Distance;
					High_Delay_Cnt=TOF_Sync_Cnt;
					observation_flag=2;
					observation_div=GD_Distance_Div;
					observation_acc=GD_Distance_Acc;
					if(WP_Sensor.tofsensor_updtate_flag==1)
					{
						altitude_updtate_flag=WP_Sensor.tofsensor_updtate_flag;
						WP_Sensor.tofsensor_updtate_flag=0;
					}
					R=R_TOFSENSOR;
				}
				else
				{
					Observation_Altitude=WP_Sensor.baro_altitude;//�߶ȹ۲���
					High_Delay_Cnt=SPL06_Sync_Cnt;
					observation_div=WP_Sensor.baro_altitude_div;
					observation_acc=WP_Sensor.baro_altitude_acc;
					if(WP_Sensor.baro_updtate_flag==1)
					{
						altitude_updtate_flag=WP_Sensor.baro_updtate_flag;
						WP_Sensor.baro_updtate_flag=0;
					}
					R=R_Baro;
				} 
		} 		
		else if(Ground_Sensor_Now_Mode==VL53L1X)
		{	
				if(Sensor_Flag.Ground_Health==1)
				{
					Observation_Altitude=GD_Distance;
					High_Delay_Cnt=VL53L1_Sync_Cnt;
					observation_flag=2;
					observation_div=GD_Distance_Div;
					observation_acc=GD_Distance_Acc;
					if(WP_Sensor.vl53l1x_updtate_flag==1)
					{
						altitude_updtate_flag=WP_Sensor.vl53l1x_updtate_flag;
						WP_Sensor.vl53l1x_updtate_flag=0;
					}
					R=R_VL53L1X;
				}
				else
				{
					Observation_Altitude=WP_Sensor.baro_altitude;//�߶ȹ۲���
					High_Delay_Cnt=SPL06_Sync_Cnt;
					observation_div=WP_Sensor.baro_altitude_div;
					observation_acc=WP_Sensor.baro_altitude_acc;
					if(WP_Sensor.baro_updtate_flag==1)
					{
						altitude_updtate_flag=WP_Sensor.baro_updtate_flag;
						WP_Sensor.baro_updtate_flag=0;
					}
					R=R_Baro;
				} 
		}  		
		
		
    if(observation_flag==2&&last_observation_flag==1)//��ѹ���г�����
    {
			if(Ground_Sensor_Now_Mode==US100)
			{
				NamelessQuad.Position[_YAW]=GD_Distance;
				for(Cnt=Num-1;Cnt>0;Cnt--){NamelessQuad.Pos_History[_YAW][Cnt]=GD_Distance;}
				NamelessQuad.Pos_History[_YAW][0]=GD_Distance;
				Total_Controller.High_Position_Control.Expect=GD_Distance;//���ߵ��߶�����Ϊ�����߶ȣ����ҽ�����һ��
				
				Origion_NamelessQuad.Position[_YAW]=GD_Distance;
				Origion_NamelessQuad.Speed[_YAW]=0;
				R=R_Ground;
			}
			else
			{	
				NamelessQuad.Position[_YAW]=GD_Distance;
				for(Cnt=Num-1;Cnt>0;Cnt--){NamelessQuad.Pos_History[_YAW][Cnt]=GD_Distance;}
				NamelessQuad.Pos_History[_YAW][0]=GD_Distance;
				Total_Controller.High_Position_Control.Expect=GD_Distance;//���ߵ��߶�����Ϊ�����߶ȣ����ҽ�����һ��
				
				Origion_NamelessQuad.Position[_YAW]=GD_Distance;
				Origion_NamelessQuad.Speed[_YAW]=0;
				R=R_Ground;
		  }
			
			//��λ���׻����м�״̬
			Origion_NamelessQuad.Position[_YAW]=NamelessQuad.Position[_YAW];
			Origion_NamelessQuad.Speed[_YAW]=NamelessQuad.Speed[_YAW];
			acc_correction[_YAW]=0 ;//���ٶȽ�����
			vel_correction[_YAW]=0; //�ٶȽ�����
			pos_correction[_YAW]=0; //λ�ý�����
			for(uint16_t i=0;i<Num;i++)
			{
				NamelessQuad.Pos_History[_YAW][i]=NamelessQuad.Position[_YAW];
				NamelessQuad.Vel_History[_YAW][i]=NamelessQuad.Speed[_YAW];
			}		
    }
    else if(observation_flag==1&&last_observation_flag==2)//����������ѹ��
    {
      NamelessQuad.Position[_YAW]=Observation_Altitude;
      for(Cnt=Num-1;Cnt>0;Cnt--){NamelessQuad.Pos_History[_YAW][Cnt]=Observation_Altitude;}
      NamelessQuad.Pos_History[_YAW][0]=Observation_Altitude;
      Total_Controller.High_Position_Control.Expect=Observation_Altitude;//���ߵ��߶�����Ϊ�����߶ȣ����ҽ�����һ��
      Origion_NamelessQuad.Position[_YAW]=Observation_Altitude;
      Origion_NamelessQuad.Speed[_YAW]=0;
			
		  //��λ���׻����м�״̬
			Origion_NamelessQuad.Position[_YAW]=NamelessQuad.Position[_YAW];
			Origion_NamelessQuad.Speed[_YAW]=NamelessQuad.Speed[_YAW];
			acc_correction[_YAW]=0 ;//���ٶȽ�����
			vel_correction[_YAW]=0; //�ٶȽ�����
			pos_correction[_YAW]=0; //λ�ý�����
			for(uint16_t i=0;i<Num;i++)
			{
				NamelessQuad.Pos_History[_YAW][i]=NamelessQuad.Position[_YAW];
				NamelessQuad.Vel_History[_YAW][i]=NamelessQuad.Speed[_YAW];
			}
			R=R_Baro;
		}
  }	
}

Testime SINS_High_Delta;
float Delta_T;
/***********************************************************
@��������Strapdown_INS_High_Kalman
@��ڲ�������
@���ڲ�������
�����������߶ȷ��򿨶����˲�
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void Strapdown_INS_High_Kalman(void)
{
  Test_Period(&SINS_High_Delta);
  Delta_T=SINS_High_Delta.Time_Delta/1000.0f;
  if(Delta_T>2*WP_Duty_Dt||Delta_T<WP_Duty_Dt||isnan(Delta_T)!=0)   Delta_T=WP_Duty_Dt;  
	if(Gyro_Safety_Calibration_Flag==1)
	{
		Observation_Tradeoff(1);
#ifdef Altitute_Kalman_Filter_Enable
		KalmanFilter(Observation_Altitude,//λ�ù۲���
								 High_Delay_Cnt,//�۲⴫������ʱ��
								 &NamelessQuad,//�ߵ��ṹ��
								 Origion_NamelessQuad.Acceleration[_YAW],//ϵͳԭʼ���������ߵ����ٶ�
								 Q,
								 R,
								 Delta_T,
								 _YAW,
								 &altitude_updtate_flag);
#else		
		Strapdown_INS_High();
#endif
	}
	else
  {
		Alt_SINS_Init();
    acc_correction[_YAW]=-Origion_NamelessQuad.Acceleration[_YAW];
		//NamelessQuad.Acce_Bias[_YAW]=-Origion_NamelessQuad.Acceleration[_YAW];
  }
}

/*************************���¼�������ͶӰ��������Դ��APM3.2 AP.Math.c�ļ�******************************/
/***********************************************************
@��������longitude_scale
@��ڲ�����Location loc
@���ڲ�������
��������������ͶӰ
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
float longitude_scale(Location loc)
{
  static int32_t last_lat;
  static float scale = 1.0;
  //�Ƚ�����γ�����ֵ�������ظ��������Һ���
  if (ABS(last_lat - loc.lat) < 100000) {
    // we are within 0.01 degrees (about 1km) of the
    // same latitude. We can avoid the cos() and return
    // the same scale factor.
    return scale;
  }
  scale = cosf(loc.lat * 1.0e-7f * DEG_TO_RAD);
  scale = constrain_float(scale, 0.01f, 1.0f);
  last_lat = loc.lat;
  return scale;
}
/*
return the distance in meters in North/East plane as a N/E vector
from loc1 to loc2
*/
Vector2f location_diff(Location loc1,Location loc2)
{
  Vector2f Location_Delta;
  Location_Delta.x=(loc2.lat - loc1.lat) * LOCATION_SCALING_FACTOR;//���뵥λΪm
  Location_Delta.y=(loc2.lng - loc1.lng) * LOCATION_SCALING_FACTOR * longitude_scale(loc2);//���뵥λΪm
  return Location_Delta;
}

// return distance in meters between two locations
float get_distance(Location loc1,Location loc2){
  float dlat              = (float)(loc2.lat - loc1.lat);
  float dlong             = ((float)(loc2.lng - loc1.lng)) * longitude_scale(loc2);
  return pythagorous2(dlat, dlong) * LOCATION_SCALING_FACTOR;
}
/*************************���ϼ�������ͶӰ��������Դ��APM3.2 AP.Math.c�ļ�******************************/
float Body_Frame_To_XYZ[3]={0,0,0};//��������������ϵ��������(Y��)������(X��)����λ��ƫ��
Vector3_Nav Earth_Frame_To_XYZ={0,0,0};//��������������ϵ���� ������������������λ��ƫ��
Vector2i GPSData_To_XY_Home={1143637460,306276000};//����γ��
Location GPS_Home;//��ʼ��λ�ɹ�����Ϣ
Location GPS_Present;//��ǰλ�õ���Ϣ
uint8_t GPS_Home_Set=0;
float Declination=0;//�����ƫ��
/***********************************************************
@��������Set_GPS_Home
@��ڲ�������
@���ڲ�������
��������������GPSԭ��
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void Set_GPS_Home(void)//����Home��
{
	static uint16_t gps_home_cnt=0;
  if(GPS_Home_Set==0
	 &&GPS_Sate_Num>=9//�������ڵ���9
	 &&Horizontal_Acc_Est<=1.5f)//ˮƽλ�ù��ƾ���С��1.5m
	 {
		 if(gps_home_cnt<=50) gps_home_cnt++;//ˢ��10hz������5S����
	 }

   if(GPS_Home_Set==0&&gps_home_cnt==50)//ȫ��ֻ����һ��
  {
    GPSData_To_XY_Home.x=Longitude_Origion;//Longitude;
    GPSData_To_XY_Home.y=Latitude_Origion;//Latitude;
    GPS_Home_Set=1;//�趨������
    GPS_Home.lng=GPSData_To_XY_Home.x;
    GPS_Home.lat=GPSData_To_XY_Home.y; 
    Strapdown_INS_Reset(&NamelessQuad,_PITCH,Earth_Frame_To_XYZ.E,0);//��λ�ߵ��ں�
    Strapdown_INS_Reset(&NamelessQuad,_ROLL,Earth_Frame_To_XYZ.N,0);//��λ�ߵ��ں�
    Declination=get_declination(0.0000001f*GPS_Home.lat,0.0000001f*GPS_Home.lng);//��ȡ���ش�ƫ��
  }
}

/***********************************************************
@��������GPSData_Sort
@��ڲ�������
@���ڲ�������
��������������GPSԭ�㣬�õ���γ�ȷ����λ��ƫ��
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void GPSData_Sort()
{
  Vector2f location_delta={0,0};
  GPS_Present.lng=Longitude_Origion;//���µ�ǰ��γ��
  GPS_Present.lat=Latitude_Origion;
  location_delta=location_diff(GPS_Home,GPS_Present);//���ݵ�ǰGPS��λ��Ϣ��Home��λ����Ϣ������������������λ��ƫ��
  /***********************************************************************************
  ��ȷ�µ���ϵ������������������Ϊ������:
  ������������������,�����˻����home�㣬���������ƶ�ʱ����ʱGPS_Present.lng>GPS_Home.lng���õ���location_delta.x����0;
  ����������γ������,�����˻����home�㣬���������ƶ�ʱ����ʱGPS_Present.lat>GPS_Home.lat���õ���location_delta.y����0;
  ******************************************************************************/
  location_delta.x*=100.0f;//�ص�������ϵ����������λ��ƫ��,��λΪCM
  location_delta.y*=100.0f;//�ص�������ϵ����������λ��ƫ��,��λΪCM
  Earth_Frame_To_XYZ.E=location_delta.y;//����ϵ�����Home������λ��ƫ�ƣ���λΪCM
  Earth_Frame_To_XYZ.N=location_delta.x;//����ϵ�����Home������λ��ƫ�ƣ���λΪCM
  //�����˻��ڵ�������ϵ�µ��������������������λ��ƫ����ת����ǰ�����λ��ƫ��:��ͷ(����)+���
  Body_Frame_To_XYZ[_PITCH]=location_delta.x*Cos_Yaw+location_delta.y*Sin_Yaw;//��ͷ����λ��ƫ��  Y������
  Body_Frame_To_XYZ[_ROLL]=-location_delta.x*Sin_Yaw+location_delta.y*Cos_Yaw;  //�������λ��ƫ��  X������
}



#define Dealt_Update 0.1 //100ms����һ��
#define Process_Noise_Constant 1.0//1.0
#define Pos_Process_Noise  (0.5*Process_Noise_Constant*Dealt_Update*Dealt_Update)//0.005
#define Vel_Process_Noise  (Process_Noise_Constant*Dealt_Update)  //0.1
float   R_GPS[2]={Pos_Process_Noise,Vel_Process_Noise};
float   Q_GPS[2]={0.02,0.45};//{0.015,3.0}{0.075,3.0};
float   R_Acce_bias[2]={0.00025,0};//0.0001  0.001��ʼ�׷�ɢ
double  Pre_conv_GPS[2][4]=
{
  0.018 ,    0.005,  0.005    , 0.5,//0.0001 ,    0.00001,  0.00001    , 0.003,
  0.018 ,    0.005,  0.005    , 0.5,
};//��һ��Э����
double  K_GPS[2][2]={0};//�������
float   Acce_Bias[2]={0,0};//0  0.001
/***********************************************************
@��������KalmanFilter_Horizontal_GPS
@��ڲ�����float Position_GPS,float Vel_GPS,float Position_Last,
					 float Vel_Last,
					 float *Position,float *Vel,
					 float *Acce,float *R,
					 float *Q,float dt,uint8_t Axis
@���ڲ�������
����������GPSˮƽ���򿨶����˲��ں�
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void   KalmanFilter_Horizontal_GPS(float Position_GPS,float Vel_GPS,float Position_Last,float Vel_Last,float *Position,float *Vel,float *Acce,float *R,float *Q,float dt,uint8_t Axis)
{
  float Conv_Z=0;
  float Z_Delta[2]={0};
  float Conv_Temp=0;
  double Temp_conv[4]={0};//����Э����
  uint8 Label=0;
  if(Axis=='X') Label=0;
  else Label=1;
  //����״̬
  *Position +=*Vel*dt+((*Acce+Acce_Bias[Label])*dt*dt)/2.0f;
  *Vel+=(*Acce+Acce_Bias[Label])*dt;
  //����Э����
  Conv_Temp=Pre_conv_GPS[Label][1]+Pre_conv_GPS[Label][3]*dt;
  Temp_conv[0]=Pre_conv_GPS[Label][0]+Pre_conv_GPS[Label][2]*dt+Conv_Temp*dt+R_GPS[0];
  Temp_conv[1]=Conv_Temp;
  Temp_conv[2]=Pre_conv_GPS[Label][2]+Pre_conv_GPS[Label][3]*dt;
  Temp_conv[3]=Pre_conv_GPS[Label][3]+R_GPS[1];
  //���㿨��������
  Conv_Z=1.0/((Temp_conv[0]+Q_GPS[0]*GPS_Quality)*(Temp_conv[3]+Q_GPS[1]*GPS_Quality)-Temp_conv[1]*Temp_conv[2]);
  //��������
  K_GPS[0][0]=( Temp_conv[0]*(Temp_conv[3]+Q_GPS[1]*GPS_Quality)-Temp_conv[1]*Temp_conv[2])*Conv_Z;
  K_GPS[0][1]=(Temp_conv[1]*Q_GPS[0]*GPS_Quality)*Conv_Z;
  K_GPS[1][0]=(Temp_conv[2]*Q_GPS[1]*GPS_Quality)*Conv_Z;
  K_GPS[1][1]=(-Temp_conv[1]*Temp_conv[2]+Temp_conv[3]*(Temp_conv[0]+Q_GPS[0]*GPS_Quality))*Conv_Z;
  //�ں��������
  Z_Delta[0]=Position_GPS-Position_Last;
  Z_Delta[1]=Vel_GPS-Vel_Last;
	
	Z_Delta[0]=constrain_float(Z_Delta[0],-10000,10000);//100m
	Z_Delta[1]=constrain_float(Z_Delta[1],-2000,2000);//20m/s
	
  *Position +=K_GPS[0][0]*Z_Delta[0]+K_GPS[0][1]*Z_Delta[1];
  *Vel      +=K_GPS[1][0]*Z_Delta[0]+K_GPS[1][1]*Z_Delta[1];
	
  Acce_Bias[Label]+=R_Acce_bias[0]*Z_Delta[0]+R_Acce_bias[1]*Z_Delta[1];
	
	Acce_Bias[Label]=constrain_float(Acce_Bias[Label],-100,100);//100
	
  //����״̬Э�������
  Pre_conv_GPS[Label][0]=(1-K_GPS[0][0])*Temp_conv[0]-K_GPS[0][1]*Temp_conv[2];
  Pre_conv_GPS[Label][1]=(1-K_GPS[0][0])*Temp_conv[1]-K_GPS[0][1]*Temp_conv[3];
  Pre_conv_GPS[Label][2]=(1-K_GPS[1][1])*Temp_conv[2]-K_GPS[1][0]*Temp_conv[0];
  Pre_conv_GPS[Label][3]=(1-K_GPS[1][1])*Temp_conv[3]-K_GPS[1][0]*Temp_conv[1];
}

void Strapdown_INS_Reset(SINS *Ins,uint8_t Axis,float Pos_Target,float Vel_Target)
{
  uint16_t Cnt=0;
  Ins->Position[Axis]=Pos_Target;//λ������
  Ins->Speed[Axis]=Vel_Target;	 //�ٶ�����
  Ins->Acceleration[Axis]=0.0f;  //���ٶ�����
  Ins->Acce_Bias[Axis]=0.0f;
  for(Cnt=Num-1;Cnt>0;Cnt--)//��ʷλ��ֵ��ȫ��װ��Ϊ��ǰ�۲�ֵ
  {
    Ins->Pos_History[Axis][Cnt]=Pos_Target;
  }
  Ins->Pos_History[Axis][0]=Pos_Target;
  for(Cnt=Num-1;Cnt>0;Cnt--)//��ʷ�ٶ�ֵ��ȫ��װ��Ϊ��ǰ�۲�ֵ
  {
    Ins->Vel_History[Axis][Cnt]=Vel_Target;
  }
  Ins->Vel_History[Axis][0]=Vel_Target;
}


#define X_Axis  0
#define Y_Axis  1
uint16 GPS_Vel_Delay_Cnt=10;//5:50ms
uint16 GPS_Pos_Delay_Cnt=10;//10:100ms
Testime SINS_Horizontal_Delta;
float Horizontal_Delta_T=0;
uint8_t Filter_Defeated_Flag=0;
void KalmanFilter_Horizontal(void)
{	
  int16 i=0;
	static int16 GPS_Position_Cnt=0;
  if(GPS_Home_Set==1//��ʼhome��������
		&&Sensor_Flag.Mag_Health==TRUE)//������������Ч
  {
    GPSData_Sort();
    Test_Period(&SINS_Horizontal_Delta);
    Horizontal_Delta_T=(float)(SINS_Horizontal_Delta.Time_Delta/1000.0f);
    if(Horizontal_Delta_T>2*WP_Duty_Dt||Horizontal_Delta_T<WP_Duty_Dt||isnan(Horizontal_Delta_T)!=0)   Horizontal_Delta_T=WP_Duty_Dt;
    GPS_Position_Cnt++;
    if(GPS_Position_Cnt>=2)//ÿ10ms����һ��
    {	
      for(i=Num-1;i>0;i--)
      {			
				NamelessQuad.Pos_History[_PITCH][i]=NamelessQuad.Pos_History[_PITCH][i-1];
				NamelessQuad.Pos_History[_ROLL][i] =NamelessQuad.Pos_History[_ROLL][i-1];
				NamelessQuad.Vel_History[_PITCH][i]=NamelessQuad.Vel_History[_PITCH][i-1];
				NamelessQuad.Vel_History[_ROLL][i] =NamelessQuad.Vel_History[_ROLL][i-1];	
			}
      NamelessQuad.Pos_History[_PITCH][0]=NamelessQuad.Position[_PITCH];
      NamelessQuad.Pos_History[_ROLL][0] =NamelessQuad.Position[_ROLL];
      NamelessQuad.Vel_History[_PITCH][0]=NamelessQuad.Speed[_PITCH];
      NamelessQuad.Vel_History[_ROLL][0] =NamelessQuad.Speed[_ROLL];			
      GPS_Position_Cnt=0;
    }
    NamelessQuad.Acceleration[_PITCH]=Origion_NamelessQuad.Acceleration[_PITCH];
    NamelessQuad.Acceleration[_ROLL] =Origion_NamelessQuad.Acceleration[_ROLL];
    if(GPS_Update_Flag==1)
    {
      KalmanFilter_Horizontal_GPS(Earth_Frame_To_XYZ.E,
                                  GPS_Speed_Resolve[1],
																	NamelessQuad.Pos_History[_PITCH][GPS_Pos_Delay_Cnt],
																	NamelessQuad.Vel_History[_PITCH][GPS_Vel_Delay_Cnt],
                                  &NamelessQuad.Position[_PITCH],
                                  &NamelessQuad.Speed[_PITCH],
                                  &Origion_NamelessQuad.Acceleration[_PITCH],
                                  R_GPS,Q_GPS,Horizontal_Delta_T,'X');
      KalmanFilter_Horizontal_GPS(Earth_Frame_To_XYZ.N,
                                  GPS_Speed_Resolve[0],
																	NamelessQuad.Pos_History[_ROLL][GPS_Pos_Delay_Cnt],
																	NamelessQuad.Vel_History[_ROLL][GPS_Vel_Delay_Cnt],
                                  &NamelessQuad.Position[_ROLL],
                                  &NamelessQuad.Speed[_ROLL],
                                  &Origion_NamelessQuad.Acceleration[_ROLL],
                                  R_GPS,Q_GPS,Horizontal_Delta_T,'Y');
      GPS_Update_Flag=0;
    }
    else
    {
      NamelessQuad.Position[_PITCH] +=NamelessQuad.Speed[_PITCH]*Horizontal_Delta_T
        +0.5f*((NamelessQuad.Acceleration[_PITCH]+Acce_Bias[0])*Horizontal_Delta_T*Horizontal_Delta_T);
			NamelessQuad.Speed[_PITCH]+=(NamelessQuad.Acceleration[_PITCH]+Acce_Bias[0])*Horizontal_Delta_T;
      
      NamelessQuad.Position[_ROLL] +=NamelessQuad.Speed[_ROLL]*Horizontal_Delta_T
        +0.5f*((NamelessQuad.Acceleration[_ROLL]+Acce_Bias[1])*Horizontal_Delta_T*Horizontal_Delta_T);
      NamelessQuad.Speed[_ROLL]+=(NamelessQuad.Acceleration[_ROLL]+Acce_Bias[1])*Horizontal_Delta_T;
    }
    
    if(ABS(NamelessQuad.Position[_PITCH]-Earth_Frame_To_XYZ.E)>10000
       ||ABS(NamelessQuad.Position[_ROLL]-Earth_Frame_To_XYZ.N)>10000
         ||ABS(NamelessQuad.Speed[_PITCH]-GPS_Speed_Resolve[1])>10000
           ||ABS(NamelessQuad.Speed[_ROLL]-GPS_Speed_Resolve[0])>10000
             )
    {
      Filter_Defeated_Flag=1;//��ʼʱ���ں�ʧ�ܱ�־
    }
  }
}
