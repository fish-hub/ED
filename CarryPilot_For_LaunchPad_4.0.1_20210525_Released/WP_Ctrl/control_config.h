/*----------------------------------------------------------------------------------------------------------------------/
*               ������ֻ����Уѧ��ѧϰʹ�ã���Ȩ����Ȩ�����人�Ƽ���ѧ���人�Ƽ���ѧ���ɿس���Դ���ṩ����Уѧ����
*               ��Уѧ��ҪΪ�人�Ƽ���ѧ�ṩ������δ��ѧУ���ɣ����ý�Դ�����ṩ�����ˣ����ý�Դ����ŵ����Ϲ�����������أ� 
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
#ifndef _CONTROL_CONFIG_H
#define _CONTROL_CONFIG_H

#include "control_althold.h"
#include "control_poshold.h"
#include "control_land.h"


#define Self_Balance_Mode 1//���ȡ�����̬�����Ų���
#define High_Hold_Mode    2//����ģʽ
#define Pos_Free_Mode 1//ˮƽλ��no fixed
#define Pos_Hold_Mode 2//����ģʽ
//GPS�����´�˿���ģʽ��ֱ����̬��
#define Speed_Mode 0  //GPS����ģʽ�£���˿���
#define Angle_Mode 1  //GPS����ģʽ�£����ֱ�Ӹ���̬������

/*****************ң�����г�����**********************/
#define  Climb_Up_Speed_Max    300//������������ٶȣ�cm/s  400  300
#define  Climb_Down_Speed_Max  150//��������½��ٶȣ�cm/s  200  150

/****************************************************************
���������رȽ�Сʱ���������½��������ٶȱȽϴ�
�ᵼ�����ӳ����������̬�������ò�����������
ʹ�ÿ��������½�ʱ����̬��ƽ�ȣ����˹��̳���ʱ�䳤��
�ᵼ����̬���ڵò���������ֱ�����ը���������رȽ�
Сʱ���ɽ��������ٶ���Сһ�㣬���������������ȼ�����
*******************************************************************/
#define  Climb_Up_Acceleration_Max     400//��������������ٶȣ�cm/s^2  400  250
#define  Climb_Down_Acceleration_Max   250//��������½����ٶȣ�cm/s^2  250  150
#define  SDK_Mild_Acceleration_Max   	 200//SDK����½����ٶȣ�cm/s^2  150  150


#define  Flight_Max_Height     5000//�����и߶�5000M
#define  Flight_Max_Radius     5000//�����а뾶5000M

#define  Thr_Start  1050//��ת��������������ǲ����ã�̫��ᵼ�¹�����
#define  Thr_Fly_Start  1050//��������� 1250
#define  Thr_Hover_Default 1500//Ĭ����ͣ���ţ�ֱ�Ӷ������ʱ��1500
#define  Thr_Min 1000
#define  Thr_Idle 1100//���ŵ��٣�ȡ�ӽ���ת����ֵ����1150
#define  Nav_Speed_Max  500//�������ˮƽ�ٶ�Ϊ5m/s

#define  Flight_Safe_Vbat  11200   //11200mv=11.2V
/*****************һ����ɸ߶����ã���λΪcm������100��ʾԭ����ɵ���Գ�ʼλ��1�׸ߵ�λ��**********************/
#define  Auto_Launch_Target 75//һ����ɵ�Ŀ��߶ȣ������ɸ߶ȣ�ʹ�ó�����ʱ�����𳬹������������̣��Ƽ�200����


//#define Alt_Accel_Control  PID_Control_Err_LPF
#define Alt_Accel_Control  	 PID_Control
#define Alt_Hold_Output_LPF  //Throttle=LPButterworth(Throttle,&Butter_Buffer_THR,&Butter_Parameter_THR);

#endif
