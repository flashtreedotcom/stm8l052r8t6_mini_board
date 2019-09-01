#include "stm8l15x.h"

//this is a stm8 led blink code,the led connect to the GPIOB0
//www.flashtree.com
//6702578@qq.com

//LED GPIOB0

//Init LED IO
void LED_GPIO_Init(void)
{

  GPIO_Init(GPIOB, GPIO_Pin_0, GPIO_Mode_Out_PP_Low_Slow);
}

//set the GPIOB0 Pin to high
void LED_On(void)
{
  GPIO_SetBits(GPIOB, GPIO_Pin_0);
}

//set the GPIOB0 Pin to low
void LED_Off(void)
{
  GPIO_ResetBits(GPIOB, GPIO_Pin_0);
}

//About 1 second, not exactly, just for demonstration purposes
void Delay(unsigned int time)
{
  unsigned int i;
  while (time--)
  {
    for (i = 300; i > 0; i--)
    {
      asm("nop");
    }
  }
}

int main(void)
{

  LED_GPIO_Init();

  while (1)
  {
    LED_On();
    Delay(1000);
    LED_Off();
    Delay(1000);
  }
}
