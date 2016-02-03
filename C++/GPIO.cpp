#include "GPIO.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

namespace GPIO_Library{

GPIO::GPIO()
{
    
}
    
GPIO::GPIO(int input_pin)
{
    this->pinNum = input_pin;
    cout << "input pinNum: " << this->pinNum <<endl;
    ostringstream pinNumStr;
    pinNumStr << "gpio" << pinNum;
    cout << "pinNumStr: " << pinNumStr.str() <<endl;
    this->name = string(pinNumStr.str());
    cout << "name: " << this->name <<endl;
    this->path = GPIO_PATH + this->name + "/";
    cout << "path: " << this->path <<endl;
    this->exportGPIO();
    usleep(250000);
}

void GPIO::GPIO_Init(int input_pin)
{
    this->pinNum = input_pin;
    cout << "input pinNum: " << this->pinNum <<endl;
    ostringstream pinNumStr;
    pinNumStr << "gpio" << pinNum;
    cout << "pinNumStr: " << pinNumStr.str() <<endl;
    this->name = string(pinNumStr.str());
    cout << "name: " << this->name <<endl;
    this->path = GPIO_PATH + this->name + "/";
    cout << "path: " << this->path <<endl;
    this->exportGPIO();
    usleep(250000);    
}


// int GPIO::write(string path, string filename, string value)
// {
//     ofstream fs;
//     fs.open((path+filename).c_str());
//     if(!fs.is_open())
//     {
// 	   perror("GPIO: write failed to open file ");
// 	   return -1;
//     }
//     fs << value;
//     fs.close();
//     return 0;
// }

int GPIO::write(string path, string filename, string value){
   ofstream fs;
   fs.open((path + filename).c_str());
   if (!fs.is_open()){
	   perror("GPIO: write failed to open file ");
	   return -1;
   }
   fs << value;
   fs.close();
   return 0;
}

int GPIO::write(string path, string filename, int value)
{
    stringstream s;
    s << value;
    return this->write(path,filename,s.str());
}
string GPIO::read(string path, string filename)
{
    ifstream fs;
    fs.open((path+filename).c_str());
    if(!fs.is_open())
    {
	   perror("GPIO: write failed to open file ");
    }
    string value;
    //fs >> value;
    getline(fs,value);
    fs.close();
    return value;
}
int GPIO::exportGPIO()
{
    return this->write(GPIO_PATH, "export", this->pinNum);
}
int GPIO::unexportGPIO()
{
    return this->write(GPIO_PATH, "unexport", this->pinNum);
}
int GPIO::setDirection(GPIO_DIRECTION dir)
{
    switch(dir)   
    {
        case INPUT:
        {
            this->write(this->path,"direction","in");
            return -1;
        }
        case OUTPUT:
        {
            this->write(this->path,"direction","out");
            return -1;
        }
        default:
        {
            cout << "Only INPUT/OUTPUT direction supported!!!!";
            return 2;
        }
    }
}
int GPIO::setValue(GPIO_VALUE value)
{
    switch(value)
    {
        case HIGH:
        {
            this->write(this->path,"value","1");
            return -1;
        }
        case LOW:
        {
            this->write(this->path,"value","0");
            return -1;
        }
        default:
        {
            cout << "Only HIGH/LOW value supported!!!!";
            return 2;
        }
    }
}
GPIO_VALUE GPIO::getValue()
{
    string s = this->read(this->path,"value");
    if(s == "0") return LOW;
    else return HIGH;
}
GPIO::~GPIO()
{
    this->unexportGPIO();
}
}