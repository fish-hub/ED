#include "Headfile.h"
#include "ADC_Button.h"

#define  ADC_Button_Control_Enable  0//ʹ�ܰ�������ʱ����Ϊ1����֮����Ϊ0


#define ADC_LONG_PRESS_LIMIT  1500//1500ms
#define ADC_IN_PRESS_LIMIT  	500//250ms

button_state ADC_Button1,ADC_Button2,ADC_Button3,ADC_Button4;
uint16_t ADC_PPM_Databuf[10]={0};



void ADC_Button_Init()
{
	ADC_Button1.port=GPIO_PORTD_BASE;
	ADC_Button1.pin=GPIO_PIN_3;
	ADC_Button1.value=1;
	ADC_Button1.last_value=1;

	ADC_Button2.port=GPIO_PORTD_BASE;
	ADC_Button2.pin=GPIO_PIN_3;
	ADC_Button2.value=1;
	ADC_Button2.last_value=1;

	ADC_Button3.port=GPIO_PORTD_BASE;
	ADC_Button3.pin=GPIO_PIN_3;
	ADC_Button3.value=1;
	ADC_Button3.last_value=1;

	ADC_Button4.port=GPIO_PORTD_BASE;
	ADC_Button4.pin=GPIO_PIN_3;
	ADC_Button4.value=1;
	ADC_Button4.last_value=1;
}




uint8_t Key_Value=0;
void ADC_Button_Read(void)
{		
	Button_ADCResult=adc_value[1]*3.3f/4095.f;
	
	if(Button_ADCResult>=3.1f)  		 Key_Value=0x00;//û�а������£�����10K������3.3V
	else if(Button_ADCResult>=2.9f)  Key_Value=0x01;//����K1���£��½�100K�� ����3.3V/11=3.0V
	else if(Button_ADCResult>=1.5f)  Key_Value=0x02;//����K3���£��½�10K��  ����3.3V/2=1.65V
	else if(Button_ADCResult>=1.0f)  Key_Value=0x03;//����K2���£��½�5K��   ����3.3V/3=1.10V
	else if(Button_ADCResult>=0.5f)  Key_Value=0x04;//����K4���£��½�2.2K�� ����3.3V/3=0.595V
	else Key_Value=0x00;
	
	
  switch(Key_Value)
	{
		case 0://û�а�������
		{
			ADC_Button1.value=1;
			ADC_Button2.value=1;
			ADC_Button3.value=1;
			ADC_Button4.value=1;
		}
		break;
		case 1://����1����
		{
			ADC_Button1.value=0;
			ADC_Button2.value=1;
			ADC_Button3.value=1;
			ADC_Button4.value=1;		
		}
		break;		
		case 2://����2����
		{
			ADC_Button1.value=1;
			ADC_Button2.value=0;
			ADC_Button3.value=1;
			ADC_Button4.value=1;		
		}
		break;		
		case 3://����3����
		{
			ADC_Button1.value=1;
			ADC_Button2.value=1;
			ADC_Button3.value=0;
			ADC_Button4.value=1;		
		}
		break;	
		case 4://����4����
		{
			ADC_Button1.value=1;
			ADC_Button2.value=1;
			ADC_Button3.value=1;
			ADC_Button4.value=0;		
		}
		break;	
	  default://û�а�������
		{
			ADC_Button1.value=1;
			ADC_Button2.value=1;
			ADC_Button3.value=1;
			ADC_Button4.value=1;				
		}
		break;	
	}
}


void Read_ADC_Button_State_One(button_state *button)
{
  //button->value=GPIOPinRead(button->port,button->pin);
	if(button->value==0)
	{
		if(button->last_value!=0)//�״ΰ���
		{
			button->press_time=millis();//��¼���µ�ʱ���
			button->in_time=millis();//��¼���µ�ʱ���
			button->in_press_cnt=0;
		}
		else
		{
			if(millis()-button->in_time>ADC_IN_PRESS_LIMIT)//��������
			{
				button->in_time=millis();
				button->press=IN_PRESS;
				//rc_beep.time=1;
				//Bling_Set(&Light_3,200,50,0.1,0,GPIO_PORT_PJ,GPIO_PIN5,0);//��ɫ
				if(button->press==IN_PRESS)  button->in_press_cnt++;
			}
		}
	}
  else
	{
		if(button->last_value==0)//���º��ͷ�
		{
			button->release_time=millis();//��¼�ͷ�ʱ��ʱ��
			
			if(button->release_time-button->press_time>ADC_LONG_PRESS_LIMIT)
			{
			   button->press=LONG_PRESS;
				 button->state_lock_time=0;//5ms*300=1.5S
				 //rc_beep.time=50;
				//Bling_Set(&Light_3,500,100,0.5,0,GPIO_PORT_PJ,GPIO_PIN5,0);//��ɫ
			}
			else
			{
			   button->press=SHORT_PRESS;
				 button->state_lock_time=0;//5ms*300=1.5S
				 //rc_beep.time=10;
				//Bling_Set(&Light_3,200,100,0.5,0,GPIO_PORT_PJ,GPIO_PIN5,0);//��ɫ
			}
		}
	}
	button->last_value=button->value;
	
	
	if(button->press==LONG_PRESS
	 ||button->press==SHORT_PRESS)//�����ͷź󣬳����̨1.5S������Ӧ����λ����״̬
	{
	  button->state_lock_time++;
		if(button->state_lock_time>=300)
		{			
			 button->press=NO_PRESS;
			 button->state_lock_time=0;
		}
	}
}


void Read_ADC_Button_State_All(void)
{
	Read_ADC_Button_State_One(&ADC_Button1);
	Read_ADC_Button_State_One(&ADC_Button2);
	Read_ADC_Button_State_One(&ADC_Button3);
	Read_ADC_Button_State_One(&ADC_Button4);
}




uint8_t adc_ppm_update_flag=0;

void ADC_Button_Scan(void)
{
	ADC_Button_Read();
	Read_ADC_Button_State_All();

#if (ADC_Button_Control_Enable==1)
	
	//����Ϊ���������¼������߼�
	if(ADC_Button1.press==IN_PRESS)
	{
		//����Ϊ�ð���ʵ�ֵ�����
		adc_ppm_update_flag=1;//����Ȩ�޸�ADC�������õ�PPM
		ADC_PPM_Databuf[0]=1500;//������λ����λ
		ADC_PPM_Databuf[1]=1500;//�����λ����λ
		ADC_PPM_Databuf[2]=1000;//���Ÿ�λ���²�
		ADC_PPM_Databuf[3]=2000;//ƫ����λ���Ҳ�
		
		ADC_PPM_Databuf[4]=2000;//����ͨ����λ�����ڶ���ģʽ
		ADC_PPM_Databuf[5]=1000;//����ͨ����λ
		ADC_PPM_Databuf[6]=1000;//����ͨ����λ
		ADC_PPM_Databuf[7]=1000;//�ڰ�ͨ����λ
		Bling_Set(&Light_3,5000,1000,0.5,0,GPIO_PORTF_BASE,GPIO_PIN_3,1);
	}
	else if(ADC_Button1.press==LONG_PRESS)//������������
	{
		//����Ϊ�ð���ʵ�ֵ�����
		adc_ppm_update_flag=1;//����Ȩ�޸�ADC�������õ�PPM
		if(Controler_State==Unlock_Controler)//������ڽ���״̬��ң�������Ż���׼��ִ��SDK
		{
			ADC_PPM_Databuf[0]=1500;//������λ����λ
			ADC_PPM_Databuf[1]=1500;//�����λ����λ
			ADC_PPM_Databuf[2]=1000;//���Ÿ�λ���²�
			ADC_PPM_Databuf[3]=1500;//ƫ����λ����λ
			
			ADC_PPM_Databuf[4]=2000;//����ͨ����λ�����ڶ���ģʽ
			ADC_PPM_Databuf[5]=1000;//����ͨ����λ
			ADC_PPM_Databuf[6]=1000;//����ͨ����λ
			ADC_PPM_Databuf[7]=1000;//�ڰ�ͨ����λ
			Bling_Set(&Light_3,5000,1000,0.5,0,GPIO_PORTF_BASE,GPIO_PIN_3,1);
		}
	}
	else if(ADC_Button1.press==SHORT_PRESS)//���������̰�
	{
		//����Ϊ�ð���ʵ�ֵ�����
		adc_ppm_update_flag=0;//����Ȩ�޸��ͷŸ�����������ȡ��PPM��PPM���ջ�������վ����ң����
													//�ʰ��������󣬴�ʱ�̰��°�����ң��������Ȩ��˲����ͷŸ����ջ�
													//ң�����ӹܺ󣬿����ֶ����Ʒɻ���ȫ����
		
		Bling_Set(&Light_3,5000,1000,0.5,0,GPIO_PORTF_BASE,GPIO_PIN_3,0);
	}
	
	
	//����Ϊ���������¼������߼�
	if(ADC_Button2.press==IN_PRESS)
	{
		//����Ϊ�ð���ʵ�ֵ�����
	}
	else if(ADC_Button2.press==LONG_PRESS)//������������
	{
		//����Ϊ�ð���ʵ�ֵ�����

	}
	else if(ADC_Button2.press==SHORT_PRESS)//���������̰�
	{
		//����Ϊ�ð���ʵ�ֵ�����
		adc_ppm_update_flag=0;//����Ȩ�޸��ͷŸ�����������ȡ��PPM��PPM���ջ�������վ����ң����
													//�ʰ��������󣬴�ʱ�̰��°�����ң��������Ȩ��˲����ͷŸ����ջ�
													//ң�����ӹܺ󣬿����ֶ����Ʒɻ���ȫ����
		
		if(Controler_State==Unlock_Controler)//������ڽ���״̬
		{
			Controler_State=Lock_Controler;//ֱ������
			Bling_Set(&Light_3,5000,1000,0.5,0,GPIO_PORTF_BASE,GPIO_PIN_3,0);
		}	
	}
	
	
	
	
	//����ΪSDK�����¼������߼�
	if(ADC_Button3.press==IN_PRESS)
	{
		//����Ϊ�ð���ʵ�ֵ�����
	}
	else if(ADC_Button3.press==LONG_PRESS)//SDK��������
	{
		//����Ϊ�ð���ʵ�ֵ�����
		adc_ppm_update_flag=1;//����Ȩ�޸�ADC�������õ�PPM
		if(Controler_State==Unlock_Controler)//������ڽ���״̬��ִ��SDK
		{		
			ADC_PPM_Databuf[0]=1500;//������λ����λ
			ADC_PPM_Databuf[1]=1500;//�����λ����λ
			ADC_PPM_Databuf[2]=1500;//���Ÿ�λ���в�
			ADC_PPM_Databuf[3]=1500;//ƫ����λ����λ

			ADC_PPM_Databuf[4]=2000;//����ͨ����λ�����ڶ���ģʽ
			ADC_PPM_Databuf[5]=2000;//����ͨ����λ������SDKģʽ
			ADC_PPM_Databuf[6]=1000;//����ͨ����λ
			ADC_PPM_Databuf[7]=2000;//�ڰ�ͨ����λ�����ڹ�������ģʽ
			
			Bling_Set(&Light_3,5000,1000,0.5,0,GPIO_PORTF_BASE,GPIO_PIN_3,1);
		}
	}
	else if(ADC_Button3.press==SHORT_PRESS)//SDK�����̰�
	{
		//����Ϊ�ð���ʵ�ֵ�����
		adc_ppm_update_flag=1;//����Ȩ�޸�ADC�������õ�PPM
		if(Controler_State==Unlock_Controler)//������ڽ���״̬���˳�SDKģʽ����ԭ����ͣ
		{
			ADC_PPM_Databuf[0]=1500;//������λ����λ
			ADC_PPM_Databuf[1]=1500;//�����λ����λ
			ADC_PPM_Databuf[2]=1500;//���Ÿ�λ���в�
			ADC_PPM_Databuf[3]=1500;//ƫ����λ����λ

			ADC_PPM_Databuf[4]=2000;//����ͨ����λ�����ڶ���ģʽ
			ADC_PPM_Databuf[5]=1000;//����ͨ����λ���˳�SDKģʽ
			ADC_PPM_Databuf[6]=1000;//����ͨ����λ
			ADC_PPM_Databuf[7]=2000;//�ڰ�ͨ����λ�����ڹ�������ģʽ
			Bling_Set(&Light_3,5000,1000,0.5,0,GPIO_PORTF_BASE,GPIO_PIN_3,1);
		}
	}
	
	
	
	//����Ϊһ�������¼������߼�
	if(ADC_Button4.press==IN_PRESS)
	{
		//����Ϊ�ð���ʵ�ֵ�����
	}
	else if(ADC_Button4.press==LONG_PRESS)//һ�����䰴������
	{
		//����Ϊ�ð���ʵ�ֵ�����

	}
	else if(ADC_Button4.press==SHORT_PRESS)//һ�����䰴���̰�
	{
		//����Ϊ�ð���ʵ�ֵ�����
		adc_ppm_update_flag=1;//����Ȩ�޸�ADC�������õ�PPM
		if(Controler_State==Unlock_Controler)//������ڽ���״̬���˳�SDKģʽ����ԭ����ͣ
		{
			ADC_PPM_Databuf[0]=1500;
			ADC_PPM_Databuf[1]=1500;
			ADC_PPM_Databuf[2]=1500;
			ADC_PPM_Databuf[3]=1500;//ǰ�ĸ�ͨ��������λ
			
			ADC_PPM_Databuf[4]=2000;//����ͨ����λ�����ڶ���ģʽ
			ADC_PPM_Databuf[5]=1000;//����ͨ����λ
			ADC_PPM_Databuf[6]=2000;//����ͨ����λ������һ������ģʽ
			ADC_PPM_Databuf[7]=2000;//�ڰ�ͨ����λ�����ڹ�������ģʽ
			Bling_Set(&Light_3,5000,1000,0.5,0,GPIO_PORTF_BASE,GPIO_PIN_3,1);
		}
	}
#endif
}




