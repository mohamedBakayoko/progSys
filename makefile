OBJETS = useComplexe.o complexe.o

CC = gcc

CFLAGS = -Wall -g

inversion : $(OBJETS)
	$(CC) $(CFLAGS) $(OBJETS) -o inversion -lm
usecomplexe.o : useComplexe.c complexe.h
	$(CC) -c usecomplexe.c
complexe.o : complexe.c complexe.h
	$(CC) -c complexe.c
