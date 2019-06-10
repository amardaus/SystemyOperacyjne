CC = gcc

.PHONY: all
all: bakery.x

bakery.o: bakery.c
bakery.x: bakery.o

%.o: %.c
	$(CC) -c -o $@ $<

%.x: %.o
	$(CC) -Wall $^ -lpthread -o $@

.PHONY: clean
clean:
	${RM} *.[ox]
