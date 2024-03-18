/*
 * simple_programmable_timer.c
 *
 * Created: 24/01/2024 20:06:40
 *  Author: Eslam
 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "7_segment.h"
#include "std_macros.h"
#include "DIO.h"
#include "Buzzer.h"
#include "Button.h"
#include "LED.h"

char timer=0;
void blink(){
	while(IS_BIT_SET(PINA,3)){
	seven_seg_vWrite('B',8);
	seven_seg_vWrite('D',8);
	_delay_ms(400);
	seven_seg_vClear('B');
	seven_seg_vClear('D');
	_delay_ms(400);
	}	
}
void set_timer(){
		
		timer=0;
		seven_seg_vWrite('B',0);
		seven_seg_vWrite('D',0);
		while(1){
			if (IS_BIT_CLR(PINA,3))
			{
				if (IS_BIT_CLR(PINA,3)){
					_delay_ms(100);
					break;
				}
			}
			
			if (IS_BIT_CLR(PINA,4))
			{
				timer++;
				timer%=100;
				seven_seg_vWrite('D',timer%10);
				seven_seg_vWrite('B',timer/10);
				_delay_ms(200);
			}
		}
}
void count(){

while(timer){
		timer--;
		seven_seg_vWrite('D',timer%10);
		seven_seg_vWrite('B',timer/10);
		_delay_ms(1000);
	}
	Buzzer_vOn('A',0);
	LED_vTurnOn('A',1);
	timer=0;
	while(1){
		if (IS_BIT_CLR(PINA,3))
		{
			_delay_ms(40);
			if (IS_BIT_CLR(PINA,3)){
			break;
		}
	}
}
		
}
int main(void)
{
	seven_seg_vInit('B');
	seven_seg_vInit('D');
	Buzzer_vInit('A',0);
	LED_vInit('A',1);
	button_vInit('A',3);
	button_vInit('A',4);
	DIO_vconnectpullup('A',3,1);
	DIO_vconnectpullup('A',4,1);
	_delay_ms(2000);

    while(1)
    {
		blink();
		_delay_ms(400);
		set_timer();	
		_delay_ms(800);
		count();
		_delay_ms(250);
		Buzzer_vOff('A',0);
		LED_vTurnOff('A',1);
		_delay_ms(800);
	}
}