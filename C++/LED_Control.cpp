#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;


#define LED3_PATH "/sys/class/leds/beaglebone:green:usr3"

void WriteLED(string file_name, string value)
{
	fstream fs;
	fs.open((LED3_PATH + file_name).c_str(), fstream::out);
	fs << value;
	fs.close();
}

void removeTrigger()
{
	WriteLED("/trigger","none");
}

int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		printf("Wrong syntax...\n");
		return 2;
	}
	printf("----Start LED program----\n");
	printf("LED 3 path is: %s\n",LED3_PATH);
	if(!strcmp(argv[1],"on"))
	{
		removeTrigger();
		WriteLED("/brightness","1");
	}
	else if(!strcmp(argv[1],"off"))
	{
		removeTrigger();
		WriteLED("/brightness","0");
	}
	else
	{
		printf("Command is not supported...\n");
		return 2;
	}
	return 0;
}