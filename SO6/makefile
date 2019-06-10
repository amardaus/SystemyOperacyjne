CC = gcc

.PHONY: all
all: libshmem.so main.x producent.x konsument.x glowny.x cykliczny.x

shmem.o: shmem.c
libshmem.so: shmem.o

main.o: main.c
main.x: main.o

producent.o: producent.c
producent.x: producent.o

konsument.o: konsument.c
konsument.x: konsument.o

glowny.o: glowny.c
glowny.x: glowny.o

cykliczny.o: cykliczny.c
cykliczny.x: cykliczny.o


shmem.o: shmem.c
	$(CC) -c -O -fPIC -lpthread shmem.c

libshmem.so: shmem.o
	$(CC) -shared -o libshmem.so shmem.o

%.o: %.c
	$(CC) -c -o $@ $<

%.x: %.o
	$(CC) -Wall $^ -L. -lshmem -lsem -o $@ -lrt -lpthread
#export: 

.PHONY: clean
clean:
	${RM} *.[ox]
	${RM} *.so

#export LD_LIBRARY_PATH=/home/olcia/Documents/SystemyOperacyjne/SO6:$LD_LIBRARY_PATH
#https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html
