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
*               �޸�����:2020/03/24                   
*               �汾����Ӯ��PRO����CarryPilot_V3.0.1
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
#include "uart.h"
#include "Usart.h"
#include "Ringbuf.h"



//����ѭ�����л������ݶ���
RingBuff_t COM0_Rx_Buf,COM1_Rx_Buf,COM2_Rx_Buf,COM3_Rx_Buf,COM4_Rx_Buf,COM5_Rx_Buf,COM6_Rx_Buf,COM7_Rx_Buf;
/***********************************************************
@��������UART0_IRQHandler
@��ڲ�������
@���ڲ�������
��������������0���ݽ���
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void UART0_IRQHandler(void)//UART0�жϺ���
{	
  //��ȡ�жϱ�־ ԭʼ�ж�״̬ �������жϱ�־		
  uint32_t flag = UARTIntStatus(UART0_BASE,1);
  //����жϱ�־	
  UARTIntClear(UART0_BASE,flag);		
  //�ж�FIFO�Ƿ�������		
  while(UARTCharsAvail(UART0_BASE))		
  {			
		RingBuf_Write(UARTCharGet(UART0_BASE),&COM0_Rx_Buf,SDK_Target_Length*2);//�����ζ�������д����
		if(COM0_Rx_Buf.Ring_Buff[0]!=0xFF)
		{
			COM0_Rx_Buf.Head=1;
			COM0_Rx_Buf.Tail=0; 
		}	
		
  }
}

/***********************************************************
@��������ConfigureUART0
@��ڲ�������
@���ڲ�������
��������������0����
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void ConfigureUART0(void)//����0��ʼ��
{
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);//ʹ��GPIO����		
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);//ʹ��UART����
  GPIOPinConfigure(GPIO_PA0_U0RX);//GPIOģʽ���� PA0--RX PA1--TX 
  GPIOPinConfigure(GPIO_PA1_U0TX);
  GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);//GPIO��UARTģʽ����
  UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);
  UARTStdioConfig(0, 921600, 16000000);
  //UARTЭ������ ������115200 8λ 1ֹͣλ  ��У��λ	
  //UART����FIFO Ĭ��FIFO LevelΪ4/8 �Ĵ�����8�ֽں�����ж�	//���ú����1λ�Ͳ����ж�	
  UARTFIFODisable(UART0_BASE);//ʹ��UART0�ж�	IntEnable(INT_UART0);	
  UARTIntEnable(UART0_BASE,UART_INT_RX);//ʹ��UART0�����ж�		
  UARTIntRegister(UART0_BASE,UART0_IRQHandler);//UART�жϵ�ַע��	
  IntPrioritySet(INT_UART0, USER_INT3);
}

/***********************************************************
@��������USART0_Send
@��ڲ�����uint8_t *pui8Buffer, uint32_t ui32Count
@���ڲ�������
��������������0����N���ֽ�����
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void USART0_Send(uint8_t *pui8Buffer, uint32_t ui32Count)//����N���ֽڳ��ȵ�����
{
  while(ui32Count--)
  {
    UARTCharPut(UART0_BASE, *pui8Buffer++);
  }
}
/***********************************************************
@��������wust_sendware
@��ڲ�����unsigned char *wareaddr, int16_t waresize
@���ڲ�������
����������ɽ������ʾ��������
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void wust_sendware(unsigned char *wareaddr, int16_t waresize)//ɽ�ⷢ�Ͳ���
{
#define CMD_WARE     3
  uint8 cmdf[2] = {CMD_WARE, ~CMD_WARE};//֡ͷ
  uint8 cmdr[2] = {~CMD_WARE, CMD_WARE};//֡β
  USART0_Send(cmdf, sizeof(cmdf));
  USART0_Send(wareaddr, waresize);
  USART0_Send(cmdr, sizeof(cmdr));
}

/***********************************************************
@��������UART1_IRQHandler
@��ڲ�������
@���ڲ�������
��������������1���ݽ���
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void UART1_IRQHandler(void)//UART1�жϺ���
{				
  uint32_t flag = UARTIntStatus(UART1_BASE,1);//��ȡ�жϱ�־ ԭʼ�ж�״̬ �����жϱ�־	
  UARTIntClear(UART1_BASE,flag);//����жϱ�־	
  while(UARTCharsAvail(UART1_BASE))//�ж�FIFO�Ƿ�������		
  {			
    //RingBuf_Write(UARTCharGet(UART1_BASE),&COM1_Rx_Buf,100);//�����ζ�������д����	
    NCLink_Data_Prase_Prepare(UARTCharGet(UART1_BASE)); 		
  }
}


/***********************************************************
@��������USART1_Send
@��ڲ�����uint8_t *pui8Buffer, uint32_t ui32Count
@���ڲ�������
��������������1����N���ֽ�����
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void USART1_Send(uint8_t *pui8Buffer, uint32_t ui32Count)//����N���ֽڳ��ȵ�����
{
  while(ui32Count--)
  {
    UARTCharPut(UART1_BASE, *pui8Buffer++);
  }
}
/***********************************************************
@��������ConfigureUART1
@��ڲ�������
@���ڲ�������
��������������1����
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void ConfigureUART1(void)//����1��ʼ��
{
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);//ʹ��GPIO����		
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);//ʹ��UART����
  GPIOPinConfigure(GPIO_PB0_U1RX);//GPIOģʽ���� PB0--RX PB1--TX 
  GPIOPinConfigure(GPIO_PB1_U1TX);
  GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1);//GPIO��UARTģʽ����
  UARTClockSourceSet(UART1_BASE, UART_CLOCK_PIOSC);
  UARTStdioConfig(1, 921600, 16000000);//115200
  UARTFIFODisable(UART1_BASE);//ʹ��UART1�ж�	
  UARTIntEnable(UART1_BASE,UART_INT_RX);//ʹ��UART1�����ж�		
  UARTIntRegister(UART1_BASE,UART1_IRQHandler);//UART1�жϵ�ַע��	
  IntPrioritySet(INT_UART1, USER_INT2);
}


/***********************************************************
@��������UART2_IRQHandler
@��ڲ�������
@���ڲ�������
��������������2���ݽ���
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void UART2_IRQHandler(void)
{
  uint32_t flag = UARTIntStatus(UART2_BASE,1);//��ȡ�жϱ�־ ԭʼ�ж�״̬ �����жϱ�־		
  UARTIntClear(UART2_BASE,flag);//����жϱ�־	
  while(UARTCharsAvail(UART2_BASE))//�ж�FIFO�Ƿ�������				
  {		
//    //����õ�������
//    RingBuf_Write(UARTCharGet(UART2_BASE),&COM2_Rx_Buf,200);//�����ζ�������д����
//    if(COM2_Rx_Buf.Ring_Buff[0]!=0XB5)
//    {
//      COM2_Rx_Buf.Head=1;
//      COM2_Rx_Buf.Tail=0; 
//    }
		RingBuf_Write(UARTCharGet(UART2_BASE),&COM2_Rx_Buf,FLOW_BUF_CNT);//�����ζ�������д����				
  }
}

/***********************************************************
@��������USART2_Send
@��ڲ�����uint8_t *pui8Buffer, uint32_t ui32Count
@���ڲ�������
��������������2����N���ֽ�����
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void USART2_Send(uint8_t *pui8Buffer, uint32_t ui32Count)//����N���ֽڳ��ȵ�����
{
  while(ui32Count--)
  {
    UARTCharPut(UART2_BASE, *pui8Buffer++);
  }
}
/***********************************************************
@��������ConfigureUART2
@��ڲ�������
@���ڲ�������
��������������2����
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void ConfigureUART2(unsigned long bound)//����2��ʼ��
{
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);//ʹ��GPIO����		
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART2);//ʹ��UART����
  
  HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;//����PD6
  HWREG(GPIO_PORTD_BASE + GPIO_O_CR) |= 0x80;//ȷ��
  HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = 0;//��������
  
  GPIOPinConfigure(GPIO_PD6_U2RX);//GPIOģʽ���� PD6--RX PD7--TX 
  GPIOPinConfigure(GPIO_PD7_U2TX);
  GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);//GPIO��UARTģʽ����
  UARTConfigSetExpClk(UART2_BASE, SysCtlClockGet(), bound,
                      (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                       UART_CONFIG_PAR_NONE));
  UARTFIFODisable(UART2_BASE);//ʹ��UART2�ж�	
  UARTIntEnable(UART2_BASE,UART_INT_RX |UART_INT_RT);//ʹ��UART0�����ж�		
  UARTIntRegister(UART2_BASE,UART2_IRQHandler);//UART�жϵ�ַע��	
  IntPrioritySet(INT_UART2, USER_INT4);
}

/***********************************************************
@��������UART3_IRQHandler
@��ڲ�������
@���ڲ�������
��������������3���ݽ���
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void UART3_IRQHandler(void)
{		
  uint32_t flag = UARTIntStatus(UART3_BASE,1);//��ȡ�жϱ�־ ԭʼ�ж�״̬ �����жϱ�־		
  UARTIntClear(UART3_BASE,flag);//����жϱ�־			
  while(UARTCharsAvail(UART3_BASE))//�ж�FIFO�Ƿ�������		
  {			
		RingBuf_Write(UARTCharGet(UART3_BASE),&COM3_Rx_Buf,SDK_Target_Length*2);//�����ζ�������д����
		if(COM3_Rx_Buf.Ring_Buff[0]!=0xFF)
		{
			COM3_Rx_Buf.Head=1;
			COM3_Rx_Buf.Tail=0; 
		}	
	}	
}

/***********************************************************
@��������USART3_Send
@��ڲ�����uint8_t *pui8Buffer, uint32_t ui32Count
@���ڲ�������
��������������3����N���ֽ�����
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void USART3_Send(uint8_t *pui8Buffer, uint32_t ui32Count)//����N���ֽڳ��ȵ�����
{
  while(ui32Count--)
  {
    UARTCharPut(UART3_BASE, *pui8Buffer++);
  }
}

/***********************************************************
@��������ConfigureUART3
@��ڲ�������
@���ڲ�������
��������������3����
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void ConfigureUART3(void)//����3��ʼ��
{
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);//ʹ��GPIO����		
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART3);//ʹ��UART����
  GPIOPinConfigure(GPIO_PC6_U3RX);//GPIOģʽ���� PC6--RX PC7--TX 
  GPIOPinConfigure(GPIO_PC7_U3TX);
  GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_6 | GPIO_PIN_7);//GPIO��UARTģʽ����
  UARTConfigSetExpClk(UART3_BASE, SysCtlClockGet(), 921600,
                      (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                       UART_CONFIG_PAR_NONE));
  UARTFIFODisable(UART3_BASE);//ʹ��UART0�ж�	
  UARTIntEnable(UART3_BASE,UART_INT_RX);//ʹ��UART3�����ж�		
  UARTIntRegister(UART3_BASE,UART3_IRQHandler);//UART3�жϵ�ַע��	
  IntPrioritySet(INT_UART3, USER_INT2);
}

/***********************************************************
@��������UART6_IRQHandler
@��ڲ�������
@���ڲ�������
��������������6���ݽ���
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void UART6_IRQHandler(void)
{		
  uint32_t flag = UARTIntStatus(UART6_BASE,1);//��ȡ�жϱ�־ ԭʼ�ж�״̬ �����жϱ�־		
  UARTIntClear(UART6_BASE,flag);//����жϱ�־	
  while(UARTCharsAvail(UART6_BASE))//�ж�FIFO�Ƿ�������		
  {			
    RingBuf_Write(UARTCharGet(UART6_BASE),&COM6_Rx_Buf,FLOW_BUF_CNT);//�����ζ�������д����		
  }
}

/***********************************************************
@��������USART6_Send
@��ڲ�����uint8_t *pui8Buffer, uint32_t ui32Count
@���ڲ�������
��������������6����N���ֽ�����
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void USART6_Send(uint8_t *pui8Buffer, uint32_t ui32Count)//����N���ֽڳ��ȵ�����
{
  while(ui32Count--)
  {
    UARTCharPut(UART6_BASE, *pui8Buffer++);
  }
}

/***********************************************************
@��������ConfigureUART6
@��ڲ�������
@���ڲ�������
��������������6����
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void ConfigureUART6(void)//����6��ʼ��
{
//  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);//ʹ��GPIO����		
//  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART6);//ʹ��UART����
//  
//	HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;//����PD6
//	HWREG(GPIO_PORTD_BASE + GPIO_O_CR) |= 0x80;//ȷ��
//	HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = 0;//��������
//	
//	GPIOPinConfigure(GPIO_PD4_U6RX);//GPIOģʽ���� PD4--RX PD5--TX 
//  GPIOPinConfigure(GPIO_PD5_U6TX);
//  GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_4 | GPIO_PIN_5);//GPIO��UARTģʽ����
//  UARTConfigSetExpClk(UART6_BASE, SysCtlClockGet(), 19200,
//                      (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
//                       UART_CONFIG_PAR_NONE));
//  UARTFIFODisable(UART6_BASE);//ʹ��UART0�ж�	
//  UARTIntEnable(UART6_BASE,UART_INT_RX);//ʹ��UART6�����ж�		
//  OpticalFlow_Init();//�����˲�������ʼ��
//  
//  UARTIntRegister(UART6_BASE,UART6_IRQHandler);//UART6�жϵ�ַע��	
//  IntPrioritySet(INT_UART4, USER_INT5);
	
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);//ʹ��GPIO����		
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART2);//ʹ��UART����
  
  HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;//����PD6
  HWREG(GPIO_PORTD_BASE + GPIO_O_CR) |= 0x80;//ȷ��
  HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = 0;//��������
  
  GPIOPinConfigure(GPIO_PD6_U2RX);//GPIOģʽ���� PD6--RX PD7--TX 
  GPIOPinConfigure(GPIO_PD7_U2TX);
  GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);//GPIO��UARTģʽ����
  UARTConfigSetExpClk(UART2_BASE, SysCtlClockGet(), 19200,
                      (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                       UART_CONFIG_PAR_NONE));
  UARTFIFODisable(UART2_BASE);//ʹ��UART2�ж�	

  UARTIntEnable(UART2_BASE,UART_INT_RX);//ʹ��UART6�����ж�		
  OpticalFlow_Init();//�����˲�������ʼ��
  OpticalFlow_Is_Work=Config_Init_Uart();//������������ʼ��
	
  UARTIntRegister(UART2_BASE,UART2_IRQHandler);//UART�жϵ�ַע��	
  IntPrioritySet(INT_UART2, USER_INT5);
}

/***********************************************************
@��������UART7_IRQHandler
@��ڲ�������
@���ڲ�������
��������������7���ݽ���
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void UART7_IRQHandler(void)//UART2�жϺ���
{		
  uint32_t flag = UARTIntStatus(UART7_BASE,1);//��ȡ�жϱ�־ ԭʼ�ж�״̬ �����жϱ�־	
  UARTIntClear(UART7_BASE,flag);//����жϱ�־		
  while(UARTCharsAvail(UART7_BASE))//�ж�FIFO�Ƿ�������			
  {			
    //����õ�������			
		if(Ground_Sensor_Now_Mode==US100)					
		{
			RingBuf_Write(UARTCharGet(UART7_BASE),&COM7_Rx_Buf,4);//�����ζ�������д����
		}
		else	if(Ground_Sensor_Now_Mode==TFMINI)	
		{
			RingBuf_Write(UARTCharGet(UART7_BASE),&COM7_Rx_Buf,18);//�����ζ�������д����
			if(COM7_Rx_Buf.Ring_Buff[0]!=0x59)
			{
				COM7_Rx_Buf.Head=1;
				COM7_Rx_Buf.Tail=0; 
			}	
		}
		else	if(Ground_Sensor_Now_Mode==TOFSENSOR)	
		{
			RingBuf_Write(UARTCharGet(UART7_BASE),&COM7_Rx_Buf,32);//�����ζ�������д����
			if(COM7_Rx_Buf.Ring_Buff[0]!=0x57)
			{
				COM7_Rx_Buf.Head=1;
				COM7_Rx_Buf.Tail=0; 
			}				
		}			
  }
}

/***********************************************************
@��������USART7_Send
@��ڲ�����uint8_t *pui8Buffer, uint32_t ui32Count
@���ڲ�������
��������������7����N���ֽ�����
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void USART7_Send(uint8_t *pui8Buffer, uint32_t ui32Count)//����N���ֽڳ��ȵ�����
{
  while(ui32Count--)
  {
    UARTCharPut(UART7_BASE, *pui8Buffer++);
  }
}

/***********************************************************
@��������ConfigureUART7
@��ڲ�������
@���ڲ�������
��������������7����
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void ConfigureUART7(void)//����7��ʼ��
{
	static uint16_t state_init_cnt=0;
	ReadFlashParameterOne(GROUND_DISTANCE_DEFAULT,&ground_sensor_default);
  if(isnan(ground_sensor_default)==0)
  {
    Ground_Sensor_Now_Mode=(uint8_t)(ground_sensor_default);
    if(Ground_Sensor_Now_Mode==US100)	
		{  
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);//ʹ��GPIO����		
			SysCtlPeripheralEnable(SYSCTL_PERIPH_UART7);//ʹ��UART����
			GPIOPinConfigure(GPIO_PE0_U7RX);//GPIOģʽ���� PE0--RX PE1--TX 
			GPIOPinConfigure(GPIO_PE1_U7TX);
			GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_0 | GPIO_PIN_1);//GPIO��UARTģʽ����
			UARTConfigSetExpClk(UART7_BASE, SysCtlClockGet(), 9600,
												(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
												 UART_CONFIG_PAR_NONE));
			RingBuff_Init(&COM7_Rx_Buf); 	
			UARTFIFODisable(UART7_BASE);//ʹ��UART0�ж�	
			UARTIntEnable(UART7_BASE,UART_INT_RX);//ʹ��UART0�����ж�		
			UARTIntRegister(UART7_BASE,UART7_IRQHandler);//UART�жϵ�ַע��	
			IntPrioritySet(INT_UART7, USER_INT1);
			state_init_cnt=1;
		}
		else if(Ground_Sensor_Now_Mode==TFMINI)	
		{
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);//ʹ��GPIO����		
			SysCtlPeripheralEnable(SYSCTL_PERIPH_UART7);//ʹ��UART����
			GPIOPinConfigure(GPIO_PE0_U7RX);//GPIOģʽ���� PE0--RX PE1--TX 
			GPIOPinConfigure(GPIO_PE1_U7TX);
			GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_0 | GPIO_PIN_1);//GPIO��UARTģʽ����
			UARTConfigSetExpClk(UART7_BASE, SysCtlClockGet(), 115200,
													(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
													 UART_CONFIG_PAR_NONE));	
			RingBuff_Init(&COM7_Rx_Buf); 	
			UARTFIFODisable(UART7_BASE);//ʹ��UART0�ж�	
			UARTIntEnable(UART7_BASE,UART_INT_RX);//ʹ��UART0�����ж�		
			UARTIntRegister(UART7_BASE,UART7_IRQHandler);//UART�жϵ�ַע��	
			IntPrioritySet(INT_UART7, USER_INT1);
			state_init_cnt=1;
		}
		else if(Ground_Sensor_Now_Mode==TOFSENSOR)	
		{
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);//ʹ��GPIO����		
			SysCtlPeripheralEnable(SYSCTL_PERIPH_UART7);//ʹ��UART����
			GPIOPinConfigure(GPIO_PE0_U7RX);//GPIOģʽ���� PE0--RX PE1--TX 
			GPIOPinConfigure(GPIO_PE1_U7TX);
			GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_0 | GPIO_PIN_1);//GPIO��UARTģʽ����
			UARTConfigSetExpClk(UART7_BASE, SysCtlClockGet(), 921600,
													(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
													 UART_CONFIG_PAR_NONE));	
			RingBuff_Init(&COM7_Rx_Buf); 	
			UARTFIFODisable(UART7_BASE);//ʹ��UART0�ж�	
			UARTIntEnable(UART7_BASE,UART_INT_RX);//ʹ��UART0�����ж�		
			UARTIntRegister(UART7_BASE,UART7_IRQHandler);//UART�жϵ�ַע��	
			IntPrioritySet(INT_UART7, USER_INT1);
			state_init_cnt=1;
		}
		else if(Ground_Sensor_Now_Mode==VL53L1X)
		{
      if(state_init_cnt==0)	 VL53L1Init(&VL53);
		}			
  }
	else//Ĭ�ϲ���US100
	{
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);//ʹ��GPIO����		
			SysCtlPeripheralEnable(SYSCTL_PERIPH_UART7);//ʹ��UART����
			GPIOPinConfigure(GPIO_PE0_U7RX);//GPIOģʽ���� PE0--RX PE1--TX 
			GPIOPinConfigure(GPIO_PE1_U7TX);
			GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_0 | GPIO_PIN_1);//GPIO��UARTģʽ����
			UARTConfigSetExpClk(UART7_BASE, SysCtlClockGet(), 9600,
												(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
												 UART_CONFIG_PAR_NONE));
			RingBuff_Init(&COM7_Rx_Buf); 	
			UARTFIFODisable(UART7_BASE);//ʹ��UART0�ж�	
			UARTIntEnable(UART7_BASE,UART_INT_RX);//ʹ��UART0�����ж�		
			UARTIntRegister(UART7_BASE,UART7_IRQHandler);//UART�жϵ�ַע��	
			IntPrioritySet(INT_UART7, USER_INT1);
			state_init_cnt=1;
	}

}



/***********************************************************
@��������Vcan_Send
@��ڲ�������
@���ڲ�������
����������ɽ�����ݷ��ͺ�����Ĭ�Ϸ���8��ͨ������������Ϊfloat
��ÿ��ͨ�����ݿ����Լ�����
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void Vcan_Send(void)//ɽ�����վ����
{
  static float DataBuf[8];	

	DataBuf[0]=Pitch;
  DataBuf[1]=Roll;
  DataBuf[2]=Yaw;
  DataBuf[3]=Pitch_Observation;
  DataBuf[4]=Roll_Observation;
  DataBuf[5]=Yaw_Observation;
  DataBuf[6]=0;
  DataBuf[7]=0;


//  DataBuf[0]=NamelessQuad.Position[_YAW];//�ߵ��߶�
//  DataBuf[1]=NamelessQuad.Speed[_YAW];//�ߵ��ٶ�
//  DataBuf[2]=Observation_Altitude;//NamelessQuad.Acceleration[_YAW];;//�ߵ����ٶ�
//  DataBuf[3]=NamelessQuad.Acceleration[_YAW];//��ѹ�Ƹ߶�
//	DataBuf[4]=Origion_NamelessQuad.Acceleration[_YAW];
//  DataBuf[5]=NamelessQuad.Acce_Bias[_YAW];//acc_correction[_YAW];
//  DataBuf[6]=vel_correction[_YAW];
//	DataBuf[7]=vl52l1x_result_data.RangeMilliMeter/10.0;
	
/*
//	DataBuf[0]=Accel_X_Butter_Filter.output[Accel_X_Butter_Filter.N-1];;
//  DataBuf[1]=Accel_Y_Butter_Filter.output[Accel_Y_Butter_Filter.N-1];;
//  DataBuf[2]=Accel_Z_Butter_Filter.output[Accel_Z_Butter_Filter.N-1];;
//  DataBuf[3]=accel.x;
//	DataBuf[4]=accel.y;
//  DataBuf[5]=accel.z;
	
	
  
  DataBuf[0]=GPS_Vel_Div.E;//�ߵ��߶�
  DataBuf[1]=GPS_Vel_Div.N;//�ߵ��ٶ�
  DataBuf[2]=NamelessQuad.Acceleration[_PITCH];;//�ߵ����ٶ�
  DataBuf[3]=NamelessQuad.Acceleration[_ROLL];;//�ߵ����ٶ�
  DataBuf[4]=0;//�ߵ��߶�;
  DataBuf[5]=0;
  DataBuf[6]=0;
  DataBuf[7]=0;   
  */
  //2      
  /*
	DataBuf[0]=opt_gyro_filter_data.x;
	DataBuf[1]=opt_gyro_filter_data.y;
	DataBuf[2]=0;
	DataBuf[3]=OpticalFlow_SINS.Speed[_PITCH];
	DataBuf[4]=OpticalFlow_SINS.Position[_PITCH];
	DataBuf[5]=OpticalFlow_Speed.x;
	DataBuf[6]=OpticalFlow_Position.x;
	DataBuf[7]=OpticalFlow_SINS.Acceleration[_PITCH];   
  
	
  DataBuf[0]=gyro_filter_data.x;//Pitch X
  DataBuf[1]=gyro_filter_data.y;//Roll R
  DataBuf[2]=opt_gyro_data.x;
  DataBuf[3]=opt_gyro_data.y;
  DataBuf[4]=opt_filter_data.x;
  DataBuf[5]=opt_filter_data.y;
  DataBuf[6]=opt_gyro_filter_data.x;
  DataBuf[7]=opt_gyro_filter_data.y;
  

  DataBuf[0]=PPM_Databuf[0];
  DataBuf[1]=PPM_Databuf[1];
  DataBuf[2]=PPM_Databuf[2];
  DataBuf[3]=PPM_Databuf[3];
  DataBuf[4]=PPM_LPF_Databuf[0];
  DataBuf[5]=PPM_LPF_Databuf[1];
  DataBuf[6]=Total_Controller.Pitch_Gyro_Control.Dis_Err;
  DataBuf[7]=Total_Controller.Pitch_Gyro_Control.Dis_Error_History[0];
  */
  //3
   /*
  DataBuf[0]=NamelessQuad.Position[_PITCH];
  DataBuf[1]=NamelessQuad.Speed[_PITCH];
  DataBuf[2]=GPS_Vel.E;
  DataBuf[3]=Earth_Frame_To_XYZ.E;
  DataBuf[4]=NamelessQuad.Position[_ROLL];
  DataBuf[5]=NamelessQuad.Speed[_ROLL];
  DataBuf[6]=GPS_Vel.N;
  DataBuf[7]=Earth_Frame_To_XYZ.N;
 
  DataBuf[0]=NamelessQuad.Position[_PITCH];
  DataBuf[1]=0;
  DataBuf[2]=NamelessQuad.Position[_ROLL];
  DataBuf[3]=0;
  DataBuf[4]=GPS_Ground_Speed;
  DataBuf[5]=sqrt(NamelessQuad.Speed[_PITCH]*NamelessQuad.Speed[_PITCH]+NamelessQuad.Speed[_ROLL]*NamelessQuad.Speed[_ROLL]);
  DataBuf[6]=0;
  DataBuf[7]=NamelessQuad.Position[_YAW];//�ߵ��߶�

  DataBuf[0]=PPM_Databuf[0];
	DataBuf[1]=PPM_Databuf[1];
	DataBuf[2]=PPM_Databuf[2];
	DataBuf[3]=PPM_Databuf[3];
	DataBuf[4]=PPM_LPF_Databuf[0];
	DataBuf[5]=PPM_LPF_Databuf[1];
	DataBuf[6]=PPM_LPF_Databuf[2];
	DataBuf[7]=PPM_LPF_Databuf[3];
	 */
  wust_sendware((unsigned char *)DataBuf,sizeof(DataBuf));
}




