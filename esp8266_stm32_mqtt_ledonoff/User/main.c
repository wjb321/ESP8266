//���� BվUID UID590045904
//Bվ�����׽̳�
//QȺ��752565966
//ʱ��2022.10.13 22��55
//���ܣ�STM32+ESP8266���������ݸ������ƣ����հ��������ݣ�ʵ��Զ�̵��
//״̬�����


//STM32+ESP8266����
//���ӣ�https://pan.baidu.com/s/13n3IFPSInl4gZyhclxd7jA?pwd=esp8 
//��ȡ�룺esp8 
//����������ݺ�򿪰ٶ������ֻ�App������������Ŷ


//��������Ƶ�������
//���ӣ�https://pan.baidu.com/s/1lwFKTPdxtT_pxnCjvMTP5Q?pwd=bili 
//��ȡ�룺bili 
//����������ݺ�򿪰ٶ������ֻ�App������������Ŷ

#include "string.h"
#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"


/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
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
	GPIO_ResetBits(LED_PORT,LED_PIN);	//LED=0 ��
  delay_ms(1000);					//�ӳ�
//�����ǳ�ʼ��
//---------------------------------------------------------
//����ָ���ESP8266���ӵ�������
	
	printf("AT+RST\r\n");		//��һ��		��λ		ֻ��һ��
	delay_ms(2000);					//�ӳ�			
	
	printf("AT+CWMODE=1\r\n");		//�ڶ���		ģʽ  ֻ��һ��
	delay_ms(2000);					//�ӳ�
//	printf("AT\r\n");		//��һ��		AT
//	delay_ms(2000);			//�ӳ�

//	printf("AT+GMR\r\n");		//��һ��		�汾��
//	delay_ms(2000);			//�ӳ�
  printf("AT+CIPSNTPCFG=1,8,\"ntp1.aliyun.com\"\r\n");		//������
	delay_ms(3000);					//�ӳ�

	printf("AT+CWJAP=\"whatever\",\"youlike!!\"\r\n");		//���Ĳ� wifi�ȵ�
	delay_ms(5000);					//�ӳ�
	delay_ms(5000);					//�ӳ�
	delay_ms(5000);					//�ӳ�	
	delay_ms(5000);					//�ӳ�

	GPIO_SetBits(LED_PORT,LED_PIN);		//LED=1	��

	printf("AT+MQTTUSERCFG=0,1,\"NULL\",\"ttcan&a5ZLiiHWg1j\",\"0ff52717e4fe45d92a9c6f11234d1d123a574e50f9b2e84642c1a0e7d415522b\",0,0,\"\"\r\n");		//���岽
	delay_ms(3000);					//�ӳ�			

	printf("AT+MQTTCLIENTID=0,\"a5ZLiiHWg1j.ttcan|securemode=2\\,signmethod=hmacsha256\\,timestamp=1676687037657|\"\r\n");		//������ \\timestamp=1676687037657|
	delay_ms(3000);					//�ӳ�	
	 delay_ms(3000);			   
	printf("AT+MQTTCONN=0,\"a5ZLiiHWg1j.iot-as-mqtt.eu-central-1.aliyuncs.com\",1883,1\r\n");		//���߲�
	delay_ms(9000);					//�ӳ�
	//delay_ms(9000);	
//���Ӱ����ƣ����豸����
//---------------------------------------------------------
//���ķ���ָ��
	printf("AT+MQTTSUB=0,\"/a5ZLiiHWg1j/ttcan/user/get\",1\r\n");		//����ָ��
	delay_ms(5000);			//�ӳ�
	//GPIO_SetBits(LED_PORT,LED_PIN);		//LED=1	��

	printf("AT+MQTTPUB=0,\"/a5ZLiiHWg1j/ttcan/user/update\",\"{\\\"LED\\\":1}\",1,0\r\n");		//������{"LED":1}
	delay_ms(5000);			//�ӳ�
	
	printf("AT+MQTTPUB=0,\"/a5ZLiiHWg1j/ttcan/user/update\",\"{\\\"LED\\\":0}\",1,0\r\n");		//������{"LED":0}
	delay_ms(5000);			//�ӳ�

  GPIO_ResetBits(LED_PORT,LED_PIN);	//LED=0 ��
//---------------------------------------------------------	
	while(1)
	{ 
//		GPIO_SetBits(LED_PORT,LED_PIN);		//LED=1	��
//		delay_ms(1000);			//�ӳ�
//		GPIO_ResetBits(LED_PORT,LED_PIN);	//LED=0 ��
//		delay_ms(1000);			//�ӳ�
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


//��һ��		AT+RST
// 
//�ڶ���		AT+CWMODE=1

//������		AT+CIPSNTPCFG=1,8,"ntp1.aliyun.com"

//���Ĳ�		AT+CWJAP="WiFi����","WiFi����"

//���岽		AT+MQTTUSERCFG=0,1,"NULL","�û���","����",0,0,""

//������		AT+MQTTCLIENTID=0,"ClienId"    					//clientId�ڶ�������ע��ÿ������ǰ�ӷָ���\

//���߲�		AT+MQTTCONN=0,"��������",1883,1

//AT+MQTTSUB=0,"topic",1							//����ָ��

//AT+MQTTPUB=0,"topic","AJson��ʽ����",1,0		//����ָ��


//ע�⣺   "ǰ��Ҫ��ת���ַ�    \ǰ��Ҫ��ת���ַ�
