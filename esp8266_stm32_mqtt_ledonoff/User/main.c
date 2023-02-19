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
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	LED_Init();
	USART1_Init(115200);//���ڲ�����115200
  ESP8266_Init();
	
	//���ķ���ָ��
	printf("AT+MQTTSUB=0,\"/a5ZLiiHWg1j/ttcan/user/get\",1\r\n");		//����ָ��
	delay_ms(5000);	
	//GPIO_SetBits(LED_PORT,LED_PIN);		//LED=1	��

	printf("AT+MQTTPUB=0,\"/a5ZLiiHWg1j/ttcan/user/update\",\"{\\\"LED\\\":1}\",1,0\r\n");		//������{"LED":1}
	delay_ms(5000);			//�ӳ�
	
	printf("AT+MQTTPUB=0,\"/a5ZLiiHWg1j/ttcan/user/update\",\"{\\\"LED\\\":0}\",1,0\r\n");		//������{"LED":0}
	delay_ms(5000);			//�ӳ�

  GPIO_ResetBits(LED_PORT,LED_PIN);	//LED=0 ��
//---------------------------------------------------------	
	while(1)
	{ 
		if(USART_RX_STA&0x8000)//�жϽ��յ��������ַ���  ���
		{					   			
				
				if(strstr((const char*)USART_RX_BUF,"off"))//�жϰ����Ʒ��������������Ƿ���on
				{   
					
						GPIO_ResetBits(LED_PORT,LED_PIN);	//LED=0 ��
				}
				if(strstr((const char*)USART_RX_BUF,"on"))//�жϰ����Ʒ��������������Ƿ���off
				{   
						GPIO_SetBits(LED_PORT,LED_PIN);		//LED=1	��
				}	

				memset(USART_RX_BUF,0,600);         //����������0
				USART_RX_STA=0;
		}
	}
}
