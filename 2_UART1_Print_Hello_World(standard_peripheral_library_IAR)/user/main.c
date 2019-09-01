#include "stm8l15x.h"
#include "uart.h"

//this is a stm8 uart1 print "hello world!" code,the baud rate is 57600.
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
  UART1_Init(57600); //Init the UART1 and the baud rate is 57600
  LED_On();

  while (1)
  {

    UART1_Send_String("Hello World!\r\n");
    Delay(1000);
  }
}
