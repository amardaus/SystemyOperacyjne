CC = gcc

.PHONY: all
all: wykluczanie.x

wykluczanie.o: wykluczanie.c
wykluczanie.x: wykluczanie.o

%.o: %.c
	$(CC) -c -o $@ $<
%.x: %.o
	$(CC) -Wall $^ -lpthread -o $@
	
.PHONY: clean
clean:
	${RM} *.[ox]
