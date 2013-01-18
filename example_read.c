#include <stdio.h>
#include "gpio.h"

int main(void)
{
	if (gpio_open(157, GPIO_READ) < 0) {
	    puts("Unable to open PIN file");
	    return -1;
	}

	while (1) {
		printf("%d\n", gpio_read(157));
	}

	gpio_close(157);
	return 0;
}

