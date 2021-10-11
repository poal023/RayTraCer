CC = gcc

CFILES = $(wildcard *.c)
OBJFILES = $(CFILES:.c=.o)
CLAGS = -Wall
LIBFLAGS = -lm

rtMain : $(OBJFILES) 
	$(CC) $(CFLAGS) $(LIBFLAGS) $(OBJFILES) -o rtMain

main.o : main.c
	$(CC) -c main.c
vec3.o : vec3.c vec3.h
	$(CC) -c vec3.c
rays.o : rays.c rays.h
	$(CC) -c rays.c
sphere.o : sphere.c sphere.h
	$(CC) -c sphere.c
utils.o : utils.c utils.h
	$(CC) -c utils.c

clean:
	rm $(OBJFILES) rtMain
