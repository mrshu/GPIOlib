#ifndef _GPIO_H
#define _GPIO_H

#include <stdio.h>


void gpio_open(int port, int DDR);
void gpio_close(int port);
int gpio_read(int port);
void gpio_write(int port,int value);

#endif


