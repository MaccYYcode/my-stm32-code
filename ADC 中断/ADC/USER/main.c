#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "key.h"
#include "beep.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "adc.h"
extern __IO uint16_t ADC_Value;
float   ADC_Valuez;
int main (void)
{

LED_Init();
	delay_init();
		  ADC_GPIO_Config();
 ADC_Config();
ADC_NVIC_Config();   	   
		uart_init(115200);		  		
	BEEP_Init();         
	KEY_Init(); 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
LED0=0;	
	
while(1)
{
ADC_Valuez=(float)ADC_Value/4096*3.3;
	printf("当前检测的数字量为：0x%04X\r\n",ADC_Value);
		printf("当前检测到的模拟量为%fV\r\n",ADC_Valuez);
delay_ms(3000);
}



}




