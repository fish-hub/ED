/* Copyright (c)  2018-2025 Wuhan Nameless Innovation Technology Co.,Ltd. All rights reserved.*/
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
*               �޸�����:2021/04/30                    
*               �汾��������PLUS����GankerPilot_V3.0
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
#include "WP_Ctrl.h"
#include "control_config.h"
/*****************ң�����г�����**********************/
int16_t Motor_PWM_1,Motor_PWM_2,Motor_PWM_3,Motor_PWM_4;//4��������PWM
int16_t Last_Motor_PWM_1,Last_Motor_PWM_2,Last_Motor_PWM_3,Last_Motor_PWM_4;//�ϴ�4��������PWM
uint8_t Controler_High_Mode=1,Last_Controler_High_Mode=1;
uint8_t Controler_Horizontal_Mode=1,Last_Controler_Horizontal_Mode=1;
uint8_t Controler_SDK1_Mode=0,Last_Controler_SDK1_Mode=0;
uint8_t Controler_Land_Mode=1,Last_Controler_Land_Mode=1,Emergency_lock=0;
uint8_t Control_Mode_Change=0;
uint16_t High_Hold_Throttle=0;
uint16_t Throttle=0;
Controller_Output Controller;
/***************************************************
������: void Controler_Mode_Select(void)
˵��:	������ģʽѡ����
���:	��
����:	��
��ע:	�ж�������ȳ�������
****************************************************/
void Controler_Mode_Select()
{
  Last_Controler_High_Mode=Controler_High_Mode;//�ϴθ߶ȿ���ģʽ
  Last_Controler_Horizontal_Mode=Controler_Horizontal_Mode;//�ϴ�λ�ÿ���ģʽ
  Last_Controler_Land_Mode=Controler_Land_Mode;//�ϴη���ģʽ
	
  if(PPM_Databuf[4]>=(RC_Data.cal[4].max-RC_Data.cal[4].deadband))       Controler_High_Mode=2;//��ѹ�ơ����񲨶���
  else if(PPM_Databuf[4]<=(RC_Data.cal[4].min+RC_Data.cal[4].deadband))  Controler_High_Mode=1;//����̬����
  
  if(PPM_Databuf[5]>=(RC_Data.cal[5].max-RC_Data.cal[5].deadband))       
	{
		Controler_SDK1_Mode=1;//SDK1ģʽ
	}
  else
	{
		Controler_SDK1_Mode=0;//��SDK1ģʽ
		NCQ_SDK_Reset();
	}

	
  if(PPM_Databuf[6]>=(RC_Data.cal[6].max-RC_Data.cal[6].deadband))            {Controler_Land_Mode=2;}//����ģʽ}
  else if(PPM_Databuf[6]<=(RC_Data.cal[6].middle+RC_Data.cal[6].deadband))    {Controler_Land_Mode=1;}//�Ƿ���ģʽ

  if(PPM_Databuf[6]>=(RC_Data.cal[6].middle-RC_Data.cal[6].deadband)
   &&PPM_Databuf[6]<=(RC_Data.cal[6].middle+RC_Data.cal[6].deadband))//ң�������ο��ش�����λ     
  {
    
  }
	else
	{
	}
	/***d
  else if(PPM_Databuf[6]<=(RC_Data.cal[6].middle-RC_Data.cal[6].deadband))
  {
			Emergency_lock=1;
  }  
	***/
  if(PPM_Databuf[7]>=(RC_Data.cal[7].max-RC_Data.cal[7].deadband))         Controler_Horizontal_Mode=2;//ˮƽλ�ÿ���
  else if(PPM_Databuf[7]<=(RC_Data.cal[7].min+RC_Data.cal[7].deadband))   
	{
		Controler_Horizontal_Mode=1;//��̬���ȿ���
    OpticalFlow_SINS_Reset();
    OpticalFlow_Ctrl_Reset();		
	}
	 
  if(Unwanted_Lock_Flag==1)//����ģʽ���������κβ���
  {
    Thr_Push_Over_State=Thr_Push_Over_Deadband();
    if(Thr_Push_Over_State==2)//ֻҪ�����ƹ�����λ���������������Զ���������
    {
      Unwanted_Lock_Flag=0;
    }
    else
    {
      Take_Off_Reset();//�����
      //Throttle_Control_Reset();//�����
    }
  }
  
  if(Controler_Land_Mode!=Last_Controler_Land_Mode)
  {
		Total_Controller.High_Position_Control.Expect=NamelessQuad.Position[_YAW];//�����ز���˲��Ĺߵ��߶�����Ϊ�����߶�
    if(Controler_Land_Mode==1)   land_reset();//����ģʽ�л�����ģʽ 
  }
  
  if(Controler_High_Mode!=Last_Controler_High_Mode)
  {
    if(Controler_High_Mode==2)  {Control_Mode_Change=1;}//�����ж��ߣ����û�׼����ֵ����ͣ�߶�
    if(Controler_High_Mode==1)  {Control_Mode_Change=1;}//����������
  }
  
  if(Controler_Horizontal_Mode!=Last_Controler_Horizontal_Mode)//λ��ͨ�����л�
  {
    if(Controler_Horizontal_Mode==2)  Control_Mode_Change=2;
    if(Controler_Horizontal_Mode==1)  Control_Mode_Change=2;
  }
  
  
  if(Control_Mode_Change==1)//���ڶ���ģʽ�л����߶�ֻ����һ��
  {
    if(Controler_High_Mode==High_Hold_Mode)//����Ϊ����ģʽ���������ж���
    {
      High_Hold_Throttle=Throttle_Control;//���浱ǰ����ֵ��ֻ��һ��
      /*******************����ǰ�ߵ���ֱλ�ù�����ΪĿ��߶�***************************/
      Total_Controller.High_Position_Control.Expect=NamelessQuad.Position[_YAW];//�����ز���˲��Ĺߵ��߶�����Ϊ�����߶�
    }
    else//����Ϊ����ģʽ��������������
    {
      //Throttle_Control_Reset();
    }
    Control_Mode_Change=0;//��ģʽ�л�λ��0,���ҽ�����һ��
  }
  else if(Control_Mode_Change==2)//���ڶ���ģʽ�л�����ͣλ��ֻ����һ��
  {
    Control_Mode_Change=0;//����Ӧ���ζ��㵵λ�л�
  }
  
}



int16_t Value_Limit(int16_t Min,int16_t Max,int16_t Data)
{
  if(Data>=Max) Data=Max;
  else if(Data<=Min) Data=Min;
  return Data;
}




void Angle_Control_Target(uint8_t mode,float roll_target,float pitch_target,float yaw_target)//�ǶȻ���
{
	//��̬�Ƕ�����
	Total_Controller.Pitch_Angle_Control.Expect=pitch_target;
	Total_Controller.Roll_Angle_Control.Expect=roll_target;
  //��̬�Ƕȷ���
  Total_Controller.Roll_Angle_Control.FeedBack =(Roll-Roll_Offset);
	Total_Controller.Pitch_Angle_Control.FeedBack=(Pitch-Pitch_Offset);
	//����PID������
  PID_Control(&Total_Controller.Roll_Angle_Control);  
	PID_Control(&Total_Controller.Pitch_Angle_Control);
	/***************�ڻ����ٶ�����****************/
	Total_Controller.Pitch_Gyro_Control.Expect=Total_Controller.Pitch_Angle_Control.Control_OutPut;
	Total_Controller.Roll_Gyro_Control.Expect=Total_Controller.Roll_Angle_Control.Control_OutPut;
  switch(mode)
	{
	  case ROTATE:
		{		
			if(yaw_target==0)//ƫ����������λ
			{
				if(Total_Controller.Yaw_Angle_Control.Expect==0)//�����л���
				{
				  Total_Controller.Yaw_Angle_Control.Expect=Yaw;
				}
				Total_Controller.Yaw_Angle_Control.FeedBack=Yaw;//ƫ���Ƿ���
				PID_Control_Yaw(&Total_Controller.Yaw_Angle_Control);//ƫ���Ƕȿ���
				Total_Controller.Yaw_Gyro_Control.Expect=Total_Controller.Yaw_Angle_Control.Control_OutPut;//ƫ�����ٶȻ���������Դ��ƫ���Ƕȿ��������
			}
			else//����ƫ������˺�ֻ�����ڻ����ٶȿ���
			{
				Total_Controller.Yaw_Angle_Control.Expect=0;//ƫ����������0,�����нǶȿ���
				Total_Controller.Yaw_Gyro_Control.Expect=yaw_target;//ƫ�����ٶȻ�������ֱ����Դ��ң���������
			}
		}
		break;
	  case AZIMUTH:
	  {
			Total_Controller.Yaw_Angle_Control.Expect=yaw_target;
			Total_Controller.Yaw_Angle_Control.FeedBack=Yaw;//ƫ���Ƿ���
			PID_Control_Yaw(&Total_Controller.Yaw_Angle_Control);//ƫ���Ƕȿ���
			Total_Controller.Yaw_Gyro_Control.Expect=Total_Controller.Yaw_Angle_Control.Control_OutPut;//ƫ�����ٶȻ���������Դ��ƫ���Ƕȿ��������
		}
		break;	
  }
}




void Yaw_Fault_Check(void)
{
	static uint16_t Yaw_Control_Fault_Cnt=0;
  /*******ƫ�������쳣����жϣ���ƫ���������ܴ�ʱ��ƫ�����ٶȺ�С�����ʱΪǿ�������š����ŵص�******************************/
  if(ABS(Total_Controller.Yaw_Gyro_Control.Control_OutPut)>Total_Controller.Yaw_Gyro_Control.Control_OutPut_Limit/2//ƫ�����������Խϴ�
     &&ABS(Yaw_Gyro)<=30.0f)//ƫ�����ٶ���Ժ�С
  {
    Yaw_Control_Fault_Cnt++;
    if(Yaw_Control_Fault_Cnt>=500) Yaw_Control_Fault_Cnt=500;
  }
  else Yaw_Control_Fault_Cnt/=2;//�����㣬����������0
  
  if(Yaw_Control_Fault_Cnt>=400)//����5ms*400=2S,���⴦��
  {
    PID_Integrate_Reset(&Total_Controller.Yaw_Gyro_Control);//���ƫ�����ٶȿ��ƵĻ���
    PID_Integrate_Reset(&Total_Controller.Yaw_Angle_Control);//���ƫ���ǿ��ƵĻ���
    Total_Controller.Yaw_Angle_Control.Expect=Yaw;//����ǰƫ���ǣ���Ϊ����ƫ����
    Yaw_Control_Fault_Cnt=0;
  }
}

void Gyro_Control(void)//���ٶȻ�
{	
	//���������������̬�ڻ����ٶȿ���������PID������
	/***************�ڻ����ٶ�����****************/
	Total_Controller.Pitch_Gyro_Control.Expect=Total_Controller.Pitch_Angle_Control.Control_OutPut;
	Total_Controller.Roll_Gyro_Control.Expect=Total_Controller.Roll_Angle_Control.Control_OutPut;
	/***************�ڻ����ٶȷ���****************/
	Total_Controller.Pitch_Gyro_Control.FeedBack=Pitch_Gyro;
	Total_Controller.Roll_Gyro_Control.FeedBack=Roll_Gyro;
	/***************�ڻ����ٶȿ��ƣ�΢�ֲ�����̬����****************/
	PID_Control_Div_LPF_For_Gyro(&Total_Controller.Pitch_Gyro_Control);
	PID_Control_Div_LPF_For_Gyro(&Total_Controller.Roll_Gyro_Control);
  //ƫ���ǿ���
  Total_Controller.Yaw_Gyro_Control.FeedBack=Yaw_Gyro_Earth_Frame;//Yaw_Gyro;
  PID_Control_Div_LPF(&Total_Controller.Yaw_Gyro_Control);
	/*******ƫ�������쳣����******************************/
  Yaw_Fault_Check();
}






void Main_Leading_Control(void)
{
	/***
	//d ����ͣ��
	if(Emergency_lock == 1)
	{
		emergency_stop()
	}
	***/
/*********************����ң�����л���λ���ɿؽ��벻ͬģʽ****************************/	
	if(Controler_Land_Mode==2)//һ������ģʽ  //swc
	{
		land_run();
		Controller.yaw_outer_control_output  =RC_Data.rc_rpyt[RC_YAW];
		return ;
	}
	
/************************����ͨ�����Ƹ߶�ģʽ************************/		
	if(Controler_High_Mode==1)//�߶ȴ��ֶ�ģʽ  //swa
	{
		Throttle=Throttle_Control;//����ֱ����Դ��ң�������Ÿ���
		Controller.roll_outer_control_output =RC_Data.rc_rpyt[RC_ROLL];
		Controller.pitch_outer_control_output=RC_Data.rc_rpyt[RC_PITCH];
		Controller.yaw_outer_control_output=RC_Data.rc_rpyt[RC_YAW];		
	}
	else
	{		
		if(Controler_SDK1_Mode==1)//�û�SDK�������Զ�����ģʽ��ˮƽ+�߶ȿ��� //swb
		{
			Auto_Flight_Ctrl(SDK1_Mode_Setup);
		}
		else//��ͨ���ߡ��������
		{
/************************�ڰ�ͨ������ˮƽλ��ģʽ************************/		
			if(Controler_Horizontal_Mode==1)//ˮƽ����
			{
				Controller.roll_outer_control_output =RC_Data.rc_rpyt[RC_ROLL];
				Controller.pitch_outer_control_output=RC_Data.rc_rpyt[RC_PITCH];
				Controller.yaw_outer_control_output  =RC_Data.rc_rpyt[RC_YAW];				
			}		
			else//ˮƽ��������ģʽ
			{
				OpticalFlow_Control_Pure(0);//��ͨ����ģʽ
				Controller.yaw_outer_control_output  =RC_Data.rc_rpyt[RC_YAW];
			}
			Flight_Alt_Hold_Control(ALTHOLD_MANUAL_CTRL,NUL,NUL);//�߶ȿ���		
		}
	}
}




/************��̬�����������Ƕ�+���ٶ�****************/
void Attitude_Control(void)
{
	Angle_Control_Target(ROTATE,Controller.roll_outer_control_output,
										          Controller.pitch_outer_control_output,
										          Controller.yaw_outer_control_output);//�Ƕȿ���	
  Gyro_Control();//���ٶȿ���
}


float Active_Para1,Active_Para2;
/***************************************************
������: void Total_Control(void)
˵��:	�ܿ��������У������������
1������ң�������롢��ǰ״̬����������ģʽ������+�����ֶ�������+���ȡ�����+���㣨���٣��ȣ�
2�������ϲ������������̬�������߶ȿ��Ƶ�
3�����ȣ���̬������
���:	��
����:	��
��ע:	�ϵ��ʼ��������һ��
****************************************************/
void Total_Control(void)
{
  /*************����������******************/
  Main_Leading_Control();		
  /*************��̬��������*****************/
  Attitude_Control();
}


void CarryPilot_Control(void)
{
  static uint8_t ctrl_cnt=0;
  ctrl_cnt++;  
  /*************������ģʽѡ��******************/
  if(ctrl_cnt>=4)//�Ĵ˼�����ֵ�����Ե�����������
  {  
    Controler_Mode_Select();
    ctrl_cnt=0;
  }
  Total_Control();//�ܿ�������ˮƽλ��+ˮƽ�ٶ�+��̬���Ƕ�+���ٶȣ����������߶�λ��+�߶��ٶ�+�߶ȼ��ٶȿ�����	
  Control_Output();//�����������
	Temperature_Ctrl();//IMU���¿���
}



//#define Thr_Feedforward_Compensation//﮵�ص�ѹǰ������ʹ��
#ifdef Thr_Feedforward_Compensation
	#define Battery_Cell_Voltage    4.2//1S﮵�س���4.2V
	#define Battery_Cell_Numeber    4//4S﮵��
	#define Battery_Full_Voltage    (Battery_Cell_Voltage*Battery_Cell_Numeber)
#endif

uint16_t Throttle_Output=0;
void Throttle_Angle_Compensate()//������ǲ���
{
  float CosPitch_CosRoll=ABS(Cos_Pitch*Cos_Roll);
  float Throttle_Makeup=0;
  float Temp=0;
  if(CosPitch_CosRoll>=0.999999f)  CosPitch_CosRoll=0.999999f;
  if(CosPitch_CosRoll<=0.000001f)  CosPitch_CosRoll=0.000001f;
  if(CosPitch_CosRoll<=0.50f)  CosPitch_CosRoll=0.50f;//Pitch,RollԼ����30��
  if(Throttle>=Thr_Start)//������ת������
  {
    Temp=(uint16_t)(MAX(ABS(100*Pitch),ABS(100*Roll)));
    Temp=constrain_float(9000-Temp,0,3000)/(3000*CosPitch_CosRoll);
    Throttle_Makeup=(Throttle-Thr_Start)*Temp;//������ǲ���
    Throttle_Output=(uint16_t)(Thr_Start+Throttle_Makeup);
    Throttle_Output=(uint16_t)(constrain_float(Throttle_Output,Thr_Start,2000));
#ifdef Thr_Feedforward_Compensation 
		Throttle_Output+=(Throttle_Output-Thr_Start)*(Battery_Full_Voltage/Battery_Voltage-1.0f);
#endif
  }
  else Throttle_Output=Throttle;	
}


/**************************************************************
***************************************************************
X�Ͱ�װ��ʽ������������̬�ǹ�ϵ
                   -
                 Pitch
					3#             1#
					   *          *
-   Roll          *         Roll   +
						 *          *
					2#             4#
				         Pitch
								   +
���ٶȴ���������������X��Y��Zͬ�ᣬ������ԭ�㿴����ʱ����ת�Ƕ�Ϊ+
Y Aixs
*
*
*
*
*
*
* * * * * * * *   X Axis
(0)
*******************************************************************
******************************************************************/
uint16_t Idel_Cnt=0;
#define Idel_Transition_Gap 4//���ٵ������ʱ�� 2*5=10ms
#define Idel_Transition_Period (Thr_Idle-Thr_Min)//����������������  10ms*100=1s
uint16_t Thr_Idle_Transition_Cnt=0;
void Control_Output()
{
  Throttle_Angle_Compensate();//������ǲ���
  landon_earth_check();//��½�����Լ�
  if(Controler_State==Unlock_Controler)//����
  {
    if(Landon_Earth_Flag==1)//��⵽��½����
    {
      if(Last_Motor_PWM_1<=Thr_Min
         &&Last_Motor_PWM_2<=Thr_Min
           &&Last_Motor_PWM_3<=Thr_Min
             &&Last_Motor_PWM_4<=Thr_Min
               )//ֻ���������ٽ���ʱ�Ż�����
      {
        //����ϴ��������ֵΪ���λ�����뵡��ʱ�����Ź��ɹ���
        Thr_Idle_Transition_Cnt=Idel_Transition_Period;
      }
      else//����ʱ�̽�����½����
      {
        if(Last_Landon_Earth_Flag==0)//�ϴ�Ϊ���״̬������Ϊ��½״̬���������
        {
          Controler_State=Lock_Controler;
          Bling_Set(&Light_3,3000,200,0.5,0,GPIO_PORTF_BASE,GPIO_PIN_3,0);
        }
      }
      
      Idel_Cnt++;
      if(Idel_Cnt>=Idel_Transition_Gap)
      {
        if(Thr_Idle_Transition_Cnt>=1)
          Thr_Idle_Transition_Cnt--;
        Idel_Cnt=0;
      }
      Motor_PWM_1=Thr_Min+(Idel_Transition_Period-Thr_Idle_Transition_Cnt)*(Thr_Idle-Thr_Min)/Idel_Transition_Period;//���ŵ���
      Motor_PWM_2=Thr_Min+(Idel_Transition_Period-Thr_Idle_Transition_Cnt)*(Thr_Idle-Thr_Min)/Idel_Transition_Period;
      Motor_PWM_3=Thr_Min+(Idel_Transition_Period-Thr_Idle_Transition_Cnt)*(Thr_Idle-Thr_Min)/Idel_Transition_Period;
      Motor_PWM_4=Thr_Min+(Idel_Transition_Period-Thr_Idle_Transition_Cnt)*(Thr_Idle-Thr_Min)/Idel_Transition_Period;
      Take_Off_Reset();//�����
      OpticalFlow_SINS_Reset();
      OpticalFlow_Ctrl_Reset();
    }
    else  //������������½������Ĭ�����
    {
      if(Controler_High_Mode==1)//��̬��λ
      {
        if(Throttle>=Thr_Fly_Start)//�����������
        {
            Motor_PWM_1=Int_Sort(
                                 Moter1_Thr_Scale*Throttle_Output
                                   +Moter1_Roll_Scale*Total_Controller.Roll_Gyro_Control.Control_OutPut
                                     +Moter1_Pitch_Scale*Total_Controller.Pitch_Gyro_Control.Control_OutPut
                                       +Moter1_Yaw_Scale*Total_Controller.Yaw_Gyro_Control.Control_OutPut);
            Motor_PWM_2=Int_Sort(
                                 Moter2_Thr_Scale*Throttle_Output
                                   +Moter2_Roll_Scale*Total_Controller.Roll_Gyro_Control.Control_OutPut
                                     +Moter2_Pitch_Scale*Total_Controller.Pitch_Gyro_Control.Control_OutPut
                                       +Moter2_Yaw_Scale*Total_Controller.Yaw_Gyro_Control.Control_OutPut);
            Motor_PWM_3=Int_Sort(
                                 Moter3_Thr_Scale*Throttle_Output
                                   +Moter3_Roll_Scale*Total_Controller.Roll_Gyro_Control.Control_OutPut
                                     +Moter3_Pitch_Scale*Total_Controller.Pitch_Gyro_Control.Control_OutPut
                                       +Moter3_Yaw_Scale*Total_Controller.Yaw_Gyro_Control.Control_OutPut);
            Motor_PWM_4=Int_Sort(
                                 Moter4_Thr_Scale*Throttle_Output
                                   +Moter4_Roll_Scale*Total_Controller.Roll_Gyro_Control.Control_OutPut
                                     +Moter4_Pitch_Scale*Total_Controller.Pitch_Gyro_Control.Control_OutPut
                                       +Moter4_Yaw_Scale*Total_Controller.Yaw_Gyro_Control.Control_OutPut);
            
        }
        else//С���������
        {
          Motor_PWM_1=Int_Sort(Throttle_Output);
          Motor_PWM_2=Int_Sort(Throttle_Output);
          Motor_PWM_3=Int_Sort(Throttle_Output);
          Motor_PWM_4=Int_Sort(Throttle_Output);
          Take_Off_Reset();//�����
        }
				
				
        Motor_PWM_1=Value_Limit(Thr_Idle,2500,Motor_PWM_1);//������޷�
        Motor_PWM_2=Value_Limit(Thr_Idle,2500,Motor_PWM_2);
        Motor_PWM_3=Value_Limit(Thr_Idle,2500,Motor_PWM_3);
        Motor_PWM_4=Value_Limit(Thr_Idle,2500,Motor_PWM_4);		
				Throttle_Control_Reset();
      }
      else if(Controler_High_Mode==2)//�����йܡ����ߵ�λ
      {
          Motor_PWM_1=Int_Sort(
                               Moter1_Thr_Scale*Throttle_Output
                                 +Moter1_Roll_Scale*Total_Controller.Roll_Gyro_Control.Control_OutPut
                                   +Moter1_Pitch_Scale*Total_Controller.Pitch_Gyro_Control.Control_OutPut
                                     +Moter1_Yaw_Scale*Total_Controller.Yaw_Gyro_Control.Control_OutPut);
          Motor_PWM_2=Int_Sort(
                               Moter2_Thr_Scale*Throttle_Output
                                 +Moter2_Roll_Scale*Total_Controller.Roll_Gyro_Control.Control_OutPut
                                   +Moter2_Pitch_Scale*Total_Controller.Pitch_Gyro_Control.Control_OutPut
                                     +Moter2_Yaw_Scale*Total_Controller.Yaw_Gyro_Control.Control_OutPut);
          Motor_PWM_3=Int_Sort(
                               Moter3_Thr_Scale*Throttle_Output
                                 +Moter3_Roll_Scale*Total_Controller.Roll_Gyro_Control.Control_OutPut
                                   +Moter3_Pitch_Scale*Total_Controller.Pitch_Gyro_Control.Control_OutPut
                                     +Moter3_Yaw_Scale*Total_Controller.Yaw_Gyro_Control.Control_OutPut);
          Motor_PWM_4=Int_Sort(
                               Moter4_Thr_Scale*Throttle_Output
                                 +Moter4_Roll_Scale*Total_Controller.Roll_Gyro_Control.Control_OutPut
                                   +Moter4_Pitch_Scale*Total_Controller.Pitch_Gyro_Control.Control_OutPut
                                     +Moter4_Yaw_Scale*Total_Controller.Yaw_Gyro_Control.Control_OutPut);
				
        Motor_PWM_1=Value_Limit(Thr_Idle,2500,Motor_PWM_1);//������޷�
        Motor_PWM_2=Value_Limit(Thr_Idle,2500,Motor_PWM_2);
        Motor_PWM_3=Value_Limit(Thr_Idle,2500,Motor_PWM_3);
        Motor_PWM_4=Value_Limit(Thr_Idle,2500,Motor_PWM_4);
      }
    }
  }
  else//δ�����������������λ��ͣת
  {
    Motor_PWM_1=Thr_Min;
    Motor_PWM_2=Thr_Min;
    Motor_PWM_3=Thr_Min;
    Motor_PWM_4=Thr_Min;
    Take_Off_Reset();//�����
		OpticalFlow_SINS_Reset();
		OpticalFlow_Ctrl_Reset();
//    Throttle_Control_Reset();
	}
  Last_Motor_PWM_1=Motor_PWM_1;
  Last_Motor_PWM_2=Motor_PWM_2;
  Last_Motor_PWM_3=Motor_PWM_3;
  Last_Motor_PWM_4=Motor_PWM_4;  
  Motor_PWM_1=Value_Limit(0,2500,Motor_PWM_1);//������޷�
  Motor_PWM_2=Value_Limit(0,2500,Motor_PWM_2);
  Motor_PWM_3=Value_Limit(0,2500,Motor_PWM_3);
  Motor_PWM_4=Value_Limit(0,2500,Motor_PWM_4);
	PWM_Output((uint16_t)(1.25*Motor_PWM_1),(uint16_t)(1.25*Motor_PWM_2),(uint16_t)(1.25*Motor_PWM_3),(uint16_t)(1.25*Motor_PWM_4),0,0,0,0);
	//PWM_Output(Motor_PWM_1,Motor_PWM_2,Motor_PWM_3,Motor_PWM_4);
}




















/* Copyright (c)  2018-2025 Wuhan Nameless Innovation Technology Co.,Ltd. All rights reserved.*/





//PWM_Output((uint16_t)(1.25*Motor_PWM_1),(uint16_t)(1.25*Motor_PWM_2),(uint16_t)(1.25*Motor_PWM_3),(uint16_t)(1.25*Motor_PWM_4),(uint16_t)(1.25*Motor_PWM_5),(uint16_t)(1.25*Motor_PWM_6),0,0);
