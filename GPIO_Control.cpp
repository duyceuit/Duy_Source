//Edited
/* A Simple GPIO application
* Written by Derek Molloy for the book "Exploring BeagleBone: Tools and 
* Techniques for Building with Embedded Linux" by John Wiley & Sons, 2014
* ISBN 9781118935125. Please see the file README.md in the repository root 
* directory for copyright and GNU GPLv3 license information.            */

#include<iostream>
#include<unistd.h> //for usleep
#include"GPIO.h"
using namespace GPIO_Library;
using namespace std;

int main(){
   GPIO outGPIO(49);
    //outGPIO.exportGPIO();
    // Basic Output - Flash the LED 10 times, once per second
  outGPIO.setDirection(OUTPUT);
  unsigned int count = 3;
    while(count)
    {
        outGPIO.setValue(HIGH);
        usleep(2000000);
        outGPIO.setValue(LOW);
        usleep(2000000);
        count--;
    }
  
   // Fast write to GPIO 1 million times

   return 0;
}
