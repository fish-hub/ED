/* Copyright (c)  2018-2025 Wuhan Nameless Innovation Technology Co.,Ltd. All rights reserved.*/
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
*               �޸�����:2021/04/30                    
*               �汾��������PLUS����GankerPilot_V3.0
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
#include "Developer_Mode.h"


int8_t SDK1_Mode_Setup=0x00;
int8_t SDK2_Mode_Setup=0x00;
void Auto_Flight_Ctrl(uint8_t mode)
{
	switch(mode)
	{
    case 0://�û�����ָ����SDK������ģʽ
		{
			NCQ_SDK_Run();//�ں�ˮƽ����+�߶ȿ���
			Controller.yaw_outer_control_output  =RC_Data.rc_rpyt[RC_YAW];
			
		}
		break;		
    case 1://����OPENMV�Ӿ�׷��ɫ��
		{
			Color_Block_Control_Pliot();//����OPENMV�Ӿ�ˮƽ׷��
			Controller.yaw_outer_control_output  =RC_Data.rc_rpyt[RC_YAW];			
			Flight_Alt_Hold_Control(ALTHOLD_MANUAL_CTRL,NUL,NUL);//�߶ȿ���
		}
		break;
    case 2://����OPENMV�Ӿ�׷��AprilTag�������߼���׷��ɫ��һ��
		{
			Top_APrilTag_Control_Pliot();//����OPENMV�Ӿ�ˮƽ׷��
			Controller.yaw_outer_control_output  =RC_Data.rc_rpyt[RC_YAW];			
			Flight_Alt_Hold_Control(ALTHOLD_MANUAL_CTRL,NUL,NUL);//�߶ȿ���
		}
		break;		
    case 3://����OPENMVѭ�����ƣ�Ĭ�Ϻ��ߣ���ֵ����openmv�����е���
		{
			Self_Track_Control_Pliot();//ѭ�������ں���ˮƽ����+ƫ������
			Flight_Alt_Hold_Control(ALTHOLD_MANUAL_CTRL,NUL,NUL);//�߶ȿ���
			
		}
		break;
    case 4://ǰ��OPENMV�Ӿ�׷��	
		{
			Front_AprilTag_Control_Pliot();//ǰ��OPENMV�Ӿ�׷��
			Controller.yaw_outer_control_output  =RC_Data.rc_rpyt[RC_YAW];
			Flight_Alt_Hold_Control(ALTHOLD_MANUAL_CTRL,NUL,NUL);//�߶ȿ���
		}
		break;		
    case 5:
		{
		  //Ԥ��ģʽ1,д�ú���Ҫ��break����
		}
    case 6:
		{
		  //Ԥ��ģʽ2,д�ú���Ҫ��break����
		}
    case 7:
		{
		  //Ԥ��ģʽ3,д�ú���Ҫ��break����
		}
    case 8:
		{
		  //Ԥ��ģʽ4,д�ú���Ҫ��break����
		}
    case 9:
		{
		  //Ԥ��ģʽ5,д�ú���Ҫ��break����
		}
    case 10:
		{
		  //Ԥ��ģʽ6,д�ú���Ҫ��break����
		}
    case 11:
		{
		  //Ԥ��ģʽ7,д�ú���Ҫ��break����
		}
    case 12:
		{
		  //Ԥ��ģʽ8,д�ú���Ҫ��break����
		}
    case 13:
		{
		  //Ԥ��ģʽ9,д�ú���Ҫ��break����
		}
    case 14:
		{
		  //Ԥ��ģʽ10,д�ú���Ҫ��break����
		}
    case 15://ǰ��Ԥ��case�����������ִ�д�����
		{
			Controller.roll_outer_control_output =RC_Data.rc_rpyt[RC_ROLL];
			Controller.pitch_outer_control_output=RC_Data.rc_rpyt[RC_PITCH];
			Controller.yaw_outer_control_output  =RC_Data.rc_rpyt[RC_YAW];
			Flight_Alt_Hold_Control(ALTHOLD_MANUAL_CTRL,NUL,NUL);//�߶ȿ���
		}
		break;
		case 16://SDKģʽ��ԭ�ؽ��������浡�ٺ�ͣ��,��������ִ����ɺ���
		{
			OpticalFlow_Control(0);
			Controller.yaw_outer_control_output  =RC_Data.rc_rpyt[RC_YAW];
		  Flight_Alt_Hold_Control(ALTHOLD_AUTO_VEL_CTRL,NUL,-50);//�߶ȿ���
		}
    break;		
	  default:
		{
			Controller.roll_outer_control_output =RC_Data.rc_rpyt[RC_ROLL];
			Controller.pitch_outer_control_output=RC_Data.rc_rpyt[RC_PITCH];
			Controller.yaw_outer_control_output  =RC_Data.rc_rpyt[RC_YAW];
			Flight_Alt_Hold_Control(ALTHOLD_MANUAL_CTRL,NUL,NUL);//�߶ȿ���
		}
	}
}


