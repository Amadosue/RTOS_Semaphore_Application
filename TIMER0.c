/*
 * TIMER0.c
 *
 * Created: 12/9/2017 1:14:14 PM
 *  Author: yosry
 */ 
#include "TIMER0.h"
volatile uint32_t count=0;
void timer0_normal_init(){
SETBIT(TCCR0,CS00);
SETBIT(TCCR0,CS02);// to enable the prescaler cs00 and cs02 must be one.
SETBIT(TCCR0,FOC0);	
SETBIT(TIMSK,TOIE0);//TO ENABLE ENTERRUPT WITH OVERFLOW

sei();	


}
void timer0_CTC_init(){
	SETBIT(TCCR0,CS00);
	SETBIT(TCCR0,CS02);// to enable the prescaler cs00 and cs02 must be one.
	SETBIT(TCCR0,WGM01);
	SETBIT(TCCR0,FOC0);
	SETBIT(TIMSK,OCIE0);//TO ENABLE ENTERRUPT WITH CTC
	OCR0=200;
	sei();

}