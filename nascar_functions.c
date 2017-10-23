/*
 * nascar_functions.c
 *
 *  Created on: Feb 3, 2012
 *      Author: mosere
 */
#include "nascar_libraries.h"
void motorsfwd(void)
{
	PORTC|=(1<<PORTC2);PORTD|=(1<<PORTD2);
	OCR0B=150;  //228
	OCR0A=200;  //255
}
void motorslright(void)
{
	PORTC&=(~(1<<PORTC3));PORTD&=(~(1<<PORTD7));
	PORTC|=(1<<PORTC2);PORTD|=(1<<PORTD2);
	OCR0A=150;
	OCR0B=250;
}
void motorslleft(void)
{
	PORTC&=(~(1<<PORTC3));PORTD&=(~(1<<PORTD7));
	PORTC|=(1<<PORTC2);PORTD|=(1<<PORTD2);
	OCR0B=150;
	OCR0A=250;
}
void motorsright(void)
{
	PORTC&=(~(1<<PORTC3));PORTD&=(~(1<<PORTD7));
	PORTC|=(1<<PORTC2);PORTD|=(1<<PORTD2);
	OCR0A=100;
	OCR0B=200;
}
void motorsleft(void)
{
	PORTC&=(~(1<<PORTC3));PORTD&=(~(1<<PORTD7));
	PORTC|=(1<<PORTC2);PORTD|=(1<<PORTD2);
	OCR0B=100;
	OCR0A=200;
}
void motorsbright(void)
{
	PORTC&=(~(1<<PORTC2));PORTD&=(~(1<<PORTD7));
	PORTC|=(1<<PORTC3);PORTD|=(1<<PORTD2);
	OCR0A=200;
	OCR0B=200;
}
void motorsbleft(void)
{
	PORTC&=(~(1<<PORTC3));PORTD&=(~(1<<PORTD2));
	PORTD|=(1<<PORTD7);PORTC|=(1<<PORTC2);
	OCR0B=200;
	OCR0A=200;
}
void pit_stop(void)//right at fork
{
	PORTC&=(~(1<<PORTC3));PORTD&=(~(1<<PORTD7));
	PORTC|=(1<<PORTC2);PORTD|=(1<<PORTD2);
	OCR0A=0;
	OCR0B=200;
}
void motorsyturn(void)//left at fork
{
	PORTC&=(~(1<<PORTC3));PORTD&=(~(1<<PORTD7));
	PORTC|=(1<<PORTC2);PORTD|=(1<<PORTD2);
	OCR0A=200;
	OCR0B=0;
}
void motorstop(void)
{
	PORTC&=(~(1<<PORTC3));PORTD&=(~(1<<PORTD2));
	PORTC&=(~(1<<PORTC2));PORTD&=(~(1<<PORTD7));
	OCR0B=0;
	OCR0A=0;
}
