#
#  @(#) Makefile
#
CC	= gcc
CFLAGS	= -Wall --std=c99 
OBJ	= siphash64.o siphash64_test.o 
INCLUDES= siphash64.h

BIN	= siphash64_test

all:	$(BIN)


siphash64_test:  $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o $(BIN)

siphash64.o: siphash64.c siphash64.h
siphash64_test.o: siphash64_test.c siphash64.h
