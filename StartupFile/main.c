#include <stdint.h>
#include<stdio.h>


#define RCCADDRS			0x40021000U
#define GPIOADDRS			0x40011000U

#define RCCCFGR				( (uint32_t *)((RCCADDRS) + (0x04)) )
#define RCCAPB				( (uint32_t *)((RCCADDRS) + (0x18)) )

#define GPIOC				( (uint32_t *)((GPIOADDRS) + (0x04)) )
#define GPIOC_ODR			( (uint32_t *)((GPIOADDRS) + (0x0C)) )

void delay(void);

	  
int main(void)
{
	  
	  volatile uint32_t *rcccfgr = RCCCFGR;	//(uint32_t*)0x40021004;
	  volatile uint32_t *rccapb = RCCAPB;		//(uint32_t*)0x40021018;
	  volatile uint32_t *gpioc = GPIOC;				//(uint32_t*)0x40011004;
	  volatile uint32_t *gpioodr =	GPIOC_ODR;			//(uint32_t*)0x4001100C;

	  //RCC->CFGR = 0x00000001;		//clock configured as sysclk
	  //RCC->CR |= (1<<16);				//Clock selected as HSE
	  //RCC->CIR |= (1<<11) | (1<<19);
	   *rcccfgr = 0x00000001;
	   *rccapb |= (1<<4);
	   *gpioc = 0x44244444;

	  //RCC->APB2RSTR |= (1<<4);
		//RCC->APB2ENR |= (1<<4);
	  //GPIOC->CRH = 0x44244444;

	while(1)
	{

		  //GPIOC->ODR |= (1<<13);
		  //delay();
		  //GPIOC->ODR = 0x00000000;
		*gpioodr |= (1<<13);
		delay();
		*gpioodr &=~(1<<13);
		delay();

	}

}

void delay(void)
{
	for(int j=0;j<100;j++)
	for(int i=0;i<60000;i++);

}