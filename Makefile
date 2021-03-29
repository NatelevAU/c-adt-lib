.PHONY: clean

BIN = adt-generator

OBJS = *.c

CC = gcc
CFLAGS = -I . \
		 -I ./include

LDLIBS = -lm

SUFFIXES= .c .o
.SUFFIXES: $(SUFFIXES) .


all: $(BIN)

$(BIN) : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(BIN)

.cpp.o:
	$(CC) $(CFLAGS) -c $*.cpp

clean:
	rm -rf *.o $(BIN)