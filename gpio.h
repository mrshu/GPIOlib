#ifndef _GPIO_H
#define _GPIO_H

#include <stdio.h>


void gpio_open(int port);
void gpio_close(int port);
int gpio_read(int port);


#endif


