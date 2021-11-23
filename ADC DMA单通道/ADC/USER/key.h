#ifndef  _KEY_H
#define  _KEY_H



#include "stm32f10x.h"



#define KEY0  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)//读取按键0
#define KEY1  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)//读取按键1
#define WK_UP   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//读取按键3(WK_UP) 
//#define KEY_ON   0
//#define KEY_OFF  1
//#define  KEY0_PRES      1
//#define  KEY1_PRES      2
//#define  WKUP_PRES      3
void KEY_Init(void);
//u8 KEY_Scan(u8);
//uint8_t KEY_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
u8 KEY_Scan(u8 key);
#endif  /*_KEY_H*/
