#ifndef _led_H
#define _led_H

#include "system.h"

/*  LEDʱ�Ӷ˿ڡ����Ŷ��� */
#define LED_PORT 			GPIOA  
#define LED_PIN 			GPIO_Pin_2
#define LED_PORT_RCC	RCC_APB2Periph_GPIOA

//#define led1 PCout(0)
//#define led2 PCout(1)
//#define led3 PCout(2)


void LED_Init(void);


#endif
