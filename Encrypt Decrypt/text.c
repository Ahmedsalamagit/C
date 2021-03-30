/** 
    @file text.c
    @author Ahmed Salama (asalama2)
    This program is to read and write from input/array to output/array
  */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "text.h"


// global lines representation
int lines;
// global 2d array representation
char arr[101][10000];

/**
    It reads text from the given file and stores it in the global text representation. 
	If the program is reading from standard input, then the given file pointer will be stdin.
	
	@param *fp file to read
*/
void readFile( FILE *fp ){
  	lines = 1;
    int row = 0;
    int col = 0;
    char ch;

 	while (fscanf(fp, "%c", &ch) == 1){
        //If the program is given an input file with a line that's too long, 
		//it will print the following message to standard error and terminate with an exit status of 1.
		//Line too long

		if ( col == 101) {
		    fprintf( stderr, "Line too long\n");
			exit(1);
		}
		//If the program is given a file with too many lines,
		//it will print the following message to standard error and terminate with an exit status of 1.
		//Too many lines
		if ( lines >= 10000) {
			fprintf( stderr, "Too many lines\n");
			exit(1);
			}
			
		arr[row][col] = ch;
		
        if (ch == '\n'){
        	arr[row][col] = '\0';
            lines++;
            row++;
            col = -1;
        }

        col++;
    }
}


/*	It writes out the text from the global text representation to the given output file. 
	If the program is writing to standard output, then the given file pointer should be stdout
	
	@param *fp file to write to
*/
void writeFile( FILE *fp ){
	
	if ( lines == 10000) {
			fprintf( stderr, "Too many lines\n" );
			exit(1);
			}	
	for (int i = 0; i < lines; i++){
        fprintf(fp, "%s", arr[i]);
        if (i != (lines-1))
        	fprintf(fp, "\n");
    }
}
