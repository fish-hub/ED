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
#include "Filter.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//-----Butterworth����-----//
Butter_Parameter Butter_80HZ_Parameter_Acce,Butter_60HZ_Parameter_Acce,Butter_51HZ_Parameter_Acce,
Butter_30HZ_Parameter_Acce,Butter_20HZ_Parameter_Acce,Butter_15HZ_Parameter_Acce,
Butter_10HZ_Parameter_Acce,Butter_5HZ_Parameter_Acce,Butter_2HZ_Parameter_Acce;
Butter_Parameter Butter_5HZ_Parameter_RC;
Butter_Parameter Butterworth_Parameter_Baro,Butterworth_Parameter_Baro_Acc;
Butter_BufferData Butterworth_Buffer_Baro,Butterworth_Buffer_Baro_Acc;

Butter_BufferData Butter_Buffer[3];
Butter_BufferData Butter_Buffer_Feedback[3];
Butter_BufferData Butter_Buffer_SINS[3];
/****************************************
Butterworth��ͨ�˲���������ʼ����http://blog.csdn.net/u011992534/article/details/73743955
***************************************/
/***********************************************************
@��������Butterworth_Parameter_Init
@��ڲ�������
@���ڲ�������
����������������˹��ͨ�˲�����ʼ��
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void Butterworth_Parameter_Init(void)
{
  Set_Cutoff_Frequency(Imu_Sampling_Freq, 80,&Butter_80HZ_Parameter_Acce);
  Set_Cutoff_Frequency(Imu_Sampling_Freq, 60,&Butter_60HZ_Parameter_Acce);
  Set_Cutoff_Frequency(Imu_Sampling_Freq, 51,&Butter_51HZ_Parameter_Acce);
  Set_Cutoff_Frequency(Imu_Sampling_Freq, 30,&Butter_30HZ_Parameter_Acce);
  Set_Cutoff_Frequency(Imu_Sampling_Freq, 20,&Butter_20HZ_Parameter_Acce);
  Set_Cutoff_Frequency(Imu_Sampling_Freq, 15,&Butter_15HZ_Parameter_Acce);
  Set_Cutoff_Frequency(Imu_Sampling_Freq, 10,&Butter_10HZ_Parameter_Acce);
  Set_Cutoff_Frequency(Imu_Sampling_Freq, 5 ,&Butter_5HZ_Parameter_Acce);
  Set_Cutoff_Frequency(Imu_Sampling_Freq, 2 ,&Butter_2HZ_Parameter_Acce);
	Set_Cutoff_Frequency(50, 10 ,&Butter_5HZ_Parameter_RC);
  Set_Cutoff_Frequency(20, 2 ,&Butterworth_Parameter_Baro);
	Set_Cutoff_Frequency(20, 1.5 ,&Butterworth_Parameter_Baro_Acc);
	//IIR_High_Order_Init();
}

/*************************************************
������:	float LPButterworth(float curr_input,Butter_BufferData *Buffer,Butter_Parameter *Parameter)
˵��:	���ٶȼƵ�ͨ�˲���
���:	float curr_input ��ǰ������ٶȼ�,�˲����������˲�������
����:	��
��ע:	2��Butterworth��ͨ�˲���
*************************************************/
float LPButterworth(float curr_input,Butter_BufferData *Buffer,Butter_Parameter *Parameter)
{
	if(Buffer->Output_Butter[0]==0&&
		 Buffer->Output_Butter[1]==0&&
		 Buffer->Output_Butter[2]==0&&
		 Buffer->Input_Butter[0]==0&&
		 Buffer->Input_Butter[1]==0&&
		 Buffer->Input_Butter[2]==0)
	{
		Buffer->Output_Butter[0]=curr_input;
		Buffer->Output_Butter[1]=curr_input;
		Buffer->Output_Butter[2]=curr_input;
		Buffer->Input_Butter[0]=curr_input;
		Buffer->Input_Butter[1]=curr_input;
		Buffer->Input_Butter[2]=curr_input;
		return curr_input;
	}
	
  /* ���ٶȼ�Butterworth�˲� */
  /* ��ȡ����x(n) */
  Buffer->Input_Butter[2]=curr_input;
  /* Butterworth�˲� */
  Buffer->Output_Butter[2]=Parameter->b[0] * Buffer->Input_Butter[2]
													+Parameter->b[1] * Buffer->Input_Butter[1]
													+Parameter->b[2] * Buffer->Input_Butter[0]
													-Parameter->a[1] * Buffer->Output_Butter[1]
													-Parameter->a[2] * Buffer->Output_Butter[0];
  /* x(n) ���б��� */
  Buffer->Input_Butter[0]=Buffer->Input_Butter[1];
  Buffer->Input_Butter[1]=Buffer->Input_Butter[2];
  /* y(n) ���б��� */
  Buffer->Output_Butter[0]=Buffer->Output_Butter[1];
  Buffer->Output_Butter[1]=Buffer->Output_Butter[2];
	
	for(uint16_t i=0;i<3;i++)
	{
	  if(isnan(Buffer->Output_Butter[i])==1
			||isnan(Buffer->Input_Butter[i])==1)		
			{		
				Buffer->Output_Butter[0]=curr_input;
				Buffer->Output_Butter[1]=curr_input;
				Buffer->Output_Butter[2]=curr_input;
				Buffer->Input_Butter[0]=curr_input;
				Buffer->Input_Butter[1]=curr_input;
				Buffer->Input_Butter[2]=curr_input;
				return curr_input;
			}
	}	
  return Buffer->Output_Butter[2];
}

Butter_Parameter Notch_Filter_Parameter_55hz={
  //200hz---55hz-5hz  ����-�ݲ�Ƶ��-����
  1,   0.3008218748187,   0.9229897627825,
  0.9614948813912,   0.3008218748187,   0.9614948813912
};
Butter_Parameter Notch_Filter_Parameter_60hz={
  //200hz---60hz-5hz  ����-�ݲ�Ƶ��-����
  1,   0.5942365167088,   0.9229897627825,
  0.9614948813912,   0.5942365167088,   0.9614948813912
};
Butter_Parameter Notch_Filter_Parameter_65hz={
  //200hz---65hz-5hz  ����-�ݲ�Ƶ��-����
  1,   0.8730190833996,   0.9229897627825,
  0.9614948813912,   0.8730190833996,   0.9614948813912
};

Butter_Parameter Notch_Filter_Parameter_75hz={
  //200hz---75hz-50hz  ����-�ݲ�Ƶ��-����
  1,   0.9372808715784,   0.3255153203391,
  0.6627576601696,   0.9372808715784,   0.6627576601696
};
Notch_Filter_BufferData  Notch_Filter_Buffer;
/***********************************************************
@��������Notch_Filter
@��ڲ�����float curr_input,Notch_Filter_BufferData *Buffer
,Butter_Parameter *Parameter
@���ڲ������˲����
�����������ݲ��˲���
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
float Notch_Filter(float curr_input,Notch_Filter_BufferData *Buffer,Butter_Parameter *Parameter)
{
  float temp=0;
  /* ��ȡ����x(n) */ 
  Buffer->Output_Butter[0]= Parameter->a[0]*curr_input
    -Parameter->a[1]*Buffer->Output_Butter[1]
      -Parameter->a[2]*Buffer->Output_Butter[2];
  /* �����ݲ��˲������ */
  temp=Parameter->b[0]*Buffer->Output_Butter[0]
    +Parameter->b[1]*Buffer->Output_Butter[1]
      +Parameter->b[2]*Buffer->Output_Butter[2];
  /* y(n) ���б��� */
  Buffer->Output_Butter[2]=Buffer->Output_Butter[1];
  Buffer->Output_Butter[1]=Buffer->Output_Butter[0]; 
  return temp;
}



Butter_Parameter Bandstop_Filter_Parameter_30_98={
  //200hz---30hz-98hz  ����-���
  1,   0.627040f,  -0.290527f,
  0.354737f,   0.627040f,    0.354737f
};
Butter_Parameter Bandstop_Filter_Parameter_30_94={
  //200hz---30hz-94hz  ����-���
  1,   0.5334540355829,  -0.2235264828971,
  0.3882367585514,   0.5334540355829,   0.3882367585514
};

Butter_BufferData  Bandstop_Filter_Buffer[2];
/***********************************************************
@��������BPF_Butterworth
@��ڲ�����float curr_input,Notch_Filter_BufferData *Buffer
,Butter_Parameter *Parameter
@���ڲ������˲����
������������ͨ�˲���
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
float BPF_Butterworth(float curr_input,Butter_BufferData *Buffer,Butter_Parameter *Parameter)
{
	if(Buffer->Output_Butter[0]==0&&
		 Buffer->Output_Butter[1]==0&&
		 Buffer->Output_Butter[2]==0&&
		 Buffer->Input_Butter[0]==0&&
		 Buffer->Input_Butter[1]==0&&
		 Buffer->Input_Butter[2]==0)
	{
		Buffer->Output_Butter[0]=curr_input;
		Buffer->Output_Butter[1]=curr_input;
		Buffer->Output_Butter[2]=curr_input;
		Buffer->Input_Butter[0]=curr_input;
		Buffer->Input_Butter[1]=curr_input;
		Buffer->Input_Butter[2]=curr_input;
		return curr_input;
	}
	
  /* ���ٶȼ�Butterworth�˲� */
  /* ��ȡ����x(n) */
  Buffer->Input_Butter[2]=curr_input;
  /* Butterworth�˲� */
  Buffer->Output_Butter[2]=Parameter->b[0] * Buffer->Input_Butter[2]
													+Parameter->b[1] * Buffer->Input_Butter[1]
													+Parameter->b[2] * Buffer->Input_Butter[0]
													-Parameter->a[1] * Buffer->Output_Butter[1]
													-Parameter->a[2] * Buffer->Output_Butter[0];
  /* x(n) ���б��� */
  Buffer->Input_Butter[0]=Buffer->Input_Butter[1];
  Buffer->Input_Butter[1]=Buffer->Input_Butter[2];
  /* y(n) ���б��� */
  Buffer->Output_Butter[0]=Buffer->Output_Butter[1];
  Buffer->Output_Butter[1]=Buffer->Output_Butter[2];
	
	for(uint16_t i=0;i<3;i++)
	{
	  if(isnan(Buffer->Output_Butter[i])==1
			||isnan(Buffer->Input_Butter[i])==1)		
			{		
				Buffer->Output_Butter[0]=curr_input;
				Buffer->Output_Butter[1]=curr_input;
				Buffer->Output_Butter[2]=curr_input;
				Buffer->Input_Butter[0]=curr_input;
				Buffer->Input_Butter[1]=curr_input;
				Buffer->Input_Butter[2]=curr_input;
				return curr_input;
			}
	}	
  return Buffer->Output_Butter[2];
}




// discrete low pass filter, cuts out the
// high frequency noise that can drive the controller crazy
//derivative = _last_derivative + _d_lpf_alpha * (derivative - _last_derivative);
float set_lpf_alpha(int16_t cutoff_frequency, float time_step)
{
  // calculate alpha
  float lpf_alpha;
  float rc = 1/(2*PI*cutoff_frequency);
  lpf_alpha = time_step / (time_step + rc);
  return lpf_alpha;
}



//https://blog.csdn.net/sszhouplus/article/details/43113505
//https://blog.csdn.net/shengzhadon/article/details/46784509
//https://blog.csdn.net/shengzhadon/article/details/46791903
//https://blog.csdn.net/shengzhadon/article/details/46803401
/***********************************************************
@��������Set_Cutoff_Frequency
@��ڲ�����float sample_frequent, float cutoff_frequent,
Butter_Parameter *LPF
@���ڲ�������
����������������˹��ͨ�˲�����ʼ��
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void Set_Cutoff_Frequency(float sample_frequent, float cutoff_frequent,Butter_Parameter *LPF)
{
  float fr = sample_frequent / cutoff_frequent;
  float ohm = tanf(M_PI_F / fr);
  float c = 1.0f + 2.0f * cosf(M_PI_F / 4.0f) * ohm + ohm * ohm;
  if (cutoff_frequent <= 0.0f) {
    // no filtering
    return;
  }
  LPF->b[0] = ohm * ohm / c;
  LPF->b[1] = 2.0f * LPF->b[0];
  LPF->b[2] = LPF->b[0];
  LPF->a[0]=1.0f;
  LPF->a[1] = 2.0f * (ohm * ohm - 1.0f) / c;
  LPF->a[2] = (1.0f - 2.0f * cosf(M_PI_F / 4.0f) * ohm + ohm * ohm) / c;
}

float Filter_data[4];
void Test_Filter()
{
  static uint32_t Filter_Cnt=0;
  static float Ts=0.005f;
  Filter_Cnt++;
  Filter_data[0]=100*sin(2*PI*30*Filter_Cnt*Ts)
    +100*sin(2*PI*90*Filter_Cnt*Ts)
      //+100*sin(2*PI*150*Filter_Cnt*Ts)
      +100*sin(2*PI*75*Filter_Cnt*Ts);//����Ƶ�ʻ���ź�
  Filter_data[1]=Notch_Filter(Filter_data[0],&Notch_Filter_Buffer,&Notch_Filter_Parameter_75hz);
  Filter_data[2]=BPF_Butterworth(Filter_data[0],&Bandstop_Filter_Buffer[0],&Bandstop_Filter_Parameter_30_98);
  Filter_data[3]=BPF_Butterworth(Filter_data[0],&Bandstop_Filter_Buffer[1],&Butter_51HZ_Parameter_Acce);
}


//���´���Ϊ���������״��߽��˲�������������룬������Ȩ���У��������κ���ҵ��;
//���´���Ϊ���������״��߽��˲�������������룬������Ȩ���У��������κ���ҵ��;
//���´���Ϊ���������״��߽��˲�������������룬������Ȩ���У��������κ���ҵ��;
#define SYMBOL_ADD  0
#define SYMBOL_SUB  1
/*======================================================================
* ��������  pascalTriangle
* �������ܣ�����������ǵĵ�N�е�ֵ�����飩����ϵ��ֵΪ(x+1)^N��ϵ����
*         �ӸĽ�(x-1)^N��ϵ������ʹ����ڵ�һ��
*
* �������ƣ�
*          N      - ������ǵ�N�У�N=0,1,...,N
*          symbol - ������ţ�0����(x+1)^N��1����(x-1)^N
*          vector - �������飬������ǵĵ�N�е�ֵ
*
* ����ֵ��  void
*=====================================================================*/
void pascalTriangle(int N,int symbol,int *vector)
{
  vector[0] = 1;
  if(N == 0)
  {
    return;
  }
  else if (N == 1)
  {
    if(symbol == SYMBOL_ADD)
    {
      vector[1] = 1;
    }
    else
    {
      vector[0] = -1; //����Ǽ��ţ���ڶ���ϵ����-1
      vector[1] = 1;
    }
    return;
  }
  int length = N + 1; //���鳤��
  //int *temp;//[N];   //�����м����

  int temp[20];
	//int *temp=(int *)malloc(N*sizeof(int));
	//memset(temp,0,sizeof(int));
	
  temp[0] = 1;
  temp[1] = 1;
  
  for(int i = 2; i <= N; i++)
  {
    vector[i] = 1;
    for(int j = 1; j < i; j++)
    {
      vector[j] = temp[j - 1] + temp[j]; //x[m][n] = x[m-1][n-1] + x[m-1][n]
    }
    if(i == N) //���һ�β���Ҫ���м������ֵ
    {
      if(symbol == SYMBOL_SUB) //�����Ϊ����
      {
        for(int k = 0; k < length; k++)
        {
          vector[k] = vector[k] * pow(-1, length - 1 - k);
        }
      }
      return;
    }
    for(int j = 1; j <= i; j++)
    {
      temp[j] = vector[j];
    }
  }
	free(temp);
}

/*======================================================================
 * ��������  coefficientEquation����������coefficientEquation2����������
 * �������ܣ��������ʽ��˵�ϵ������ʹ����ڵ�һ��
 *
 * �������ƣ�
 *          originalCoef - ԭ����ϵ�����飬������ϵ��Ҳ�洢�ڸ�������
 *          N            - ԭ�����������ݵĳ��ȣ�����ʽ��ߴ�ΪN-1
 *          nextCoef     - ��ԭ������˵������ϵ�������
 *
 * ����ֵ��  void
 *=====================================================================*/
float tempCoef[20];
void coefficientEquation(int *originalCoef,int N,int *nextCoef,int nextN)
{    
		//tempCoef=(float *)malloc(sizeof(float)*(N+nextN-1)); //[N + nextN - 1];    //�м����
    for(int i = 0; i < N + nextN - 1; i++)
    {
        tempCoef[i] = originalCoef[i]; //�м������ʼ��
        originalCoef[i] = 0;
    }
    
    for(int j = 0; j < nextN; j++)
    {
        for(int i = j; i < N + nextN - 1; i++)
        {
            originalCoef[i] += tempCoef[i-j] * nextCoef[j];
        }
    }
		//free(tempCoef);
}

void coefficientEquation2(float *originalCoef,int N,float *nextCoef,int nextN)
{
    float tempCoef[N + nextN - 1];    //�м����
    for(int i = 0; i < N + nextN - 1; i++)
    {
        tempCoef[i] = originalCoef[i]; //�м������ʼ��
        originalCoef[i] = 0;
    }
    
    for(int j = 0; j < nextN; j++)
    {
        for(int i = j; i < N + nextN - 1; i++)
        {
            originalCoef[i] += tempCoef[i-j] * nextCoef[j];
        }
    }
}


float Data_X_MAG[N2];
float Data_Y_MAG[N2];
float Data_Z_MAG[N2];
/***********************************************************
@��������GildeAverageValueFilter_MAG
@��ڲ�����float NewValue,float *Data
@���ڲ�������
�������������������˲�
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
float GildeAverageValueFilter_MAG(float NewValue,float *Data)
{
  float sum;
  unsigned char i;
  Data[0]=NewValue;
  for(i=N2-1;i>0;i--)
  {
    sum+=Data[i];
    Data[i]=Data[i-1];
  }
  sum=sum/N2;
  return(sum);
}


//#define M_PI  PI

#define FILTER_IIR_BUTTER_LOW  0
#define FILTER_IIR_BUTTER_HIGH 1
#define FILTER_IIR_BUTTER_PASS 2
#define FILTER_IIR_BUTTER_STOP 3
//���������˹�˲���pbϵ���б�b0,b1,...,bn��
static float g_butterPb[10][10] = {{1.0,0,0,0,0,0,0,0,0,0},
    {1.0, 1.4142136, 0,0,0,0,0,0,0,0},
    {1.0, 2.0, 2.0, 0,0,0,0,0,0,0},
    {1.0, 2.6131259, 3.4142136, 2.6131259, 0,0,0,0,0,0},
    {1.0, 3.236068, 5.236068, 5.236068, 3.236068, 0,0,0,0,0},
    {1.0, 3.8637033, 7.4641016, 9.1416202, 7.4641016, 3.8637033, 0,0,0,0},
    {1.0, 4.4939592, 10.0978347, 14.5917939, 14.5917939, 10.0978347, 4.4939592, 0,0,0},
    {1.0, 5.1258309, 13.1370712, 21.8461510, 25.6883559, 21.8461510, 13.1370712, 5.1258309, 0,0},
    {1.0, 5.7587705, 16.5817187, 31.1634375, 41.9863857, 41.9863857, 31.1634375, 16.5817187, 5.7587705, 0},
    {1.0, 6.3924532, 20.4317291, 42.8020611, 64.8823963, 74.2334292, 64.8823963, 42.8020611, 20.4317291, 6.3924532}};
/*======================================================================
 * ��������  filterIIRButterLowpass
 * �������ܣ���ư�����˹������ͨʾ����
 *
 * �������ƣ�
 *          fpass - ͨ����ֹƵ�ʣ�ģ��Ƶ�ʣ�
 *          fstop - �����ֹƵ�ʣ�ģ��Ƶ�ʣ�
 *          rp    - ͨ�����˥����dB��
 *          rs    - �����С˥����dB��
 *          Fs    - ����Ƶ��
 *
 * ����ֵ��  ���ذ�����˹��ͨ�˲����Ľ���N�ͽ�ֹƵ��Ws�ṹ��
 *=====================================================================*/
ButterFilterStruct filterIIRButterLowpass( float passF_alpha,
	                                         float passF_beta,
																					 float stopF_alpha,
																					 float stopF_beta,
																					 float rp,
																					 float rs,
																					 float fs,
																					 int filterType)
{
    ButterFilterStruct nAndFc;      //�����˲����Ľ���N�ͽ�ֹƵ��fc
    nAndFc.filterType = filterType; //�˲�������
    float nOfN = 0.0;
    float passW = 0.0, stopW = 0.0, wa, wc; //wa = stopW/passW���䵼��
    float passF1 = 0.0, passF2 = 0.0, stopF1 = 0.0, stopF2 = 0.0, w0 = 0.0;//w0 - ����Ƶ��
    float passW1 = 0.0, passW2 = 0.0, stopW1 = 0.0, stopW2 = 0.0, fc = 0.0;
    
    rs = fabs(rs);
    rp = fabs(rp);
    passF1 = passF_alpha;
    stopF1 = stopF_alpha;
    
    //�����˲������ͣ�ѡ��ͬ��Ԥ���任ʽ
    switch (filterType) {
        case FILTER_IIR_BUTTER_LOW:
            if(passF1 >= stopF1)
            {
                nAndFc.isFOK = false;
                //NSLog(@"����Ӧ���㣺passF < stopF");
                return nAndFc;
            }
            
            nAndFc.isFOK = true;
            passW = tan(passF1 * M_PI / fs);    //���ֵ�ͨ��Ƶ��Ԥ����W = tan(w/2)
            stopW = tan(stopF1 * M_PI / fs);
            wa = fabs(stopW/passW);
            break;
        case FILTER_IIR_BUTTER_HIGH:
            if(passF1 <= stopF1)
            {
                nAndFc.isFOK = false;
                //NSLog(@"����Ӧ���㣺passF > stopF");
                return nAndFc;
            }
            
            nAndFc.isFOK = true;
            passW = 1/tan(passF1 * M_PI / fs); //���ָ�ͨ��Ƶ��Ԥ����W = cot(w/2)
            stopW = 1/tan(stopF1 * M_PI / fs);
            wa = fabs(stopW/passW);
            break;
            
        case FILTER_IIR_BUTTER_PASS:
            passF2 = passF_beta;
            stopF2 = stopF_beta;
            if(!(stopF1 < passF1 && passF1 < passF2 && passF2 < stopF2))
            {
                nAndFc.isFOK = false;
                //NSLog(@"����Ӧ���㣺stopF[1] < passF[1] < passF[2] < stopF[2]");
                return nAndFc;
            }
            
            nAndFc.isFOK = true;
            //ת��Ϊ����Ƶ�ʣ�������Ԥ����
            passW1 = 2 * M_PI * passF1 / fs;
            passW2 = 2 * M_PI * passF2 / fs;
            stopW1 = 2 * M_PI * stopF1 / fs;
            stopW2 = 2 * M_PI * stopF2 / fs;
            
            nAndFc.cosW0 = cos((passW1 + passW2)/2)/cos((passW1 - passW2)/2); //����cos(w0)
            w0 = acos(nAndFc.cosW0);//���ͨ�˲���������Ƶ��
            
            passW1 = (cos(w0)-cos(passW1))/sin(passW1);  //ͨ����ֹƵ��
            passW2 = (cos(w0)-cos(passW2))/sin(passW2);
            
            stopW1 = (cos(w0)-cos(stopW1))/sin(stopW1);
            stopW2 = (cos(w0)-cos(stopW2))/sin(stopW2);
            
            passW = MAX(passW1, passW2);                    //ͨ����ֹƵ��
            stopW = MIN(stopW1, stopW2);                    //�����ֹƵ��
            wa = fabs(stopW/passW);
            
            break;
            
        case FILTER_IIR_BUTTER_STOP:
            passF2 = passF_beta;
            stopF2 = stopF_beta;
            if(!(passF1 < stopF1 && stopF1 < stopF2 && stopF2 < passF2))
            {
                nAndFc.isFOK = false;
                //NSLog(@"����Ӧ���㣺passF[1] < stopF[1] < stopF[2] < passF[2]");
                return nAndFc;
            }
            
            nAndFc.isFOK = true;
            //ת��Ϊ����Ƶ�ʣ�������Ԥ����
            passW1 = 2 * M_PI * passF1 / fs;
            passW2 = 2 * M_PI * passF2 / fs;
            stopW1 = 2 * M_PI * stopF1 / fs;
            stopW2 = 2 * M_PI * stopF2 / fs;
            
            nAndFc.cosW0 = cos((stopW1 + stopW2)/2)/cos((stopW1 - stopW2)/2); //����cos(w0)
            w0 = acos(nAndFc.cosW0);//���ͨ�˲���������Ƶ��
            
            passW1 = sin(passW1)/(cos(passW1)-nAndFc.cosW0);  //ͨ����ֹƵ��
            passW2 = sin(passW2)/(cos(passW2)-nAndFc.cosW0);
            
            stopW1 = sin(stopW1)/(cos(stopW1)-nAndFc.cosW0);
            stopW2 = sin(stopW2)/(cos(stopW2)-nAndFc.cosW0);
            
            passW = MAX(passW1, passW2);                    //ͨ����ֹƵ��
            stopW = MIN(stopW1, stopW2);                    //�����ֹƵ��
            
            wa = fabs(stopW/passW);
            
            break;
            
        default:
            break;
    }
    nAndFc.fs = fs; //����Ƶ��
    
		nAndFc.N =ceil((double)(0.5f * log10((pow(10.0f, 0.1f*rs)-1.0f)/(pow(10.0f, 0.1f*rp)-1.0f))/log10(wa))); //����N
    
    nOfN = (float)nAndFc.N;   //��Nת��Ϊfloat��
    
    //�����˲������ͣ�ѡ��ͬ��Ԥ���任ʽ
    switch (filterType) {
        case FILTER_IIR_BUTTER_LOW:
            wc = stopW / pow((pow(10.0f, 0.1f*rs) - 1.0f), 1.0f/(2*nOfN));
            nAndFc.fc = fs/M_PI*atan(wc);                         //�����ֹƵ��(3dB)Hz
            
            nAndFc.length = nAndFc.N + 1; //ϵ�����鳤��
            
            break;
            
        case FILTER_IIR_BUTTER_HIGH:
            wc = stopW / pow((pow(10.0f, 0.1f*rs) - 1.0f), 1.0f/(2*nOfN));
            //wc = passW / pow((pow(10, 0.1*rp) - 1), 1/(2*nOfN));
            
            nAndFc.fc = fs/M_PI*atan(1/wc); //�����ֹƵ��(3dB)Hz
            
            nAndFc.length = nAndFc.N + 1; //ϵ�����鳤��
            
            break;
            
        case FILTER_IIR_BUTTER_PASS:
            wc = stopW1 / pow((pow(10.0f, 0.1f*rs) - 1.0f), 1.0f/(2*nOfN));
            fc =asin((2*cos(w0)*wc + sqrt(pow(2*cos(w0)*wc, 2)-4*(wc*wc+1)*(cos(w0)*cos(w0)-1)))/(2*wc*wc+2));
            
//            wc = passW1 / pow((pow(10, 0.1*rp) - 1), 1/(2*nOfN));
//            fc =asin((2*cos(w0)*wc + sqrt(pow(2*cos(w0)*wc, 2)-4*(wc*wc+1)*(cos(w0)*cos(w0)-1)))/(2*wc*wc+2));
            
            nAndFc.fc = fs / (2*M_PI) * fc;
            
            nAndFc.length = 2 * nAndFc.N + 1; //ϵ�����鳤��
            
            break;
        
        case FILTER_IIR_BUTTER_STOP:
            wc = -1.0f/(stopW1 / pow((pow(10.0f, 0.1f*rs) - 1.0f), 1.0f/(2*nOfN)));
            fc =asin((2*cos(w0)*wc + sqrt(pow(2*cos(w0)*wc, 2)-4*(wc*wc+1)*(cos(w0)*cos(w0)-1)))/(2*wc*wc+2));
            
            nAndFc.fc = fs / (2*M_PI) * fc;
            
            nAndFc.length = 2 * nAndFc.N + 1; //ϵ�����鳤��
            break;
        default:
            break;
    }
    return nAndFc;
}



/*======================================================================
 * ��������  butterSbValue
 * �������ܣ����������˹�˲�����ĸ����ʽH(s)��ϵ��Sb��ע�⣺����ΪWc^N
 * ˵����   Sb[k] = Wc^(N-k) * Pb������Pb�ǹ�һ���ķ�ĸ����ʽ�ĸ����ɲ��õ�
 *         ϵ���ɵʹ���ߴ�����
 *
 * �������ƣ�
 *          butterValue   - ����˲��������������ͽ�ֹƵ�ʣ��Ľṹ�����
 *          returnSb      - ������
 *
 * ����ֵ��  void
 *=====================================================================*/
void butterSbValue(ButterFilterStruct *butterValue)
{
    int length = butterValue->N;        //�˲�������
    float Wc = 0.0;                   //�˲����Ľ�ֹƵ�� 
    //ѡ��Ԥ������
    switch (butterValue->filterType) {
        case FILTER_IIR_BUTTER_LOW:
            Wc = fabs(tan(butterValue->fc * M_PI / butterValue->fs));
            break;       
        case FILTER_IIR_BUTTER_HIGH:
            Wc = fabs(1/tan(butterValue->fc * M_PI / butterValue->fs));
            break;
        case FILTER_IIR_BUTTER_PASS:
            Wc = 2 * M_PI * butterValue->fc / butterValue->fs;
            Wc = fabs((butterValue->cosW0 - cos(Wc))/sin(Wc));
            break;
        case FILTER_IIR_BUTTER_STOP:
            Wc = 2 * M_PI * butterValue->fc / butterValue->fs;
            Wc = fabs(sin(Wc)/(cos(Wc) - butterValue->cosW0));      
            break;
        default:
            break;
    }  
    for(int i = 0; i < length; i++)
    {
        butterValue->sbvalue[i] = g_butterPb[length - 1][i] * pow(Wc, length-i); //����ϵ��
    }  
    butterValue->sbvalue[length] = 1.0; //��ߴ��ݵ�ϵ��Ϊ1
}




/*======================================================================
 * ��������  butterLowOrHigh
 * �������ܣ����������˹��ͨ����ͨ���˲���ϵͳ������ϵ�����������Ӻͷ�ĸϵ��
 *
 * �������ƣ�
 *          butterValue   - ����˲��������������ͽ�ֹƵ�ʣ��Ľṹ�����
 *          sb            - �����ģ���˲�����ϵ������H(s)�ķ�ĸϵ��
 *          numerator     - �����ķ���ϵ������
 *          denominator   - �����ķ�ĸϵ������
 *
 * ����ֵ��  void
 *=====================================================================*/
void butterLowOrHigh(ButterFilterStruct *butterValue)
{
    int length = butterValue->N;    //�˲�������   
    int tempCoef1[20];//[length + 1];     //����ϵ�����飬���ڴ��1 - z^(-1)��1 + z^(-1)ÿ����ݣ�0-N��ϵ������ʹ��ڵ�һ��
    int tempCoef2[20];//[length + 1];
	  //tempCoef1=(int *)malloc(sizeof(int)*(length + 1));
	  //tempCoef2=(int *)malloc(sizeof(int)*(length + 1));
		//free(tempCoef1);
		///free(tempCoef2);
    int otherN;                    //1+z^(-1)�Ĵ���
    float Fsx2 = 1;//butterValue.fs * 2; //����2/T  
    for(int i = 0; i<= length; i++)
    {
        butterValue->num[i] = 0.0;   //��ʼ��numerator��denominator
        butterValue->den[i] = 0.0;
    }    
    for(int i = 0; i <= length; i++)
    {
        for(int j = 0; j<= length; j++)
        {
            tempCoef1[j] = 0;     //tempCoef1��tempCoef2���г�ʼ��
            tempCoef2[j] = 0;
        }        
        otherN = length - i;
        if(butterValue->filterType == FILTER_IIR_BUTTER_LOW)
        {
					   pascalTriangle(i,SYMBOL_SUB,tempCoef1);//����������Ǽ���1 - z^(-1)�ݵ�ϵ��
             pascalTriangle(otherN,SYMBOL_ADD,tempCoef2);////����������Ǽ���1 + z^(-1)�ݵ�ϵ��
        }
        else
        {
						 pascalTriangle(i,SYMBOL_ADD,tempCoef1); //����������Ǽ���1 + z^(-1)�ݵ�ϵ��
             pascalTriangle(otherN,SYMBOL_SUB,tempCoef2);//����������Ǽ���1 - z^(-1)�ݵ�ϵ��
        }        
        coefficientEquation(tempCoef1,i+1,tempCoef2,otherN+1); //��������ʽ��ˣ�����ϵ�� 	
        for(int j = 0; j <= length; j++)
        {
            butterValue->den[j] += pow(Fsx2, i) * (float)tempCoef1[length - j] * butterValue->sbvalue[i];
        }      
        //����ϵ��
        if(i == 0)
        {
            for(int j = 0; j <= length; j++)
            {
                butterValue->num[j] = butterValue->sbvalue[0] * tempCoef2[length - j];
            }
        }
    } 
    //ϵ����һ������ĸ�ĳ�����Ϊ1
    for(int i = length; i >= 0; i--)
    {
        butterValue->num[i] = butterValue->num[i] / butterValue->den[0];
        butterValue->den[i] = butterValue->den[i] / butterValue->den[0];
    }
		//free(tempCoef1);
		//free(tempCoef2);
}


/*======================================================================
 * ��������  butterPassOrStop
 * �������ܣ����������˹��ͨ�����裩�˲���ϵͳ������ϵ�����������Ӻͷ�ĸϵ��
 *
 * �������ƣ�
 *          butterValue   - ����˲��������������ͽ�ֹƵ�ʣ��Ľṹ�����
 *          sb            - �����ģ���˲�����ϵ������H(s)�ķ�ĸϵ��
 *          numerator     - �����ķ���ϵ������
 *          denominator   - �����ķ�ĸϵ������
 *
 * ����ֵ��  void
 *=====================================================================*/
 
void butterPassOrStop(ButterFilterStruct butterValue,float *sb,float *numerator,float *denominator)
{
    int length = butterValue.length;      //�˲���ϵ������   
    int tempCoef1[length];                //����ϵ�����飬���ڴ��1 - z^(-2)��1 - 2*cos(w0)*z^(-1) + z^(-2)ÿ����ݣ�0-N��ϵ������ʹ��ڵ�һ��
    float tempCoef2[length];
    float tempCoef3[length], tempCoef[3];
    int otherN;                           //1+z^(-1)�Ĵ�����pass��,1 - 2*cos(w0)*z^(-1) + z^(-2)�Ĵ�����stop��   
    float Fsx2 = 1;//butterValue.fs * 2;  //����2/T = 1    
    for(int i = 0; i < length; i++)
    {
        numerator[i] = 0.0;   //��ʼ��numerator��denominator
        denominator[i] = 0.0;
        tempCoef1[i] = 0;     //tempCoef1��tempCoef2���г�ʼ��
        tempCoef2[i] = 0.0;
        tempCoef3[i] = 0.0;
    }    
    tempCoef[0] = 1.0;
    tempCoef[1] = -2.0 * butterValue.cosW0;
    tempCoef[2] = 1.0;    
    //----------�������ϵ��-----------
    if(butterValue.filterType == FILTER_IIR_BUTTER_PASS) //��ͨ�˲���
    {
			  pascalTriangle(butterValue.N,SYMBOL_SUB,tempCoef1);//����������Ǽ���1 - z^(-1)�ݵ�ϵ��       
        for(int i = 0; i < length; i++)  //��Ϊ1 - z^(-2)�ݵ�ϵ������������0
        {
            int temp = i%2;  //�ж�i��ż
            if(!temp)        //ż���ݲ�Ϊ0
                numerator[i] = sb[0] * tempCoef1[butterValue.N - i/2];
            else
                numerator[i] = 0.0;
        }
    }
    else //�����˲���
    {
        tempCoef3[0] = 1.0;                       //1 - 2*cos(w0)*z^(-1) + z^(-2)��ϵ��1,-2cos(w0),1
        tempCoef3[1] = -2.0 * butterValue.cosW0;
        tempCoef3[2] = 1.0;
        
        for(int j = 1; j < butterValue.N; j++)
        {
					   coefficientEquation2(tempCoef3,j*2+1,tempCoef,3);
        }
        for(int i = 0; i < length; i++)
        {
            numerator[i] = sb[0] * tempCoef3[length - i - 1];
        }
    }
    
    //----------�����ĸϵ��,����ÿһ������ϵ��----------
    for(int i = 0; i <= butterValue.N; i++)
    {
        if(butterValue.filterType == FILTER_IIR_BUTTER_PASS)
        {
            otherN = butterValue.N - i;
        }
        else
        {
            otherN = i;
        }
        
        for(int j = 0; j < length; j++)
        {
            tempCoef1[j] = 0;     //tempCoef1��tempCoef2��tempCoef3���г�ʼ��
            tempCoef2[j] = 0.0;
            tempCoef3[j] = 0.0;
        }
        tempCoef3[0] = 1.0;
        if(butterValue.N - otherN > 0) //����0�����ʱ����һ��Ϊ1������Ϊ0
        {
            tempCoef3[1] = -2.0 * butterValue.cosW0;
            tempCoef3[2] = 1.0;
        }
 
        pascalTriangle(otherN,SYMBOL_SUB,tempCoef1);//����������Ǽ���1 - z^(-1)�ݵ�ϵ��
        for(int j = 0; j < otherN*2+1; j++)  //��Ϊ1 - z^(-2)�ݵ�ϵ������������0
        {
            int temp = j%2;  //�ж�i��ż
            if(!temp)        //ż���ݲ�Ϊ0
            {
                tempCoef2[j] = (float)tempCoef1[j/2];
                tempCoef1[j/2] = 0;
            }
            else
                tempCoef2[j] = 0.0;
        }
        
        //���ö���ʽ��˷�������1 - 2*cos(w0)*z^(-1) + z^(-2)�ݵ�ϵ��,j��ʾ�ڼ������
        for(int j = 1; j < butterValue.N - otherN; j++)
        {
					  coefficientEquation2(tempCoef3,j*2+1,tempCoef,3);
        }
        
        coefficientEquation2(tempCoef3,(butterValue.N - otherN)*2+1,tempCoef2,2*otherN+1); //��������ʽ��ˣ�����ϵ��
        for(int j = 0; j < length; j++)
        {
            denominator[j] += pow(Fsx2, i) * tempCoef3[length - j - 1] * sb[i];
        }
    }
    
    //ϵ����һ������ĸ�ĳ�����Ϊ1
    for(int i = length - 1; i >= 0; i--)
    {
        numerator[i] = numerator[i] / denominator[0];
        denominator[i] = denominator[i] / denominator[0];
    }
}



 
 
/*======================================================================
 * ��������  filter
 * �������ܣ����������˲���ϵͳ������ϵ��������ԭʼ�źŽ����˲�
 *
 * �������ƣ�
 *          butterValue   - ����˲��������������ͽ�ֹƵ�ʣ��Ľṹ�����
 *          numerator     - ϵͳ����������ϵ������
 *          denominator   - ϵͳ��������ĸϵ������
 *          xVector       - �����ԭʼ�źţ����飩
 *          length        - ԭʼ�źŵĳ��ȣ�Ҳ���˲����źŵĳ���
 *          yVector       - �˲�����źţ����飩
 *
 * ����ֵ��  ����Ƿ�ɹ���true-�ɹ���false-ʧ��
 *=====================================================================*/
 
bool filter(ButterFilterStruct butterValue,float *numerator,float *denominator,float *xVector,int length,float *yVector)
{
    bool isFilterOK = false;  
    if(!butterValue.isFOK)
    {
        //NSLog(@"ϵͳ��������");
        isFilterOK = false;
        return isFilterOK;
    }
    if(butterValue.N > 10)
    {
        //NSLog(@"ʧ�ܣ��˲����Ľ������ܴ���10��");
        isFilterOK = false;
        return isFilterOK;
    }
    int N = butterValue.length; //ϵ������ĳ��� 
    //����ֵ��ʼ��
    for(int i = 0; i < length; i++)
    {
        yVector[i] = 0.0; //����ѭ�����õ�y�ݹ��㷨����Ҫ��ǰ��ʼ��
    }   
    //��һ��ѭ��������length��y�����ֵ
    for(int i = 0; i < length; i++)
    {
        if(i == 0)
        {
            yVector[i] = numerator[i]*xVector[i];
        }
        else
        {
            yVector[i] = numerator[0]*xVector[i];
            //�ڶ���ѭ��������ÿ��y��ÿһ��
            for(int j = 1; j <= i && j < N; j++)
            {
                yVector[i] += numerator[j]*xVector[i-j] - denominator[j]*yVector[i-j];
            }
        }
        yVector[i] /= denominator[0];
    } 
    isFilterOK = true;
    return isFilterOK;
}

/*======================================================================
 * ��������  filter
 * �������ܣ����������˲���ϵͳ������ϵ��������ԭʼ�źŽ����˲�
 *
 * �������ƣ�
 *          butterValue   - ����˲��������������ͽ�ֹƵ�ʣ��Ľṹ�����
 *          numerator     - ϵͳ����������ϵ������
 *          denominator   - ϵͳ��������ĸϵ������
 *          xVector       - �����ԭʼ�źţ����飩
 *          length        - ԭʼ�źŵĳ��ȣ�Ҳ���˲����źŵĳ���
 *          yVector       - �˲�����źţ����飩
 *
 * ����ֵ��  ����Ƿ�ɹ���true-�ɹ���false-ʧ��
 *=====================================================================*/
 
bool IIR_High_Order_Filter(ButterFilterStruct *butterValue,float data)
{
    bool isFilterOK = false;  
    if(!butterValue->isFOK)
    {
        //NSLog(@"ϵͳ��������");
        isFilterOK = false;
        return isFilterOK;
    }
    if(butterValue->N > 10)
    {
        //NSLog(@"ʧ�ܣ��˲����Ľ������ܴ���10��");
        isFilterOK = false;
        return isFilterOK;
    }
    int N = butterValue->length; //ϵ������ĳ��� 
    butterValue->input[N-1]=data;
		
    //��һ��ѭ��������length��y�����ֵ
    butterValue->output[N-1]=0;
		 for(int i = 0; i < N; i++)
    {
      butterValue->output[N-1]+=butterValue->num[i]*butterValue->input[N-1-i];
    }
     for(int i = 1; i < N; i++)
    {
      butterValue->output[N-1]-=butterValue->den[i]*butterValue->output[N-1-i];
    }
		for(int i = 0; i < N; i++)
		{
		  butterValue->output[i]=butterValue->output[i+1];
			butterValue->input[i] =butterValue->input[i+1];
		}
		
		for(int i = 0; i <=N; i++)
		{
			if(isnan(butterValue->output[i])==1)
			{
				for(int j = 0; j<=N; j++)
				{
					butterValue->output[j]=data;
				}
			}
	 }		
    isFilterOK = true;
    return isFilterOK;
}

ButterFilterStruct Gyro_X_Butter_Filter,Gyro_Y_Butter_Filter,Gyro_Z_Butter_Filter;
ButterFilterStruct Accel_X_Butter_Filter,Accel_Y_Butter_Filter,Accel_Z_Butter_Filter;
ButterFilterStruct Accel_X_INS,Accel_Y_INS,Accel_Z_INS;
void IIR_High_Order_Init(void)
{
	//���ٶȼƸ߽׵�ͨ�˲�����
	Accel_Z_Butter_Filter=filterIIRButterLowpass(20,0,30,0,1,20,200,FILTER_IIR_BUTTER_LOW);//���1dB˥��ͨ�����������20DB˥��
	butterSbValue(&Accel_Z_Butter_Filter);
	butterLowOrHigh(&Accel_Z_Butter_Filter);	
	
	Accel_Y_Butter_Filter=filterIIRButterLowpass(20,0,30,0,1,20,200,FILTER_IIR_BUTTER_LOW);
  butterSbValue(&Accel_Y_Butter_Filter);
	butterLowOrHigh(&Accel_Y_Butter_Filter);
	
  Accel_X_Butter_Filter=filterIIRButterLowpass(20,0,30,0,1,20,200,FILTER_IIR_BUTTER_LOW);
	butterSbValue(&Accel_X_Butter_Filter);
	butterLowOrHigh(&Accel_X_Butter_Filter);	
	for(uint16_t i=0;i<100;i++)
	{
		IIR_High_Order_Filter(&Accel_X_Butter_Filter,0.0f);
		IIR_High_Order_Filter(&Accel_Y_Butter_Filter,0.0f);
		IIR_High_Order_Filter(&Accel_Z_Butter_Filter,AcceMax);		
	}	
////////////////////////////////////////////	
	
		//���ٶȼƸ߽׵�ͨ�˲�����
	Accel_X_INS=filterIIRButterLowpass(30,0,90,0,1,80,200,FILTER_IIR_BUTTER_LOW);//���1dB˥��ͨ�����������40DB˥��
	butterSbValue(&Accel_X_INS);
	butterLowOrHigh(&Accel_X_INS);	
	
	Accel_Y_INS=filterIIRButterLowpass(30,0,90,0,1,80,200,FILTER_IIR_BUTTER_LOW);//70  40
  butterSbValue(&Accel_Y_INS);
	butterLowOrHigh(&Accel_Y_INS);
	
  Accel_Z_INS=filterIIRButterLowpass(30,0,90,0,1,80,200,FILTER_IIR_BUTTER_LOW);
	butterSbValue(&Accel_Z_INS);
	butterLowOrHigh(&Accel_Z_INS);	
	for(uint16_t i=0;i<100;i++)
	{
		IIR_High_Order_Filter(&Accel_X_INS,0.0f);
		IIR_High_Order_Filter(&Accel_Y_INS,0.0f);
		IIR_High_Order_Filter(&Accel_Z_INS,AcceMax);		
	}	
	
///////////////////////////////////////////////	
	//�����Ǹ߽׵�ͨ�˲�����
	Gyro_X_Butter_Filter=filterIIRButterLowpass(50,0,70,0,0.5,20,200,FILTER_IIR_BUTTER_LOW);//���1dB˥��ͨ�����������20DB˥��
	butterSbValue(&Gyro_X_Butter_Filter);
	butterLowOrHigh(&Gyro_X_Butter_Filter);	
	
	Gyro_Y_Butter_Filter=filterIIRButterLowpass(50,0,70,0,0.5,20,200,FILTER_IIR_BUTTER_LOW);
  butterSbValue(&Gyro_Y_Butter_Filter);
	butterLowOrHigh(&Gyro_Y_Butter_Filter);
	
  Gyro_Z_Butter_Filter=filterIIRButterLowpass(50,0,70,0,0.5,20,200,FILTER_IIR_BUTTER_LOW);
	butterSbValue(&Gyro_Z_Butter_Filter);
	butterLowOrHigh(&Gyro_Z_Butter_Filter);	
	for(uint16_t i=0;i<200;i++)
	{	
		IIR_High_Order_Filter(&Gyro_X_Butter_Filter,0.0f);
		IIR_High_Order_Filter(&Gyro_Y_Butter_Filter,0.0f);
		IIR_High_Order_Filter(&Gyro_Z_Butter_Filter,0.0f);		
	}		
}

