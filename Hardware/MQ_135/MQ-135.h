#ifndef __MQ135_H
#define __MQ135_H	
#include "sys.h"
#include "adc.h"

#define MQ135_AO_GPIO_Port       GPIOA
#define MQ135_AO_GPIO_Pin        GPIO_Pin_0
#define MQ135_AO_RCC_Periph      RCC_APB2Periph_GPIOA
#define MQ135_ADC_CHANNEL        ADC_Channel_0


void MQ135_Init(void);
void MQ135_GPIO_Config(void);
uint16_t MQ135_Read_Value(void);
float MQ135_Get_Percentage(void);
 
#endif 


