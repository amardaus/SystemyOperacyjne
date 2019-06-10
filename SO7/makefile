CC = gcc

.PHONY: all
all: libmsg.a klient.x serwer.x

msg: msg.c
libmsg.a: msg.o

msg: msg.c
	gcc -c msg.c
#The -c switch means: Compile and assemble, but do not link. 
libmsg.a: msg.o
	ar rv libmsg.a msg.o
#r – replace, v – verbose. 

%..o: %..c
	$(CC) -c -o $@ $<

%.x: %.c
	$(CC) $^ -L. -lmsg -o $@

.PHONY: clean
clean:
	${RM} *.[oax]

xt:
	xterm ./serwer.x &
	xterm ./klient.x &
	xterm ./klient.x &
	xterm ./klient.x &
