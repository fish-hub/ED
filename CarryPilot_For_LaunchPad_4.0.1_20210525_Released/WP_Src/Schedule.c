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
#include "Time.h"
#include "Schedule.h"







//void Schedule_init(void)
//{
//  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);//��ʱ��1ʹ��				
//  TimerConfigure(TIMER1_BASE,TIMER_CFG_PERIODIC_UP);//32λ���ڶ�ʱ��
//  TimerLoadSet(TIMER1_BASE,TIMER_A,SysCtlClockGet()/100);//�趨װ��ֵ,��80M/100��*1/80M=10ms				
//  IntEnable(INT_TIMER1A);//��ʱ��1�ж�ʹ��				
//  TimerIntEnable(TIMER1_BASE,TIMER_TIMA_TIMEOUT); //�ж����, ����ģʽ;
//  TimerIntRegister(TIMER1_BASE,TIMER_A,TIMER1A_Handler);//�жϺ���ע��
//  //IntMasterEnable();			
//  TimerEnable(TIMER1_BASE,TIMER_A); //��ʱ��ʹ�ܿ�ʼ����	
//  //IntPriorityGroupingSet(0);
//  IntPrioritySet(INT_TIMER1A,USER_INT0);
//}



////#define Hour         3
////#define Minute       2
////#define Second       1
////#define MicroSecond  0
////uint16 Time_Sys[4]={0};
////uint16 Microsecond_Cnt=0;
////uint32 TIME_ISR_CNT=0,LAST_TIME_ISR_CNT=0;
//void TIMER1A_Handler(void)//�жϺ���
//{
//  //LAST_TIME_ISR_CNT=TIME_ISR_CNT;
//  //TIME_ISR_CNT++;//ÿ10ms�Լ�
//  //	Microsecond_Cnt++;
//  //	if(Microsecond_Cnt>=100)//1s
//  //	{
//  //		Microsecond_Cnt=0;
//  //		Time_Sys[Second]++;
//  //		if(Time_Sys[Second]>=60)//1min
//  //		{
//  //			Time_Sys[Second]=0;
//  //			Time_Sys[Minute]++;
//  //			if(Time_Sys[Minute]>=60)//1hour
//  //			{
//  //				Time_Sys[Minute]=0;
//  //				Time_Sys[Hour]++;
//  //			}
//  //		}
//  //	}
//  TimerIntClear(TIMER1_BASE,TIMER_TIMA_TIMEOUT);  	
//}

void Test_Period(Testime *Time_Lab)
{
  Time_Lab->Last_Time=Time_Lab->Now_Time;
  Time_Lab->Now_Time=micros()/1000.0f;//(10000*TIME_ISR_CNT+TimerValueGet(TIMER1_BASE,TIMER_A)/80.0f)/1000.0f;//��λms
  Time_Lab->Time_Delta=(Time_Lab->Now_Time-Time_Lab->Last_Time);
  Time_Lab->Time_Delta_INT=(uint16)(Time_Lab->Time_Delta);
}


void Get_Systime(systime *sys)
{
  sys->last_time=sys->current_time;
  sys->current_time=micros()/1000.0f;//��λms
  sys->period=sys->current_time-sys->last_time;
  sys->period_int=(uint16_t)(sys->period);
}








