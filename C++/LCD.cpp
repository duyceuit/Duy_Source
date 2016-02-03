#include<iostream>
#include<string>
#include"GPIO.h"
#include"LCD.h"

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
    
void LCD::LCD_Init(GPIO RS, GPIO E, GPIO D4, GPIO D5, GPIO D6, GPIO D7)
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

void LCD::LCD_SetUp()
{
    
}

LCD::~LCD()
{

}    
    
}

