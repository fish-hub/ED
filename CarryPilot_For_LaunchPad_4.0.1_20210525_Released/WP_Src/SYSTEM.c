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
#include "SYSTEM.h"

/***********************************************************
@��������HardWave_Init
@��ڲ�������
@���ڲ�������
������������ϵͳоƬ��Դ����Ӳ����Դ����һϵ�г�ʼ���������
����ʼ�����ע��
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/


void HardWave_Init(void)
{
	WP_Init();									   //�ɿ�оƬ��ʼ��
  Butterworth_Parameter_Init();  //�˲���������ʼ��
  PPM_Init();                    //PPM������ʼ��
  Init_PWM();                    //PWM��ʼ��
  Bling_Init();                  //LED״ָ̬ʾ�Ƴ�ʼ�� ��������
	Key_Init();										 //���ذ�����ʼ��
  RC_Calibration_Trigger();      //ң�����г̱궨���
  Horizontal_Calibration_Init(); //����ˮƽ�궨��ʼ��
  PID_Paramter_Init_With_Flash();//PID������ʼ��
	Other_Parameter_Init();        //����������ʼ��
  while(MPU6050_Init());				 //MPU6050�����ǡ����ٶȼ����ó�ʼ��
  Compass_Init();								 //���������ó�ʼ��
  SPL06_Init();									 //SPL06��ѹ�����ó�ʼ��
  Parameter_Init();							 //���ٶȼơ�������У׼������ʼ��
  WP_Quad_Init();								 //���ݹ۲⴫�������ٶȼơ������ƶ���̬��Ԫ����ʼ��
  ConfigureUART3();							 //����3��ʼ����OPENMV����ݮ���Ӿ�ģ�顢SDKģʽ����
//  Set_GPS_USART();							 //����2��ʼ����ʹ��UBLOXЭ������GPSģ��
  ConfigureUART7();							 //����7��ʼ��.������ģ��/TOF��������	
  ConfigureUART6();							 //����6��ʼ��������ģ��LC306���ݽ���
  SDK_Init();										 //SDKģʽ��ʼ��
	Temperature_Ctrl_Init();			 //�¶ȿ�������ʼ��
  Time_init();									 //�ɿص��ȶ�ʱ����ʼ��
  delay_ms(200);								 //��ʼ����ʱ	
}

uint32_t priority[10];
void nvic_priority_get(void)
{
	priority[0]=IntPriorityGet(INT_TIMER2A);
	priority[1]=IntPriorityGet(INT_TIMER1A);
	priority[2]=IntPriorityGet(INT_TIMER0A);
	priority[3]=IntPriorityGet(INT_GPIOC);
	priority[4]=IntPriorityGet(INT_UART0);
	priority[5]=IntPriorityGet(INT_UART1);		
	priority[6]=IntPriorityGet(INT_UART2);
	priority[7]=IntPriorityGet(INT_UART3);
	priority[8]=IntPriorityGet(INT_UART6);
	priority[9]=IntPriorityGet(INT_UART7);
}
