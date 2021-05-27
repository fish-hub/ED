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
#include "tfmini.h"



			
					
uint8_t Ground_Sensor_Now_Mode=0x01;
float ground_sensor_default=0x01;

tfmini tfdata; 
uint16_t tfmini_tail,last_tfmini_tail,tfmini_offset;
void TFmini_Statemachine(void)
{
  static uint16_t tfmini_cnt=0;
	uint8_t check_sum=0;
	tfmini_cnt++;
  if(tfmini_cnt>=20)//100ms=10hz
  {
		tfmini_cnt=0;
		tfmini_tail=COM7_Rx_Buf.Tail;
		if(tfmini_tail<9)
		{
		  tfmini_offset=9;
		}
    else
		{
		  tfmini_offset=0;
		}			
		for(uint16_t i=tfmini_offset;i<tfmini_offset+9;i++)
		{
			if(COM7_Rx_Buf.Ring_Buff[i]==0x59
				&&COM7_Rx_Buf.Ring_Buff[i+1]==0x59)
			{
				for(uint16_t j=i;j<i+8;j++)  check_sum += COM7_Rx_Buf.Ring_Buff[j];//和校验
				if(check_sum==COM7_Rx_Buf.Ring_Buff[i+8])
				{
					tfdata.pre_last_distance=tfdata.last_distance;//上上次高度
					tfdata.last_distance=tfdata.distance;//上次高度
					tfdata.last_vel=tfdata.vel;//上次速度
					
					tfdata.distance=((COM7_Rx_Buf.Ring_Buff[i+3]*256)+COM7_Rx_Buf.Ring_Buff[i+2])/1.0f;
//					tfdata.distance*=rMat[2][2];
					tfdata.strength=(COM7_Rx_Buf.Ring_Buff[i+4]*256)+COM7_Rx_Buf.Ring_Buff[i+5];
					tfdata.temperature=((COM7_Rx_Buf.Ring_Buff[i+6]*256)+COM7_Rx_Buf.Ring_Buff[i+7])/8.0f-256;
					
					tfdata.vel=(tfdata.distance-tfdata.last_distance)/0.1f; //观测速度
					tfdata.acc=(tfdata.vel-tfdata.last_vel)/0.1f;					  //观测加速度
					
					GD_Distance=tfdata.distance*rMat[2][2];
					GD_Distance_Div=tfdata.vel;
					GD_Distance_Acc=tfdata.acc;		
			
					WP_Sensor.tfmini_updtate_flag=1;
				}					
			}
		}
			
		
		if(tfdata.strength!=65535&&tfdata.strength>=100)
		{
			if(tfdata.distance<=1100&&tfdata.distance>1.0f)  Sensor_Flag.Ground_Health=1;
			else Sensor_Flag.Ground_Health=0;
		}			
		else Sensor_Flag.Ground_Health=0;
	}	
}


void Ground_Sensor_Statemachine(void)
{
	if(Ground_Sensor_Now_Mode==US100)						US_100_Statemachine();	  //超声波传感器状态机更新
	else if(Ground_Sensor_Now_Mode==TFMINI)			TFmini_Statemachine();		//激光TFMINI_PLUS传感器状态机更新
	else if(Ground_Sensor_Now_Mode==TOFSENSOR)	TOF_Statemachine();			  //激光TOFSensor传感器状态机更新
	else 
	{
		static uint16_t cnt=0;
		cnt++;
		if(cnt%10==0)//50ms
		{
			VL53L1X_Get_Distance(&VL53);
		}
	}
}
























//					static uint8_t fault_flag=0;
//					if(ABS(tfdata.vel)<1000&&tfdata.distance>=1.0f&&tfdata.strength!=65535)
//					{
//						if(fault_flag==1&&tfdata.distance==tfdata.pre_last_distance)//本次=上上次
//						{
//							fault_flag=1;
//						}			
//						else if(fault_flag==1&&tfdata.distance==tfdata.last_distance)//本次=上次
//						{
//							fault_flag=1;
//						}
//						else if(fault_flag==1&&tfdata.last_distance==tfdata.pre_last_distance)//上次=上上次
//						{
//							fault_flag=1;		
//						}
//						//以上为传感器异常处理
//						else
//						{
//							TF_Distance=tfdata.distance;
//							TF_Distance_Div=tfdata.vel;
//							TF_Distance_Acc=tfdata.acc;		
//						}
//					}
//					else
//					{
//						fault_flag=1;		
//					}	
					
					
					
					
					
					
					
					




