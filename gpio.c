#include "gpio.h"
void gpio_open(int port, int DDR)
{
	FILE *f;
	f = fopen("/sys/class/gpio/export", "w");
	fprintf(f, "%d\n", port);
	fclose(f);

	char file[128];
	sprintf(file, "/sys/class/gpio/gpio%d/direction", port);
	f = fopen(file, "w");
	if (DDR == 0)	fprintf(f, "in\n");
	else		fprintf(f, "out\n");
	fclose(f);
}

void gpio_close(int port)
{
	FILE *f;
	f = fopen("/sys/class/gpio/unexport", "w");
	fprintf(f, "%d\n", port);
	fclose(f);
}

int gpio_read(int port)
{
	FILE *f;
	
	char file[128];
	sprintf(file, "/sys/class/gpio/gpio%d/value", port);
	f = fopen(file, "r");

	int i;
	fscanf(f, "%d", &i);
	fclose(f);
	return i;

}
void gpio_write(int port, int value){
	FILE *f;

	char file[128];
	sprintf(file, "/sys/class/gpio/gpio%d/value", port);
	f = fopen(file, "w");
	
	if (value == 0)	fprintf(f, "0\n");
	else		fprintf(f, "1\n");
	
	fclose(f);
}
