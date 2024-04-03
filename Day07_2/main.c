#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "uart.h"
#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	int choice;
	char str[32];
	SystemInit();
	UartInit(BAUD_9600);
	LedInit(LED_RED);
	LedInit(LED_BLUE);

	do {
	UartPuts("Enter Your Choice..\r\n");
	UartPuts("1. Red Led On\r\n");
	UartPuts("2. Red Led Off\r\n");
	UartPuts("3. Blue Led On\r\n");
	UartPuts("4. Blue Led Off\r\n");

	UartGets(str);

	sscanf(str,"%d", &choice);

	switch(choice)
	{
		case 1: LedOn(LED_RED);
			break;
		case 2: LedOff(LED_RED);
			break;
		case 3: LedOn(LED_BLUE);
			break;
		case 4: LedOff(LED_BLUE);
			break;
	}

	}while(choice != 0);

	return 0;
}
