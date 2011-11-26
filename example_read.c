#include <stdio.h>
#include "gpio.h"

int main(void)
{
	gpio_open(157,0);

	while (1) {
		printf("%d\n", gpio_read(157));
	}

	gpio_close(157);
}

