#include "stm32f10x.h"
#include "esp8266.h"
#include "usart.h"
#include <string.h>
#include <stdio.h>

void ESP8266_Init()
{
  printf("AT+RST\r\n");		//第一步		复位		只用一次
	delay_ms(2000);					//延迟			
	printf("AT+CWMODE=1\r\n");		//第二步		模式  只用一次
	delay_ms(2000);					//延迟
  printf("AT+CIPSNTPCFG=1,8,\"ntp1.aliyun.com\"\r\n");		//第三步
	delay_ms(3000);					//延迟

	printf("AT+CWJAP=\"whatever\",\"youlike!!\"\r\n");		//第四步 wifi热点
	delay_ms(5000);					//延迟
	delay_ms(5000);					//延迟
	delay_ms(5000);					//延迟	
	delay_ms(5000);					//延迟
	printf("AT+MQTTUSERCFG=0,1,\"NULL\",\"ttcan&a5ZLiiHWg1j\",\"0ff52717e4fe45d92a9c6f11234d1d123a574e50f9b2e84642c1a0e7d415522b\",0,0,\"\"\r\n");		//第五步
	delay_ms(3000);					//延迟			

	printf("AT+MQTTCLIENTID=0,\"a5ZLiiHWg1j.ttcan|securemode=2\\,signmethod=hmacsha256\\,timestamp=1676687037657|\"\r\n");		//第六步 \\timestamp=1676687037657|
	delay_ms(3000);					//延迟	
	 delay_ms(3000);			   
	printf("AT+MQTTCONN=0,\"a5ZLiiHWg1j.iot-as-mqtt.eu-central-1.aliyuncs.com\",1883,1\r\n");		//第七步
	delay_ms(3000);					//延迟
}