.PHONY: all
all: libsem.a semuse.x powielacz.x prog.x

sem.o: sem.c
libsem.a: sem.o

sem.o: sem.c
	gcc -c sem.c

libsem.a: sem.o
	ar rv libsem.a sem.o

%.o: %.c
	gcc -c -o $@ $<

%.x: %.c
	gcc $^ -L. -lsem -lpthread -o $@


.PHONY: clean
clean:
	${RM} *.[oax]

