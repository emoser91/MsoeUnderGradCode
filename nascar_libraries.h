/*
 * nascar_libraries.h
 *
 *  Created on: Feb 3, 2012
 *      Author: mosere
 */
#ifndef NASCAR_LIBRARIES_H_
#define NASCAR_LIBRARIES_H_
#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>

//function prototypes
void motorstop(void);
void motorsfwd(void);
void motorsback(void);
void motorsleft(void);
void motorsright(void);
void motorslleft(void);
void motorslright(void);
void motorsbleft(void);
void motorsbright(void);
void startup(void);
void linetracker(void);
void motorsyturn(void);
void pit_stop(void);

//Initilaize LCD Prototypes
void lcd_init(void);// set cursor to home
void lcd_home(void);// clear display
void lcd_clear(void);// set cursor position
void lcd_goto_xy(uint8_t x,uint8_t y);// print character
void lcd_print_char(uint8_t symbol);// print string at current position
void lcd_print_string(char *string);// print hex number on LCD
void lcd_print_hex(uint8_t hex);// print uint8 on LCD
void lcd_print_uint8(uint8_t no);// print int8 on LCD
void lcd_print_int8(int8_t no);// print uint16 on LCD
void lcd_print_uint16(uint16_t no);// print int16 on LCD
void lcd_print_int16(int16_t no);// print float on LCD
void lcd_print_float(float no);// lcdprintf
void lcd_printf(char *fmt, ...);

#endif /* NASCAR_LIBRARIES_H_ */
