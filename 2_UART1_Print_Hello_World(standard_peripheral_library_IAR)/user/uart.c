#include "stm8l15x.h"
#include "uart.h"

void UART1_Send_Byte(uint8_t ucData)
{
	USART_SendData8(USART1, ucData);
	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == 0)
		;
}

//send string
void UART1_Send_String(char *Str)
{

	while (*Str != '\0') // "\0" meaning is the end of a string
	{
		UART1_Send_Byte(*Str);
		Str++;
	}
}

void UART1_Init(uint32_t uiBaudRate)
{
	//INIT UART1 PINS
	GPIO_Init(GPIOC, GPIO_Pin_3, GPIO_Mode_Out_PP_High_Fast);
	GPIO_Init(GPIOC, GPIO_Pin_2, GPIO_Mode_In_PU_No_IT);
	GPIO_SetBits(GPIOC, GPIO_Pin_3);

	//enable UART1 Clock
	CLK_PeripheralClockConfig(CLK_Peripheral_USART1, ENABLE);

	//setting the UART1
	USART_Init(USART1, uiBaudRate, USART_WordLength_8b, USART_StopBits_1, USART_Parity_No,
			   (USART_Mode_TypeDef)(USART_Mode_Tx | USART_Mode_Rx));

	//enable UART1
	USART_Cmd(USART1, ENABLE);
}