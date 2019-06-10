CC := gcc
CFLAGS := -O3 -Wall
LDFLAGS := -lm

.PHONY: all
all: obsluga.x wysylaj.x grupa.x

obsluga.o: obsluga.c
obsluga.x: obsluga.o

wysylaj.o: wysylaj.c
wysylaj.x: wysylaj.o

grupa.o: grupa.c
grupa.x: grupa.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^

.PHONY: clean
clean:
	${RM} *.[ox]
