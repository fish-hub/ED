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
#include "VL53L1X.h"
#include "vl53l1_api.h"
#include "VL53L1X_i2c.h"
int32_t distance;
VL53L1_Dev_t VL53;
VL53L1_RangingMeasurementData_t vl52l1x_result_data;
mode_data Mode_data[]=
{
	{(FixPoint1616_t)(16384), //its uint32_t, uint16_.uint16_t, 0.25*65536
	 (FixPoint1616_t)(1179648),	 //18*65536
	 33000,
	 14,
	 10},//default
		
	{(FixPoint1616_t)(16384),	//0.25*65536
	 (FixPoint1616_t)(1179648),		//18*65536
	 200000, 
	 14,
	 10},//high accuracy
		
  {(FixPoint1616_t)(6554),		//0.1*65536
	 (FixPoint1616_t)(3932160),		//60*65536
	 33000,
	 18,
	 14},//long distance
	
  {(FixPoint1616_t)(16384),	//0.25*65536
	 (FixPoint1616_t)(2097152),		//32*65536
	 20000,
	 14,
	 10},//high speed
};

uint16_t di;

VL53L1_Error VL53L1Init(VL53L1_Dev_t* pDev)
{
	
	VL53L1_I2C_Init();
	VL53L1_Error Status = VL53L1_ERROR_NONE;
	pDev->I2cDevAddr=(0x52);//Ĭ�ϵ�ַ
	pDev->comms_type=1;//Ĭ��ͨ��ģʽ
	pDev->comms_speed_khz = 400;//ͨ�����ʣ��ɵ�400hz��

	VL53L1_RdWord(pDev, 0x010F, &di);
	Status = VL53L1_WaitDeviceBooted(pDev);
  if(Status!=VL53L1_ERROR_NONE)
	{
		//printf("Wait device Boot failed!\r\n");
		return Status;
	}
	
  Delay_Ms(2);
	Status = VL53L1_DataInit(pDev);//device init
	if(Status!=VL53L1_ERROR_NONE) 
	{
		//printf("datainit failed!\r\n");
		return Status;
	}

	Delay_Ms(2);
	Status = VL53L1_StaticInit(pDev);
	if(Status!=VL53L1_ERROR_NONE) 
	{
		//printf("static init failed!\r\n");
		return Status;
	}
	
	Delay_Ms(2);
	Status = VL53L1_SetDistanceMode(pDev, VL53L1_DISTANCEMODE_LONG);	//short,medium,long
	if(Status!=VL53L1_ERROR_NONE) 
	{
		//printf("set discance mode failed!\r\n");
		return Status;
	}
	//��ʱԤ�㴫����ִ��һ����������Ҫ��ʱ�䣬��С�����ʱ��Ԥ��Ϊ [20 ms��1000 ms]ʾ����
	VL53L1_SetMeasurementTimingBudgetMicroSeconds(pDev, 35000);//35ms
	VL53L1_SetInterMeasurementPeriodMilliSeconds(pDev, 50);//����������ó�50ms
	VL53L1_StopMeasurement(pDev);
	VL53L1_StartMeasurement(pDev);	
	Delay_Ms(2);
	return Status;
}

/** 
* @brief  ����������һ������У׼
* @param [in] pDev  ָ��������
* @param [in] save  ����洢��ַ
* @retval  VL53L1_Error���� 
* @par ��־ 
*
*/
VL53L1_Error VL53Cali(VL53L1_Dev_t* pDev,void * save)
{
    VL53L1_Error Status = VL53L1_ERROR_NONE;
    Status = VL53L1_StopMeasurement(pDev);
	if(Status!=VL53L1_ERROR_NONE) 
		return Status;
    Status = VL53L1_PerformRefSpadManagement(pDev);//perform ref SPAD management
	if(Status!=VL53L1_ERROR_NONE) 
		return Status;
    /*
    Status = VL53L1_PerformOffsetSimpleCalibration(pDev,140);//14cm�ĳ���У��ֵ
	if(Status!=VL53L1_ERROR_NONE) 
		return Status;
    */
    Status = VL53L1_GetCalibrationData(pDev,save);
	if(Status!=VL53L1_ERROR_NONE) 
		return Status;
    //ȫ����� ���´򿪲���
    Status = VL53L1_StartMeasurement(pDev);
    return Status;
}

VL53L1_Error VL53InitParam(VL53L1_Dev_t* pDev,uint8_t mode)
{
    VL53L1_Error status = VL53L1_ERROR_NONE;
    //4������
    status = VL53L1_SetLimitCheckEnable(pDev,VL53L1_CHECKENABLE_SIGMA_FINAL_RANGE,1);//sigma--standard deviation, enable SIGMA limit check
	if(status!=VL53L1_ERROR_NONE) 
		return status;
    Delay_Ms(2);
	status = VL53L1_SetLimitCheckEnable(pDev,VL53L1_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE,1);//signal--amplitude of the signal-
																																												//-reflected. enable signal rate limit check
	if(status!=VL53L1_ERROR_NONE) 
		return status;
	
	
	Delay_Ms(2);
	status = VL53L1_SetLimitCheckValue(pDev,VL53L1_CHECKENABLE_SIGMA_FINAL_RANGE,Mode_data[mode].sigmaLimit);//set SIGMA limit
	if(status!=VL53L1_ERROR_NONE) 
		return status;
	
	
	Delay_Ms(2);
	status = VL53L1_SetLimitCheckValue(pDev,VL53L1_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE,Mode_data[mode].signalLimit);//set signal rate limit
	if(status!=VL53L1_ERROR_NONE) 
		return status;
    //4������ֵ�������
    
    
    status = VL53L1_SetMeasurementTimingBudgetMicroSeconds(pDev,Mode_data[mode].timingBudget);//set the max interval for a whole diatance test
	if(status!=VL53L1_ERROR_NONE) 
		return status;
	Delay_Ms(2);
	status = VL53L1_SetInterMeasurementPeriodMilliSeconds(pDev, 300);
	if(status!=VL53L1_ERROR_NONE) 
	{
		//printf("SetInterMeasurementPeriodMilliSeconds failed!\r\n");
		return status;
	}
	Delay_Ms(2);
	status = VL53L1_StartMeasurement(pDev);
	if(status!=VL53L1_ERROR_NONE) 
	{
		//printf("start measurement failed!\r\n");
		return status;
	}
    return status;
}



//Test_Period(Testime *Time_Lab)
Testime vl;
VL53L1_Error VL53L1X_Get_Distance(VL53L1_Dev_t* pDev)
{
	VL53L1_Error status = VL53L1_ERROR_NONE;
	uint8_t isDataReady=0;
	status = VL53L1_GetMeasurementDataReady(pDev,&isDataReady);
	if(isDataReady)
	{
		Test_Period(&vl);
		status = VL53L1_GetRangingMeasurementData(pDev, &vl52l1x_result_data);
		GD_Distance = vl52l1x_result_data.RangeMilliMeter/10.0;
		status = VL53L1_ClearInterruptAndStartMeasurement(pDev);
		
		WP_Sensor.vl53l1x_updtate_flag=1;
		GD_Distance_Div=1000*(GD_Distance-Last_GD_Distance)/vl.Time_Delta;
		GD_Distance_Acc=1000*(GD_Distance_Div-Last_GD_Distance_Div)/vl.Time_Delta;
		if(GD_Distance<=350&&GD_Distance>0)  Sensor_Flag.Ground_Health=1;
		else  Sensor_Flag.Ground_Health=0; 
	}
	return status;
}


