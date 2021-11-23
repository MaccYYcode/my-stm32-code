#include "lcd.h"

void LCD_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE | RCC_APB2Periph_GPIOG, ENABLE);


    //PB 背光
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //推挽
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);


    //复用推挽PD

    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);


    //复用推挽PE
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15 | GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    //复用推挽PG
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0 | GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOG, &GPIO_InitStructure);
}

void FSMC_Config(void)
{
    FSMC_NORSRAMInitTypeDef FSMC_NORSRAMInitStructure;
    FSMC_NORSRAMTimingInitTypeDef FSMC_ReadWriteTiming;
    FSMC_NORSRAMTimingInitTypeDef FSMC_WriteTiming;
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);
	
	
    FSMC_ReadWriteTiming.FSMC_AddressSetupTime = 0x01;	
    FSMC_ReadWriteTiming.FSMC_AddressHoldTime =0x00;
    FSMC_ReadWriteTiming.FSMC_DataSetupTime =0x0f;
    FSMC_ReadWriteTiming.FSMC_BusTurnAroundDuration = 0x00;
	  FSMC_ReadWriteTiming.FSMC_CLKDivision = 0x00;
	  FSMC_ReadWriteTiming.FSMC_DataLatency = 0x00;
	  FSMC_ReadWriteTiming.FSMC_AccessMode = FSMC_AccessMode_A;


     FSMC_WriteTiming.FSMC_AddressSetupTime = 0x00;
     FSMC_WriteTiming.FSMC_AddressHoldTime = 0x00;
     FSMC_WriteTiming.FSMC_DataSetupTime = 0x03;
     FSMC_WriteTiming.FSMC_BusTurnAroundDuration = 0x00;
     FSMC_WriteTiming.FSMC_CLKDivision = 0x00;
     FSMC_WriteTiming.FSMC_DataLatency = 0x00;
     FSMC_WriteTiming.FSMC_AccessMode = FSMC_AccessMode_A;


    FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM4;
    FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable; //不复用
    FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_SRAM;
    FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;
    FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
    FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait = FSMC_AsynchronousWait_Disable;
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
    FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
    FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
    FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
    FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Enable;
    FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
    FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &FSMC_ReadWriteTiming; //读写时序
    FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &FSMC_WriteTiming;
    FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);
		FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM4, ENABLE); 
}

  void Write_CMD(uint16_t usCmd) //写命令
{
            CMD_ADDR = usCmd;

}

 void Write_DATA(uint16_t usData) //写数据
{
            DATA_ADDR = usData;
}
	 uint16_t Read_data(void)  //读数据
	{
	         return(DATA_ADDR);
	}

	uint16_t Read_Pixel(void)  //读取像素格式
	{
	Write_CMD(0x0C);          //发送0x0C命令
	Read_data();               //接收数据
	return Read_data();
	}
	
	
	
	
	
	
	