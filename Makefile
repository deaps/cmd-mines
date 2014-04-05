# Makefile

# Make vars
VPATH      = src
CC         = gcc
CFLAGS     = -Wall -g
INCLUDES  = position.h
SOURCES    = position.c main.c
OBJFILES   = position.o main.o
EXECUTABLE = World-mines

.SUFFIXES : .c .o
.c.o:
	${CC} -c ${CFLAGS} $<

${EXECUTABLE}: ${OBJFILES}
	gcc -o ${EXECUTABLE} ${OBJFILES}

${OBJFILES}: ${SOURCES} ${INCLUDES}

run:
	./${EXECUTABLE}

.PHONY: clean
clean:
	rm *.o
