#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LED3_PATH "/sys/class/leds/beaglebone:green:usr3"

void WriteLED(char file_name[], char value[])
{
	FILE *fp;
	char fullFileName[100];
	sprintf(fullFileName,LED3_PATH "%s",file_name);
	fp = fopen(fullFileName, "w+");
	fprintf(fp, "%s", value);
	fclose(fp);
}

void removeTrigger()
{
	WriteLED("/trigger","none");
}

void turnOn()
{
	removeTrigger();
	WriteLED("/brightness","1");
}

void turnOff()
{
	removeTrigger();
	WriteLED("/brightness","0");
}

void delay_ms(unsigned int t_ms)
{
	unsigned int t_us=t_ms*1000;
	usleep(t_us);
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
	else if(!strcmp(argv[1],"flash"))
	{
		while(1)
		{
			turnOn();
			delay_ms(1000);
			turnOff();
			delay_ms(1000);
		}
	}
	else
	{
		printf("Command is not supported...\n");
		return 2;
	}
	return 0;
}