/* Copyright (c)  2019-2025 Wuhan Nameless Innovation Technology Co.,Ltd. All rights reserved.*/
/*----------------------------------------------------------------------------------------------------------------------/
                ��Դ����������ѣ������ߵ���ʷ�Ѿ�֤�����ڹ�����������£���������Ŀ�Դ������������˰����ߣ��Է��ز�����
								Ŀ���Ƶķ�ʽ�в�ͨ���õĿ�Դ��Ŀ��Ҫ��רְ��Ա�����ۺ�����ְ��ֽ�ѧ��ͳ���û�����������ʵ������ɶԲ�
								Ʒ��һ�δ���������������������ۺϿ��ǣ������ɿؿ�Դ�����У������������˾���漤��ܴ��룬�汾������ʵ��
								���ܣ����ڹ�˾��Ʒ���������������Ӱ��ͻ�ѧϰ���������ȫ�����Ÿ��ͻ�ѧϰ���ͻ���ֲ�Ͷ��ο��������뱣����
								���Ȩ��
-----------------------------------------------------------------------------------------------------------------------/
*               ������ֻ��������ѧϰʹ�ã���Ȩ����Ȩ���������ƴ��Ŷӣ������ƴ��Ŷӽ��ɿس���Դ���ṩ�������ߣ�
*               ������ҪΪ�����ƴ��Ŷ��ṩ������δ���������ɣ����ý�Դ�����ṩ�����ˣ����ý�Դ����ŵ����Ϲ�����������أ� 
*               �������Դ�����Ĳ�����緢��������Ϊ�������ƴ��Ŷӽ���֮�Է��ɽ��������
-----------------------------------------------------------------------------------------------------------------------
*                                                 Ϊʲôѡ���������£�
*                                         �ж����ļ۸�������׵Ŀ�Դ�ɿأ�
*                                         ����ҵ������֮������µ��ۺ����
*                                         ׷�����û����飬��Ч����ѧϰ֮·��
*                                         ���²��ٹµ��������������տ�Դ�߶ȣ�
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
*               ���ߣ���˾����ǰ��֪����1���ڼ�ʱ�������������ѧУ����λ����������
*               ������ַ��Ϣ�ᱻ�����ڹ�˾�������ٷ�΢�Ź���ƽ̨���ٷ��������͡�֪��
*               ר���Լ��Ա�������ҳ���Թ�ʾ���棬����������Ϊ�����Ϊ�����۵㣬Ӱ��
*               ��ѧ���ҹ���������������ܿ�ͺ������˻����������������ء�
*               �����Ϊ����˾����ش���ʧ�ߣ����Է���;���������л���ĺ�����лл������
----------------------------------------------------------------------------------------------------------------------*/
#include "Headfile.h"
/***********************************************************
@��������main
@��ڲ�������
@���ڲ�������
@��������������������ϵͳоƬ��Դ���ɿ�������г�ʼ����ִ��
while��1���������Ҫ�������Ҫ������ָ������û���ϸ�Ҫ�����
ִ��ʱ�����غ�ʱ���Ӻ��������磺��ѹ�ɼ�������ɨ�衢��ʾ��ˢ 
�¡�����վ���͡����ٶȼƱ궨�������Ʊ궨��ң�����г̱궨����
������ȡ�
@���ߣ�����С��
@���ڣ�2020��10��25��
*************************************************************/
int main(void)
{
  HardWave_Init();//оƬ��Դ���ɿ������ʼ��	
  while(1)//��ѭ��
  {	
		Get_Battery_Voltage();//������ص�ѹ		
		Key_Scan(Key_Right_Release);//����ɨ��
		QuadShow(Oled_Show_Enable);//OLED��ʾ���ɿ���������ͬʱ���£�ֹͣ/�ָ��Զ�ˢ��
		Accel_Calibartion();//���ٶȼ�6��У׼
		Mag_Calibartion_LS(&WP_Sensor.mag_raw,Circle_Angle);//����������У׼
		RC_Calibration_Check(PPM_Databuf);//ң�����г�У׼
		Save_Or_Reset_PID_Parameter();//���õ���վ���޸Ŀ��Ʋ���
  }
}


/******************************���ú��а�������ӭ����һ���ȸ��棨��ƴ�������Ϻ��ں����ȸ���4Ԫһ�룩������С��֧������1094744141@qq.com********/
/******************************���ڽֵ��������ģ�ԭ�������ȸ���̯�Ѳ������ӭ����һƿ��������������**************************************************/
/*
																																		 _oo0oo_
																																		o8888888o
																																		88" . "88
																																		(| -_- |)
																																		0\  =  /0
																																	___/`---'\___
																																.' \\|     |// '.
																															 / \\|||  :  |||// \
																															/ _||||| -:- |||||- \
																														 |   | \\\  -  /// |   |
																														 | \_|  ''\---/''  |_/ |
																														 \  .-\__  '-'  ___/-. /
																													 ___'. .'  /--.--\  `. .'___
																												."" '<  `.___\_<|>_/___.' >' "".
																											 | | :  `- \`.;`\ _ /`;.`/ - ` : | |
																											 \  \ `_.   \_ __\ /__ _/   .-` /  /
																									 =====`-.____`.___ \_____/___.-`___.-'=====
																																		 `=---='
*/
