#include "key.h"
#include "delay.h"



void KEY_Init(void)
{
GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	



}





//u8 KEY_Scan(u8 mode)
//{
//static u8 key_up=1;
//    key_up=1;
//	if(key_up&&(KEY0==0||KEY1==0||WK_UP==1))
//	{
//	delay_ms(10);
//		key_up=0;
//		if(KEY0==0)return KEY0_PRES;
//		else if(KEY1==0)return KEY1_PRES;
//		else if(WK_UP==1)return WKUP_PRES;
//		
//	}return 0;
//}

//uint8_t KEY_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
//{

//  if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0||GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==0||GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==1)
//	{
//	delay_ms(10);  /*����*/
//		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0)        /*�ж�KEY0����*/
//		{
//		while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0)      /*���ּ��*/
//			return KEY0_PRES;
//		
//		}
//		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==0)          /*�ж�KEY1����*/
//		{
//		while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==0)
//			return KEY1_PRES;
//		
//		}
//		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==1)               /*�ж�WK_UP����*/
//		{
//		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==1)
//			return WKUP_PRES;
//		
//		}
//		
//			
//				
//	
//	
//	
//	}return 0;   /*�ް�������*/
//		





//}

u8 KEY_Scan(u8 key)  
{
 static  u8 i=1;
	if(i==1&&(KEY0==0||KEY1==0|WK_UP==1))
	{  delay_ms(10);
		i=0;
		if(KEY0==0) key=1;
	  if(KEY1==0) key=2;
    if(WK_UP==1) key=3;
	}else if(KEY0==1&&KEY1==1&&WK_UP==0) i=1;
	return key;
}











