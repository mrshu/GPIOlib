
CC=$(CROSS_COMPILE)gcc -g
TARGET=gpio

gpio.o:gpio.c
	$(CC) -c gpio.c

install: gpio.o
	$(CROSS_COMPILE)ar rcs lib$(TARGET).a gpio.o
	install lib$(TARGET).a /usr/lib/lib$(TARGET).a
	install *.h /usr/include/

example: example_write example_read

example_write:example_write.c
	$(CC) example_write.c -lgpio -o example_write

example_read:example_read.c
	$(CC) example_read.c -lgpio -o example_read

