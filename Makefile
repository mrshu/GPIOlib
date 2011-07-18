
CC=$(CROSS_COMPILE)gcc -g
TARGET=gpio

gpio.o:gpio.c
	$(CC) -c gpio.c

install: gpio.o
	$(CROSS_COMPILE)ar rcs lib$(TARGET).a gpio.o
	install lib$(TARGET).a /usr/lib/lib$(TARGET).a
	install *.h /usr/include/

example: example.c
	$(CC) example.c -lgpio -o example 
