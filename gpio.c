#include "gpio.h"
int gpio_open(int port, int DDR)
{
	FILE *f;
	char file[35],ris[5];
	
	f = fopen("/sys/class/gpio/export", "w");
	if(fprintf(f, "%d\n", port) < 0)
	    return -1;
	fclose(f);

	sprintf(file, "/sys/class/gpio/gpio%d/direction", port);
	f = fopen(file, "w");
	if(DDR)
	    sprintf(ris,"in\n");
	else
	    sprintf(ris,"out\n");
	    
	if(fprintf(f, "%s",ris) < 0)
	    return -1;
	
	fclose(f);
	
	return 0;
}

int gpio_close(int port)
{
	FILE *f;
	f = fopen("/sys/class/gpio/unexport", "w");
	if(fprintf(f, "%d\n", port) < 0)
	    return -1;
	fclose(f);
	return 0;
}

int gpio_read(int port)
{
	FILE *f;
	char file[30];
	int i;
	
	sprintf(file, "/sys/class/gpio/gpio%d/value", port);
	f = fopen(file, "r");
	fscanf(f, "%d", &i);
	fclose(f);
	return i;
}

int gpio_write(int port, int value){
	FILE *f;
	char file[30],ris[5];
	
	sprintf(file, "/sys/class/gpio/gpio%d/value", port);
	f = fopen(file, "w");
	if (value)
	    sprintf(ris,"0\n");
	else
	    sprintf(ris,"1\n");
	
	if(fprintf(f, "%s",ris) < 0)
	    return -1;
	
	fclose(f);
	return 0;
}
