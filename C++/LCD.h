#ifndef _LCD_4BIT_
#define _LCD_4BIT_

#include<iostream>
#include<string>
#include"GPIO.h"

/****************************************************************************
	define LCD command
*****************************************************************************/
#define LCD_CLEAR			0x01	// Clear display
#define LCD_HOME			0x02  	// return cursor and LCD to home position
#define LCD_OFF 			0x08	// turn off display and cursor
#define LCD_DISPLAY_ON		0x0C	// turn on display and turn off cursor
#define LCD_CURSOR_ON		0x0A 	// turn on cursor and turn off display
#define LCD_BLINK_CURSOR 	0x0E	// turn on display and blink cursor
#define LCD_FONT_8BIT		0x38	// set interace length: 8bits, 2 lines, font 5x8
#define LCD_FONT_4BIT		0x28	// set interace length: 4bits, 2 lines, font 5x8	
#define LCD_MOVE_CURSOR		0x06	// Entry mode set: set increments mode, not shift (cursor)
#define LCD_MDRIGHT			0x1C	// Move display to the right
#define LCD_MDLEFT			0x18    // Move display to the left

using namespace GPIO_Library;
using namespace std;

namespace LCD_4bit_Library{
    
class LCD
{
    private:
        GPIO RS,E,D4,D5,D6,D7;
    
    public:
        LCD();
        LCD(GPIO RS, GPIO E, GPIO D4, GPIO D5, GPIO D6, GPIO D7);
        virtual void LCD_contrusctor(GPIO RS, GPIO E, GPIO D4, GPIO D5, GPIO D6, GPIO D7);
        virtual void PrintName();
        virtual void LCD_enable();
        virtual void LCD_command(unsigned char command);
        virtual void LCD_putc(unsigned char c);
        virtual void LCD_init();
        ~LCD();
};
    
}

#endif