// I want to change here .....
/* A Simple GPIO application
* Written by Derek Molloy for the book "Exploring BeagleBone: Tools and 
* Techniques for Building with Embedded Linux" by John Wiley & Sons, 2014
* ISBN 9781118935125. Please see the file README.md in the repository root 
* directory for copyright and GNU GPLv3 license information.            */

#include<iostream>
#include<unistd.h> //for usleep
#include"GPIO.h"
#include <bitset>
using namespace GPIO_Library;
using namespace std;

#define IO_SIZE 4

void init_GPIO_group(GPIO* GPIO_Group, unsigned char GPIO_Group_size);
void sent_byte(unsigned char value, GPIO* GPIO_Group, unsigned char GPIO_Group_size);

int main(){
    // GPIO outGPIO(3);
    // outGPIO.setDirection(OUTPUT);
    
  unsigned int count=0;
    //GPIO IO_Group[IO_SIZE] = {3,2,49,15};
    // init_GPIO_group(IO_Group, IO_SIZE);
    // while(count<16)
    // {
    //     sent_byte(count, IO_Group, IO_SIZE);
    //     count++;
    //     usleep(1*1000000);
    // }
   return 0;
}

void init_GPIO_group(GPIO* GPIO_Group, unsigned char GPIO_Group_size)
{
    unsigned int i=0;
    std::cout << "init_GPIO_group - size of IO_Group: " << static_cast<unsigned>(GPIO_Group_size) << std::endl;
    for(i=0;i<GPIO_Group_size;i++)
    {
        GPIO_Group[i].setDirection(OUTPUT);
        std::cout << "GPIO[" << GPIO_Group[i].pinNum << "] set as OUTPUT" << std::endl;
    }
}

void sent_byte(unsigned char value, GPIO* GPIO_Group, unsigned char GPIO_Group_size)
{
    unsigned char i = 0;
    GPIO_Library::GPIO_VALUE tmp_var;
    std::cout << "sent_byte - size of IO_Group: " << static_cast<unsigned>(GPIO_Group_size) << std::endl;
    std::cout << "Value will be sent: " << std::bitset<8>(value) << std::endl;
    for(i=0;i<GPIO_Group_size;i++)
    {
        // std::cout << "GPIO[" << GPIO_Group[i] << "] is set to: " << (value>>i)&0x01 << std::endl;
        //GPIO_Group[i].setValue((value>>i)&0x01);
        tmp_var = (((value>>i)&0x01)==0x01)?HIGH:LOW;
        GPIO_Group[i].setValue(tmp_var);
    }
}