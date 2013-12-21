#Makefile for gbv

SOURCES = main.c gameboy.c
CFLAGS += -std=c99 -g -Wall

all: gbv

gbv: $(SOURCES)
	gcc -o gbv $(CFLAGS) $(SOURCES)

clean:
	rm gbv

.PHONY: all clean
