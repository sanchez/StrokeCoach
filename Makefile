SOURCES=lcd.c main.c util.c

all: program
	@echo "Compiling and uploading"

help:
	@echo "Help details:"
	@echo "hex: compile hex file"
	@echo "flash: install hex file"
	@echo "program: compile hex and install"

.c.o:
	avr-gcc -E -c -std=gnu99 -pedantic -g -Os -mmcu=atmega328p $< -o $@

hex: $(SOURCES:.c=.o)
	avr-gcc -g -std=gnu99 -mmcu=atmega328p $(SOURCES) -o project.elf -Wl,-u,vfprintf -lprintf_flt
	avr-objcopy -j .text -j .data -O ihex project.elf project.hex

flash:
	avrdude -F -p m328p -c usbasp -U flash:w:project.hex

program: hex flash

clean:
	rm *.o
	rm project.elf

serial:
	sudo screen /dev/ttyUSB0 19200J