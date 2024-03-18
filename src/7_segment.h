/*
 * _7_segment.h
 *
 * Created: 24/01/2024 14:34:15
 *  Author: Eslam
 */ 


#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#define COM_CATHODE
//#define COM_ANODE


void seven_seg_vInit(unsigned char port_name);
void seven_seg_vWrite(unsigned char portname,unsigned char number);

void seven_seg_vClear(unsigned char portname);
#endif /* 7_SEGMENT_H_ */