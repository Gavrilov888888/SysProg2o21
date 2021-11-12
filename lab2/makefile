CC=gcc
CFLAGS=-I.
DEPS = rps.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

rps: rps.o rpsf.o 
	$(CC) -o rps rps.o rpsf.o 
