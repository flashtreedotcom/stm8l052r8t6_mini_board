#include "stm8l15x.h"
#include "uart.h"
#include "rtc.h"

//this is a stm8 rtc demo UART1 print,the baud rate is 57600.
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
  LED_On();

  UART1_Init(57600); //Init the UART1 and the baud rate is 57600
  UART1_Send_String("www.flashtree.com\r\n");
  UART1_Send_String("RTC Demo Code\r\n");

  RTC_Setting_Init(); //Init RTC

  while (1)
  {

    RTC_Get_Time();
    UART1_Send_String("Current Time:");
    UART1_Send_Dec(clock.cYear, 2); //YY-MM-DD
    UART1_Send_String("-");
    UART1_Send_Dec(clock.cMonth, 2);
    UART1_Send_String("-");
    UART1_Send_Dec(clock.cDay, 2);

    UART1_Send_String(" "); //HH:MM:SS
    UART1_Send_Dec(clock.cHour, 2);
    UART1_Send_String(":");
    UART1_Send_Dec(clock.cMinute, 2);
    UART1_Send_String(":");
    UART1_Send_Dec(clock.cSecond, 2);
    UART1_Send_String(" ");

    LED_On();
    Delay(200);
    LED_Off();
    Delay(200);
  }
}
