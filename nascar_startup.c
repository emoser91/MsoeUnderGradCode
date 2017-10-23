/*
 * nascar_startup.c
 *
 *  Created on: Feb 3, 2012
 *      Author: mosere
 */
#include "nascar_libraries.h"
void startup(void)
{
//ADC FOR DISTANCE SENSOR
ADMUX=(1<<REFS0);
ADCSRA=(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN)|(1<<ADIE)|(1<<ADSC);
PORTC|=0b00000000;//turning off pull-up resistor

//SETTING UP T/C 2 FOR MOTORS ~500hz
DDRC=(1<<PORTC2)|(1<<PORTC3);//motor polarity control bits
DDRD=(1<<PORTD6)|(1<<PORTD5)|(1<<PORTD2)|(1<<PORTD7);//OC0A=D6 and OC0B=D5
TCCR0A=(1<<COM0B1)|(1<<COM0A1)|(1<<WGM00);//Phase correct PWM mode top=0xFF
TCCR0B=(1<<CS01)|(1<<CS00);//N=64 =490.2Hz (but drop CS00 and get 3921.57Hz)

//Timer counter 10ms
TIMSK2=(1<<OCIE2A);
TCCR2A=(1<<WGM20)|(1<<WGM21);
TCCR2B=(1<<CS22)|(1<<WGM22);
OCR2A=249;

//LCD START UP
lcd_init();lcd_clear();lcd_home();//LCD enable

sei();//turning on global interrupts
}
