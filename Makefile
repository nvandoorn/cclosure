# lift life
# http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/makefile.4
CC=gcc
CFLAGS=-I. -I./segfault-suite
DEPS=segfault-suite/test-lib.h core.h
OBJ=segfault-suite/test-lib.o core.o
MAIN_OBJ=cclosure.o
TEST_OBJ=core.test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cclosure: $(OBJ) $(MAIN_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

test: $(OBJ) $(TEST_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -rf *.o

