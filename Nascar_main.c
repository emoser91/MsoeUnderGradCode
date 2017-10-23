/*EE 2930 LAB EXAM #2
 * Nascar_main.c
 *
 *  Created on: Feb 3, 2012
 *      Author: mosere
 */
#include "nascar_libraries.h"
#include "MSOE_I2C/lcd.h"

//GLOBAL VARS
uint16_t distance;//store distance data
int input;
int lap=0;
int start=0;
int loop=0;
int pitstop=0;
int main(void)
{
	startup();
	//START UP WAVE
	while(start==0){
		if(distance>250){start=1;lcd_clear();lcd_printf("NASCAR IS KOOL");delay_ms(100);}
		else{lcd_home();lcd_printf("WAVE YOUR HAND");}}
	while(start==1)
	{
		//KEEP LAPING CASE
		if(lap==2){start=2;}
		if(distance<80){loop=0;delay_ms(50);}
		if((distance>350)&(loop==0)){loop=1;lap++;lcd_goto_xy(0,1);lcd_printf("LAP: %d",lap);delay_ms(50);}

		if(input==12){motorsfwd();}
		else if(input==6){motorslright();}
		else if(input==3){motorsright();}
		else if(input==1){motorsbright();}
		else if(input==24){motorslleft();}
		else if(input==48){motorsleft();}
		else if(input==32){motorsbleft();}
		//fork---right=pass though
		else if(input==56){motorsyturn();} //special case
		else if (input==7){motorsyturn();} //special case
		else if(input==28){motorsyturn();}
		else if(input==14){motorsyturn();}
		else if(input==10){motorsyturn();}
		else if(input==20){motorsyturn();}
		else if(input==18){motorsyturn();}
		else if(input==30){motorsyturn();}
		else if(input==60){motorsyturn();}
		else if(input==15){motorsyturn();}
		else if(input==54){motorsyturn();}
		else if(input==38){motorsyturn();}
		else if(input==25){motorsyturn();}
		else if(input==36){motorsyturn();}
		else if(input==9){motorsyturn();}
	}//while
	while(start==2)
	{
		if(lap==4){start=3;}
		if(distance<80){loop=0;delay_ms(50);}
		if((distance>350)&(loop==0)){loop=1;lap++;lcd_goto_xy(0,1);lcd_printf("LAP: %d",lap);delay_ms(50);}
		//PIT STOP CASE
		if(input==12){motorsfwd();}
		else if(input==6){motorslright();}
		else if(input==3){motorsright();}
		else if(input==1){motorsbright();}
		else if(input==24){motorslleft();}
		else if(input==48){motorsleft();}
		else if(input==32){motorsbleft();}
		//fork--left=turn to pit stop
		else if(input==28){pit_stop();pitstop=1;}
		else if(input==14){pit_stop();pitstop=1;}
		else if(input==10){pit_stop();pitstop=1;}
		else if(input==20){pit_stop();pitstop=1;}
		else if(input==18){pit_stop();pitstop=1;}
		else if(input==30){pit_stop();pitstop=1;}
		else if(input==60){pit_stop();pitstop=1;}
		else if(input==15){pit_stop();pitstop=1;}
		else if(input==54){pit_stop();pitstop=1;}
		else if(input==38){pit_stop();pitstop=1;}
		else if(input==25){pit_stop();pitstop=1;}
		else if(input==36){pit_stop();pitstop=1;}
		else if(input==9){pit_stop();pitstop=1;}
	}
	while(start==3)
	{
		if(distance<80){loop=0;}
		if((distance>200)&(loop==0)){loop=1;lap++;lcd_goto_xy(0,1);lcd_printf("LAP: %d",lap);}
		while((distance>200)&&(lap==4)){motorstop();}
		while(distance<=200)
		{
		lcd_goto_xy(0,1);lcd_printf("LAP: %d",lap);
		if(input==12){motorsfwd();}
		else if(input==6){motorslright();}
		else if(input==3){motorsright();}
		else if(input==1){motorsbright();}
		else if(input==24){motorslleft();}
		else if(input==48){motorsleft();}
		else if(input==32){motorsbleft();}
		//fork---right=pass though
		else if(input==56){motorsyturn();} //special case
		else if (input==7){motorsyturn();} //special case
		else if(input==28){motorsyturn();}
		else if(input==14){motorsyturn();}
		else if(input==10){motorsyturn();}
		else if(input==20){motorsyturn();}
		else if(input==18){motorsyturn();}
		else if(input==30){motorsyturn();}
		else if(input==60){motorsyturn();}
		else if(input==15){motorsyturn();}
		else if(input==54){motorsyturn();}
		else if(input==38){motorsyturn();}
		else if(input==25){motorsyturn();}
		else if(input==36){motorsyturn();}
		else if(input==9){motorsyturn();}
		}
	}

}//main
ISR(ADC_vect)//ADC interrupt for when a conversion stops
{
	distance=ADCW;//wring ADC result to a global
	ADCSRA|=(1<<ADSC);//starting a new ACD conversion
}
ISR(TIMER2_COMPA_vect)
{
	input=((PINB&0b00011111)+((PIND&0b00001000)<<2));
	DDRB|=(1<<PORTB0)|(1<<PORTB1)|(1<<PORTB2)|(1<<PORTB3)|(1<<PORTB4);//set pin for output
	DDRD|=(1<<PORTD3);
	PORTB|=(1<<PORTB0)|(1<<PORTB1)|(1<<PORTB2)|(1<<PORTB3)|(1<<PORTB4);//write a 1 to pin
	PORTD|=(1<<PORTD3);
	delay_us(10);
	DDRB&=(~(1<<PORTB0))&(~(1<<PORTB1))&(~(1<<PORTB2))&(~(1<<PORTB3))&(~(1<<PORTB4));//set pin to input
	DDRD&=(~(1<<PORTD3));
	TCNT2=0;
}

