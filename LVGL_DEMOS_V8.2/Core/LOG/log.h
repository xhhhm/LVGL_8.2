#ifndef __LOG_H__
#define __LOG_H__

/*--------����log֮ǰ����Ҫ�򿪴���DMA--------*/
#include "main.h"
#include "usart.h"
#include "stdio.h"
#include "string.h"

#define DEBUG_LEN 100	//���崮�ڷ���������󳤶�
extern char log_buf[DEBUG_LEN];//������ӡ�������Ϊ�ⲿ����

#define DEBUG_OFF 		0//�رմ�ӡ
#define DEBUG_ERROR 	1//ֻ��ӡ����
#define DEBUG_WARNING 2//��ӡ����ʹ���
#define DEBUG_INFO 		3//��ӡ������Ϣ

#define DEBUG	3//ѡ���ӡ������Ϣ
#define DEBUG_USART huart1//��־��ӡ����Ϊ����1

#if (DEBUG==DEBUG_OFF)
#define LOGE(fmt,...) {;}	
#define LOGW(fmt,...) {;}	
#define LOGI(fmt,...) {;}	
#else 

#if(DEBUG>=DEBUG_ERROR)
#define LOGE(fmt,...) {sprintf(log_buf,fmt,##__VA_ARGS__);\
HAL_UART_Transmit_DMA(&DEBUG_USART, (uint8_t *)log_buf ,strlen(log_buf));\
while(__HAL_UART_GET_FLAG(&DEBUG_USART,UART_FLAG_TC)==RESET);}

#if(DEBUG>=DEBUG_WARNING)
#define LOGW(fmt,...) {sprintf(log_buf,fmt,##__VA_ARGS__);\
HAL_UART_Transmit_DMA(&DEBUG_USART, (uint8_t *)log_buf ,strlen(log_buf));\
while(__HAL_UART_GET_FLAG(&DEBUG_USART,UART_FLAG_TC)==RESET);}


#if(DEBUG>=DEBUG_INFO)
#define LOGI(fmt,...) {sprintf(log_buf,fmt,##__VA_ARGS__);\
HAL_UART_Transmit_DMA(&DEBUG_USART, (uint8_t *)log_buf ,strlen(log_buf));\
while(__HAL_UART_GET_FLAG(&DEBUG_USART,UART_FLAG_TC)==RESET);}
#else
#define LOGI(fmt,...) {;}	
#endif	
	
#else
#define LOGW(fmt,...) {;}	
#define LOGI(fmt,...) {;}	
#endif
#endif
#endif

#endif
