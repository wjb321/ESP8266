#ifndef __usart_H
#define __usart_H

#include "system.h" 
#include "stdio.h" 


#define USART_REC_LEN  			200  	//�����������ֽ��� 200

void USART1_Init(u32 bound);

extern u8  USART_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART_RX_STA;         				//����״̬���	

#endif


