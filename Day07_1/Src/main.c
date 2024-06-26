
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
	//char str[4];
	char ch = 0 ;
	SystemInit();
	LedInit(LED_GREEN);
	LedInit(LED_BLUE);
	LedInit(LED_RED);
	LedInit(LED_ORANGE);
	UartInit(BAUD_9600);
	//UartPuts("Enter Strings...\r\n");
	while(1) {
		//UartGets(str);
		//strupr(str);

		UartPuts("Enter your choice \r\n1.LED redon\r\n2.LED redoff\r\n3.LED Blueon\r\n4.LED blueoff\r\n");
		ch = UartGetch();
        switch(ch)
        {
           case '1':
        	   LedOn(LED_RED) ;
        	     break;
           case '2':
        	    LedOff(LED_RED);
        	     break;
           case '3':
        	   LedOn(LED_BLUE) ;
        	     break;
           case '4':
        	   LedOff(LED_BLUE);
        	     break;
        }
        ch = 0;
	}
	return 0;
}
