CC = gcc
CFLAGS = -Wall -std=c99 -g

#The default to build the executable
movies: movies.o database.o input.o

#Builds the file
movies.o: movies.c database.h input.h
    
#Builds the database.o file
database.o: database.c database.h input.h 

#Builds the input.o file
input.o: input.c input.h 

#Rule used for cleaning the directory of files
clean:
	rm -f movies.o database.o input.o
	rm -f output.txt