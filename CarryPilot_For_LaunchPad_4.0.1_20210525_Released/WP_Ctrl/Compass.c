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
#include "Compass.h"
#include "MMC3630.h"


#define MAG_EXTERNAL_ENABLE  1//�������ⲿ������ʱʹ��1
#define MAG_EXTERNAL_IST8310 0
#define MAG_EXTERNAL_QMC5883 1
#define MAG_EXTERNAL_MMC3630 2
#define MAG_EXTERNAL_TYPE    MAG_EXTERNAL_QMC5883//MAG_EXTERNAL_IST8310 



#define GPS_QMC5883_ENABLE 0//ʹ����������GPS���Դ��Ĵ�����ʱ��ʹ��1



void Compass_Init(void)
{
#if (!MAG_EXTERNAL_ENABLE)//���ô�����IST8310
	Single_WriteI2C(IST8310_SLAVE_ADDRESS,0x41,0x24);//����16x�ڲ�ƽ��
	Single_WriteI2C(IST8310_SLAVE_ADDRESS,0x42,0xC0);//Set/Reset�ڲ�ƽ��
	Single_WriteI2C(IST8310_SLAVE_ADDRESS,IST8310_REG_CNTRL1,0x01);//Single Measurement Mode
#else  										//���ô�����IST8310��QMC5883
  I2C_GPIO_Config();
	Delay_Ms(10);
	if(MAG_EXTERNAL_TYPE==MAG_EXTERNAL_QMC5883) 			QMC5883L_Init();
	else if(MAG_EXTERNAL_TYPE==MAG_EXTERNAL_MMC3630) {MMC3630KJ_Initialization();}
  else		
	{
		Single_WriteI2C0(IST8310_SLAVE_ADDRESS,0x41,0x24);//����16x�ڲ�ƽ��
	  Single_WriteI2C0(IST8310_SLAVE_ADDRESS,0x42,0xC0);//Set/Reset�ڲ�ƽ��
		Single_WriteI2C0(IST8310_SLAVE_ADDRESS,IST8310_REG_CNTRL1,0x01);//Single Measurement Mode
	}
#endif	
	Set_Cutoff_Frequency(40, 18,&Mag_Parameter);//������У׼�Ӽ��˲�ֵ	
}

Testime T3,T4;
float S1=0;
/***********************************************************
@��������Compass_Read_Data
@��ڲ�����vector3f *mag
@���ڲ�������
�������������������ݲɼ�״̬��
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
uint8_t Compass_Read_Data(vector3f *mag)//��ȡ����������״̬��
{
  static uint16_t compass_sampling_cnt=0;
  uint8_t buf[6];
  compass_sampling_cnt++;
  if(compass_sampling_cnt==1)
  {
#if (!MAG_EXTERNAL_ENABLE)//����ӳ���������������
    Single_WriteI2C(IST8310_SLAVE_ADDRESS,IST8310_REG_CNTRL1,0x01);//Single Measurement Mode
#else	
		if(MAG_EXTERNAL_TYPE==MAG_EXTERNAL_IST8310)	Single_WriteI2C0(IST8310_SLAVE_ADDRESS,IST8310_REG_CNTRL1,0x01);//Single Measurement Mode
		
		if(MAG_EXTERNAL_TYPE==MAG_EXTERNAL_MMC3630)	
		{
			//MMC3630KJ_SET();/* if sample rate is 50Hz, so here do SET action every 5 seconds*/
			/* Write 0x08 to register 0x08, set SET bit high */
			//Single_WriteI2C0(MMC3630KJ_7BITI2C_ADDRESS, MMC3630KJ_REG_CTRL0, MMC3630KJ_CMD_SET);
		}
#endif		
  }
  else if(compass_sampling_cnt>=50/WP_Duty_Dt_Ms)//50ms
  {
#if (!MAG_EXTERNAL_ENABLE)//����ӳ���������������
    buf[0]=Single_ReadI2C(IST8310_SLAVE_ADDRESS,0x03);//OUT_X_L_A
    buf[1]=Single_ReadI2C(IST8310_SLAVE_ADDRESS,0x04);//OUT_X_H_A
    buf[2]=Single_ReadI2C(IST8310_SLAVE_ADDRESS,0x05);//OUT_Y_L_A
    buf[3]=Single_ReadI2C(IST8310_SLAVE_ADDRESS,0x06);//OUT_Y_H_A
    buf[4]=Single_ReadI2C(IST8310_SLAVE_ADDRESS,0x07);//OUT_Z_L_A
    buf[5]=Single_ReadI2C(IST8310_SLAVE_ADDRESS,0x08);//OUT_Z_H_A
    mag->x= (int16_t)((buf[1]<<8)|buf[0])/330;
    mag->y=-(int16_t)((buf[3]<<8)|buf[2])/330;
    mag->z= (int16_t)((buf[5]<<8)|buf[4])/330;
#else	
		Test_Period(&T3);//������̬����
		if(MAG_EXTERNAL_TYPE==MAG_EXTERNAL_QMC5883)
		{
			buf[0]=Single_ReadI2C0(QMC5883L_RD_ADDRESS,QMC5883L_DATA_READ_X_LSB);//OUT_X_L_A
			buf[1]=Single_ReadI2C0(QMC5883L_RD_ADDRESS,QMC5883L_DATA_READ_X_MSB);//OUT_X_H_A
			buf[2]=Single_ReadI2C0(QMC5883L_RD_ADDRESS,QMC5883L_DATA_READ_Y_LSB);//OUT_Y_L_A
			buf[3]=Single_ReadI2C0(QMC5883L_RD_ADDRESS,QMC5883L_DATA_READ_Y_MSB);//OUT_Y_H_A
			buf[4]=Single_ReadI2C0(QMC5883L_RD_ADDRESS,QMC5883L_DATA_READ_Z_LSB);//OUT_Z_L_A
			buf[5]=Single_ReadI2C0(QMC5883L_RD_ADDRESS,QMC5883L_DATA_READ_Z_MSB);//OUT_Z_H_A
//			mag->y= (int16_t)((buf[1]<<8)|buf[0])/QMC5883L_CONVERT_GAUSS_8G;
//			mag->x= (int16_t)((buf[3]<<8)|buf[2])/QMC5883L_CONVERT_GAUSS_8G;
//			mag->z=-(int16_t)((buf[5]<<8)|buf[4])/QMC5883L_CONVERT_GAUSS_8G;
			mag->x= (float)((int16_t)((buf[1]<<8)|buf[0])/QMC5883L_CONVERT_GAUSS_8G);
			mag->y= (float)((int16_t)((buf[3]<<8)|buf[2])/QMC5883L_CONVERT_GAUSS_8G);
			mag->z= (float)((int16_t)((buf[5]<<8)|buf[4])/QMC5883L_CONVERT_GAUSS_8G);
			

#if GPS_QMC5883_ENABLE
				float tmp_x,tmp_y,tmp_z;
				tmp_x=mag->x;tmp_y=mag->y;tmp_z=mag->z;
				mag->x=tmp_x;
				mag->y=-tmp_y;
				mag->z=-tmp_z;
#endif

		}
		else if(MAG_EXTERNAL_TYPE==MAG_EXTERNAL_IST8310)
		{
			i2c0ReadNByte(IST8310_SLAVE_ADDRESS,0x03,buf,6);			
//			buf[0]=Single_ReadI2C0(IST8310_SLAVE_ADDRESS,0x03);//OUT_X_L_A
//			buf[1]=Single_ReadI2C0(IST8310_SLAVE_ADDRESS,0x04);//OUT_X_H_A
//			buf[2]=Single_ReadI2C0(IST8310_SLAVE_ADDRESS,0x05);//OUT_Y_L_A
//			buf[3]=Single_ReadI2C0(IST8310_SLAVE_ADDRESS,0x06);//OUT_Y_H_A
//			buf[4]=Single_ReadI2C0(IST8310_SLAVE_ADDRESS,0x07);//OUT_Z_L_A
//			buf[5]=Single_ReadI2C0(IST8310_SLAVE_ADDRESS,0x08);//OUT_Z_H_A
			mag->x=(float)( (int16_t)((buf[1]<<8)|buf[0])/330.0f);
			mag->y=(float)(-(int16_t)((buf[3]<<8)|buf[2])/330.0f);
			mag->z=(float)( (int16_t)((buf[5]<<8)|buf[4])/330.0f);			
		}
		else if(MAG_EXTERNAL_TYPE==MAG_EXTERNAL_MMC3630)
		{
			uint16_t dataTemp[3];
			uint16_t rawData[3];			
			i2c0ReadNByte(MMC3630KJ_7BITI2C_ADDRESS,MMC3630KJ_REG_XL,buf,6);
//			buf[0]=Single_ReadI2C0(MMC3630KJ_7BITI2C_ADDRESS,MMC3630KJ_REG_XL);//OUT_X_L_A
//			buf[1]=Single_ReadI2C0(MMC3630KJ_7BITI2C_ADDRESS,MMC3630KJ_REG_XH);//OUT_X_H_A
//			buf[2]=Single_ReadI2C0(MMC3630KJ_7BITI2C_ADDRESS,MMC3630KJ_REG_YL);//OUT_Y_L_A
//			buf[3]=Single_ReadI2C0(MMC3630KJ_7BITI2C_ADDRESS,MMC3630KJ_REG_YH);//OUT_Y_H_A
//			buf[4]=Single_ReadI2C0(MMC3630KJ_7BITI2C_ADDRESS,MMC3630KJ_REG_ZL);//OUT_Z_L_A
//			buf[5]=Single_ReadI2C0(MMC3630KJ_7BITI2C_ADDRESS,MMC3630KJ_REG_ZH);//OUT_Z_H_A
			
			dataTemp[0] = (uint16_t)buf[1] << 8 | buf[0];
			dataTemp[1] = (uint16_t)buf[3] << 8 | buf[2];	
			dataTemp[2] = (uint16_t)buf[5] << 8 | buf[4];
						
			rawData[0] = dataTemp[0];
			rawData[1] = dataTemp[1] - dataTemp[2] + 32768;
			rawData[2] = dataTemp[1] + dataTemp[2] - 32768;
			
			mag->x = ((float)rawData[0] - MMC3630KJ_OFFSET);///MMC3630KJ_SENSITIVITY; //unit Gauss;
			mag->y = ((float)rawData[1] - MMC3630KJ_OFFSET);///MMC3630KJ_SENSITIVITY; //unit Gauss;
			mag->z = ((float)rawData[2] - MMC3630KJ_OFFSET);///MMC3630KJ_SENSITIVITY; //unit Gauss;
			
			mag->x*=fOtpMatrix[0];
			mag->y*=fOtpMatrix[1];
			mag->z*=(-fOtpMatrix[2]);
			Single_WriteI2C0(MMC3630KJ_7BITI2C_ADDRESS,MMC3630KJ_REG_CTRL0, MMC3630KJ_CMD_TM_M);
		}
		Test_Period(&T4);
		S1=T4.Now_Time-T3.Now_Time;
#endif			
    compass_sampling_cnt=0;
    return 1;
  }
  return 0;
}

uint16_t compass_fault_cnt=0;
void Compass_Fault_Check(void)
{ 
    
  static uint16_t compass_gap_cnt=0;
  compass_gap_cnt++;
  if(compass_gap_cnt>=40)//ÿ200ms���һ�Σ���Ϊ�����Ƹ������ڴ���5ms
  {
    compass_gap_cnt=0;
    if(WP_Sensor.last_mag_raw.x==WP_Sensor.mag_raw.x
       &&WP_Sensor.last_mag_raw.y==WP_Sensor.mag_raw.y
         &&WP_Sensor.last_mag_raw.z==WP_Sensor.mag_raw.z)
    {
      compass_fault_cnt++;
      if(compass_fault_cnt>10)  Sensor_Flag.Mag_Health=FALSE;//���������ݲ�����   
    }
    else
    {
      compass_fault_cnt/=2;
      if(compass_fault_cnt==0)  Sensor_Flag.Mag_Health=TRUE; 
    }
		WP_Sensor.last_mag_raw=WP_Sensor.mag_raw;
  }
}

