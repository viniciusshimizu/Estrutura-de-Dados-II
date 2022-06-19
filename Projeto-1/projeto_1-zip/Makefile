T = ./TAD/


all: exec
 
exec: main.o DNA.o
	gcc -o exec main.o DNA.o
 
main.o: main.c $(T)DNA.h
	gcc -I$(T)  -o main.o main.c -c -Wall -pedantic
 
DNA.o: $(T)DNA.c $(T)DNA.h
	gcc -I$(T) -o DNA.o $(T)DNA.c -c -Wall -pedantic
 
clean:
	rm *.o exec