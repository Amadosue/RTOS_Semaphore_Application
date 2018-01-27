

#include "FreeRTOS.h"
#include "semphr.h"
#include "stdMacros.h"
#include "task.h"


uint8_t x=0;
uint8_t y=0;
uint8_t AccFlag=0;

void T1(void *pv);
void T2(void *pv);
SemaphoreHandle_t myMutex;
SemaphoreHandle_t myBinary;


/*
int main(void)
{
    xTaskCreate(T1,"debug",100,NULL,2,NULL);
	xTaskCreate(T2,"debug",100,NULL,1,NULL);
	
	myMutex=xSemaphoreCreateMutex();
    vTaskStartScheduler();
}

void T1(void *pv)
{
	
	DDRD |=(1<<7);
	while(1)
	{
		/ *cli();
		if (AccFlag==0)  // event flag methode
		{
			AccFlag=1;
			sei();* /
		xSemaphoreTake(myMutex,1000); //semaphore Mutex
		if (x!=y)
		{
			PORTD ^=(1<<7);
		}			
		
		//_delay_ms(1000);
		xSemaphoreGive(myMutex);
		vTaskDelay(1000);
		/ *cli();
		AccFlag=0;
		sei();* /
		/ *}
		else{
			sei();
		}	* /	
	}
}

void T2(void *pv)
{
	
	DDRD |=(1<<6);
	while(1)
	{
		//PORTD ^=(1<<6);
		//cli();
		//vTaskSuspendAll();
		/ *cli();
		if (AccFlag==0)
		{
			AccFlag=1;
			sei();* /
		xSemaphoreTake(myMutex,1000);
			++x;
			_delay_ms(200);
			//vTaskDelay(200);
			++y;
		xSemaphoreGive(myMutex);
			/ *cli();
			AccFlag=0;
			sei();
		}
		else{
			sei();
		}* /
		
	
		//sei();
		//xTaskResumeAll();
	}
}*/


int main(void)
{
	GICR=1<<INT0;
	MCUCR=(1<<ISC01) | (1<<ISC00);
	xTaskCreate(T1,"debug",100,NULL,1,NULL);
	
	myBinary=xSemaphoreCreateBinary();
	
	vTaskStartScheduler();
}

void T1(void *pv)
{
	DDRD |=(1<<6);
	while(1)
	{
		
		if ((xSemaphoreTake(myBinary,10000))==pdTRUE);
		PORTD^=(1<<6);
		
	}
}
				
		
ISR(INT0_vect)
{
	xSemaphoreGiveFromISR(myBinary,NULL);
}