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
#include "I2C.h"
#include "WP_DataType.h"
#include "QMC5883.h"


uint8_t QMC5883L_Read_Reg(uint8_t reg)
{
	return Single_ReadI2C0(QMC5883L_RD_ADDRESS,reg); 
}

void QMC5883L_Write_Reg(uint8_t reg, uint8_t data)
{
	Single_WriteI2C0(QMC5883L_WR_ADDRESS,reg,data);
}


void QMC5883L_Read_Data(int16_t *MagX,int16_t *MagY,int16_t *MagZ) // (-32768 / +32768)
{
	*MagX=((int16_t)QMC5883L_Read_Reg(QMC5883L_DATA_READ_X_LSB) | (((int16_t)QMC5883L_Read_Reg(QMC5883L_DATA_READ_X_MSB))<<8));
	*MagY=((int16_t)QMC5883L_Read_Reg(QMC5883L_DATA_READ_Y_LSB) | (((int16_t)QMC5883L_Read_Reg(QMC5883L_DATA_READ_Y_MSB))<<8));
	*MagZ=((int16_t)QMC5883L_Read_Reg(QMC5883L_DATA_READ_Z_LSB) | (((int16_t)QMC5883L_Read_Reg(QMC5883L_DATA_READ_Z_MSB))<<8));
}


int16_t QMC5883L_Read_Temperature()
{
	return (((int16_t)QMC5883L_Read_Reg(QMC5883L_TEMP_READ_LSB)) | (((int16_t)QMC5883L_Read_Reg(QMC5883L_TEMP_READ_MSB))<<8))/100;
}


void QMC5883L_Initialize(_qmc5883l_MODE MODE,_qmc5883l_ODR ODR,_qmc5883l_RNG RNG,_qmc5883l_OSR OSR)
{
	QMC5883L_Write_Reg(QMC5883L_CONFIG_3,0x01);
	QMC5883L_Write_Reg(QMC5883L_CONFIG_1,MODE | ODR | RNG | OSR);
}

void QMC5883L_Reset()
{
	QMC5883L_Write_Reg(QMC5883L_CONFIG_2,0x81);
}

void QMC5883L_InterruptConfig(_qmc5883l_INT INT)
{
	if(INT==INTERRUPT_ENABLE){QMC5883L_Write_Reg(QMC5883L_CONFIG_2,0x00);}
	else {QMC5883L_Write_Reg(QMC5883L_CONFIG_2,0x01);}
}


_qmc5883l_status QMC5883L_DataIsReady()
{
	uint8_t Buffer=QMC5883L_Read_Reg(QMC5883L_STATUS);
	if((Buffer&0x00)==0x00)	  {return NO_NEW_DATA;}
	else if((Buffer&0x01)==0X01){return NEW_DATA_IS_READY;}
	return NORMAL;
}

_qmc5883l_status QMC5883L_DataIsSkipped()
{
	uint8_t Buffer=QMC5883L_Read_Reg(QMC5883L_STATUS);
	if((Buffer&0x00)==0X00)	  {return NORMAL;}
	else if((Buffer&0x04)==0X04){return DATA_SKIPPED_FOR_READING;}
		return NORMAL;
}

_qmc5883l_status QMC5883L_DataIsOverflow()
{
	uint8_t Buffer=QMC5883L_Read_Reg(QMC5883L_STATUS);
	if((Buffer&0x00)==0X00)	  {return NORMAL;}
	else if((Buffer&0x02)==0X02){return DATA_OVERFLOW;}
		return NORMAL;
}


void QMC5883L_ResetCalibration() 
{ 
	Xmin=Xmax=Ymin=Ymax=0;
} 

 
float QMC5883L_Heading(int16_t Xraw,int16_t Yraw,int16_t Zraw) 
{ 
   float X=Xraw,Y=Yraw,Z=Zraw; 
   float Heading;
   if(X<Xmin) {Xmin = X;} 
   else if(X>Xmax) {Xmax = X;} 
   if(Y<Ymin) {Ymin = Y;} 
   else if(Y>Ymax) {Ymax = Y;} 
   
   if( Xmin==Xmax || Ymin==Ymax ) {return 0.0;} 
 	 X -= (Xmax+Xmin)/2; 
   Y -= (Ymax+Ymin)/2; 
   X = X/(Xmax-Xmin); 
   Y = Y/(Ymax-Ymin); 
   Heading = atan2(Y,X); 
		//EAST
	 Heading += QMC5883L_DECLINATION_ANGLE;
	//WEST
	//Heading -= QMC5883L_DECLINATION_ANGLE;	
if(Heading <0)
{Heading += 2*M_PI;}
else if(Heading > 2*M_PI)
{Heading -= 2*M_PI;}
return Heading; 
} 


void QMC5883L_Scale(int16_t *X,int16_t *Y,int16_t *Z)
{
	*X*=QMC5883L_SCALE_FACTOR;
	*Y*=QMC5883L_SCALE_FACTOR;
	*Z*=QMC5883L_SCALE_FACTOR;
}


void QMC5883L_Init(void)
{
	QMC5883L_Reset();
	delay_ms(5);
  QMC5883L_Initialize(MODE_CONTROL_CONTINUOUS,OUTPUT_DATA_RATE_200HZ,FULL_SCALE_8G,OVER_SAMPLE_RATIO_64);
}
