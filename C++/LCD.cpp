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
    cout << "RS: " << this->RS.pinNum  << "Path: " << this->RS.path << endl;
    cout << "E: " << this->E.pinNum  << "Path: " << this->E.path << endl;
    cout << "D4: " << this->D4.pinNum  << "Path: " << this->D4.path << endl;
    cout << "D5: " << this->D5.pinNum  << "Path: " << this->D5.path << endl;
    cout << "D6: " << this->D6.pinNum  << "Path: " << this->D6.path << endl;
    cout << "D7: " << this->D7.pinNum  << "Path: " << this->D7.path << endl;
}

void LCD::Test_LCD_Port()
{
    for(int i=0;i<1;i++)
    {
        cout << "Test LCD Port: " << i << endl;
        this->RS.setValue(HIGH);
        this->E.setValue(HIGH);
        this->D4.setValue(HIGH);
        this->D5.setValue(HIGH);
        this->D6.setValue(HIGH);
        this->D7.setValue(HIGH);
        usleep(2*_S);
        this->RS.setValue(LOW);
        this->E.setValue(LOW);
        this->D4.setValue(LOW);
        this->D5.setValue(LOW);
        this->D6.setValue(LOW);
        this->D7.setValue(LOW);
        usleep(2*_S);
    }
}

void LCD::LCD_enable()
{
    this->E.setValue(HIGH);
    usleep(500);
    this->E.setValue(LOW);
}

void LCD::LCD_command(unsigned char command)
{
    this->RS.setValue(LOW);
    this->D7.setValue((((command>>7)&0x01)?HIGH:LOW));
    this->D6.setValue((((command>>6)&0x01)?HIGH:LOW));
    this->D5.setValue((((command>>5)&0x01)?HIGH:LOW));
    this->D4.setValue((((command>>4)&0x01)?HIGH:LOW));
    LCD_enable();
    usleep(1*1000);
    this->D7.setValue((((command>>3)&0x01)?HIGH:LOW));
    this->D6.setValue((((command>>2)&0x01)?HIGH:LOW));
    this->D5.setValue((((command>>1)&0x01)?HIGH:LOW));
    this->D4.setValue((((command>>0)&0x01)?HIGH:LOW));
    LCD_enable();
    usleep(1*1000);
}

void LCD::LCD_putc(unsigned char c)
{
    this->RS.setValue(HIGH);
    this->D7.setValue((((c>>7)&0x01)?HIGH:LOW));
    this->D6.setValue((((c>>6)&0x01)?HIGH:LOW));
    this->D5.setValue((((c>>5)&0x01)?HIGH:LOW));
    this->D4.setValue((((c>>4)&0x01)?HIGH:LOW));
    LCD_enable();
    usleep(1*1000);
    this->D7.setValue((((c>>3)&0x01)?HIGH:LOW));
    this->D6.setValue((((c>>2)&0x01)?HIGH:LOW));
    this->D5.setValue((((c>>1)&0x01)?HIGH:LOW));
    this->D4.setValue((((c>>0)&0x01)?HIGH:LOW));
    LCD_enable();
    usleep(1*1000);
}

void LCD::LCD_Set_Direction()
{
    cout << "Set Direction" << endl;
    this->RS.exportGPIO();
    this->RS.setDirection(OUTPUT);
    this->E.exportGPIO();
    this->E.setDirection(OUTPUT);
    this->D4.exportGPIO();
    this->D4.setDirection(OUTPUT);
    this->D5.exportGPIO();
    this->D5.setDirection(OUTPUT);
    this->D6.exportGPIO();
    this->D6.setDirection(OUTPUT);
    this->D7.exportGPIO();
    this->D7.setDirection(OUTPUT);
    usleep(20*1000);
    this->RS.setValue(HIGH);
    this->E.setValue(HIGH);
    this->D4.setValue(HIGH);
    this->D5.setValue(HIGH);
    this->D6.setValue(HIGH);
    this->D7.setValue(HIGH);
    usleep(20*1000);
}

void LCD::LCD_RESET()
{
    LCD_command(0x33);
    LCD_command(0x32);
}

void LCD::LCD_init()
{
    LCD_Set_Direction();
    LCD_command(0x28);       // 4-bit mode - 2 line - 5x7 font. 
	LCD_command(0x0F);       // Display no cursor - no blink.
	LCD_command(0x06);       // Automatic Increment - No Display shift.
}

LCD::~LCD()
{
    // cout << "Uncontructor LCD..." << endl;
    LCD_command(LCD_CLEARDISPLAY);
    LCD_RESET();
}    
    
}

