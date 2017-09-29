#include "MQ-135.h"
#include "delay.h"
	   
void MQ135_Init(void)
{
    MQ135_GPIO_Config();
    ADC1_GPIO_Init();
}

void MQ135_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(MQ135_AO_RCC_Periph, ENABLE );	  //使能ADC1通道时钟
 
	//PA1 作为模拟通道输入引脚                         
	GPIO_InitStructure.GPIO_Pin = MQ135_AO_GPIO_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//模拟输入引脚
	GPIO_Init(MQ135_AO_GPIO_Port, &GPIO_InitStructure);	
}

uint16_t MQ135_Read_Value(void)
{
    uint16_t ADC_Value = 0;
    ADC_Value = Get_ADC1_Average(MQ135_ADC_CHANNEL,10);
    return ADC_Value;
}

float MQ135_Get_Percentage(void)
{
    return MQ135_Read_Value()/4095.0*100;
}









