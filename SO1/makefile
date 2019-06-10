CC := gcc
CFLAGS := -O3 -Wall
LDLIBS := -lm

.PHONY: all
all: main.x kopiuj.x procesy.x lider.x drzewko_genealogiczne.x

main.o: main.c procinfo.h
procinfo.o : procinfo.c procinfo.h
main.x: main.o procinfo.o

kopiuj.o: kopiuj.c
kopiuj.x: kopiuj.o

procesy.o: procesy.c procinfo.h
procesy.x: procesy.o procinfo.o

lider.o: lider.c procinfo.h
lider.x: lider.o procinfo.o

drzewko_genealogiczne.o: drzewko_genealogiczne.c procinfo.h
drzewko_genealogiczne.x: drzewko_genealogiczne.o procinfo.o

%.o: %.c 
	$(CC) $(CFLAGS) -c -o $@ $<
#-c genereate object file, $< is the first dependency

%.x: %.o
	$(CC) $(LDLIBS) -o $@ $^

.PHONY: clean
clean:
	${RM} *.[ox]
#-f - force, if files do not exits, it doesnt show errors



