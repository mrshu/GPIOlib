#include <stdio.h>
#include "gpio.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
	int error=0;
	
	if(gpio_open(157,1) < 0)
	{
	    puts("Unable to open PIN file");
	    return -1;
	}
	
	while(!error)
	{
	    error = gpio_write(157,1);
	    sleep(1);
	    error = gpio_write(157,0);
	    sleep(1);
	};
	
	gpio_close(157);
	return 0;
}

