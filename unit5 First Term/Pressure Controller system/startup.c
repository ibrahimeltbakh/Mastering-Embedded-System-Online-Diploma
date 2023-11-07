/*
*************************************************************
*** @file         :startup.c cortex-m3
*** @auther       :ibrahim samir eltbakh
*** @date         : 19/10/2023
*************************************************************
*/


#include<stdint.h>
#define Stack_start_SP 0x20001000
extern int main(void);

void Reset_Handler(void);

void Default_Handler()
{
	Reset_Handler();
}

void NMI_Handler(void) __attribute__ ((weak, alias("Default_Handler")));;
void H_Fault_Handler(void)  __attribute__ ((weak, alias("Default_Handler")));
void NM_Falult_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void Bus_Falult(void) __attribute__ ((weak, alias("Default_Handler")));
void Usage_Falult_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
extern unsigned int _stack_top;
uint32_t Vectors[] __attribute__((section(".vectors"))) = {
(uint32_t)	&_stack_top,
(uint32_t)	&Reset_Handler,
(uint32_t)	&NMI_Handler,
(uint32_t)	&H_Fault_Handler,
(uint32_t)	&NM_Falult_Handler,
(uint32_t)	&Bus_Falult,
(uint32_t)	&Usage_Falult_Handler
	
};

extern unsigned int _E_Text;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Reset_Handler(void)
{
	// copy data section from flash to ram
	
	unsigned int DATA_size = (unsigned char *)&_E_DATA - (unsigned char *)&_S_DATA;
	unsigned char* p_Src = (unsigned char *)&_E_Text;
	unsigned char* p_dst = (unsigned char *)&_S_DATA;	
	int i;
	for (i = 0 ; i<DATA_size ; i++)
	{
		*((unsigned char *)p_dst++) = *((unsigned char *)p_Src++);
	}
	
	// init bss section
	unsigned int bss_size = (unsigned char *)&_E_bss - (unsigned char *)&_S_bss;
	p_dst = (unsigned char *)&_S_bss;
	
	for (i = 0 ; i<bss_size ; i++)
	{
		*((unsigned char *)p_dst++) = (unsigned char *)0;
	}
	
	
	// jump main
	main();
}