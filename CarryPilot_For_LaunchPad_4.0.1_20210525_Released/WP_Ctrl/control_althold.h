/*----------------------------------------------------------------------------------------------------------------------/
*               ������ֻ����Уѧ��ѧϰʹ�ã���Ȩ����Ȩ�����人�Ƽ���ѧ���人�Ƽ���ѧ���ɿس���Դ���ṩ����Уѧ����
*               ��Уѧ��ҪΪ�人�Ƽ���ѧ�ṩ������δ��ѧУ��ɣ����ý�Դ�����ṩ�����ˣ����ý�Դ����ŵ����Ϲ�����������أ� 
*               �������Դ�����Ĳ�����緢��������Ϊ���人�Ƽ���ѧ����֮�Է��ɽ��������
-----------------------------------------------------------------------------------------------------------------------/
*               ������Ϣ���ܶ���ֹ��ǰ�����������˳���������
*               ��Դ���ף���ѧ����ϧ��ף������Ϯ�����׳ɹ�������
*               ѧϰ�����ߣ��������Ƽ���DJI��ZEROTECH��XAG��AEE��GDU��AUTEL��EWATT��HIGH GREAT�ȹ�˾��ҵ
*               ��ְ�����뷢�ͣ�15671678205@163.com���豸ע��ְ����λ����λ��������
*               �����ƴ���Դ�ɿ�QQȺ��540707961
*               CSDN���ͣ�http://blog.csdn.net/u011992534
*               �ſ�ID��NamelessCotrunWUST
*               Bվ��ѧ��Ƶ��https://space.bilibili.com/67803559/#/video
*               �ͻ�ʹ���ĵá��Ľ������������http://www.openedv.com/forum.php?mod=viewthread&tid=234214&extra=page=1
*               �Ա����̣�https://shop348646912.taobao.com/?spm=2013.1.1000126.2.5ce78a88ht1sO2
*               �ٶ�����:�����ƴ���Դ�ɿ�
*               �޸�����:2018/8/30
*               �汾���۷��ߡ���V1.0.1
*               ��Ȩ���У�����ؾ���
*               Copyright(C) �人�Ƽ���ѧ�人�Ƽ���ѧ 2017-2025
*               All rights reserved
----------------------------------------------------------------------------------------------------------------------*/
#ifndef _CONTROL_ALTHOLD_H
#define _CONTROL_ALTHOLD_H



//ע�������п�����������ģʽ������ֱ�߶�λ��+��ֱ�ٶ�+��ֱ���ٶ�
#define YAW_Pos_Control_Accel_Disable  0
//#define ALT_VEL_FEEDFORWARD_ENABLE 		 1 //�ٶ�ǰ������ʹ��


typedef enum 
{
  ALTHOLD_MANUAL_CTRL=0,
  ALTHOLD_AUTO_POS_CTRL,
	ALTHOLD_AUTO_VEL_CTRL,
}ALTHOLD_CTRL_MODE;

#define NUL 0


void Flight_Alt_Hold_Control(uint8_t mode,float target_alt,float target_vel);



void Thr_Scale_Set(rc_calibration *rc_date);
void ncq_control_althold(void);
float get_stopping_point_z(Vector3f *stopping_point);
uint8_t Thr_Push_Over_Deadband(void);


extern float ALT_VEL_FEEDFORWARD_ENABLE_Output;//��ֱ�ٶ�ǰ�����������;
extern float ALT_VEL_FEEDFORWARD_ENABLE_Rate;//��ֱ�ٶ�ǰ����������APM����Ϊ1��0.45;
extern float ALT_VEL_FEEDFORWARD_ENABLE_Delta;//��ֱ�����ٶȱ仯��;
extern float Last_Yaw_Vel_Target;
extern float Yaw_Vel_Target;
extern Vector3f UAV_Cushion_Stop_Point;

extern uint16_t  Deadband;//������λ����
extern uint16_t  Deadzone_Min;
extern uint16_t  Deadzone_Max;
extern uint16_t  Thr_Top;//����������г�
extern uint16_t  Thr_Buttom;//����������г�
extern uint8_t Thr_Push_Over_State;
#endif

