#include "string.h"
#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "esp8266.h"

int main()
{
	u8 i=0; 
	u16 data=1234;
	float fdata=12.34;
	char str[]="Hello World!";	
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //中断优先级分组 分2组
	LED_Init();
	USART1_Init(115200);//串口波特率115200
  ESP8266_Init();
	
	//订阅发布指令
	printf("AT+MQTTSUB=0,\"/a5ZLiiHWg1j/ttcan/user/get\",1\r\n");		//订阅指令
	delay_ms(5000);	
	//GPIO_SetBits(LED_PORT,LED_PIN);		//LED=1	灭

	printf("AT+MQTTPUB=0,\"/a5ZLiiHWg1j/ttcan/user/update\",\"{\\\"LED\\\":1}\",1,0\r\n");		//发数据{"LED":1}
	delay_ms(5000);			//延迟
	
	printf("AT+MQTTPUB=0,\"/a5ZLiiHWg1j/ttcan/user/update\",\"{\\\"LED\\\":0}\",1,0\r\n");		//发数据{"LED":0}
	delay_ms(5000);			//延迟

  GPIO_ResetBits(LED_PORT,LED_PIN);	//LED=0 亮
//---------------------------------------------------------	
	while(1)
	{ 
		if(USART_RX_STA&0x8000)//判断接收到完整的字符串  完成
		{					   			
				
				if(strstr((const char*)USART_RX_BUF,"off"))//判断阿里云发下来的数据里是否有on
				{   
					
						GPIO_ResetBits(LED_PORT,LED_PIN);	//LED=0 亮
				}
				if(strstr((const char*)USART_RX_BUF,"on"))//判断阿里云发下来的数据里是否有off
				{   
						GPIO_SetBits(LED_PORT,LED_PIN);		//LED=1	灭
				}	

				memset(USART_RX_BUF,0,600);         //将接收区清0
				USART_RX_STA=0;
		}
	}
}
