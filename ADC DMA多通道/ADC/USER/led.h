#ifndef  _LED_H
#define  _LED_H



#include "stm32f10x.h"

#define LED0 PBout(5)// PB5
#define LED1 PEout(5)// PE5	
void LED_Init(void);
#endif  /*_LED_H*/


