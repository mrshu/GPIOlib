#include <stdio.h>
#include "gpio.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
	gpio_open(157,1);
	while(1){
		gpio_write(157,1);
		sleep(1);
		gpio_write(157,0);
		sleep(1);
	}
	gpio_close(157);
	return 0;
}

