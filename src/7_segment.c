/*
 * _7_segment.c
 *
 * Created: 24/01/2024 14:32:42
 *  Author: Eslam
 */ 


#include <avr/io.h>
#include "DIO.h"

#define F_CPU 8000000UL


#include <util/delay.h>


void seven_seg_vInit(unsigned char port_name){
	DIO_vset_port_direction(port_name,0x7F);
}
void seven_seg_vWrite(unsigned char portname,unsigned char number){
	unsigned char numbers[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f,0x77,0x7f,0x39,0x3f,0x79,0x71};
	
	DIO_vwrite_port(portname,numbers[number]);
	_delay_ms(20);

}

void seven_seg_vClear(unsigned char portname){
	DIO_vwrite_port(portname,0);
	_delay_ms(20);

}