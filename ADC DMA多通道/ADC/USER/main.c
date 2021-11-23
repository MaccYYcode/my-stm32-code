#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "key.h"
#include "beep.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "adc.h"
extern __IO uint16_t ADC_Value[num];
float   ADC_Valuez[num];
int main (void)
{

LED_Init();
	delay_init();
		  ADC_GPIO_Config();
 ADC_Config();
   	  ADC_DMA_Config();  
		uart_init(115200);		  		
	BEEP_Init();         
	KEY_Init(); 
	
LED0=0;	
	

	while(1)
	{
	ADC_Valuez[0] = (float)ADC_Value[0]/4096*3.3;
	ADC_Valuez[1] = (float)ADC_Value[1]/4096*3.3;
	ADC_Valuez[2] = (float)ADC_Value[2]/4096*3.3;
		ADC_Valuez[3] = (float)ADC_Value[3]/4096*3.3;
		ADC_Valuez[4] = (float)ADC_Value[4]/4096*3.3;
		ADC_Valuez[5] = (float)ADC_Value[5]/4096*3.3;
		
		
		printf("ͨ��1��������Ϊ:0x%4x,ͨ��1��ģ����Ϊ��%fv\r\n",ADC_Value[0],ADC_Valuez[0]);
			printf("ͨ��2��������Ϊ:0x%4x,ͨ��1��ģ����Ϊ��%fv\r\n",ADC_Value[1],ADC_Valuez[1]);
			printf("ͨ��3��������Ϊ:0x%4x,ͨ��1��ģ����Ϊ��%fv\r\n",ADC_Value[2],ADC_Valuez[2]);
			printf("ͨ��4��������Ϊ:0x%4x,ͨ��1��ģ����Ϊ��%fv\r\n",ADC_Value[3],ADC_Valuez[3]);
			printf("ͨ��5��������Ϊ:0x%4x,ͨ��1��ģ����Ϊ��%fv\r\n",ADC_Value[4],ADC_Valuez[4]);
			printf("ͨ��6��������Ϊ:0x%4x,ͨ��1��ģ����Ϊ��%fv\r\n",ADC_Value[5],ADC_Valuez[5]);
		printf("\r\n\r\n");
		delay_ms(3000);	
	}



}




