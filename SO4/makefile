CC := gcc
CFLAGS := -O3 -Wall
LDFLAGS := -lm

.PHONY: all
all: prodkons.x fifo.x producent.x konsument.x

prodkons.o: prodkons.c
prodkons.x: prodkons.o

fifo.o: fifo.c
fifo.x: fifo.o

producent.o: producent.c
producent.x: producent.o

konsument.o: konsument.c
konsument.x: konsument.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^

.PHONY: clean
clean:
	${RM} *.[ox]
