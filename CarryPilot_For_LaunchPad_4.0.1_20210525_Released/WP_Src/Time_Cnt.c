/* Copyright (c)  2019-2025 Wuhan Nameless Innovation Technology Co.,Ltd. All rights reserved.*/
/*----------------------------------------------------------------------------------------------------------------------/
                ��Դ����������ѣ������ߵ���ʷ�Ѿ�֤�����ڹ�����������£���������Ŀ�Դ������������˰����ߣ��Է��ز�����
								Ŀ���Ƶķ�ʽ�в�ͨ���õĿ�Դ��Ŀ��Ҫ��רְ��Ա�����ۺ�����ְ��ֽ�ѧ��ͳ���û�����������ʵ������ɶԲ�
								Ʒ��һ�δ���������������������ۺϿ��ǣ������ɿؿ�Դ�����У������������˾���漤��ܴ��룬�汾������ʵ��
								���ܣ����ڹ�˾��Ʒ���������������Ӱ��ͻ�ѧϰ���������ȫ�����Ÿ��ͻ�ѧϰ���ͻ���ֲ�Ͷ��ο��������뱣����
								���Ȩ��
-----------------------------------------------------------------------------------------------------------------------/
*               ������ֻ��������ѧϰʹ�ã���Ȩ����Ȩ���������ƴ��Ŷӣ������ƴ��Ŷӽ��ɿس���Դ���ṩ�������ߣ�
*               ������ҪΪ�����ƴ��Ŷ��ṩ������δ���������ɣ����ý�Դ�����ṩ�����ˣ����ý�Դ����ŵ����Ϲ�����������أ� 
*               �������Դ�����Ĳ�����緢��������Ϊ�������ƴ��Ŷӽ���֮�Է��ɽ��������
-----------------------------------------------------------------------------------------------------------------------
*                                                 Ϊʲôѡ���������£�
*                                         �ж����ļ۸�������׵Ŀ�Դ�ɿأ�
*                                         ����ҵ������֮������µ��ۺ����
*                                         ׷�����û����飬��Ч����ѧϰ֮·��
*                                         ���²��ٹµ��������������տ�Դ�߶ȣ�
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
*               ���ߣ���˾����ǰ��֪����1���ڼ�ʱ�������������ѧУ����λ����������
*               ������ַ��Ϣ�ᱻ�����ڹ�˾�������ٷ�΢�Ź���ƽ̨���ٷ��������͡�֪��
*               ר���Լ��Ա�������ҳ���Թ�ʾ���棬����������Ϊ�����Ϊ�����۵㣬Ӱ��
*               ��ѧ���ҹ���������������ܿ�ͺ������˻����������������ء�
*               �����Ϊ����˾����ش���ʧ�ߣ����Է���;���������л���ĺ�����лл������
----------------------------------------------------------------------------------------------------------------------*/
#include "Headfile.h"
#include "Time_Cnt.h"


void Time0A_init(void)//ϵͳ���ȶ�ʱ����ʼ��
{
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);							//��ʱ��0ʹ��				
  TimerConfigure(TIMER0_BASE,TIMER_CFG_PERIODIC);						//32λ���ڶ�ʱ��				
  TimerLoadSet(TIMER0_BASE,TIMER_A,SysCtlClockGet()/200);		//�趨װ��ֵ,��80M/200��*1/80M=5ms				
  IntEnable(INT_TIMER0A);																		//���ж�ʹ��				
  TimerIntEnable(TIMER0_BASE,TIMER_TIMA_TIMEOUT); 					//�ж����, ����ģʽ;			
  TimerIntRegister(TIMER0_BASE,TIMER_A,TIMER0A_Handler);		//�жϺ���ע��
//  IntMasterEnable();			
  TimerEnable(TIMER0_BASE,TIMER_A); 												//��ʱ��ʹ�ܿ�ʼ����
  IntPrioritySet(INT_TIMER0A,USER_INT7);
}

void Time2A_init(void)//ϵͳ���ȶ�ʱ����ʼ��
{
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);							//��ʱ��0ʹ��				
  TimerConfigure(TIMER2_BASE,TIMER_CFG_PERIODIC);						//32λ���ڶ�ʱ��				
  TimerLoadSet(TIMER2_BASE,TIMER_A,SysCtlClockGet()/200);		//�趨װ��ֵ,��80M/100��*1/80M=10ms				
  IntEnable(INT_TIMER2A);																		//���ж�ʹ��				
  TimerIntEnable(TIMER2_BASE,TIMER_TIMA_TIMEOUT); 					//�ж����, ����ģʽ;			
  TimerIntRegister(TIMER2_BASE,TIMER_A,TIMER2A_Handler);		//�жϺ���ע��
//  IntMasterEnable();			
  TimerEnable(TIMER2_BASE,TIMER_A); 												//��ʱ��ʹ�ܿ�ʼ����
  IntPrioritySet(INT_TIMER2A,USER_INT6);
}



/***********************************************************
@��������Time_init
@��ڲ�������
@���ڲ�������
@����������ϵͳ���ȶ�ʱ����ʼ��
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void Time_init(void)//ϵͳ���ȶ�ʱ����ʼ��
{
	IntMasterDisable();
  Time0A_init();
//	Time2A_init();
	Schedule_init();//��ʱ��ʹ��
	IntMasterEnable();	
}





Sensor WP_Sensor;
Testime Time0_Delta;
float tmax=0;
/***********************************************************
@��������TIMER0A_Handler
@��ڲ�������
@���ڲ�������
@����������ϵͳ���ȶ�ʱ���жϷ���������Ҫ����ң����������
�������ݲɼ��������˲�����̬���㡢���Ե��������Ƶȶ�������
�ϸ�Ҫ��ĺ���
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void TIMER0A_Handler(void)				//ϵͳ�����жϺ���
{  
  Test_Period(&Time0_Delta);
	if(Time0_Delta.Time_Delta>tmax) tmax=Time0_Delta.Time_Delta;	
	Remote_Control();								//ң�������ݽ���
  Get_Status_Feedback();					//��ȡ��̬���ݡ�ˮƽ����ֱ����ߵ�����	
	Optflow_Statemachine();					//����״̬������ʼ��ʱ���ڹ�������
	SDK_Data_Prase_1();							//SDK���ݽ���
	SDK_Data_Prase_2();			
  GPS_Data_Prase();								//GPS���ݽ���
  KalmanFilter_Horizontal();			//ˮƽλ��GPS˫�۲���Kalman�˲��ں�	
  CarryPilot_Control();						//�ܿ�����
	Accel_Calibration_Check();			//���ٶ�У׼���
  Mag_Calibration_Check();				//������У׼���
  ESC_Calibration_Check();				//����г�У׼���
  Horizontal_Calibration_Check();	//����ˮƽУ׼���
	Ground_Sensor_Statemachine();   //�Եؾ��봫����״̬�����£�������/tfmini_plus/VL53L1X
  Bling_Working(Bling_Mode);			//״ָ̬ʾ������
	NCLink_SEND_StateMachine();			//�������¿�Դ����վ����������http://nameless.tech/download.html
	ADC_Sample_Trigger();
	Read_Button_State_All();
	ADC_Button_Scan();
	TimerIntClear(TIMER0_BASE,TIMER_TIMA_TIMEOUT);
}


Testime Time2_Delta;
void TIMER2A_Handler(void)
{
	TimerIntClear(TIMER2_BASE,TIMER_TIMA_TIMEOUT);
  Test_Period(&Time2_Delta);
}
