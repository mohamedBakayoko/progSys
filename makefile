#--------Makefile1---------


#useComplexe: useComplexe.o complexe.o
#	gcc -Wall -g useComplexe.o complexe.o-o useComplexe -lm
#usecomplexe.o : useComplexe.c complexe.h
#	gcc -c usecomplexe.c
#complexe.o : complexe.c complexe.h
#	gcc -c complexe.c 



#---------Makefile2-------------

#OBJETS = useComplexe.o complexe.o

#CC = gcc

#CFLAGS = -Wall -g

#inversion : $(OBJETS)
#	$(CC) $(CFLAGS) $(OBJETS) -o inversion -lm
#usecomplexe.o : useComplexe.c complexe.h
#	$(CC) -c usecomplexe.c
#complexe.o : complexe.c complexe.h
#	$(CC) -c complexe.c 


#--------makefile 3, utilisation de APPLi----------

compile = gcc -Wall -O3
objet = $(compile) -c
executable = $(compile) -o
objetsFile = complexe.o $(APPLI).o

all : $(APPLI) run 

$(APPLI) : $(objetsFile)
	$(compile) $(objetsFile) -o $(APPLI) -lm

$(APPLI).o: $(APPLI).c complexe.h
	$(objet) $(APPLI).c

complexe.o : complexe.c complexe.h
	$(objet) complexe.c

# --suppresion des fichiers objet
clean : $(APPLI)
	rm -f *.o
#-- run the programme APPLI after compilation
run : $(APPLI)
	./$(APPLI)	
	
	
	
	
	
	
	
	
	
	
