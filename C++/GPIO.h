#ifndef _GPIO_H
#define _GPIO_H
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using std::string;
using std::ofstream;

#define GPIO_PATH "/sys/class/gpio/"
#define _MS 1000
#define _S  1000000
namespace GPIO_Library{

enum GPIO_DIRECTION{ INPUT, OUTPUT };
enum GPIO_VALUE{ LOW=0, HIGH=1 };

class GPIO
{
    private:

        
        int write(string path, string filename, string value);
        int write(string path, string filename, int value);
        string read(string path, string filename);
        
        
        
    public:
        int pinNum;
        string name, path;
        GPIO();
        GPIO(int pinNum);
        virtual void GPIO_Init(int input_pin);
        virtual int setDirection(GPIO_DIRECTION dir);
        virtual int setValue(GPIO_VALUE value);
        virtual GPIO_VALUE getValue();
        virtual int exportGPIO();
        virtual int unexportGPIO();
        ~GPIO();
};
}
#endif