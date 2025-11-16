#include "stm32f10x.h"

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOE, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_5);
	GPIO_SetBits(GPIOE, GPIO_Pin_5);
}

/**
  * @brief  On or off the LED
  * @param  LED_num: 0 is LED0(PB5) , 1 is LED1(PE5)
  * @param  operation: 1 is ON, 0 is off.
  *   This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */

void LED_Operation(int LED_num, _Bool operation)
{
	if (LED_num == 0)
	{
		if (operation)
		{
			GPIO_ResetBits(GPIOB, GPIO_Pin_5);
		}
		else
		{
			GPIO_SetBits(GPIOB, GPIO_Pin_5);
		}
	}
	else if (LED_num == 1)
	{
		if (operation)
		{
			GPIO_ResetBits(GPIOE, GPIO_Pin_5);
		}
		else
		{
			GPIO_SetBits(GPIOE, GPIO_Pin_5);
		}
	}
}

void LED_Turn(int LED_num)
{
	if (LED_num == 0)
	{
		if (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_5) == 0)
		{
			GPIO_SetBits(GPIOB, GPIO_Pin_5);
		}
		else
		{
			GPIO_ResetBits(GPIOB, GPIO_Pin_5);
		}
	}
	else if (LED_num ==1)
	{
		if (GPIO_ReadOutputDataBit(GPIOE, GPIO_Pin_5) == 0)
		{
			GPIO_SetBits(GPIOE, GPIO_Pin_5);
		}
		else
		{
			GPIO_ResetBits(GPIOE, GPIO_Pin_5);
		}
	}
}
