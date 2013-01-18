#ifndef _GPIO_H
#define _GPIO_H

#include <stdio.h>


int gpio_open(int port, int DDR);
int gpio_close(int port);
int gpio_read(int port);
int gpio_write(int port,int value);

#endif


