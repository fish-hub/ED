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
#include "Ringbuf.h"



/**
* @brief  RingBuff_Init
* @param  void
* @return void
* @author �ܽ�
* @date   2018
* @version v1.0
* @note   ��ʼ�����λ�����
*/
void RingBuff_Init(RingBuff_t *ringBuff)
{
  //��ʼ�������Ϣ
  ringBuff->Head = 0;
  ringBuff->Tail = 0;
  ringBuff->Lenght = 0;
}

/**
* @brief  Write_RingBuff
* @param  u8 data
* @return FLASE:���λ�����������д��ʧ��;TRUE:д��ɹ�
* @author �ܽ�
* @date   2018
* @version v1.0
* @note   �����λ�����д��u8���͵�����
*/
uint8_t Write_RingBuff(uint8_t data,RingBuff_t *ringBuff)
{
  if(ringBuff->Lenght >= RINGBUFF_LEN) //�жϻ������Ƿ�����
  {
    return 0;
  }
  ringBuff->Ring_Buff[ringBuff->Tail]=data;
  //ringBuff.Tail++;
  ringBuff->Tail = (ringBuff->Tail+1)%RINGBUFF_LEN;//��ֹԽ��Ƿ�����
  ringBuff->Lenght++;
  return 1;
}

/**
* @brief  Read_RingBuff
* @param  u8 *rData�����ڱ����ȡ������
* @return FLASE:���λ�����û�����ݣ���ȡʧ��;TRUE:��ȡ�ɹ�
* @author �ܽ�
* @date   2018
* @version v1.0
* @note   �ӻ��λ�������ȡһ��u8���͵�����
*/
uint8_t Read_RingBuff(uint8_t *rData,RingBuff_t *ringBuff)
{
  if(ringBuff->Lenght == 0)//�жϷǿ�
  {
    return 0;
  }
  *rData = ringBuff->Ring_Buff[ringBuff->Head];//�Ƚ��ȳ�FIFO���ӻ�����ͷ��
  //ringBuff.Head++;
  ringBuff->Head = (ringBuff->Head+1)%RINGBUFF_LEN;//��ֹԽ��Ƿ�����
  ringBuff->Lenght--;
  return 1;
}



void RingBuf_Write(unsigned char data,RingBuff_t *ringBuff,uint16_t Length)
{
  ringBuff->Ring_Buff[ringBuff->Tail]=data;//��β��׷��
  if(++ringBuff->Tail>=Length)//β�ڵ�ƫ��
    ringBuff->Tail=0;//����������󳤶� ���� �γɻ��ζ���  
  if(ringBuff->Tail==ringBuff->Head)//���β���ڵ�׷��ͷ���ڵ㣬���޸�ͷ�ڵ�ƫ��λ�ö�����������
  {
    if((++ringBuff->Head)>=Length)  
      ringBuff->Head=0; 
  }
}

uint8_t RingBuf_Read(unsigned char* pData,RingBuff_t *ringBuff)
{
  if(ringBuff->Head==ringBuff->Tail)  return 1;//���ͷβ�Ӵ���ʾ������Ϊ��
  else 
  {  
    *pData=ringBuff->Ring_Buff[ringBuff->Head];//����������ǿ���ȡͷ�ڵ�ֵ��ƫ��ͷ�ڵ�
    if((++ringBuff->Head)>=RINGBUFF_LEN)   ringBuff->Head=0;
    return 0;//����0����ʾ��ȡ���ݳɹ�
  }
}
