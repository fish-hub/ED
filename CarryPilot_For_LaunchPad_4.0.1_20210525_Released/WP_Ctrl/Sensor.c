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
#include "Sensor.h"
#include "Filter.h"

#define  YAW_FUSION_MODE_QUAD  0	//1��ƫ������Դ����Ԫ�����£�ʱ�䳤����ƫ�ƣ�
																	//   ��Ե������ڻ����ų����Ŵ��������Ƽ��˷�ʽ
																	//0��ƫ������Դ��ƫ�����ٶ��������һ�׻�����GPS����ʱѡ��˷�ʽ
																	//   �Ƽ��������ô���������
float Pitch,Roll,Yaw;//�����ǡ�����ǡ�ƫ����
float Yaw_Gyro=0,Pitch_Gyro=0,Roll_Gyro=0;//�������ٶȡ�������ٶȡ�ƫ�����ٶ�
float Pitch_Observation,Roll_Observation,Yaw_Observation;//�����۲�ǡ�����۲�ǡ�ƫ���۲��
float Inclination_Rate=0;
Vector3f_Body Circle_Angle;
float Gyro_Length=0;//������ģ��
float qr[4][10]={0};
float K[3]={1.0,1.0,1.0};//Ĭ�ϱ��(����)���
float B[3]={0,0,0};//Ĭ����λ���
Sensor_Health Sensor_Flag;

float invSqrt(float x)
{
  float halfx = 0.5f * x;
  float y = x;
  long i = *(long*)&y;  
  i = 0x5f3759df - (i>>1);
  y = *(float*)&i;
  y = y * (1.5f - (halfx * y * y));
  return y;
}

float Sin_Pitch=0,Sin_Roll=0,Sin_Yaw=0;
float Cos_Pitch=0,Cos_Roll=0,Cos_Yaw=0;
float rMat[3][3];
float sqf(float x) {return ((x)*(x));}
void imuComputeRotationMatrix(void)
{
  Sin_Pitch=sin(Pitch*DEG2RAD);
  Cos_Pitch=cos(Pitch*DEG2RAD);
  Sin_Roll =sin(Roll *DEG2RAD);
  Cos_Roll =cos(Roll *DEG2RAD);
  Sin_Yaw  =sin(Yaw  *DEG2RAD);
  Cos_Yaw  =cos(Yaw  *DEG2RAD);
  Inclination_Rate=(rMat[2][2]-Cos_Pitch * Cos_Roll);
  rMat[0][0]=Cos_Yaw* Cos_Roll;
  rMat[0][1]=Sin_Pitch*Sin_Roll*Cos_Yaw-Cos_Pitch * Sin_Yaw;
  rMat[0][2]=Sin_Pitch * Sin_Yaw+Cos_Pitch * Sin_Roll * Cos_Yaw;  
  rMat[1][0]=Sin_Yaw * Cos_Roll;
  rMat[1][1]=Sin_Pitch * Sin_Roll * Sin_Yaw +Cos_Pitch * Cos_Yaw;
  rMat[1][2]=Cos_Pitch * Sin_Roll * Sin_Yaw - Sin_Pitch * Cos_Yaw;
  rMat[2][0]=-Sin_Roll;
  rMat[2][1]= Sin_Pitch * Cos_Roll;
  rMat[2][2]= Cos_Pitch * Cos_Roll;
}


uint8_t Get_Baro_Offset()
{
  static uint16_t baro_sample_cnt=0;
  if(baro_sample_cnt<=100) 
  {
    baro_sample_cnt++;
  }    
  if(baro_sample_cnt==100) 
  {
    WP_Sensor.baro_presure_offset=WP_Sensor.baro_pressure_raw;
    return 1;
  }
  else if(baro_sample_cnt==101) 
  {
    float Tempbaro=(float)(WP_Sensor.baro_pressure_raw/WP_Sensor.baro_presure_offset)*1.0f;
    WP_Sensor.baro_altitude = 4433000.0f * (1 - powf((float)(Tempbaro),0.190295f));
		if(baro_flag==1)
		{
			WP_Sensor.baro_altitude_div=(WP_Sensor.baro_altitude-WP_Sensor.last_baro_altitude)/(Baro_Update_Dt*0.001f);			
		  WP_Sensor.last_baro_altitude=WP_Sensor.baro_altitude;			
			WP_Sensor.baro_altitude_acc=(WP_Sensor.baro_altitude_div-WP_Sensor.last_baro_altitude_div)/(Baro_Update_Dt*0.001f);
			WP_Sensor.last_baro_altitude_div=WP_Sensor.baro_altitude_div;
			baro_flag=0;
		}
    return 1;
  }
  return 0;
}


float Accel_For_Cal[3]={0};
Vector3f gyro,accel,mag;
Vector3f gyro_filter,accel_filter,mag_filter,gyro_filter_bug;
Vector3f gyro_bpf_filter,accel_bpf_filter,accel_bpf_filter_bug;
Vector3f ins_accel_filter;
Butter_BufferData ins_accel_filter_buf[3],gyro_filter_buf_bug[3],gyro_filter_buf[3],accel_filter_buf[3],mag_filter_buf[3],accel_cal_filter_buf[3],accel_for_cal_filter_buf[3];
Butter_BufferData gyro_bpf_filter_buf[3],accel_bpf_filter_buf[3],accel_bpf_filter_buf_bug[3];
uint8_t mag_update_flag=0;
Butter_BufferData imu_temperature;
void Sensor_Update(void)
{
  //����������0.5~0.8ms�ɼ����
  MPU6050_Read_Data(&WP_Sensor.gyro_raw,&WP_Sensor.accel_raw,&WP_Sensor.temperature);
  WP_Sensor.imu_updtate_flag=1;
	if(Gyro_Safety_Calibration_Flag==0)  
		Gyro_Safety_Calibration_Flag=Gyro_Calibration_Check(&WP_Sensor.gyro_raw);
	if(cal_flag==0x01) 
  {
		Gyro_Safety_Calibration_Flag=0;
		cal_flag=0x00;
	}	
  mag_update_flag=Compass_Read_Data(&WP_Sensor.mag_raw);
	Compass_Fault_Check();
  SPL06_Read_Data(&WP_Sensor.baro_temp_raw,&WP_Sensor.baro_pressure_raw);
  Get_Baro_Offset();
  
  //�õ�У׼��Ľ��ٶȡ����ٶȡ�����������
  gyro.x=WP_Sensor.gyro_raw.x-gyro_offset.x;
  gyro.y=WP_Sensor.gyro_raw.y-gyro_offset.y;
  gyro.z=WP_Sensor.gyro_raw.z-gyro_offset.z;
  
  accel.x=K[0]*WP_Sensor.accel_raw.x-B[0]*One_G_TO_Accel;
  accel.y=K[1]*WP_Sensor.accel_raw.y-B[1]*One_G_TO_Accel;
  accel.z=K[2]*WP_Sensor.accel_raw.z-B[2]*One_G_TO_Accel;
  
  mag.x=WP_Sensor.mag_raw.x-mag_offset.x;
  mag.y=WP_Sensor.mag_raw.y-mag_offset.y;
  mag.z=WP_Sensor.mag_raw.z-mag_offset.z;
  //ԭʼ�����˲����� 
	WP_Sensor.mag_intensity=pythagorous3(mag.x,mag.y,mag.z);	
	
//  IIR_High_Order_Filter(&Accel_X_Butter_Filter,accel.x);accel_filter.x=Accel_X_Butter_Filter.output[Accel_X_Butter_Filter.N-1];//accel_filter.x=LPButterworth(accel.x,&accel_filter_buf[0],&Accel_Parameter);
//  IIR_High_Order_Filter(&Accel_Y_Butter_Filter,accel.y);accel_filter.y=Accel_Y_Butter_Filter.output[Accel_Y_Butter_Filter.N-1];//accel_filter.y=LPButterworth(accel.y,&accel_filter_buf[1],&Accel_Parameter);
//  IIR_High_Order_Filter(&Accel_Z_Butter_Filter,accel.z);accel_filter.z=Accel_Z_Butter_Filter.output[Accel_Z_Butter_Filter.N-1];//accel_filter.z=LPButterworth(accel.z,&accel_filter_buf[2],&Accel_Parameter);		


//	IIR_High_Order_Filter(&Gyro_X_Butter_Filter,gyro.x);gyro_filter.x=Gyro_X_Butter_Filter.output[Gyro_X_Butter_Filter.N-1];//	gyro_filter.x=LPButterworth(gyro.x,&gyro_filter_buf_bug[0],&Gyro_Parameter);
//  IIR_High_Order_Filter(&Gyro_Y_Butter_Filter,gyro.y);gyro_filter.y=Gyro_Y_Butter_Filter.output[Gyro_Y_Butter_Filter.N-1];//	gyro_filter.y=LPButterworth(gyro.y,&gyro_filter_buf_bug[1],&Gyro_Parameter);
//  IIR_High_Order_Filter(&Gyro_Z_Butter_Filter,gyro.z);gyro_filter.z=Gyro_Z_Butter_Filter.output[Gyro_Z_Butter_Filter.N-1];//	gyro_filter.z=LPButterworth(gyro.z,&gyro_filter_buf_bug[2],&Gyro_Parameter);		
//	
//  IIR_High_Order_Filter(&Accel_X_INS,accel.x);ins_accel_filter.x=Accel_X_INS.output[Accel_X_INS.N-1];//ins_accel_filter.x=LPButterworth(accel.x,&ins_accel_filter_buf[0],&Ins_Accel_Parameter);
//  IIR_High_Order_Filter(&Accel_Y_INS,accel.y);ins_accel_filter.y=Accel_Y_INS.output[Accel_Y_INS.N-1];//ins_accel_filter.y=LPButterworth(accel.y,&ins_accel_filter_buf[1],&Ins_Accel_Parameter);
//  IIR_High_Order_Filter(&Accel_Z_INS,accel.z);ins_accel_filter.z=Accel_Z_INS.output[Accel_Z_INS.N-1];//ins_accel_filter.z=LPButterworth(accel.z,&ins_accel_filter_buf[2],&Ins_Accel_Parameter);
	
	  //ԭʼ�����˲�����	
  static float last_temperature;
	last_temperature=WP_Sensor._temperature;
  WP_Sensor._temperature=last_temperature+0.1f*(WP_Sensor.temperature-last_temperature);
	
	
	accel_filter.x=LPButterworth(accel.x,&accel_filter_buf[0],&Accel_Parameter);
	accel_filter.y=LPButterworth(accel.y,&accel_filter_buf[1],&Accel_Parameter);
	accel_filter.z=LPButterworth(accel.z,&accel_filter_buf[2],&Accel_Parameter);	
		
	gyro_filter.x=LPButterworth(gyro.x,&gyro_filter_buf_bug[0],&Gyro_Parameter);
  gyro_filter.y=LPButterworth(gyro.y,&gyro_filter_buf_bug[1],&Gyro_Parameter);
  gyro_filter.z=LPButterworth(gyro.z,&gyro_filter_buf_bug[2],&Gyro_Parameter);	

//  accel_filter.x=accel.x;
//	accel_filter.y=accel.y;
//  accel_filter.z=accel.z;

//  gyro_filter.x=gyro.x;
//	gyro_filter.y=gyro.y;
//  gyro_filter.z=gyro.z;
	
	
  ins_accel_filter.x=LPButterworth(accel.x,&ins_accel_filter_buf[0],&Ins_Accel_Parameter);
  ins_accel_filter.y=LPButterworth(accel.y,&ins_accel_filter_buf[1],&Ins_Accel_Parameter);
  ins_accel_filter.z=LPButterworth(accel.z,&ins_accel_filter_buf[2],&Ins_Accel_Parameter);
	
	
  Accel_For_Cal[0]=LPButterworth(WP_Sensor.accel_raw.x,&accel_for_cal_filter_buf[0],&Calibrate_Parameter);
  Accel_For_Cal[1]=LPButterworth(WP_Sensor.accel_raw.y,&accel_for_cal_filter_buf[1],&Calibrate_Parameter);
  Accel_For_Cal[2]=LPButterworth(WP_Sensor.accel_raw.z,&accel_for_cal_filter_buf[2],&Calibrate_Parameter);	  
  WP_Sensor.acce_filter[0]=Accel_For_Cal[0];
  WP_Sensor.acce_filter[1]=Accel_For_Cal[1];
  WP_Sensor.acce_filter[2]=Accel_For_Cal[2];
}

void Observation_Angle_Calculate(void)
{
  float ACCE_X_TEMP,ACCE_Y_TEMP,ACCE_Z_TEMP;
  float MagTemp[3]={0};  
  ACCE_X_TEMP=accel.x;
  ACCE_Y_TEMP=accel.y;
  ACCE_Z_TEMP=accel.z;
  Roll_Observation=-57.3*atan(ACCE_X_TEMP*invSqrt(ACCE_Y_TEMP*ACCE_Y_TEMP+ACCE_Z_TEMP*ACCE_Z_TEMP));//�����
  Pitch_Observation=57.3*atan(ACCE_Y_TEMP*invSqrt(ACCE_X_TEMP*ACCE_X_TEMP+ACCE_Z_TEMP*ACCE_Z_TEMP));//������
  /************��������ǲ���*****************/
	if(mag_update_flag==1)
	{
		mag_filter.x=mag.x;
		mag_filter.y=mag.y;
		mag_filter.z=mag.z;			
		MagTemp[0]=mag_filter.x;
		MagTemp[1]=mag_filter.y;
		MagTemp[2]=mag_filter.z;
		
		magn.x=  MagTemp[0] * Cos_Roll+ MagTemp[2] * Sin_Roll;
		magn.y=  MagTemp[0] * Sin_Pitch*Sin_Roll
						+MagTemp[1] * Cos_Pitch
					  -MagTemp[2] * Sin_Pitch*Cos_Roll;
		/***********�����еõ������ƹ۲�Ƕ�*********/
		Yaw_Observation=atan2(magn.x,magn.y)*57.296f;	
	}
}

float euler_roll_init,euler_pitch_init,euler_yaw_init;
float q0_init, q1_init, q2_init, q3_init;

void Euler_Angle_Init()
{
  float ACCE_X_TEMP,ACCE_Y_TEMP,ACCE_Z_TEMP;
  float MagTemp[3]={0};    
  MPU6050_Read_Data(&WP_Sensor.gyro_raw,&WP_Sensor.accel_raw,&WP_Sensor.temperature);
  accel.x=K[0]*WP_Sensor.accel_raw.x-B[0]*One_G_TO_Accel;
  accel.y=K[1]*WP_Sensor.accel_raw.y-B[1]*One_G_TO_Accel;
  accel.z=K[2]*WP_Sensor.accel_raw.z-B[2]*One_G_TO_Accel;
  ACCE_X_TEMP=accel.x;
  ACCE_Y_TEMP=accel.y;
  ACCE_Z_TEMP=accel.z;
  Roll_Observation=-57.3*atan(ACCE_X_TEMP*invSqrt(ACCE_Y_TEMP*ACCE_Y_TEMP+ACCE_Z_TEMP*ACCE_Z_TEMP));//�����
  Pitch_Observation=57.3*atan(ACCE_Y_TEMP*invSqrt(ACCE_X_TEMP*ACCE_X_TEMP+ACCE_Z_TEMP*ACCE_Z_TEMP));//������
  
  Sin_Pitch=sin(Pitch_Observation* DEG2RAD);
  Cos_Pitch=cos(Pitch_Observation* DEG2RAD);
  Sin_Roll=sin(Roll_Observation* DEG2RAD);
  Cos_Roll=cos(Roll_Observation* DEG2RAD);
  while(mag_update_flag==0)
  {
    delay_ms(5);
    mag_update_flag=Compass_Read_Data(&WP_Sensor.mag_raw);
  }
  /************��������ǲ���*****************/
  MagTemp[0]=WP_Sensor.mag_raw.x-mag_offset.x;
  MagTemp[1]=WP_Sensor.mag_raw.y-mag_offset.y;
  MagTemp[2]=WP_Sensor.mag_raw.z-mag_offset.z;
  
  magn.x=  MagTemp[0] * Cos_Roll+ MagTemp[2] * Sin_Roll;
  magn.y=  MagTemp[0] * Sin_Pitch*Sin_Roll
    +MagTemp[1] * Cos_Pitch
      -MagTemp[2] * Sin_Pitch*Cos_Roll;
  
  /***********�����еõ������ƹ۲�Ƕ�*********/
  Yaw_Observation=atan2(magn.x,magn.y)*57.296f;	
  euler_pitch_init=Roll_Observation*DEG2RAD; //��ʼ��ŷ��������
  euler_roll_init=Pitch_Observation*DEG2RAD; //��ʼ��ŷ��������
  euler_yaw_init  =Yaw_Observation*DEG2RAD ;
}

void Euler_Angle_Init_Again(void)
{
  float ACCE_X_TEMP,ACCE_Y_TEMP,ACCE_Z_TEMP;
  float MagTemp[3]={0};    
  accel.x=K[0]*WP_Sensor.accel_raw.x-B[0]*One_G_TO_Accel;
  accel.y=K[1]*WP_Sensor.accel_raw.y-B[1]*One_G_TO_Accel;
  accel.z=K[2]*WP_Sensor.accel_raw.z-B[2]*One_G_TO_Accel;
  ACCE_X_TEMP=accel.x;
  ACCE_Y_TEMP=accel.y;
  ACCE_Z_TEMP=accel.z;
  Roll_Observation=-57.3*atan(ACCE_X_TEMP*invSqrt(ACCE_Y_TEMP*ACCE_Y_TEMP+ACCE_Z_TEMP*ACCE_Z_TEMP));//�����
  Pitch_Observation=57.3*atan(ACCE_Y_TEMP*invSqrt(ACCE_X_TEMP*ACCE_X_TEMP+ACCE_Z_TEMP*ACCE_Z_TEMP));//������  
  Sin_Pitch=sin(Pitch_Observation* DEG2RAD);
  Cos_Pitch=cos(Pitch_Observation* DEG2RAD);
  Sin_Roll=sin(Roll_Observation* DEG2RAD);
  Cos_Roll=cos(Roll_Observation* DEG2RAD);
  /************��������ǲ���*****************/
  MagTemp[0]=WP_Sensor.mag_raw.x-mag_offset.x;
  MagTemp[1]=WP_Sensor.mag_raw.y-mag_offset.y;
  MagTemp[2]=WP_Sensor.mag_raw.z-mag_offset.z;
  magn.x=  MagTemp[0] * Cos_Roll+ MagTemp[2] * Sin_Roll;
  magn.y=  MagTemp[0] * Sin_Pitch*Sin_Roll
    +MagTemp[1] * Cos_Pitch
      -MagTemp[2] * Sin_Pitch*Cos_Roll;
  /***********�����еõ������ƹ۲�Ƕ�*********/
  Yaw_Observation=atan2(magn.x,magn.y)*57.296f;	
  euler_pitch_init=Roll_Observation*DEG2RAD; //��ʼ��ŷ��������
  euler_roll_init=Pitch_Observation*DEG2RAD; //��ʼ��ŷ��������
  euler_yaw_init  =Yaw_Observation*DEG2RAD ;
	q0 = cos(euler_yaw_init/2)*cos(euler_pitch_init/2)*cos(euler_roll_init/2)
			+sin(euler_yaw_init/2)*sin(euler_pitch_init/2)*sin(euler_roll_init/2);
	q1 = cos(euler_yaw_init/2)*cos(euler_pitch_init/2)*sin(euler_roll_init/2)
			-sin(euler_yaw_init/2)*sin(euler_pitch_init/2)*cos(euler_roll_init/2);
	q2 = cos(euler_yaw_init/2)*sin(euler_pitch_init/2)*cos(euler_roll_init/2)
			+sin(euler_yaw_init/2)*cos(euler_pitch_init/2)*sin(euler_roll_init/2);
	q3 = sin(euler_yaw_init/2)*cos(euler_pitch_init/2)*cos(euler_roll_init/2)
			-cos(euler_yaw_init/2)*sin(euler_pitch_init/2)*sin(euler_roll_init/2);
			
	for(int16_t i=9;i>0;i--)
	{ 
	  qr[0][i]=q0;
		qr[1][i]=q1;
		qr[2][i]=q2;
		qr[3][i]=q3;
	}
		qr[0][0]=q0;
		qr[1][0]=q1;
		qr[2][0]=q2;
		qr[3][0]=q3;
}


/****************** ���ݳ�ʼ��ŷ���ǳ�ʼ����Ԫ�� *****************************/
void Quaternion_Init()
{
  Euler_Angle_Init();
  q0_init = cos(euler_yaw_init/2)*cos(euler_pitch_init/2)*cos(euler_roll_init/2)
    +sin(euler_yaw_init/2)*sin(euler_pitch_init/2)*sin(euler_roll_init/2);
  q1_init = cos(euler_yaw_init/2)*cos(euler_pitch_init/2)*sin(euler_roll_init/2)
    -sin(euler_yaw_init/2)*sin(euler_pitch_init/2)*cos(euler_roll_init/2);
  q2_init = cos(euler_yaw_init/2)*sin(euler_pitch_init/2)*cos(euler_roll_init/2)
    +sin(euler_yaw_init/2)*cos(euler_pitch_init/2)*sin(euler_roll_init/2);
  q3_init = sin(euler_yaw_init/2)*cos(euler_pitch_init/2)*cos(euler_roll_init/2)
    -cos(euler_yaw_init/2)*sin(euler_pitch_init/2)*sin(euler_roll_init/2);
}

void WP_Quad_Init(void)//��ʼ��Ԫ����ʼ��
{
  Quaternion_Init();
  q0=q0_init;
  q1=q1_init;
  q2=q2_init;
  q3=q3_init;
	
	for(int16_t i=9;i>0;i--)
	{ 
	  qr[0][i]=q0;
		qr[1][i]=q1;
		qr[2][i]=q2;
		qr[3][i]=q3;
	}
		qr[0][0]=q0;
		qr[1][0]=q1;
		qr[2][0]=q2;
		qr[3][0]=q3;
}
Testime Imu_Delta;
float IMU_Dt=0.0f;
float Yaw_Gyro_Earth_Frame=0;
#define sampleFreq 200
#define AHRS_SYNC_CNT 0
uint8_t ahrs_sync_flag=0;
float q0=1.0f,q1=0,q2=0,q3=0;
volatile float beta=0.01f;//0.0175
float Yaw_Fusion_Beta=0.025f;
float accel_mode=0;
float gx_delta=0,gy_delta=0,gz_delta=0;
float kp=0;
void Madgwick_AHRS_Update_IMU(float gx, float gy, float gz, 
                              float ax, float ay, float az,
                              float mx, float my, float mz,
                              float gyro_mold) 
{
  float recipNorm;
  float s0, s1, s2, s3;
  float qDot1, qDot2, qDot3, qDot4;
  float _2q0, _2q1, _2q2, _2q3, _4q0, _4q1, _4q2 ,_8q1, _8q2;
  float q0q0, q0q1, q0q2, q0q3, q1q1, q1q2, q1q3, q2q2, q2q3, q3q3;  
  float hx, hy, bx, bz;
  float halfwx, halfwy, halfwz;
  float halfex, halfey, halfez;
  float beta_temp=0;
	static uint16_t ahrs_sync_cnt=0;
  Test_Period(&Imu_Delta);
  IMU_Dt=(float)(Imu_Delta.Time_Delta/1000.0f);
  if(IMU_Dt>2*WP_Duty_Dt||IMU_Dt<WP_Duty_Dt||isnan(IMU_Dt)!=0)   IMU_Dt=WP_Duty_Dt;
	
  gx*=GYRO_CALIBRATION_COFF;
  gy*=GYRO_CALIBRATION_COFF;
  gz*=GYRO_CALIBRATION_COFF;
  //{-sin��          cos��sin ��                          cos��cos��                   }
  Yaw_Gyro_Earth_Frame=-Sin_Roll*gx+ Cos_Roll*Sin_Pitch *gy+ Cos_Pitch * Cos_Roll *gz;
  
  gx+=gx_delta;
  gy+=gy_delta;
  gz+=gz_delta;
  
  // Rate of change of quaternion from gyroscope
  qDot1 = 0.5f * (-q1 * gx - q2 * gy - q3 * gz)*DEG2RAD;
  qDot2 = 0.5f * ( q0 * gx + q2 * gz - q3 * gy)*DEG2RAD;
  qDot3 = 0.5f * ( q0 * gy - q1 * gz + q3 * gx)*DEG2RAD;
  qDot4 = 0.5f * ( q0 * gz + q1 * gy - q2 * gx)*DEG2RAD;
  
	ahrs_sync_cnt++;
	if(ahrs_sync_cnt>=2)//10ms
	{
		for(int16_t i=9;i>0;i--)
		{ 
			qr[0][i]=qr[0][i-1];
			qr[1][i]=qr[1][i-1];
			qr[2][i]=qr[2][i-1];
			qr[3][i]=qr[3][i-1];
		}
		ahrs_sync_cnt=0;
		ahrs_sync_flag=1;
	}
		qr[0][0]=q0;
		qr[1][0]=q1;
		qr[2][0]=q2;
		qr[3][0]=q3;
		
  // Compute feedback only if accelerometer measurement valid (avoids NaN in accelerometer normalisation)
  if(!((ax == 0.0f) && (ay == 0.0f) && (az == 0.0f))&&ahrs_sync_flag==1) 
  {
		accel_mode=GRAVITY_MSS*((safe_sqrt(sq(ax)+sq(ay)+sq(az))/AcceMax_1G)-1.0f);
    ahrs_sync_flag=0;		
    // Normalise accelerometer measurement
    recipNorm = invSqrt(ax * ax + ay * ay + az * az);
    ax *= recipNorm;
    ay *= recipNorm;
    az *= recipNorm;     
    // Normalise magnetometer measurement
    recipNorm = invSqrt(mx * mx + my * my + mz * mz);
    mx *= recipNorm;
    my *= recipNorm;
    mz *= recipNorm;		
    
    // Auxiliary variables to avoid repeated arithmetic  
		_2q0=2.0f *qr[0][AHRS_SYNC_CNT];//_2q0 = 2.0f * q0;
		_2q1=2.0f *qr[1][AHRS_SYNC_CNT];//_2q1 = 2.0f * q1;
		_2q2=2.0f *qr[2][AHRS_SYNC_CNT];//_2q2 = 2.0f * q2;
		_2q3=2.0f *qr[3][AHRS_SYNC_CNT];//_2q3 = 2.0f * q3;	
		_4q0=4.0f *qr[0][AHRS_SYNC_CNT];//_4q0 = 4.0f * q0;
		_4q1=4.0f *qr[1][AHRS_SYNC_CNT];//_4q1 = 4.0f * q1;
		_4q2=4.0f *qr[2][AHRS_SYNC_CNT];//_4q2 = 4.0f * q2;
		_8q1=8.0f *qr[1][AHRS_SYNC_CNT];//_8q1 = 8.0f * q1;
		_8q2=8.0f *qr[2][AHRS_SYNC_CNT];//_8q2 = 8.0f * q2;
		q0q0 = qr[0][AHRS_SYNC_CNT] * qr[0][AHRS_SYNC_CNT];//		q0q0 = q0 * q0;
    q0q1 = qr[0][AHRS_SYNC_CNT] * qr[1][AHRS_SYNC_CNT];//    q0q1 = q0 * q1;
    q0q2 = qr[0][AHRS_SYNC_CNT] * qr[2][AHRS_SYNC_CNT];//    q0q2 = q0 * q2;
    q0q3 = qr[0][AHRS_SYNC_CNT] * qr[3][AHRS_SYNC_CNT];//    q0q3 = q0 * q3;
    q1q1 = qr[1][AHRS_SYNC_CNT] * qr[1][AHRS_SYNC_CNT];//    q1q1 = q1 * q1;
    q1q2 = qr[1][AHRS_SYNC_CNT] * qr[2][AHRS_SYNC_CNT];//    q1q2 = q1 * q2;
    q1q3 = qr[1][AHRS_SYNC_CNT] * qr[3][AHRS_SYNC_CNT];//    q1q3 = q1 * q3;
    q2q2 = qr[2][AHRS_SYNC_CNT] * qr[2][AHRS_SYNC_CNT];//    q2q2 = q2 * q2;
    q2q3 = qr[2][AHRS_SYNC_CNT] * qr[3][AHRS_SYNC_CNT];//    q2q3 = q2 * q3;
    q3q3 = qr[3][AHRS_SYNC_CNT] * qr[3][AHRS_SYNC_CNT];//    q3q3 = q3 * q3;		  
    
    // Reference direction of Earth's magnetic field
    hx = 2.0f * (mx * (0.5f - q2q2 - q3q3) + my * (q1q2 - q0q3) + mz * (q1q3 + q0q2));
    hy = 2.0f * (mx * (q1q2 + q0q3) + my * (0.5f - q1q1 - q3q3) + mz * (q2q3 - q0q1));
    bx = sqrt(hx * hx + hy * hy);
    bz = 2.0f * (mx * (q1q3 - q0q2) + my * (q2q3 + q0q1) + mz * (0.5f - q1q1 - q2q2));
    
    halfwx = bx * (0.5f - q2q2 - q3q3) + bz * (q1q3 - q0q2);
    halfwy = bx * (q1q2 - q0q3) + bz * (q0q1 + q2q3);
    halfwz = bx * (q0q2 + q1q3) + bz * (0.5f - q1q1 - q2q2); 
    // Error is sum of cross product between estimated direction and measured direction of field vectors
    halfex = (my * halfwz - mz * halfwy);
    halfey = (mz * halfwx - mx * halfwz);
    halfez = (mx * halfwy - my * halfwx);
    
    gx_delta=kp*halfex;
    gy_delta=kp*halfey;
    gz_delta=kp*halfez;
    
    // Gradient decent algorithm corrective step
    s0 = _4q0 * q2q2 + _2q2 * ax + _4q0 * q1q1 - _2q1 * ay;
    s1 = _4q1 * q3q3 - _2q3 * ax + 4.0f * q0q0 * qr[1][AHRS_SYNC_CNT] - _2q0 * ay - _4q1 + _8q1 * q1q1 + _8q1 * q2q2 + _4q1 * az;
    s2 = 4.0f * q0q0 * qr[2][AHRS_SYNC_CNT] + _2q0 * ax + _4q2 * q3q3 - _2q3 * ay - _4q2 + _8q2 * q1q1 + _8q2 * q2q2 + _4q2 * az;
    s3 = 4.0f * q1q1 * qr[3][AHRS_SYNC_CNT] - _2q1 * ax + 4.0f * q2q2 * qr[3][AHRS_SYNC_CNT] - _2q2 * ay;
    
		recipNorm = invSqrt(s0 * s0 + s1 * s1 + s2 * s2 + s3 * s3); // normalise step magnitude
    s0 *= recipNorm;
    s1 *= recipNorm;
    s2 *= recipNorm;
    s3 *= recipNorm;
    
    beta_temp=beta+0.01f*IMU_Dt*constrain_float(gyro_mold,0,500);//0.0175f  0.025 
		beta_temp-=0.0005f*(accel_mode/GRAVITY_MSS);//0.005
    beta_temp=constrain_float(beta_temp,beta,0.06f);
    
    // Apply feedback step
    qDot1 -= beta_temp * s0;
    qDot2 -= beta_temp * s1;
    qDot3 -= beta_temp * s2;
    qDot4 -= beta_temp * s3;
  }
  
  // Integrate rate of change of quaternion to yield quaternion
  q0 += qDot1 * IMU_Dt;
  q1 += qDot2 * IMU_Dt;
  q2 += qDot3 * IMU_Dt;
  q3 += qDot4 * IMU_Dt;
  
  // Normalise quaternion
  recipNorm = invSqrt(q0 * q0 + q1 * q1 + q2 * q2 + q3 * q3);
  q0 *= recipNorm;
  q1 *= recipNorm;
  q2 *= recipNorm;
  q3 *= recipNorm;
}



float Yaw_Temp=0;
void Get_Status_Feedback(void)
{
  Sensor_Update();//���������ݸ���
	Observation_Angle_Calculate();//�۲�������
  Madgwick_AHRS_Update_IMU(gyro_filter.x,gyro_filter.y,gyro_filter.z
                           ,accel_filter.x,accel_filter.y,accel_filter.z
                             ,mag_filter.x,mag_filter.y,mag_filter.z
                               ,Gyro_Length);	
  Pitch= atan2(2.0f * q2 * q3 + 2.0f * q0 * q1, -2.0f *q1 *q1 - 2.0f * q2* q2 + 1.0f) * RAD2DEG;		// Pitch
  Roll = asin(2.0f * q0* q2-2.0f * q1 * q3) * RAD2DEG;																								// Roll
 
#if (YAW_FUSION_MODE_QUAD)
	Yaw = atan2(2.0f * q1 * q2 + 2.0f * q0 * q3, -2.0f * q3 *q3 - 2.0f * q2 * q2 + 1.0f) * RAD2DEG;		// Yaw
#else
	if(Sensor_Flag.Mag_Health==TRUE)
	{		
		//ƫ����һ�׻����ں�
		Yaw_Temp+=Yaw_Gyro_Earth_Frame*IMU_Dt;
		if(mag_update_flag==1)
		{			
			if((Yaw_Observation>90 && Yaw_Temp<-90)|| (Yaw_Observation<-90 && Yaw_Temp>90))
					 Yaw_Temp = -Yaw_Temp * (1-Yaw_Fusion_Beta) + Yaw_Observation * Yaw_Fusion_Beta;//0.02
			else Yaw_Temp = Yaw_Temp * (1-Yaw_Fusion_Beta) + Yaw_Observation * Yaw_Fusion_Beta;
			//ƫ��������������0~360
	  }
		if(Yaw_Temp<0)   Yaw=Yaw_Temp+360;
		else Yaw=Yaw_Temp;
		if(GPS_Home_Set==1)  Yaw=Yaw-Declination;//���GPS home�������ã���ȡ���ش�ƫ�ǣ��õ������汱
	}
	else
	{
		Yaw = atan2(2.0f * q1 * q2 + 2.0f * q0 * q3, -2.0f * q3 *q3 - 2.0f * q2 * q2 + 1.0f) * RAD2DEG;		// Yaw
	}
#endif
		
  //����������ٶȣ�������̬�ڻ�����
  Pitch_Gyro=gyro_filter.x*GYRO_CALIBRATION_COFF;
  Roll_Gyro =gyro_filter.y*GYRO_CALIBRATION_COFF;
  Yaw_Gyro  =gyro_filter.z*GYRO_CALIBRATION_COFF;
  Gyro_Length=sqrt(Yaw_Gyro*Yaw_Gyro+Pitch_Gyro*Pitch_Gyro+Roll_Gyro*Roll_Gyro);//��λdeg/s
  imuComputeRotationMatrix();
  
  Circle_Angle.Pit+=Pitch_Gyro*IMU_Dt;
  Circle_Angle.Rol+=Roll_Gyro*IMU_Dt;
  Circle_Angle.Yaw+=Yaw_Gyro*IMU_Dt;
  if(Circle_Angle.Pit<0.0f)   Circle_Angle.Pit+=360.0f;
  if(Circle_Angle.Pit>360.0f) Circle_Angle.Pit-=360.0f;
  if(Circle_Angle.Rol<0.0f)   Circle_Angle.Rol+=360.0f;
  if(Circle_Angle.Rol>360.0f) Circle_Angle.Rol-=360.0f;
  if(Circle_Angle.Yaw<0.0f)   Circle_Angle.Yaw+=360.0f;
  if(Circle_Angle.Yaw>360.0f) Circle_Angle.Yaw-=360.0f;
  //����λ�á��ٶȡ����ٶ�
  SINS_Prepare();//�ߵ����ٶȸ���
  Strapdown_INS_High_Kalman();//�߶ȷ��򿨶����˲�������ֱ�ٶȡ�λ��
}


  
