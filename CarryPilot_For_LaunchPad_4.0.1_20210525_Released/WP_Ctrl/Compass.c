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
#include "Compass.h"
#include "MMC3630.h"


#define MAG_EXTERNAL_ENABLE  1//当采用外部磁力计时使能1
#define MAG_EXTERNAL_IST8310 0
#define MAG_EXTERNAL_QMC5883 1
#define MAG_EXTERNAL_MMC3630 2
#define MAG_EXTERNAL_TYPE    MAG_EXTERNAL_QMC5883//MAG_EXTERNAL_IST8310 



#define GPS_QMC5883_ENABLE 0//使用无名创新GPS上自带的磁力计时，使能1



void Compass_Init(void)
{
#if (!MAG_EXTERNAL_ENABLE)//内置磁力计IST8310
	Single_WriteI2C(IST8310_SLAVE_ADDRESS,0x41,0x24);//开启16x内部平均
	Single_WriteI2C(IST8310_SLAVE_ADDRESS,0x42,0xC0);//Set/Reset内部平均
	Single_WriteI2C(IST8310_SLAVE_ADDRESS,IST8310_REG_CNTRL1,0x01);//Single Measurement Mode
#else  										//外置磁力计IST8310、QMC5883
  I2C_GPIO_Config();
	Delay_Ms(10);
	if(MAG_EXTERNAL_TYPE==MAG_EXTERNAL_QMC5883) 			QMC5883L_Init();
	else if(MAG_EXTERNAL_TYPE==MAG_EXTERNAL_MMC3630) {MMC3630KJ_Initialization();}
  else		
	{
		Single_WriteI2C0(IST8310_SLAVE_ADDRESS,0x41,0x24);//开启16x内部平均
	  Single_WriteI2C0(IST8310_SLAVE_ADDRESS,0x42,0xC0);//Set/Reset内部平均
		Single_WriteI2C0(IST8310_SLAVE_ADDRESS,IST8310_REG_CNTRL1,0x01);//Single Measurement Mode
	}
#endif	
	Set_Cutoff_Frequency(40, 18,&Mag_Parameter);//传感器校准加计滤波值	
}

Testime T3,T4;
float S1=0;
/***********************************************************
@函数名：Compass_Read_Data
@入口参数：vector3f *mag
@出口参数：无
功能描述：磁力计数据采集状态机
@作者：无名小哥
@日期：2019年01月27日
*************************************************************/
uint8_t Compass_Read_Data(vector3f *mag)//读取磁力计数据状态机
{
  static uint16_t compass_sampling_cnt=0;
  uint8_t buf[6];
  compass_sampling_cnt++;
  if(compass_sampling_cnt==1)
  {
#if (!MAG_EXTERNAL_ENABLE)//重新映射磁力计三轴数据
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
#if (!MAG_EXTERNAL_ENABLE)//重新映射磁力计三轴数据
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
		Test_Period(&T3);//更新姿态数据
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
  if(compass_gap_cnt>=40)//每200ms检测一次，因为磁力计更新周期大于5ms
  {
    compass_gap_cnt=0;
    if(WP_Sensor.last_mag_raw.x==WP_Sensor.mag_raw.x
       &&WP_Sensor.last_mag_raw.y==WP_Sensor.mag_raw.y
         &&WP_Sensor.last_mag_raw.z==WP_Sensor.mag_raw.z)
    {
      compass_fault_cnt++;
      if(compass_fault_cnt>10)  Sensor_Flag.Mag_Health=FALSE;//磁力计数据不健康   
    }
    else
    {
      compass_fault_cnt/=2;
      if(compass_fault_cnt==0)  Sensor_Flag.Mag_Health=TRUE; 
    }
		WP_Sensor.last_mag_raw=WP_Sensor.mag_raw;
  }
}

