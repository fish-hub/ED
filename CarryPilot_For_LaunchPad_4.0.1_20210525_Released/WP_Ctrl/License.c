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
#include "PPM.h"
#include "License.h"
#include "stdlib.h"





void System_Start_Init(void)
{
  SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ |SYSCTL_OSC_MAIN);
  FPUEnable();
  FPULazyStackingEnable();
  initTime();
  EEPROM_Init();
	//ȫ���ж�ʹ��
	IntMasterEnable();
	IntPriorityGroupingSet(3);	
//	EEPROMMassErase();
}	



void Resume_Factory_Setting(void)
{
	EEPROMMassErase();
}



void Schedule_init(void)
{
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);//��ʱ��1ʹ��				
  TimerConfigure(TIMER1_BASE,TIMER_CFG_PERIODIC_UP);//32λ���ڶ�ʱ��
  TimerLoadSet(TIMER1_BASE,TIMER_A,SysCtlClockGet()/1000);//�趨װ��ֵ,��80M/1000��*1/80M=1ms				
  IntEnable(INT_TIMER1A);//��ʱ��1�ж�ʹ��				
  TimerIntEnable(TIMER1_BASE,TIMER_TIMA_TIMEOUT); //�ж����, ����ģʽ;
  TimerIntRegister(TIMER1_BASE,TIMER_A,TIMER1A_Handler);//�жϺ���ע��
//  IntMasterEnable();			
  TimerEnable(TIMER1_BASE,TIMER_A); //��ʱ��ʹ�ܿ�ʼ����	
  //IntPriorityGroupingSet(0);	
  IntPrioritySet(INT_TIMER1A,USER_INT5);
}


void TIMER1A_Handler(void)//�жϺ���
{
	Temperature_Ctrl();	
  Simulation_PWM_Output(Total_Controller.IMU_Temperature_Control.Control_OutPut);
  TimerIntClear(TIMER1_BASE,TIMER_TIMA_TIMEOUT);  	
}

/***********************************************************
@��������ESC_HardWave_Init
@��ڲ�������
@���ڲ�������
@�������������У׼���漴ִ�е��ģʽ�������Դ��ʼ��������
оƬ��Դ���ر������ʼ��
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void ESC_HardWave_Init()//ֻ��ʼ��У׼����ı�Ҫ��Դ
{
  OLED_Init_Fast();//OLED��ʾ����ʼ��
  PPM_Init();//PPM������ʼ��
  Init_PWM();//PWM��ʼ��
  delay_ms(100);
  WriteFlashParameter(ESC_CALIBRATION_FLAG,0,&Table_Parameter);//д������´��ϵ��ٴν���
  while(1)
  {
    ESC_Calibration();
    LCD_clear_L(0,0);LCD_clear_L(0,1);LCD_P8x16Str(0,0,"Please Move Thr");
    LCD_clear_L(0,2);LCD_clear_L(0,3);LCD_P8x16Str(0,2,"Down When ESC");
    LCD_clear_L(0,4);LCD_clear_L(0,5);LCD_P8x16Str(0,4,"Beep Beep");
    LCD_P6x8Str(80,4,"Thr:");
    write_6_8_number(80,5,Receiver_PPM_Databuf[2]);
    LCD_clear_L(0,6);LCD_P6x8Str(0,6,"Repower When Set Up");
  }
}



/***********************************************************
@��������WP_Init
@��ڲ�������
@���ڲ�������
������������ϵͳоƬ��Դ����ִ�п������У׼�Լ캯��������Ҫ
���У׼���漴ִ�е��ģʽ�������Դ��ʼ��������ִ�г���Ӳ��
��Դ��ʼ����
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void WP_Init(void)
{
  System_Start_Init();//ϵͳ������ʼ��
	Simulation_PWM_Init();
  ReadFlashParameterOne(ESC_CALIBRATION_FLAG,&ESC_Calibration_Flag);
  if(ESC_Calibration_Flag==1)
  {
    ESC_HardWave_Init();//ֻ��ʼ��У׼����ı�Ҫ��Դ 
  }
  else
  {	
		ConfigureUART1();//����1��ʼ�����������µ���վ
		ConfigureUART0();//����0��ʼ����ɽ�����վ
		ADC_Init();//ADC��ʼ��������ⲿ��ص�ѹ
		OLED_Init();//OLED��ʾ����ʼ��
		Init_I2C();	//Ӳ��I2C��ʼ��
		spl0601_init();
		//Lcd_Init();
		//ST7789_LCD_Clear(LCD_WHITE);
		//BACK_COLOR=LCD_WHITE;
  }
}


