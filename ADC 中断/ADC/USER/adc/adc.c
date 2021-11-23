#include "adc.h"
__IO uint16_t ADC_Value;

void ADC_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOA, &GPIO_InitStructure);


}


void ADC_Config(void)
{
    ADC_InitTypeDef ADC_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;//����ģʽ
    ADC_InitStructure.ADC_ScanConvMode = DISABLE; //ɨ�����ڶ�ͨ��
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;//����ת��
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;//�������
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//�Ҷ���
    ADC_InitStructure.ADC_NbrOfChannel = 1;//Ҫת����ͨ����
    ADC_Init(ADC1, &ADC_InitStructure);
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);//PCLK2/8  =9M
    ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_239Cycles5);
    ADC_ITConfig(ADC1, ADC_IT_EOC, ENABLE); //�����ж�
    ADC_Cmd(ADC1, ENABLE);
    ADC_StartCalibration(ADC1);//У׼ADC

    while(ADC_GetCalibrationStatus(ADC1));//�ȴ�У׼���

    ADC_SoftwareStartConvCmd(ADC1, ENABLE); //ʹ��ָ����ADC1�����ת����������

}

void ADC_NVIC_Config(void)
{
    NVIC_InitTypeDef    NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = ADC1_2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);


}


void ADC1_2_IRQHandler(void)

{
    if (ADC_GetITStatus(ADC1, ADC_IT_EOC) == SET)
    {

        ADC_Value = ADC_GetConversionValue(ADC1);

    }

    ADC_ClearITPendingBit(ADC1, ADC_IT_EOC);
}



