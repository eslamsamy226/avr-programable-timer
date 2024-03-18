/*
 * IncFile1.h
 *
 * Created: 09/10/2023 12:21:29
 *  Author: Eslam
 */ 


#ifndef STD_MACROS
#define STD_MACROS

#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)	(reg|=(1<<bit))
#define CLR_BIT(reg,bit)    (reg&=(~(1<<bit)))
#define TOG_BIT(reg,bit)    (reg^=(1<<bit))
#define READ_BIT(reg,bit)    ((reg&(1<<bit))>>bit)
#define IS_BIT_SET(reg,bit)  ((reg&(1<<bit))>>bit)
#define IS_BIT_CLR(reg,bit)  (!((reg&(1<<bit))>>bit))
#define ROR(reg,num)         (reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num)))
#define ROL(reg,num)         (reg=(reg>>(REGISTER_SIZE-num))|(reg<<(num)))

#endif /* INCFILE1_H_ */