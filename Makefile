CC = gcc
CFLAGS = -Wall -g

all: student_registry

student_registry: main.o student_registry.o
	$(CC) $(CFLAGS) main.o student_registry.o -o student_registry

main.o: main.c student_registry.h
	$(CC) $(CFLAGS) -c main.c

student_registry.o: student_registry.c student_registry.h
	$(CC) $(CFLAGS) -c student_registry.c

clean:
	rm -f *.o student_registry student_registry.exe
Add Makefile
