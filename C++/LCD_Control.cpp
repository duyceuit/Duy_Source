// I want to change here .....
/* A Simple GPIO application
* Written by Derek Molloy for the book "Exploring BeagleBone: Tools and 
* Techniques for Building with Embedded Linux" by John Wiley & Sons, 2014
* ISBN 9781118935125. Please see the file README.md in the repository root 
* directory for copyright and GNU GPLv3 license information.            */

#include<iostream>
#include<unistd.h> //for usleep
#include"GPIO.h"
#include"LCD.h"
#include <bitset>
using namespace GPIO_Library;
using namespace LCD_4bit_Library;
using namespace std;

#define _4BIT_MODE  4
#define _RS  48
#define _E   51
#define _D4  3
#define _D5  2
#define _D6  49
#define _D7  15

int main(){
    int count=2;
    GPIO RS(_RS),E(_E), D4(_D4), D5(_D5), D6(_D6), D7(_D7);
    cout << "------------------Contruct MyLCD------------------" << endl;
    LCD MyLCD(RS,E,D4,D5,D6,D7);
    cout << "------------------Init LCD------------------" << endl;
    MyLCD.LCD_init();
    MyLCD.LCD_putc('H');
    MyLCD.LCD_putc('E');
    MyLCD.LCD_putc('L');
    MyLCD.LCD_putc('L');
    MyLCD.LCD_putc('O');
    while(count)
    {
        cout << count << endl;
        usleep(3*1000000);
        count--;
    }
    cout << "------------------End------------------" << endl;
   return 0;
}
