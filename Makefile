# Makefile

# Make vars
VPATH      = src
CC         = gcc
CFLAGS     = -Wall -g
INCLUDES  = position.h gameBoard.h
SOURCES    = position.c gameBoard.c main.c
OBJFILES   = position.o gameBoard.o main.o
EXECUTABLE = cmd-mines

.SUFFIXES : .c .o
.c.o:
	${CC} -c ${CFLAGS} $<

${EXECUTABLE}: ${OBJFILES}
	${CC} -o ${EXECUTABLE} ${OBJFILES}

${OBJFILES}: ${SOURCES} ${INCLUDES}

run:
	./${EXECUTABLE}

.PHONY: clean
clean:
	rm *.o
