#ifndef __IOI2C_H
#define __IOI2C_H
#include "main.h"


//������ʹ�õ���PB8-->SCL,PB9-->SDA




#define I2C_PORT GPIOB
#define I2C_SDA_PIN 9

//IO��������
#define SDA_IN()  {I2C_PORT->MODER&=~(3<<(I2C_SDA_PIN*2));I2C_PORT->MODER|=0<<I2C_SDA_PIN*2;}//����ģʽ
#define SDA_OUT() {I2C_PORT->MODER&=~(3<<(I2C_SDA_PIN*2));I2C_PORT->MODER|=1<<I2C_SDA_PIN*2;}//���ģʽ


//IO��������	 
#define IIC_SCL(x)  HAL_GPIO_WritePin(I2C_PORT,GPIO_PIN_8,x) //SCL				{I2C_PORT->ODR &= 0XFF7F;I2C_PORT->ODR|=((x)<<I2C_PIN);}
#define IIC_SDA(x)  HAL_GPIO_WritePin(I2C_PORT,GPIO_PIN_9,x) //SDA	 			GPIOB->ODR
#define READ_SDA   	HAL_GPIO_ReadPin(I2C_PORT,GPIO_PIN_9)  //����SDA 	GPIOB->IDR

//IIC���в�������
void IIC_Init(void);                //��ʼ��IIC��IO��				 
int IIC_Start(void);				//����IIC��ʼ�ź�
void IIC_Stop(void);	  			//����IICֹͣ�ź�
void IIC_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u8 IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
int IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC_Ack(void);					//IIC����ACK�ź�
void IIC_NAck(void);				//IIC������ACK�ź�

void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC_Read_One_Byte(u8 daddr,u8 addr);	 
unsigned char I2C_Readkey(unsigned char I2C_Addr);

unsigned char I2C_ReadOneByte(unsigned char I2C_Addr,unsigned char addr);
unsigned char IICwriteByte(unsigned char dev, unsigned char reg, unsigned char data);
u8 IICwriteBytes(u8 dev, u8 reg, u8 length, u8* data);
u8 IICwriteBits(u8 dev,u8 reg,u8 bitStart,u8 length,u8 data);
u8 IICwriteBit(u8 dev,u8 reg,u8 bitNum,u8 data);
u8 IICreadBytes(u8 dev, u8 reg, u8 length, u8 *data);

int i2cWrite(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *data);
int i2cRead(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *buf);

#endif

//------------------End of File----------------------------
