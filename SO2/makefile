CC := gcc
CFLAGS := -O3 -Wall
LDFLAGS := -lm

.PHONY: all
all: main.x drzewko1.x drzewko2.x potomny.x macierzysty.x zombie.x orphan.x execute.x

main.o: main.c procinfo.h
main.x: main.o procinfo.o

procinfo.o: procinfo.c procinfo.h

drzewko1.o: drzewko1.c procinfo.h
drzewko1.x: drzewko1.o procinfo.o

drzewko2.o: drzewko2.c procinfo.h
drzewko2.x: drzewko2.o procinfo.o

potomny.o: potomny.c procinfo.h
potomny.x: potomny.o procinfo.o

macierzysty.o: macierzysty.c procinfo.h
macierzysty.x: macierzysty.o procinfo.o

zombie.o: zombie.c
zombie.x: zombie.o

orphan.o: orphan.c
orphan.x: orphan.o

execute.o: execute.c
execute.x: execute.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^

.PHONY: clean
clean:
	${RM} *.[ox]
