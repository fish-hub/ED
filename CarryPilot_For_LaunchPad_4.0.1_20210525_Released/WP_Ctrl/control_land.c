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
#include "control_config.h"
#include "control_land.h"

Vector2_Nav land_pos_target,land_pos_now,land_home_pos;
float target_yaw_rate=0,target_yaw_alt=0;
bool land_althold(float taret_climb_rate,float target_climb_alt)
{
  static uint8_t move_flag=0;
  bool handmove_flag=FALSE;
  float step_mapping=0,scale_mapping=0;
  Thr_Scale_Set(&RC_Data.cal[2]);
  High_Hold_Throttle=Thr_Hover_Default;
  /*�߶ȿ�������1��*/
  /********
      **
      **
      **
      **
      **
  ********/
  /*******************************�߶ȿ�������ʼ****************************************/
  /****************���ߣ��߶�λ�û�+�ٶȻ�+���ٶȻ����������ڷֱ�Ϊ8ms��4ms��4ms*******************/
  if(target_climb_alt==0)
  {
    Total_Controller.High_Position_Control.Expect=NamelessQuad.Position[_YAW];//һֱ���¸߶�����
  }
  else
  {
    Total_Controller.High_Position_Control.Expect=target_climb_alt;//���¸߶�����
  }
  if(TRPY[0]>=Deadzone_Min
     &&TRPY[0]<=Deadzone_Max)
  {
    //�߶�λ�û���������ٶ�����
		Total_Controller.High_Position_Control.FeedBack=NamelessQuad.Position[_YAW];//����
		PID_Control(&Total_Controller.High_Position_Control);//���θ߶�λ�ÿ�����
		//�ڻ��ٶ�����
		if(target_climb_alt==0) Yaw_Vel_Target=taret_climb_rate;//�����ٶ�������Դ���ⲿֱ�Ӹ���
		else Yaw_Vel_Target=Total_Controller.High_Position_Control.Control_OutPut;//�����ٶ�������Դ��λ�ÿ��������
#ifdef ALT_VEL_FEEDFORWARD_ENABLE  //�ٶ�ǰ��������
		ALT_VEL_FEEDFORWARD_ENABLE_Delta=(Yaw_Vel_Target-Last_Yaw_Vel_Target)/(1*Delta);//�ٶ������仯��
		ALT_VEL_FEEDFORWARD_ENABLE_Output=ALT_VEL_FEEDFORWARD_ENABLE_Rate*ALT_VEL_FEEDFORWARD_ENABLE_Delta;
		Last_Yaw_Vel_Target=Yaw_Vel_Target;//�ϴ��ٶ�����
#endif
		Total_Controller.High_Speed_Control.Expect=Yaw_Vel_Target;
    handmove_flag=FALSE;
    move_flag=0;
  }
  else if(TRPY[0]>Deadzone_Max)//���������ٶ�����
  {
    //���Ÿ����ơ������ٶ�����
    step_mapping=(float)(TRPY[0]-Deadzone_Max)/(Thr_Top-Deadzone_Max);//��Χ0~1
    scale_mapping=constrain_float(step_mapping*step_mapping,0,1);
    Total_Controller.High_Speed_Control.Expect=Max_Upvel*scale_mapping;//��������ٶ�50cm/s
    handmove_flag=TRUE;
    move_flag=1;
  }
  else if(TRPY[0]<Deadzone_Min)//�����½��ٶ�����
  {
    //���Ÿ����ơ������ٶ�����
    step_mapping=(float)(TRPY[0]-Deadzone_Min)/(Deadzone_Min-Thr_Buttom);//��Χ0~-1
    scale_mapping=constrain_float(step_mapping*step_mapping,0,1);
    Total_Controller.High_Speed_Control.Expect=-Max_Downvel*scale_mapping;//����½��ٶ�40cm/s
    handmove_flag=TRUE;
    move_flag=2;
  }
  /*�߶ȿ�������2��*/
  /********
          *
          *
   * * * *
  *
  *
  ********/
  /*******************************��ֱ�ٶȿ�������ʼ*******************************************************************/
	Total_Controller.High_Speed_Control.FeedBack=NamelessQuad.Speed[_YAW];//�ߵ��ٶȹ��Ƹ��ٶȷ���
	Alt_Accel_Control(&Total_Controller.High_Speed_Control);//���θ߶��ٶȿ���
	//ADRC_TD_Control(&ADRC_Alt_Vel_Controller,Total_Controller.High_Speed_Control.Expect,Total_Controller.High_Speed_Control.FeedBack);
	//Total_Controller.High_Speed_Control.Control_OutPut=ADRC_Alt_Vel_Controller.u;
  /*******************************�����½��������������ٶ��޷���������*******************************************************************/     
  if(move_flag==0)
	{
    Total_Controller.High_Speed_Control.Control_OutPut=constrain_float(Total_Controller.High_Speed_Control.Control_OutPut,
                                                                       -SDK_Mild_Acceleration_Max,SDK_Mild_Acceleration_Max);  
	}		
  else if(move_flag==1)//�������Ƹ�ʱ���ٶȿ�����������������������½����ٶȽ��зֱ��޷���ȷ�������½�ʱ��̬ƽ��
  {
    Total_Controller.High_Speed_Control.Control_OutPut=constrain_float(Total_Controller.High_Speed_Control.Control_OutPut,
                                                                       -Climb_Up_Acceleration_Max,Climb_Up_Acceleration_Max);                                                                
  }
  else if(move_flag==2)
  {
    Total_Controller.High_Speed_Control.Control_OutPut=constrain_float(Total_Controller.High_Speed_Control.Control_OutPut,
                                                                       -Climb_Down_Acceleration_Max,Climb_Down_Acceleration_Max);
  }    
  /*******************************��ֱ�ٶȿ���������******************************************************************/
  /*�߶ȿ�������3��*/
  /********
         **
         **
       **
         **
         **
  ********/
  
  /*******************************��ֱ���ٶȿ�������ʼ******************************************************************/
  Total_Controller.High_Acce_Control.Expect=Total_Controller.High_Speed_Control.Control_OutPut;//���ٶ�����
#ifdef ALT_VEL_FEEDFORWARD_ENABLE  //�ٶ�ǰ��������
  Total_Controller.High_Acce_Control.Expect+=ALT_VEL_FEEDFORWARD_ENABLE_Output;//����ǰ�����������
#endif
  Total_Controller.High_Acce_Control.FeedBack=Acceleration_Feedback[_YAW];//���ٶȷ���
	Alt_Accel_Control(&Total_Controller.High_Acce_Control);//���θ߶ȼ��ٶȿ���
  /**************************************
  ���ٶȻ�ǰ������������ʱ��ע������
  ��ͣ���� = ���ٶȻ�����ֵ + ��׼��ͣ����
  ��ʱ����� F = mg
  ����Ҫ���a�ļ��ٶ�ʱ������� F1=m(g+a)
  F1/F = 1 + a/g
  ��˴�ʱӦ�������ͣ����*(1 + a/g)
  **************************************/
  Total_Controller.High_Acce_Control.Control_OutPut+=(High_Hold_Throttle+Total_Controller.High_Acce_Control.Integrate-Thr_Start)*
    (Total_Controller.High_Acce_Control.Expect/980);
  /*******************************��ֱ���ٶȿ���������******************************************************************/
  if(YAW_Pos_Control_Accel_Disable==0)
  {
    Throttle=Int_Sort(High_Hold_Throttle+Total_Controller.High_Acce_Control.Control_OutPut);//������Դ�ڸ߶ȼ��ٶȿ��������
		Alt_Hold_Output_LPF;
  }
  else
  {
    Throttle=Int_Sort(High_Hold_Throttle+Total_Controller.High_Speed_Control.Control_OutPut);//������Դ�ڸ߶��ٶȿ��������
		Alt_Hold_Output_LPF;
  }
  /*****************************************�߶ȿ������������������ſ�����***********************************************************/
  return handmove_flag;
}






#define Minimal_Thrust_Threshold 1150//��½���������Сֵ
uint16_t Landon_Earth_Cnt=0;
uint8_t Last_Landon_Earth_Flag=0,Landon_Earth_Flag=0;
uint8_t Landon_Earth_Flag_Set=0;

void landon_earth_check(void)//�Լ촥�ؽ��뵡��ģʽ
{
  Last_Landon_Earth_Flag=Landon_Earth_Flag;
  //���ſ��ƴ��ڽϵ��г̣�//1����̬ģʽ�£����Ÿ˴��ڵ�λ
  //2������ģʽ�£������ٶ����£������ٶȻ�����Ϊ��Сֵ��
  //���ٶȿ���������ڳ�ʱ����֣������Ľϴ�ֵ��ʹ�����ſ��ƽϵ�
  if(Throttle_Output<=Minimal_Thrust_Threshold
     &&Gyro_Length<=30.0f//���غ�����ת���Ͻ��ٶ�С��30deg/s
       &&ABS(NamelessQuad.Speed[_YAW])<=40.0f//�ߵ���ֱ���ٶ�+-40cm/s
         &&Unwanted_Lock_Flag==0)
    Landon_Earth_Cnt++;
  else Landon_Earth_Cnt/=2;
  
  if(Landon_Earth_Cnt>=1500)  Landon_Earth_Cnt=1500;//��ֹ���
  if(Landon_Earth_Cnt>=200*2.0)//����2.0S
  {
    Landon_Earth_Flag=1;//��½��־λ
    //Landon_Earth_Cnt=0;
  }
  else
  {
    Landon_Earth_Flag=0;//��½��־λ
  }
  /*
  if(ABS(Throttle_Rate)>=1.0E-5f)//ֻҪ���ű仯�ʲ�Ϊ0���������½��־λ
  {
  Landon_Earth_Flag=0;
  Landon_Earth_Cnt=0;
	}
  */
  
  
}

// land_nogps_run - runs the land controller
//      pilot controls roll and pitch angles
//      should be called at 100hz or more
void land_nogps_run()
{
  if(Landon_Earth_Flag==0)//δ���أ�����̬���Ʋ���
  {
		Controller.roll_outer_control_output =RC_Data.rc_rpyt[RC_ROLL];
		Controller.pitch_outer_control_output=RC_Data.rc_rpyt[RC_PITCH];
    
    if(NamelessQuad.Position[_YAW]<=Safe_Height)//��Գ�ʼ�߶�10M����,��ʱ����Ư��
      target_yaw_rate=Nav_Decline_Rate;//��Nav_Decline_rate�ٶ��½�
    else target_yaw_rate=Nav_Rapid_Decline_Rate;//��Nav_Rapid_Decline_rate�ٶ��½�   
    target_yaw_alt=0;
   
//    land_althold(target_yaw_rate,target_yaw_alt);
		Flight_Alt_Hold_Control(ALTHOLD_AUTO_VEL_CTRL,target_yaw_alt,target_yaw_rate);//�߶ȿ���
  }
  else
  {
		Controller.roll_outer_control_output =0;
		Controller.pitch_outer_control_output=0;
    Take_Off_Reset();//��ջ��ֿ�����
    target_yaw_rate=2*Nav_Rapid_Decline_Rate;//��2*Nav_Rapid_Decline_rate�ٶ��½�,ʹ��������Ѹ�����㵡������
    target_yaw_alt=0;
//   land_althold(target_yaw_rate,target_yaw_alt);
		Flight_Alt_Hold_Control(ALTHOLD_AUTO_VEL_CTRL,target_yaw_alt,target_yaw_rate);//�߶ȿ���
  }
}



uint8_t last_handmove_change_mode=1,handmove_change_mode=1;
uint16 nav_transition_cnt=0;
uint16 nav_transition_flag=0;
uint16 nav_climb_rate_cnt=0;
int16 nav_decline_rate_cnt=0;
uint16 first_switch_flag=1;
uint8_t distance_land_mode=0,last_distance_land_mode=0;
uint8_t climb_safe_alt_flag=0,home_fixed_flag=0;
bool check_pos_handmove=FALSE;
bool check_alt_handmove=FALSE;

void land_reset()//��½�����д��ڸ��ֱ�־λ����һ�η��й����У����ܻ�Ƶ���л�����Ҫ����ϴ�δ������ϵı�־λ�����л�ʱ��ȫ�����
{
  //��λ�����е����б�־λ������Ӧ�Խ�Ϊ���ӵ��߼����̵ıر���̼��ɣ�һ��Ҫ���պ�
  last_handmove_change_mode=0;
  
  nav_transition_cnt=0;
  nav_transition_flag=0;
  nav_climb_rate_cnt=0;
  distance_land_mode=0;
  last_distance_land_mode=0;//���Զ�����ģʽ��־λ��0����һ��ѭ���������ж�
  climb_safe_alt_flag=0;
  first_switch_flag=1;
  home_fixed_flag=0;
  handmove_change_mode=2;//ˮƽλ���ֶ�ģʽ
  first_switch_flag=1;//׼�����´λ���ʱ�̵��л�
}




bool GPS_ok()// returns true if the GPS is ok and home position is set
{
    return FALSE;
}


// land_run - runs the land controller
// should be called at 100hz or more
void land_run()
{
  land_nogps_run();//GPS��Чʱ��ִ��һ����½����
}

/* Copyright (c)  2018-2025 Wuhan Nameless Innovation Technology Co.,Ltd. All rights reserved.*/



