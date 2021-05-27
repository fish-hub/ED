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
#include "myiic.h"
#include "mpu6050.h"
Butter_Parameter Ins_Accel_Parameter;
Butter_Parameter Accel_Parameter;
Butter_Parameter Gyro_Parameter;
Butter_Parameter Calibrate_Parameter;
uint8_t IMU_ID=0x68; 


uint8_t IMU_Config_Write[6]={
	0x00,//PWR_MGMT_1
	0x00,//SMPLRT_DIV	
	0x02,//MPU_CONFIG
	0x08,//GYRO_CONFIG
	0x08,//ACCEL_CONFIG
	0x03//ACCEL_CONFIG2
};
uint8_t IMU_Config_Read[6];
/***********************************************************
@��������Init_MPU6050
@��ڲ�������
@���ڲ�������
����������MPU6050��ʼ��
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
uint8_t MPU6050_Init(void)//MPU6050��ʼ��
{
	uint8_t fault=0;
	IMU_ID=Single_ReadI2C(MPU_ADRESS,WHO_AM_I);
  if(IMU_ID==IMU_MPU6050_ID)//MPU6050
	{
		i2cWrite(MPU_ADRESS,PWR_MGMT_1  , 0x00);//�ر������ж�,�������
		i2cWrite(MPU_ADRESS,SMPLRT_DIV  , 0x00); // sample rate.  Fsample= 1Khz/(<this value>+1) = 1000Hz
//		i2cWrite(MPU_ADRESS,MPU_CONFIG  , 0x02); //�ڲ���ͨ�˲�Ƶ�ʣ����ٶȼ�94hz��������98hz
		i2cWrite(MPU_ADRESS,MPU_CONFIG  , 0x03);//�ڲ���ͨ�˲�Ƶ�ʣ����ٶȼ�44hz��������42hz
		i2cWrite(MPU_ADRESS,GYRO_CONFIG , 0x08);//500deg/s
		i2cWrite(MPU_ADRESS,ACCEL_CONFIG, 0x08);// Accel scale 16g (8192 LSB/g)
	}
	else if(IMU_ID==IMU_ICM20689_ID)//ICM20689
	{	
		i2cWrite(MPU_ADRESS,PWR_MGMT_1  , IMU_Config_Write[0]);//�ر������ж�,�������
		i2cWrite(MPU_ADRESS,SMPLRT_DIV  , IMU_Config_Write[1]); // sample rate.  Fsample= 1Khz/(<this value>+1) = 1000Hz					
		i2cWrite(MPU_ADRESS,MPU_CONFIG  , IMU_Config_Write[2]);//0x00���������ǡ��¶��ڲ���ͨ�˲�Ƶ�ʷ�Χ��������250hz����������306.6hz���¶�4000hz
																												  //0x01���������ǡ��¶��ڲ���ͨ�˲�Ƶ�ʷ�Χ��������176hz����������177hz���¶�188hz
																												  //0x02���������ǡ��¶��ڲ���ͨ�˲�Ƶ�ʷ�Χ��������92hz����������108.6hz���¶�98hz
																												  //0x03���������ǡ��¶��ڲ���ͨ�˲�Ƶ�ʷ�Χ��������41hz����������59hz���¶�42hz		
																												  //0x04���������ǡ��¶��ڲ���ͨ�˲�Ƶ�ʷ�Χ��������20hz����������30.5hz���¶�20hz
																									 //0x05���������ǡ��¶��ڲ���ͨ�˲�Ƶ�ʷ�Χ��������10hz����������15.6hz���¶�10hz
		i2cWrite(MPU_ADRESS,GYRO_CONFIG , IMU_Config_Write[3]);//�������������̣�500deg/s
		i2cWrite(MPU_ADRESS,ACCEL_CONFIG, IMU_Config_Write[4]);// Accel scale 4g (8192 LSB/g)	
		i2cWrite(MPU_ADRESS,ACCEL_CONFIG2,IMU_Config_Write[5]);
																									 //0x00���ü��ٶȼ��ڲ���ͨ�˲�Ƶ�ʷ�Χ�����ٶ�218.1hz����������235hz		
																									 //0x01���ü��ٶȼ��ڲ���ͨ�˲�Ƶ�ʷ�Χ�����ٶ�218.1hz����������235hz
																									 //0x02���ü��ٶȼ��ڲ���ͨ�˲�Ƶ�ʷ�Χ�����ٶ�99.0hz����������121.3hz		
																									 //0x03���ü��ٶȼ��ڲ���ͨ�˲�Ƶ�ʷ�Χ�����ٶ�44.8hz����������61.5hz
																									 //0x04���ü��ٶȼ��ڲ���ͨ�˲�Ƶ�ʷ�Χ�����ٶ�21.2hz����������31.0hz
																									 //0x05���ü��ٶȼ��ڲ���ͨ�˲�Ƶ�ʷ�Χ�����ٶ�10.2hz����������15.5hz	
		//Single_WriteI2C(MPU_ADRESS,ACCEL_CONFIG2,0xC3);//���ü��ٶȼ��ڲ���ͨ�˲�Ƶ�ʷ�Χ�����ٶ�1046.0hz����������1100.0hz
		delay_ms(100);		
		IMU_Config_Read[0]=i2cRead(MPU_ADRESS,PWR_MGMT_1);
		IMU_Config_Read[1]=i2cRead(MPU_ADRESS,SMPLRT_DIV);
		IMU_Config_Read[2]=i2cRead(MPU_ADRESS,MPU_CONFIG);
		IMU_Config_Read[3]=i2cRead(MPU_ADRESS,GYRO_CONFIG);
		IMU_Config_Read[4]=i2cRead(MPU_ADRESS,ACCEL_CONFIG);
		IMU_Config_Read[5]=i2cRead(MPU_ADRESS,ACCEL_CONFIG2);
		if(IMU_Config_Read[0]!=IMU_Config_Write[0]) fault=1;
		if(IMU_Config_Read[1]!=IMU_Config_Write[1]) fault=1;
		if(IMU_Config_Read[2]!=IMU_Config_Write[2]) fault=1;
		if(IMU_Config_Read[3]!=IMU_Config_Write[3]) fault=1;
		if(IMU_Config_Read[4]!=IMU_Config_Write[4]) fault=1;
		if(IMU_Config_Read[5]!=IMU_Config_Write[5]) fault=1;
	}
  delay_ms(500);	
  IMU_Calibration();
  Set_Cutoff_Frequency(Imu_Sampling_Freq, 95,&Gyro_Parameter);//��̬���ٶȷ����˲�����  60 50
  Set_Cutoff_Frequency(Imu_Sampling_Freq, 30,&Accel_Parameter);//��̬����Ӽ������˲�ֵ 20 30
  Set_Cutoff_Frequency(Imu_Sampling_Freq, 2 ,&Calibrate_Parameter);//������У׼�Ӽ��˲�ֵ
  Set_Cutoff_Frequency(Imu_Sampling_Freq, 60,&Ins_Accel_Parameter);//INS�Ӽ��˲�ֵ
	
	return fault;
}

/***********************************************************
@��������MPU6050_Read_Data
@��ڲ�����vector3f *gyro,vector3f *accel
@���ڲ�������
����������MPU6050���ݲɼ�
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void MPU6050_Read_Data(vector3f *gyro,vector3f *accel,float *temperature)//��ȡMPU6050����
{
	uint8_t buf[14];
	int16_t temp;
	i2cReadData(MPU_ADRESS,ACCEL_XOUT_H,buf,14);
	accel->x=(int16_t)((buf[0]<<8)|buf[1]);
	accel->y=-(int16_t)((buf[2]<<8)|buf[3]);
	accel->z=-(int16_t)((buf[4]<<8)|buf[5]);	
	temp		=(int16_t)((buf[6]<<8)|buf[7]);
	gyro->x	=(int16_t)((buf[8]<<8)|buf[9]);
	gyro->y	=-(int16_t)((buf[10]<<8)|buf[11]);
	gyro->z	=-(int16_t)((buf[12]<<8)|buf[13]);	
	if(IMU_ID==IMU_MPU6050_ID)
	{
		//MPU6050
		//Sensitivity=340 LSB/��C
		//Temperature Offset=35 ��C
		*temperature=36.53f+(double)(temp/340.0f);
	}
	if(IMU_ID==IMU_ICM20689_ID)
	{
		//ICM20689
		//Room Temperature Offset=25 ��C
		//Sensitivity=326.8 LSB/��C
		//TEMP_degC = ((TEMP_OUT �CRoomTemp_Offset)/Temp_Sensitivity) +25degC
		*temperature=25.0f+(double)((temp-25.0f)/326.8f);
	}	
}


Vector3f gyro_offset;
s32 g_Gyro_xoffset = 0, g_Gyro_yoffset = 0, g_Gyro_zoffset = 0;
/***********************************************************
@��������IMU_Calibration
@��ڲ�������
@���ڲ�������
���������������ǿ�����ƫ�궨
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void IMU_Calibration(void)
{
  u8 i;
	vector3f gyro_offset_temp;
	ReadFlashParameterOne(GYRO_X_OFFSET,&gyro_offset_temp.x);
	ReadFlashParameterOne(GYRO_Y_OFFSET,&gyro_offset_temp.y);
	ReadFlashParameterOne(GYRO_Z_OFFSET,&gyro_offset_temp.z);	
	if(isnan(gyro_offset_temp.x)==0
		&&isnan(gyro_offset_temp.y)==0
		 &&isnan(gyro_offset_temp.z)==0)//���֮ǰ�Ѿ��¶�У׼��������ʱֱ����֮ǰУ׼������ 
	{
		 gyro_offset.x=gyro_offset_temp.x;
		 gyro_offset.y=gyro_offset_temp.y;
		 gyro_offset.z=gyro_offset_temp.z;
	}
	else
	{
		delay_ms(500);
		for (i = 0; i < 100; i++)			//��������30�Σ�һ����ʱ30*3=90ms
		{
			g_Gyro_xoffset +=Double_ReadI2C(MPU_ADRESS,GYRO_XOUT_H);
			g_Gyro_yoffset +=Double_ReadI2C(MPU_ADRESS,GYRO_YOUT_H);
			g_Gyro_zoffset +=Double_ReadI2C(MPU_ADRESS,GYRO_ZOUT_H);
			delay_ms(10);
		}
		gyro_offset.x =(g_Gyro_xoffset/100);//�õ��궨ƫ��
		gyro_offset.y =(g_Gyro_yoffset/100);
		gyro_offset.z =(g_Gyro_zoffset/100);
	}
}

