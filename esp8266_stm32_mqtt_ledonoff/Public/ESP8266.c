#include "stm32f10x.h"
#include "esp8266.h"
#include "usart.h"
#include <string.h>
#include <stdio.h>

void ESP8266_Init()
{
  printf("AT+RST\r\n");		//��һ��		��λ		ֻ��һ��
	delay_ms(2000);					//�ӳ�			
	printf("AT+CWMODE=1\r\n");		//�ڶ���		ģʽ  ֻ��һ��
	delay_ms(2000);					//�ӳ�
  printf("AT+CIPSNTPCFG=1,8,\"ntp1.aliyun.com\"\r\n");		//������
	delay_ms(3000);					//�ӳ�

	printf("AT+CWJAP=\"whatever\",\"youlike!!\"\r\n");		//���Ĳ� wifi�ȵ�
	delay_ms(5000);					//�ӳ�
	delay_ms(5000);					//�ӳ�
	delay_ms(5000);					//�ӳ�	
	delay_ms(5000);					//�ӳ�
	printf("AT+MQTTUSERCFG=0,1,\"NULL\",\"ttcan&a5ZLiiHWg1j\",\"0ff52717e4fe45d92a9c6f11234d1d123a574e50f9b2e84642c1a0e7d415522b\",0,0,\"\"\r\n");		//���岽
	delay_ms(3000);					//�ӳ�			

	printf("AT+MQTTCLIENTID=0,\"a5ZLiiHWg1j.ttcan|securemode=2\\,signmethod=hmacsha256\\,timestamp=1676687037657|\"\r\n");		//������ \\timestamp=1676687037657|
	delay_ms(3000);					//�ӳ�	
	 delay_ms(3000);			   
	printf("AT+MQTTCONN=0,\"a5ZLiiHWg1j.iot-as-mqtt.eu-central-1.aliyuncs.com\",1883,1\r\n");		//���߲�
	delay_ms(3000);					//�ӳ�
}