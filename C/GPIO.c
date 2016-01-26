#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GPIO49_PATH "/sys/class/gpio/gpio49"

void WriteGPIO(char file_name[], char value[])
{
	FILE *fp;
	char fullFileName[100];
	sprintf(fullFileName,GPIO49_PATH "%s",file_name);
	fp = fopen(fullFileName, "w+");
	fprintf(fp, "%s", value);
	fclose(fp);
}

void GPIO_export()
{
	WriteGPIO("export","echo 49");
}

void GPIO_unexport()
{
	WriteGPIO("unexport","echo 49");
}

void turnOn()
{
	WriteGPIO("/value","1");
}

void turnOff()
{
	WriteGPIO("/value","0");
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
	printf("----Start GPIO program----\n");
	printf("GPIO49 path is: %s\n",GPIO49_PATH);
	if(!strcmp(argv[1],"on"))
	{
		turnOn();
	}
	else if(!strcmp(argv[1],"off"))
	{
		turnOff();
	}
	else if(!strcmp(argv[1],"flash"))
	{
		while(1)
		{
			turnOn();
			delay_ms(2000);
			turnOff();
			delay_ms(2000);
		}
	}
	else if(!strcmp(argv[1],"reset"))
	{
	    turnOff();
		WriteGPIO("/direction","in");
	}
	else
	{
		printf("Command is not supported...\n");
		return 2;
	}
	return 0;
}