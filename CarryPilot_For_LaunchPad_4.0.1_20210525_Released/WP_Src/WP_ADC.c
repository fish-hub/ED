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
#include "WP_ADC.h"
#include "hw_adc.h"
#include "adc.h"



void ADC0IntHandler(void);


uint32_t adc_value[8];
double value_filter;
float Button_ADCResult;
/***********************************************************
@��������ADC_Init
@��ڲ�������
@���ڲ�������
������������ѹ�����˿�PE3����ΪADC0��ͨ��0��ʼ�������ж�ʽ�ɼ�
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void ADC_Init(void)//ADC��ʼ������   
{    
  SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);// Enable the ADC1 module.
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0));// Wait for the ADC1 module to be ready.	
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);    
  GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_3);
	
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);    
//  GPIOPinTypeADC(GPIO_PORTD_BASE, GPIO_PIN_0);	
//	GPIOPinTypeADC(GPIO_PORTD_BASE, GPIO_PIN_1);
//	GPIOPinTypeADC(GPIO_PORTD_BASE, GPIO_PIN_2);
	GPIOPinTypeADC(GPIO_PORTD_BASE, GPIO_PIN_3);
	
  //ADCReferenceSet(ADC0_BASE, ADC_REF_EXT_3V);
  //Enable the first sample sequencer to capture the value of channel 0 when
  //the processor trigger occurs.  
  ADCSequenceConfigure(ADC0_BASE,0,ADC_TRIGGER_PROCESSOR, 0); 
  //ADCHardwareOversampleConfigure(ADC0_BASE, 8);	
	ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_CH0);
	ADCSequenceStepConfigure(ADC0_BASE, 0, 1, ADC_CTL_CH4	|ADC_CTL_END | ADC_CTL_IE);
//	ADCSequenceStepConfigure(ADC0_BASE, 0, 2, ADC_CTL_CH5);
//	ADCSequenceStepConfigure(ADC0_BASE, 0, 3, ADC_CTL_CH6);
//	ADCSequenceStepConfigure(ADC0_BASE, 0, 4, ADC_CTL_CH7 |ADC_CTL_END | ADC_CTL_IE);
		
	ADCIntClear(ADC0_BASE, 0);
	ADCSequenceEnable(ADC0_BASE, 0);    
  ADCIntEnable(ADC0_BASE, 0); 
  //�жϴ�����ʽ����ADC_INT_SS0��ADC_INT_DMA_SS0��ADC_INT_DCON_SS0
	ADCIntEnableEx(ADC0_BASE,ADC_INT_SS0);//�ֱ������ͨ���д�����DMA���������ֱȽ�������
	IntEnable(INT_ADC0SS0); //ʹ��ADC���������ж�	
	ADCIntRegister(ADC0_BASE,0,ADC0IntHandler);		//�жϺ���ע��
	IntPrioritySet(INT_ADC0SS0, USER_INT7);	
} 


float Battery_Voltage;
/***********************************************************
@��������Get_Battery_Voltage
@��ڲ�������
@���ڲ�������
����������������ص�ѹ���ɿ�Ĭ�Ϸ�ѹ��Ϊ11���ʲ�����ѹ��Ҫ����
3.3V*11=36.6V����������ĵ�ѹ�����������Ϸ�ѹ������ֵ����
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void Get_Battery_Voltage(void)//ADC��ȡ   
{
//	ADCProcessorTrigger(ADC0_BASE, 0);   
//	while(!ADCIntStatus(ADC0_BASE, 0, false)) {;}
//	ADCIntClear(ADC0_BASE, 0);	
//	ADCSequenceDataGet(ADC0_BASE, 0, value);   
	//value[0] =  HWREG(ADC0_BASE+ ADC_SEQ + (ADC_SEQ_STEP*0) + ADC_SSFIFO);
	value_filter=(double)(0.7*value_filter+10.89*adc_value[0]/4095.0f);	
	Battery_Voltage=value_filter;		
}


void ADC_Sample_Trigger(void)
{
	static uint16_t cnt=0;
	cnt++;
	if(cnt<=2) return;
	cnt=0;
	ADCProcessorTrigger(ADC0_BASE, 0);
}

Testime ADC_Delta;
void ADC0IntHandler(void)
{
	Test_Period(&ADC_Delta);
	ADCIntClear(ADC0_BASE, 0);// ���ADC�жϱ�־��
	//while(!ADCIntStatus(ADC0_BASE, 0, false));//�ȴ��ɼ�����
	ADCSequenceDataGet(ADC0_BASE, 0, adc_value);// ��ȡADCֵ
}





