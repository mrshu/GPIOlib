#ifndef _GPIO_H
#define _GPIO_H

#include <stdio.h>

#define EXPORT "/sys/class/gpio/export"
#define UNEXPORT "/sys/class/gpio/unexport"
#define IN "in\n"
#define OUT "out\n"
#define LOW "0\n"
#define HIGH "1\n"


int gpio_open(int port, int DDR);
int gpio_close(int port);
int gpio_read(int port);
int gpio_write(int port,int value);
int pin_exist(int port);

#endif


