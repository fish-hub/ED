#include "Headfile.h"
#include "TOPSensor.h"

#define FRAME_HEADER 					0x57

#define Frame_MARK_READ_FRAME 0x10





void NLink_Data_Send(uint8_t *buf, uint32_t cnt)  
{
	//USART1_Send(buf,cnt);//用户移植时，重写此串口发送函数
}


void  NLink_TOFSense_Read_Frame(uint8_t id)
{
	uint8_t buf[8];
	buf[0]=FRAME_HEADER;
	buf[1]=Frame_MARK_READ_FRAME;
	buf[2]=0xff;
	buf[3]=0xff;
	buf[4]=id;
	buf[5]=0xff;
	buf[6]=0xff;
	buf[7]=0x63;
	NLink_Data_Send(buf,8);
}

TOFSensor_Data tofdata; 
uint16_t tof_tail,last_tof_tail,tof_offset;


systime tofsensor;
void TOF_Statemachine(void)
{
//	check_sum=0x57+0x00+0xff+0x00+0x9e+0x8f+0x00+0x00+0xad+0x08+0x00+0x00+0x03+0x00+0xff;
  static uint16_t _cnt=0;
	_cnt++;
  if(_cnt>=20)//100ms=10hz
  {
		_cnt=0;	
		tof_tail=COM7_Rx_Buf.Tail;
		if(tof_tail<16)
		{
			tof_offset=16;
		}
		else
		{
			tof_offset=0;
		}		
		
		
		for(uint16_t i=tof_offset;i<16+tof_offset;i++)
		{
			if(COM7_Rx_Buf.Ring_Buff[i]==0x57)
			{
				  uint8_t check_sum=0;
					for(uint16_t j=i;j<i+15;j++)  
					{
						check_sum+= COM7_Rx_Buf.Ring_Buff[j];//和校验
					}
					
				  if(check_sum==COM7_Rx_Buf.Ring_Buff[i+15])
					{
						tofdata.pre_last_distance=tofdata.last_distance;//上上次高度
						tofdata.last_distance=tofdata.distance;//上次高度
						tofdata.last_vel=tofdata.vel;//上次速度
						tofdata.last_system_time=tofdata.system_time;
						
						
						tofdata.id=COM7_Rx_Buf.Ring_Buff[i+3];
						tofdata.system_time=COM7_Rx_Buf.Ring_Buff[i+4]|(COM7_Rx_Buf.Ring_Buff[i+5]<<8)|(COM7_Rx_Buf.Ring_Buff[i+6]<<16)|(COM7_Rx_Buf.Ring_Buff[i+7]<<24);
					
  					//if(tofdata.last_system_time==tofdata.system_time)//数据未更新 
			
						Get_Systime(&tofsensor);
						
						tofdata.dis=(int32_t)(COM7_Rx_Buf.Ring_Buff[8]<< 8|COM7_Rx_Buf.Ring_Buff[9]<<16|COM7_Rx_Buf.Ring_Buff[10]<<24)/256;
						tofdata.dis_status=COM7_Rx_Buf.Ring_Buff[i+11];
						tofdata.signal_strength=COM7_Rx_Buf.Ring_Buff[i+12]|(COM7_Rx_Buf.Ring_Buff[i+13]<<8);

				
						tofdata.distance=tofdata.dis/10.0f;//cm
						tofdata.vel=(tofdata.distance-tofdata.last_distance)/0.1f; //观测速度
						tofdata.acc=(tofdata.vel-tofdata.last_vel)/0.1f;					  //观测加速度
					
						GD_Distance=tofdata.distance*rMat[2][2];
						GD_Distance_Div=tofdata.vel;
						GD_Distance_Acc=tofdata.acc;		
						
						WP_Sensor.tofsensor_updtate_flag=1;	
						break;			
					}		
			}
		}
					
		if(GD_Distance<=450&&GD_Distance>0)  Sensor_Flag.Ground_Health=1;
		else  Sensor_Flag.Ground_Health=0; 
	}	
}

