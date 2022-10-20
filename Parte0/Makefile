CC     = gcc
CFLAGS = -Wall -pedantic -g -O2

all: average mmul

mmul: mmul.c
	$(CC) -o mmul $(CEXTRA) $(CFLAGS) mmul.c

average: average.c
	$(CC) -o average $(CEXTRA) $(CFLAGS) average.c
   

.PHONY: clean
clean:
	rm mmul
