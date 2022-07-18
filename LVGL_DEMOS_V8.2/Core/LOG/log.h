#ifndef __LOG_H__
#define __LOG_H__

/*--------开启log之前必须要打开串口DMA--------*/
#include "main.h"
#include "usart.h"
#include "stdio.h"
#include "string.h"

#define DEBUG_LEN 100	//定义串口发送数据最大长度
extern char log_buf[DEBUG_LEN];//声明打印缓存变量为外部变量

#define DEBUG_OFF 		0//关闭打印
#define DEBUG_ERROR 	1//只打印错误
#define DEBUG_WARNING 2//打印警告和错误
#define DEBUG_INFO 		3//打印所有信息

#define DEBUG	3//选择打印所有信息
#define DEBUG_USART huart1//日志打印串口为串口1

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
