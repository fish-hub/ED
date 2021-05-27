#ifndef _TOPSENSOR_H_
#define _TOPSENSOR_H_


typedef struct 
{
	uint8_t reserved1;
	uint8_t id;
	uint32_t system_time;
	int32_t dis;
	uint8_t dis_status;
	uint16_t signal_strength;
	uint8_t reserved2;
	
	uint32_t last_system_time;
	
	float distance;
	float last_distance;
	float pre_last_distance;
	float vel;
	float acc;
	float last_vel;
}TOFSensor_Data;



void TOF_Statemachine(void);

extern TOFSensor_Data tofdata; 



#endif







