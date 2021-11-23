#ifndef  _LCD_H
#define  _LCD_H



#include "stm32f10x.h"
#define CMD_ADDR  *(__IO uint16_t*)(0x6C000000)
#define DATA_ADDR *(__IO uint16_t*)(0x6C000800)
#define LCD_LED PB(0) //±³¹â


#define setxcmd  2A
#define setycmd  2B
#define wramcmd  2C
#define rramcmd  2E
#endif  /*_LCD_H*/



