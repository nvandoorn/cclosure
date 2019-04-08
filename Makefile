# lift life
# http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/makefile.4
CC=gcc
CFLAGS=-I./src
DEPS=
OBJ=
MAIN_OBJ= cclosure.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cclosure: $(OBJ) $(MAIN_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -rf *.o

