#include "stm32f4xx.h"

void Delay(__IO uint32_t nCount) 
{
  while(nCount--) {
  }
}
 
void ms_delay(int ms)
{
   while (ms-- > 0) 
   {
      volatile int x=5971;
      while (x-- > 0)
        asm("nop");
   }
}



//Flash orange LED at about 1hz
int main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;  // enable the clock to GPIOD
    asm("dsb");                         // stall instruction pipeline, until instruction completes, as
                                          //    per Errata 2.1.13, "Delay after an RCC peripheral clock enabling"
    GPIOD->MODER = (1 << 26);             // set pin 13 to be general purpose output
    GPIOD->MODER |= (1 << 24);             // set pin 13 to be general purpose output
    GPIOD->MODER |= (1 << 28);             // set pin 13 to be general purpose output
    GPIOD->MODER |= (1 << 30);             // set pin 13 to be general purpose output

    for (;;) 
    {
        ms_delay(500);
       GPIOD->ODR ^= (1 << 13);           // Toggle the pin 
	ms_delay(500);       
       GPIOD->ODR ^= (1 << 12);           // Toggle the pin 
	ms_delay(500);       
       GPIOD->ODR ^= (1 << 14);           // Toggle the pin 
	ms_delay(500);
       GPIOD->ODR ^= (1 << 15);           // Toggle the pin 

}
}
