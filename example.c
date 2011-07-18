#include <stdio.h>
#include "gpio.h"


int main(void)
{
	gpio_open(139);

	while (1) {
		printf("%d\n", gpio_read(139));
	}

	gpio_close(139);
}

