/*
 * main.c
 *
 *  Created on: Jul 23, 2023
 *      Author: hello
 */

typedef volatile unsigned int vuint32_t;
#include<stdint.h>

#define RCC_BASE      0X40021000
#define PORTA_BASE    0X40010800

#define RCC_APB2ENR   *(volatile uint32_t *) (RCC_BASE + 0x18 )
#define GPIOA_CRH     *(volatile uint32_t *) (PORTA_BASE + 0x04)
#define GPIOA_ODR     *(volatile uint32_t *) (PORTA_BASE + 0x0c)

#define RCC_IOPAEN   (1<<2)
#define GPIOA13      (1UL<<13)

typedef union {
	vuint32_t all_fields;
	struct {
		vuint32_t reserved:13;
		vuint32_t pin13    :1;
		vuint32_t pin14    :1;
		vuint32_t pin15    :1;
	}ODR_field;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t *)(PORTA_BASE + 0x0C) ;
unsigned char g_variables[3] = {1,2,3};
unsigned char const const_variables[3] = {1,2,3};

/*extern Bus_Falult(void)
{
	
}

extern NMI_Handler(void)
{
	
}	
*/
int main(void)
{
	int i;
	RCC_APB2ENR |= RCC_IOPAEN;
	GPIOA_CRH &= 0XFF0FFFFF;
	GPIOA_CRH |= 0X00200000;

	while(1)
	{
		R_ODR->ODR_field.pin13 = 1;
		for(i=0 ; i<5000 ;i++);
		R_ODR->ODR_field.pin13 = 0;
		for(i=0 ; i<5000 ;i++);

	}
}
