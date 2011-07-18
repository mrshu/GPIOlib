#include "gpio.h"
void gpio_open(int port)
{
	FILE *f;
	f = fopen("/sys/class/gpio/export", "w");
	fprintf(f, "%d\n", port);
	fclose(f);

	char file[128];
	sprintf(file, "/sys/class/gpio/gpio%d/direction", port);
	f = fopen(file, "w");
	fprintf(f, "in\n");
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
