#ifndef _LCD_4BIT_
#define _LCD_4BIT_

#include<iostream>
#include<string>
#include"GPIO.h"

/****************************************************************************
	define LCD command
*****************************************************************************/
#define LCD_CLEARDISPLAY    0x01
#define LCD_RETURNHOME           0x02
#define LCD_ENTRYMODESET         0x04
#define LCD_DISPLAYCONTROL       0x08
#define LCD_CURSORSHIFT          0x10
#define LCD_FUNCTIONSET          0x20
#define LCD_SETCGRAMADDR         0x40
#define LCD_SETDDRAMADDR         0x80

//Entry flags
#define LCD_ENTRYRIGHT           0x00
#define LCD_ENTRYLEFT            0x02
#define LCD_ENTRYSHIFTINCREMENT  0x01
#define LCD_ENTRYSHIFTDECREMENT  0x00

//Control flags
#define LCD_DISPLAYON            0x04
#define LCD_DISPLAYOFF           0x00
#define LCD_CURSORON             0x02
#define LCD_CURSOROFF            0x00
#define LCD_BLINKON              0x01
#define LCD_BLINKOFF             0x00

//Move flags
#define LCD_DISPLAYMOVE          0x08
#define LCD_CURSORMOVE           0x00
#define LCD_MOVERIGHT            0x04
#define LCD_MOVELEFT             0x00

//Function set flags
#define LCD_8BITMODE             0x10
#define LCD_4BITMODE             0x00
#define LCD_2LINE                0x08
#define LCD_1LINE                0x00
#define LCD_5x10DOTS             0x04
#define LCD_5x8DOTS              0x00

using namespace GPIO_Library;
using namespace std;

namespace LCD_4bit_Library{
    
class LCD
{
    private:

    
    public:
        GPIO RS,E,D4,D5,D6,D7;
        LCD();
        LCD(GPIO RS, GPIO E, GPIO D4, GPIO D5, GPIO D6, GPIO D7);
        virtual void LCD_contrusctor(GPIO RS, GPIO E, GPIO D4, GPIO D5, GPIO D6, GPIO D7);
        virtual void PrintName();
        virtual void LCD_enable();
        virtual void LCD_command(unsigned char command);
        virtual void LCD_putc(unsigned char c);
        virtual void LCD_Set_Direction();
        virtual void Test_LCD_Port();
        virtual void LCD_RESET();
        virtual void LCD_init();
        ~LCD();
};
    
}

#endif