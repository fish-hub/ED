/* Copyright (c)  2019-2025 Wuhan Nameless Innovation Technology Co.,Ltd. All rights reserved.*/
/*----------------------------------------------------------------------------------------------------------------------/
                开源并不等于免费，先驱者的历史已经证明，在国内这个环境下，毫无收益的开源，单靠坊间个人爱好者，自发地参与项
								目完善的方式行不通，好的开源项目需要请专职人员做好售后服务、手把手教学、统计用户反馈需求、在实践中完成对产
								品的一次次完善与迭代升级。经过综合考虑，无名飞控开源代码中，程序仅保留公司正版激活功能代码，版本激活无实际
								功能，属于公司产品常规出厂操作，不影响客户学习，其余代码全部开放给客户学习，客户移植和二次开发代码请保留代
								码版权。
-----------------------------------------------------------------------------------------------------------------------/
*               本程序只供购买者学习使用，版权著作权属于无名科创团队，无名科创团队将飞控程序源码提供给购买者，
*               购买者要为无名科创团队提供保护，未经作者许可，不得将源代码提供给他人，不得将源代码放到网上供他人免费下载， 
*               更不能以此销售牟利，如发现上述行为，无名科创团队将诉之以法律解决！！！
-----------------------------------------------------------------------------------------------------------------------
*                                                 为什么选择无名创新？
*                                         感动人心价格厚道，最靠谱的开源飞控；
*                                         国内业界良心之作，最精致的售后服务；
*                                         追求极致用户体验，高效进阶学习之路；
*                                         萌新不再孤单求索，合理把握开源尺度；
*                                         响应国家扶贫号召，促进教育体制公平；
*                                         新时代奋斗最出彩，建人类命运共同体。 
-----------------------------------------------------------------------------------------------------------------------
*               生命不息、奋斗不止；前人栽树，后人乘凉！！！
*               开源不易，且学且珍惜，祝早日逆袭、进阶成功！！！
*               学习优秀者，简历可推荐到DJI、ZEROTECH、XAG、AEE、GDU、AUTEL、EWATT、HIGH GREAT等公司就业
*               求职简历请发送：15671678205@163.com，需备注求职意向单位、岗位、待遇等
*               无名科创开源飞控QQ群：2号群465082224、1号群540707961（人员已满）
*               CSDN博客：http://blog.csdn.net/u011992534
*               优酷ID：NamelessCotrun无名小哥
*               B站教学视频：https://space.bilibili.com/67803559/#/video
*               客户使用心得、改进意见征集贴：http://www.openedv.com/forum.php?mod=viewthread&tid=234214&extra=page=1
*               淘宝店铺：https://shop348646912.taobao.com/?spm=2013.1.1000126.2.5ce78a88ht1sO2
*               百度贴吧:无名科创开源飞控
*               公司官网:www.nameless.tech
*               无名创新国内首款TI开源飞控设计初衷、知乎专栏:https://zhuanlan.zhihu.com/p/54471146
*               修改日期:2021/03/20                  
*               版本：躺赢者PRO——CarryPilot_V3.0.4
*               版权所有，盗版必究。
*               Copyright(C) 2019-2025 武汉无名创新科技有限公司 
*               All rights reserved
-----------------------------------------------------------------------------------------------------------------------
*               重要提示：
*               正常淘宝咸鱼转手的飞控、赠送朋友、传给学弟的都可以进售后群学习交流，
*               不得直接在网上销售无名创新资料，无名创新代码有声明版权，他人不得将
*               资料代码传网上供他人下载，不得以谋利为目的销售资料代码，发现有此操
*               作者，公司会提前告知，请1天内及时处理，否则你的学校、单位、姓名、电
*               话、地址信息会被贴出在公司官网、官方微信公众平台、官方技术博客、知乎
*               专栏以及淘宝店铺首页予以公示公告，此种所作所为，会成为个人污点，影响
*               升学、找工作、社会声誉、很快就很在无人机界出名，后果很严重。
*               因此行为给公司造成重大损失者，会以法律途径解决，感谢您的合作，谢谢！！！
----------------------------------------------------------------------------------------------------------------------*/
#include "Headfile.h"
#include "RC.h"

uint16 Throttle_Control=0;
float Pitch_Control=0,Roll_Control=0,Yaw_Control=0;
float Target_Angle[2]={0};
uint16 Last_Throttle_Control,Pre_Last_Throttle_Control;
uint16 Throttle_Base=1000,TempThrottle_Control;
uint16_t Controler_State=0;
uint16_t Auto_ReLock_Cnt=0;//自动上锁计数器
uint8_t Auto_Relock_Flag=0;
uint8_t Auto_Relock_Flag_Set=0;
int16 Temp_RC=0;
uint16_t Unlock_Makesure_Cnt=0,Lock_Makesure_Cnt=0;
uint16_t Unwanted_Lock_Flag=0;
uint16_t Forced_Lock_Makesure_Cnt=0;

uint16_t RC_Buttom=1000,RC_Top=2000,RC_Middle=1500,RC_Deadband=100;
uint16_t RC_Deadzone_Buttom=0,RC_Deadzone_Top=0;
Butter_BufferData RC_LPF_Buffer[8];
uint16_t PPM_LPF_Databuf[8];
rc RC_Data;
int16_t TRPY[4]={0};




int16_t constrain_int16_t(int16_t amt, int16_t low, int16_t high){
  return ((amt)<(low)?(low):((amt)>(high)?(high):(amt)));
}


/***********************************************************
@函数名：RC_Data_LPF_Filter
@入口参数：无
@出口参数：无
功能描述：遥控器原始数据滤波
@作者：无名小哥
@日期：2019年01月27日
*************************************************************/
void RC_Data_LPF_Filter()
{
  uint16_t i=0;
  for(i=0;i<8;i++)//对遥控器前四个通道滤波处理
  {
    PPM_LPF_Databuf[i]=(uint16_t)(LPButterworth(PPM_Databuf[i],&RC_LPF_Buffer[i],&Butter_5HZ_Parameter_RC));
  }
}


int16_t Throttle_Rate=0;
/***********************************************************
@函数名：Get_Thr_Rate
@入口参数：float Thr
@出口参数：无
功能描述：油门数据变化率
@作者：无名小哥
@日期：2019年01月27日
*************************************************************/
int16_t Get_Thr_Rate(float Thr)//油门变化量
{
  static float Thr_Rec[20];
  uint16_t i=0;
  for(i=19;i>0;i--)
  {
    Thr_Rec[i]=Thr_Rec[i-1];
  }
  Thr_Rec[0]=Thr;
  return (int16_t)((Thr_Rec[0]-Thr_Rec[9])/1.0f);
}

/***********************************************************
@函数名：RC_Scale_Set
@入口参数：Vector_RC *rc_date
@出口参数：无
功能描述：遥控器通道行程获取
@作者：无名小哥
@日期：2019年01月27日
*************************************************************/
void RC_Scale_Set(rc_calibration *rc_date)
{
  RC_Buttom=(uint16_t)(rc_date->min);
  RC_Top=(uint16_t)(rc_date->max);
  RC_Middle=(uint16_t)(rc_date->middle);
  RC_Deadband=(uint16_t)(rc_date->deadband);
  RC_Deadzone_Buttom=RC_Middle-RC_Deadband/2;
  RC_Deadzone_Top=RC_Middle+RC_Deadband/2;
}



uint8_t RC_Read_Switch(uint16_t ch)
{
		uint16_t pulsewidth = ch;
		if (pulsewidth <= 900 || pulsewidth >= 2200) return 255;// This is an error condition
		if (pulsewidth <= 1210) return 0;//低位
		if (pulsewidth <= 1710) return 1;//中位
		return 2;//高位
}



float Remote_Data_Remap(rc *data,uint16_t ch,float max_down,float max_up,bool reverse_flag)
{
  float value=0;
  if(data->rcdata[ch]<=data->cal[ch].middle-0.5f*data->cal[ch].deadband)
  value=(data->cal[ch].middle-0.5f*data->cal[ch].deadband-data->rcdata[ch])*max_down
												  /data->cal[ch].scale;
	else if(data->rcdata[ch]>=data->cal[ch].middle+0.5f*data->cal[ch].deadband)
  value=(data->cal[ch].middle+0.5f*data->cal[ch].deadband-data->rcdata[ch])*max_up
												  /data->cal[ch].scale;	
  else value=0;
	
	if(reverse_flag)  value*=(-1);
  return 	value;
}


/***********************************************************
@函数名：Remote_Control
@入口参数：无
@出口参数：无
功能描述：遥控器数据转换
@作者：无名小哥
@日期：2019年01月27日
*************************************************************/
void Remote_Control(void )
{
	static uint8_t _cnt=0;
	_cnt++;
	if(_cnt<4) return ;
	_cnt=0;
	if(adc_ppm_update_flag==1)
	{
		memcpy(PPM_Databuf,ADC_PPM_Databuf,10*sizeof(uint16));
	}
	else if(ppm_update_flag==1)//优先选择外部接收机输入的PPM信号
	{
	  memcpy(PPM_Databuf,Receiver_PPM_Databuf,10*sizeof(uint16));
	}
	else if(rc_update_flag==1)
	{
	  memcpy(PPM_Databuf,NCLINK_PPM_Databuf,10*sizeof(uint16));
	}
	
	
	
	if(ppm_update_flag==1||rc_update_flag==1||adc_ppm_update_flag==1)
	{
			memcpy(RC_Data.rcdata,PPM_Databuf,RC_CHL_MAX*sizeof(uint16_t));//更新每个通道遥控器数据
		
			RC_Data.rc_rpyt[RC_ROLL]	=Remote_Data_Remap(&RC_Data ,RC_ROLL_CHANNEL	,Pit_Rol_Max,Pit_Rol_Max,true);
			RC_Data.rc_rpyt[RC_PITCH] =Remote_Data_Remap(&RC_Data ,RC_PITCH_CHANNEL ,Pit_Rol_Max,Pit_Rol_Max,true);
			RC_Data.rc_rpyt[RC_YAW]		=Remote_Data_Remap(&RC_Data ,RC_YAW_CHANNEL	  ,Yaw_Max		,Yaw_Max    ,false);
			RC_Data.rc_rpyt[RC_THR]		=Remote_Data_Remap(&RC_Data ,RC_THR_CHANNEL	  ,Climb_Down_Speed_Max,Climb_Up_Speed_Max,true);
		
		
			RC_Data.thr=RC_Data.rcdata[RC_THR_CHANNEL];
			RC_Data.aux[AUX1]=RC_Data.rcdata[RC_AUX1_CHANNEL];
			RC_Data.aux[AUX2]=RC_Data.rcdata[RC_AUX2_CHANNEL];
			RC_Data.aux[AUX3]=RC_Data.rcdata[RC_AUX3_CHANNEL];
			RC_Data.aux[AUX4]=RC_Data.rcdata[RC_AUX4_CHANNEL];

			RC_Data.last_thr_mode=RC_Data.thr_mode;			
			switch(RC_Read_Switch(RC_Data.aux[AUX1]))
			{
				case 0://手动控制油门
				case 1:RC_Data.thr_mode=HAND_THR;break;//手动控制油门
				case 2:RC_Data.thr_mode=AUTO_THR;break;//自动控制油门
				default:RC_Data.thr_mode=HAND_THR;
			}
			

	
			rc_update_flag=0;
			ppm_update_flag=0;
			RC_Data_LPF_Filter();
			RC_Scale_Set(&RC_Data.cal[0]);
			if(PPM_Databuf[0]<=RC_Deadzone_Buttom)  Roll_Control=(RC_Deadzone_Buttom-PPM_LPF_Databuf[0])*Pit_Rol_Max/(RC_Deadzone_Buttom-RC_Buttom);//最大行程控制量+-45
			else if(PPM_Databuf[0]>=RC_Deadzone_Top)  Roll_Control=(RC_Deadzone_Top-PPM_LPF_Databuf[0])*Pit_Rol_Max/(RC_Top-RC_Deadzone_Top);
			else Roll_Control=0;
			Roll_Control=constrain_float(Roll_Control,-Pit_Rol_Max,Pit_Rol_Max);
			
			RC_Scale_Set(&RC_Data.cal[1]);
			if(PPM_Databuf[1]<=RC_Deadzone_Buttom)  Pitch_Control=(RC_Deadzone_Buttom-PPM_LPF_Databuf[1])*Pit_Rol_Max/(RC_Deadzone_Buttom-RC_Buttom);//最大行程控制量+-45
			else if(PPM_Databuf[1]>=RC_Deadzone_Top)  Pitch_Control=(RC_Deadzone_Top-PPM_LPF_Databuf[1])*Pit_Rol_Max/(RC_Top-RC_Deadzone_Top);
			else Pitch_Control=0;
			Pitch_Control=constrain_float(Pitch_Control,-Pit_Rol_Max,Pit_Rol_Max);
			
			Target_Angle[0]=-Pitch_Control;//自稳时，期望俯仰角
			Target_Angle[1]=-Roll_Control;//自稳时，期望横滚角
			
			RC_Scale_Set(&RC_Data.cal[2]);
			int16_t _thr=0;
			_thr=1000*(PPM_LPF_Databuf[2]-RC_Buttom)/(RC_Top-RC_Buttom);//为了安全，油门杆低位死区为Buttom_Safe_Deadband
			Throttle_Control=constrain_int16_t(_thr,0,1000);
			TRPY[0]=Throttle_Control;//遥感油门原始行程量
			
			
			RC_Scale_Set(&RC_Data.cal[3]);
			if(PPM_Databuf[3]<=RC_Deadzone_Buttom)  Yaw_Control=-(PPM_LPF_Databuf[3]-RC_Deadzone_Buttom)*Yaw_Max/(RC_Deadzone_Buttom-RC_Buttom);//偏航最大行程控制量+-150
			else if(PPM_Databuf[3]>=RC_Deadzone_Top)  Yaw_Control=-(PPM_LPF_Databuf[3]-RC_Deadzone_Top)*Yaw_Max/(RC_Top-RC_Deadzone_Top);
			else Yaw_Control=0;
			Yaw_Control=constrain_float(Yaw_Control,-Yaw_Max,Yaw_Max);
			
			
			Throttle_Rate=Get_Thr_Rate(Throttle_Control);
			Throttle_Control=Throttle_Base+Throttle_Control;
			/***************************************************************
			左手油门时，遥控器解锁动作：左边摇杆处于低位并向内侧打杆
			左手油门时，遥控器上锁动作：左边摇杆处于低位并向外侧打杆
			***************************************************************/
			if(Throttle_Control<=(1000+Buttom_Safe_Deadband)
				 &&Yaw_Control>=Yaw_Max*Scale_Pecent_Max
					 &&Roll_Control==0
						 &&Pitch_Control==0)
			{
				Unlock_Makesure_Cnt++;
				if(Forced_Lock_Makesure_Cnt<10000) Forced_Lock_Makesure_Cnt++;
			}
			else Unlock_Makesure_Cnt/=2;
			
			
			
			if((Throttle_Control<=(1000+Buttom_Safe_Deadband)
				 &&Yaw_Control>=Yaw_Max*Scale_Pecent_Max
					 &&Roll_Control==0
						 &&Pitch_Control==0
							 &&Unlock_Makesure_Cnt>50*2.0)//持续2.0S
									||Forced_Lock_Makesure_Cnt>=50*5
									||unlock_flag==0)//上锁
			{
				Controler_State=Lock_Controler;
				Unlock_Makesure_Cnt=0;
				Lock_Makesure_Cnt=0;
				Forced_Lock_Makesure_Cnt=0;
				Bling_Set(&Light_3,3000,200,0.5,0,GPIO_PORTF_BASE,GPIO_PIN_3,0);
				Bling_Mode=0;
				Page_Number=0;//OLED恢复首页
				Reset_Mag_Calibartion(1);
				Reset_Accel_Calibartion(1);
				Reset_RC_Calibartion(1);
			}
			
			if(Throttle_Control<=(1000+Buttom_Safe_Deadband)
				 &&Yaw_Control<=-Yaw_Max*Scale_Pecent_Max
					 &&Roll_Control==0
						 &&Pitch_Control==0)
				Lock_Makesure_Cnt++;
			else Lock_Makesure_Cnt/=2;
			
			if((Throttle_Control<=(1000+Buttom_Safe_Deadband)
				 &&Yaw_Control<=-Yaw_Max*Scale_Pecent_Max
					 &&Roll_Control==0
						 &&Pitch_Control==0
							 &&Lock_Makesure_Cnt>50*2.0//持续2.0S
								 &&Gyro_Safety_Calibration_Flag==1
									&&Check_Calibration_Flag()==0x00)
			            ||unlock_flag==1)//解锁
			{
				Controler_State=Unlock_Controler;
				if(RC_Data.thr_mode==AUTO_THR)//如果是在定高模式下解锁 
				{  
					 Unwanted_Lock_Flag=1;   //不需要自动进入上锁模式
		#if    (YAW_Pos_Control_Accel_Disable==1)
					Total_Controller.High_Speed_Control.Integrate=-Total_Controller.High_Speed_Control.Integrate_Max;
		#else
					Total_Controller.High_Acce_Control.Integrate=-Total_Controller.High_Acce_Control.Integrate_Max;
		#endif
				}
				else Unwanted_Lock_Flag=0;
				Lock_Makesure_Cnt=0;
				Unlock_Makesure_Cnt=0;
				Forced_Lock_Makesure_Cnt=0;
				Bling_Set(&Light_3,5000,2000,0.1,0,GPIO_PORTF_BASE,GPIO_PIN_3,0);
				Bling_Mode=0;
				Page_Number=0;//OLED恢复首页
				Reset_Mag_Calibartion(1);
				Reset_Accel_Calibartion(1);
				Reset_RC_Calibartion(1);
				Auto_ReLock_Cnt=50*6;//持续6S
				Auto_Relock_Flag_Set=0;
			}
			
			
			
			if(Controler_State==Unlock_Controler
				 &&Auto_Relock_Flag_Set==0//自动上锁位未设置
					 &&Throttle_Control<=(1000+Buttom_Safe_Deadband)
						 &&Pitch_Control==0
							 &&Roll_Control==0
								 &&Yaw_Control==0//解锁后遥感回中
									 &&Unwanted_Lock_Flag==0)
			{
				Auto_Relock_Flag=1;//解锁初始时开启自动上锁标志位
				Auto_Relock_Flag_Set=1;//单次解锁后，只置位一次
			}
			
			
			if(Auto_Relock_Flag==1)
			{
				if(Throttle_Control<=(1000+Buttom_Safe_Deadband)
					 &&Pitch_Control==0
						 &&Roll_Control==0
							 &&Yaw_Control==0
								 &&Controler_State==Unlock_Controler//自动上锁计数器
									 &&Unwanted_Lock_Flag==0)
				{
					Auto_ReLock_Cnt--;
					if(Auto_ReLock_Cnt<=0)  Auto_ReLock_Cnt=0;
					if(Auto_ReLock_Cnt==0)
					{
						Controler_State=Lock_Controler;//再次上锁
						Bling_Set(&Light_3,3000,200,0.5,0,GPIO_PORTF_BASE,GPIO_PIN_3,0);
						Bling_Mode=0;
					}
				}
				
				if((Throttle_Control>(1000+Buttom_Safe_Deadband)
						||Pitch_Control!=0
							||Roll_Control!=0
								||Yaw_Control!=0)
					 &&Auto_ReLock_Cnt>0//自动上锁计数器
						 &&Unwanted_Lock_Flag==0)
				{
					Auto_Relock_Flag=0;//只要遥感有动作，本次解锁后，自动上锁就不开启
					Auto_ReLock_Cnt=0;
					Bling_Set(&Light_3,5000,2000,0.3,0,GPIO_PORTF_BASE,GPIO_PIN_3,0);
					Bling_Mode=0;
				}
			}
	}
	
	if(shutdown_now_cal_flag==1)
	{
		Reset_Mag_Calibartion(1);
		Reset_Accel_Calibartion(1);
		Reset_RC_Calibartion(1);
		shutdown_now_cal_flag=0;
		Bling_Set(&Light_3,0,1000,0.5,0,GPIO_PORTF_BASE,GPIO_PIN_3,0);
		Page_Number=0;//OLED恢复首页
	}
}
