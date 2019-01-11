CC=gcc

VPATH = src include
vpath %.c src
vpath %.h include

CFLAGS  = -g -Wall

all: CC

CC: cc.o cipher.o
	gcc $(CFLAGS) -o cc cc.o cipher.o

CC.o: 
	gcc -c $<
	
clean:
	rm CC.o CC
