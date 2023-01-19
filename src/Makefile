CC=gcc
CFLAGS=-c -Wall
LDFKAGS=-Wall -Werror -Wextra

SOURCES1=graph.c stack.c 

EXECUTABLE1=../build/graph

all:
	$(CC) $(SOURCES1) $(LDFKAGS) -o $(EXECUTABLE1)

rebuild:
	rm -rf *.o 
	make

clear:
	rm -rf *.o 
