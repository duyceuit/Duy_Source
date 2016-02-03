#include<iostream>
#include<string>
#include"GPIO.h"
#include"LCD.h"
#include<unistd.h> //for usleep

using namespace GPIO_Library;
using namespace std;

namespace LCD_4bit_Library{
    
LCD::LCD()
{

}
    
LCD::LCD(GPIO RS, GPIO E, GPIO D4, GPIO D5, GPIO D6, GPIO D7)
{
    this->RS    =   RS;
    this->E     =   E;
    this->D4    =   D4;
    this->D5    =   D5;
    this->D6    =   D6;
    this->D7    =   D7;
}
    
void LCD::LCD_contrusctor(GPIO RS, GPIO E, GPIO D4, GPIO D5, GPIO D6, GPIO D7)
{
    this->RS    =   RS;
    this->E     =   E;
    this->D4    =   D4;
    this->D5    =   D5;
    this->D6    =   D6;
    this->D7    =   D7;
}

void LCD::PrintName()
{
    cout << "RS: " << this->RS.pinNum << endl;
    cout << "E: " << this->E.pinNum << endl;
    cout << "D4: " << this->D4.pinNum << endl;
    cout << "D5: " << this->D5.pinNum << endl;
    cout << "D6: " << this->D6.pinNum << endl;
    cout << "D7: " << this->D7.pinNum << endl;
}

void LCD::LCD_enable()
{
    this->E.setValue(LOW);
    usleep(1*1000);
    this->E.setValue(HIGH);
}

void LCD::LCD_command(unsigned char command)
{
    this->RS.setValue(LOW);
    this->D7.setValue((((command>>8)&0x01)?HIGH:LOW));
    this->D6.setValue((((command>>7)&0x01)?HIGH:LOW));
    this->D5.setValue((((command>>6)&0x01)?HIGH:LOW));
    this->D4.setValue((((command>>5)&0x01)?HIGH:LOW));
    LCD_enable();
    this->D7.setValue((((command>>4)&0x01)?HIGH:LOW));
    this->D6.setValue((((command>>3)&0x01)?HIGH:LOW));
    this->D5.setValue((((command>>2)&0x01)?HIGH:LOW));
    this->D4.setValue((((command>>1)&0x01)?HIGH:LOW));
    LCD_enable();
    usleep(1*1000);
}

void LCD::LCD_putc(unsigned char c)
{
    this->RS.setValue(LOW);
    this->D7.setValue((((c>>8)&0x01)?HIGH:LOW));
    this->D6.setValue((((c>>7)&0x01)?HIGH:LOW));
    this->D5.setValue((((c>>6)&0x01)?HIGH:LOW));
    this->D4.setValue((((c>>5)&0x01)?HIGH:LOW));
    LCD_enable();
    this->D7.setValue((((c>>4)&0x01)?HIGH:LOW));
    this->D6.setValue((((c>>3)&0x01)?HIGH:LOW));
    this->D5.setValue((((c>>2)&0x01)?HIGH:LOW));
    this->D4.setValue((((c>>1)&0x01)?HIGH:LOW));
    LCD_enable();
    usleep(1*1000);
}


void LCD::LCD_init()
{
    this->E.setValue(HIGH);
    this->RS.setValue(LOW);
    LCD_command(0x33);
    LCD_command(0x32);
    LCD_command(LCD_FONT_4BIT);
    LCD_command(LCD_DISPLAY_ON);
    LCD_command(LCD_MOVE_CURSOR);
    LCD_command(LCD_CURSOR_ON);
    LCD_command(LCD_CLEAR);
    usleep(250*1000);
}

LCD::~LCD()
{

}    
    
}

