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
#include "VL53L1X_i2c.h"

void VL53L1_I2C_Init(void)
{
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	
  GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_1);
  GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_0);
	GPIOPadConfigSet(GPIO_PORTE_BASE,GPIO_PIN_1,GPIO_STRENGTH_12MA,GPIO_PIN_TYPE_STD);
	GPIOPadConfigSet(GPIO_PORTE_BASE,GPIO_PIN_0,GPIO_STRENGTH_12MA,GPIO_PIN_TYPE_STD);
	
  Delay_Ms(10);
  GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, GPIO_PIN_1);//���ø�
  GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0, GPIO_PIN_0);//���ø�
}

void VL53L1_SDA_OUT(void)
{
	GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_0);
	GPIOPadConfigSet(GPIO_PORTE_BASE,GPIO_PIN_0,GPIO_STRENGTH_12MA,GPIO_PIN_TYPE_STD);///GPIO_PIN_TYPE_STD);
}

void VL53L1_SDA_IN(void)
{
  GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_0);
	GPIOPadConfigSet(GPIO_PORTE_BASE,GPIO_PIN_0,GPIO_STRENGTH_12MA,GPIO_PIN_TYPE_STD_WPU);
}

#define STATUS_OK       0x00
#define STATUS_FAIL     0x01
#define VL_SDA_IN()  VL53L1_SDA_IN()
#define VL_SDA_OUT() VL53L1_SDA_OUT()
#define VL_IIC_SCL_H GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1,GPIO_PIN_1)//SCL  
#define VL_IIC_SCL_L GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1,0)//SCL
#define VL_IIC_SDA_H GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_0,GPIO_PIN_0)//SDA 
#define VL_IIC_SDA_L GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_0,0)//SDA 
//#define VL_READ_SDA  GPIOPinRead(GPIO_PORTE_BASE,GPIO_PIN_0)
#define VL_READ_SDA  (*((volatile uint32_t *)(GPIO_PORTE_BASE + (GPIO_O_DATA + (GPIO_PIN_0 << 2)))))


void DelayUs(uint16_t n)		//need tested arrcoding to system clock, for 30Mhz a slight slow 
{
	uint16_t i;
	while(n)
	{
		i=2;
		while(i)
			i--;
		n--;
	}
}


void VL_IIC_Start(void)
{
	VL_SDA_OUT();//sda�����
	VL_IIC_SDA_H;	  	  
	VL_IIC_SCL_H;
	//DelayUs(4);
 	VL_IIC_SDA_L;//START:when CLK is high,DATA change form high to low 
	//DelayUs(4);
	VL_IIC_SCL_L;//ǯסI2C���ߣ�׼�����ͻ�������� 
}

//����IICֹͣ�ź�
void VL_IIC_Stop(void)
{
	VL_SDA_OUT();//sda�����
	VL_IIC_SCL_L;
	VL_IIC_SDA_L;//STOP:when CLK is high DATA change form low to high
 	//DelayUs(4);
	VL_IIC_SCL_H; 
	VL_IIC_SDA_H;//����I2C���߽����ź�
	//DelayUs(4);							   	
}

u8 VL_IIC_Wait_Ack(void)
{
	u8 ucErrTime=0;
	VL_IIC_SDA_H;
	DelayUs(1);	   
	VL_IIC_SCL_H;
	DelayUs(1);
  VL_SDA_IN();  //SDA����Ϊ���� 	 
	while(VL_READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			VL_IIC_Stop();
			return 1;
		}
	}
	VL_IIC_SCL_L;//ʱ�����0 	   
	return 0;  
}

//����ACKӦ��
void VL_IIC_Ack(void)
{
	VL_IIC_SCL_L;
	VL_SDA_OUT();
	VL_IIC_SDA_L;
	DelayUs(1);//DelayUs(2);
	VL_IIC_SCL_H;
	DelayUs(1);//DelayUs(2);
	VL_IIC_SCL_L;
}

//������ACKӦ��		    
void VL_IIC_NAck(void)
{
	VL_IIC_SCL_L;
	VL_SDA_OUT();
	VL_IIC_SDA_H;
	DelayUs(1);//DelayUs(2);
	VL_IIC_SCL_H;
	DelayUs(1);//DelayUs(2);
	VL_IIC_SCL_L;
}

//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void VL_IIC_Send_Byte(u8 txd)
{                        
    u8 t;   
	  VL_SDA_OUT(); 	    
    VL_IIC_SCL_L;//����ʱ�ӿ�ʼ���ݴ���
    for(t=0;t<8;t++)
    {              
			if((txd&0x80)>>7)	VL_IIC_SDA_H;
			else	VL_IIC_SDA_L;
			txd<<=1; 	  
			DelayUs(1);//DelayUs(2);  
			VL_IIC_SCL_H;
			DelayUs(1);//DelayUs(2); 
			VL_IIC_SCL_L;	
			DelayUs(1);//DelayUs(2);
    }	 
} 

//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
u8 VL_IIC_Read_Byte(void)
{
	unsigned char i,receive=0;
	VL_IIC_SDA_H;
	VL_SDA_IN();//SDA����Ϊ����
	//DelayUs(4);
	for(i=0;i<8;i++)
	{
		receive<<=1;
		VL_IIC_SCL_L; 
		DelayUs(1);//DelayUs(4);
	  VL_IIC_SCL_H;
		DelayUs(1);//DelayUs(4);
		if(VL_READ_SDA)
			receive |= 0x01;   
	  DelayUs(1);//DelayUs(4);
	}	
  VL_IIC_SCL_L;	
	return receive;
}

//IICдһ���ֽ�����
u8 VL_IIC_Write_1Byte(u8 SlaveAddress, u16 REG_Address,u8 REG_data)
{
	VL_IIC_Start();
	VL_IIC_Send_Byte(SlaveAddress);
	if(VL_IIC_Wait_Ack())
	{
		VL_IIC_Stop();//�ͷ�����
		return 1;//ûӦ�����˳�
	}
	VL_IIC_Send_Byte(REG_Address >> 8);
	VL_IIC_Wait_Ack();	
	VL_IIC_Send_Byte(REG_Address & 0x00ff);
	VL_IIC_Wait_Ack();
	//DelayUs(500);
	VL_IIC_Send_Byte(REG_data);
	VL_IIC_Wait_Ack();	
	VL_IIC_Stop();

	return 0;
}

//IIC��һ���ֽ�����
u8 VL_IIC_Read_1Byte(u8 SlaveAddress, u16 REG_Address,u8 *REG_data)
{
	VL_IIC_Start();
	VL_IIC_Send_Byte(SlaveAddress);//��д����
	if(VL_IIC_Wait_Ack())
	{
		 VL_IIC_Stop();//�ͷ�����
		 return 1;//ûӦ�����˳�
	}		
	VL_IIC_Send_Byte(REG_Address >> 8);
	VL_IIC_Wait_Ack();
	VL_IIC_Send_Byte((REG_Address & 0x00ff));
	VL_IIC_Wait_Ack();
	//DelayUs(500);
	VL_IIC_Start(); 
	VL_IIC_Send_Byte(SlaveAddress|0x01);//��������
	VL_IIC_Wait_Ack();
	*REG_data = VL_IIC_Read_Byte();
	VL_IIC_Stop();

	return 0;
}

//I2C read n bytes
uint8_t VL_I2C_Read_nByte(uint8_t SlaveAddress, uint16_t REG_Address, uint8_t *buf, uint16_t len)
{
	VL_IIC_Start();
	VL_IIC_Send_Byte(SlaveAddress);//��д����
	if(VL_IIC_Wait_Ack()) 
	{
		VL_IIC_Stop();//�ͷ�����
		return 1;//ûӦ�����˳�
	}
	VL_IIC_Send_Byte(REG_Address >> 8);
	VL_IIC_Wait_Ack();
	VL_IIC_Send_Byte((REG_Address & 0x00ff));
	VL_IIC_Wait_Ack();
	//DelayUs(500);
	VL_IIC_Start(); 
	VL_IIC_Send_Byte(SlaveAddress|0x01);//��������
	VL_IIC_Wait_Ack();
	while(len)
	{
		*buf = VL_IIC_Read_Byte();
		if(1 == len)
		{
			VL_IIC_NAck();
		}
		else
		{
			VL_IIC_Ack();
		}
		buf++;
		len--;
	}
	VL_IIC_Stop();
	return STATUS_OK;
}

//I2C write n bytes
uint8_t VL_I2C_Write_nByte(uint8_t SlaveAddress, uint16_t REG_Address, uint8_t *buf, uint16_t len)
{
	VL_IIC_Start();
	VL_IIC_Send_Byte(SlaveAddress);//��д����
	if(VL_IIC_Wait_Ack()) 
	{
		VL_IIC_Stop();//�ͷ�����
		return 1;//ûӦ�����˳�
	}
	VL_IIC_Send_Byte(REG_Address >> 8);
	VL_IIC_Wait_Ack();
	VL_IIC_Send_Byte(REG_Address & 0x00ff);
	VL_IIC_Wait_Ack();
	while(len--)
	{
		VL_IIC_Send_Byte(*buf++);
		VL_IIC_Wait_Ack();
	}
	VL_IIC_Stop();
	return STATUS_OK;
}
//VL53L1X wrtie multi data
//address: device addr
//index: reg addr
//pdata
//count
uint8_t VL53L1_write_multi(uint8_t address, uint16_t index, uint8_t *pdata, uint16_t count)
{
	uint8_t status = STATUS_OK;
	
	if(VL_I2C_Write_nByte(address,index,pdata,count))
	   status  = STATUS_FAIL;

	return status;
}


//VL53L1X read multi data
//address: dev addr
//index: reg addr
//pdata
//count
uint8_t VL53L1_read_multi(uint8_t address,uint16_t index,uint8_t *pdata,uint16_t count)
{
	uint8_t status = STATUS_OK;

	if(VL_I2C_Read_nByte(address,index,pdata,count))
	  status  = STATUS_FAIL;

	return status;
}

//VL53L1X write 1 byte
//address: dev addr
//index: reg addr
//data (8 bits)
uint8_t VL53L1_write_byte(uint8_t address,uint16_t index,uint8_t data)
{
	uint8_t status = STATUS_OK;

	status = VL53L1_write_multi(address,index,&data,1);

	return status;
}

//VL53L1X write 1 word (2 bytes)
//address: dev addr
//index: reg addr
//data (16 bits)
uint8_t VL53L1_write_word(uint8_t address, uint16_t index, uint16_t data)
{
	uint8_t status = STATUS_OK;
	
	uint8_t buf[2];
	
	buf[0] = (uint8_t)(data >> 8);	//H
	buf[1] = (uint8_t)(data & 0xff);	//L
	
	if(index % 2 == 1)
	{
		status = VL53L1_write_multi(address,index,&buf[0],1);
		status = VL53L1_write_multi(address,index,&buf[0],1);
	}
	status = VL53L1_write_multi(address,index,buf,2);
	
	return status;
}

//VL53L1X a dword(4 bytes)
//address: dev addr
//index: reg addr
//data (32 bits)
uint8_t VL53L1_write_dword(uint8_t address, uint16_t index, uint32_t data)
{
  uint8_t status = STATUS_OK;

  uint8_t buf[4];	
	
	buf[0] = (uint8_t)(data >> 24);
	buf[1] = (uint8_t)((data & 0xff0000) >> 16);
	buf[2] = (uint8_t)((data & 0xff00) >> 8);
	buf[3] = (uint8_t)(data & 0xff);
	
	status = VL53L1_write_multi(address,index,buf,4);
	
	return status;
}


//VL53L1X read 1 byte
//address: dev addr
//index: reg addr
//data (8 bits)
uint8_t VL53L1_read_byte(uint8_t address, uint16_t index, uint8_t *pdata)
{
	uint8_t status = STATUS_OK;
	 
	status = VL53L1_read_multi(address, index, pdata, 1);
	return status;
}

//VL53L1X read a word
//address: dev addr
//index: reg addr
//data (16 bits)
uint8_t VL53L1_read_word(uint8_t address, uint16_t index, uint16_t *pdata)
{
	uint8_t status = STATUS_OK;
	uint8_t buf[2];
	
	status = VL53L1_read_multi(address, index, buf, 2);
	*pdata = ((uint16_t)buf[0] << 8)+(uint16_t)buf[1];
	
	return status;
}

//VL53L1X read a dword
//address: dev addr
//index: reg addr
//data (32 bits)
uint8_t VL53L1_read_dword(uint8_t address, uint16_t index, uint32_t *pdata)
{
	uint8_t status = STATUS_OK;
	
	uint8_t buf[4];
	
	status = VL53L1_read_multi(address,index,buf,4);
	
	*pdata = ((uint32_t)buf[0] << 24)+((uint32_t)buf[1] << 16)+((uint32_t)buf[2] << 8)+((uint32_t)buf[3]);
	
	return status;
}



