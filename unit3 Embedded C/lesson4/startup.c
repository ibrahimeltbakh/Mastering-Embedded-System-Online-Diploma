/*startup.c cortex-m3*/

#include<stdint.h>

void Reset_Handler();

extern int main(void);
//#define AAA		(*((volatile unsigned long*)0x1FFFFFFC))
//#define BBB		(*((volatile unsigned long*)0x1FFFFFEC))


void Default_Handler()
{
	Reset_Handler();
}

void NMI_Handler() __attribute__ ((weak, alias("Default_Handler")));;
void H_Fault_Handler()  __attribute__ ((weak, alias("Default_Handler")));;

// booking 1024B located by .bss through uninitialized array of 256B (256*4)
static unsigned long Stack_top[256];


void (* const g_p_fn_vectors[])() __attribute__((section(".vectors"))) =
{
	(void (*)())	((unsigned long)Stack_top + sizeof(Stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_Fault_Handler
	
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