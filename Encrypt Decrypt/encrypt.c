/** 
    @file encrypt.c
    @author Ahmed Salama (asalama2)
    This program will apply various operations 
    to an input file to produce an encrypted output file 
  */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "operations.h"
#include "text.h"
/*
	Invalid arguments
	
	@return 1
*/
void usage()
{
  fprintf( stderr, "invalid arguments\n");
  fprintf( stderr, "usage: encrypt operation* (infile|-) (outfile|-)\n" );
  exit(1);
}

/**
    This is the starting point for running your program.
    It will read input from the user, print the table header,
     then use the other two functions to print the rest of the table.

    @return EXIT_SUCCESS
  */
int main( int argc, char *argv[] )
{

  int minNumOfArg = 2;
  int currentArg = 	1;
  
  FILE *infile;
  //if input doesn't = -
  if ( !strcmp( argv[ argc-2 ], "-" ) ){
  	infile = stdin;
  }	
  else{
  		infile = fopen( argv[ argc-2 ], "r" );
  	if ( !infile ) {
    	fprintf( stderr, "Can't open file: %s\n", argv[ argc-2 ]);
    	exit(1);
  	}
  }
  	
  
  readFile( infile  );
  
  while( (argc-minNumOfArg) > currentArg ){
  	if ( strcmp( argv[ currentArg ], "shift" ) != 0 && 
  		strcmp( argv[ currentArg ], "swap" ) != 0  &&
        strcmp( argv[ currentArg ], "left" ) != 0 &&
    	strcmp( argv[ currentArg ], "right" ) != 0 &&
        strcmp( argv[ currentArg ], "reverse" ) != 0 ) {
        
		usage();
        }

  	if ( !strcmp( argv[ currentArg ], "shift" )  ) {
  	  	int n = atoi(argv[ currentArg + 1 ]);
  	  	if ((1 <= n && n <=25 )||( -1 >= n && n  >= -25)){
  		currentArg++;
  		currentArg++;
  		shiftLetters( n );
  		}
  		else{
  		usage();
  		}
  	}
  	if ( !strcmp( argv[ currentArg ], "swap" )  ) {
  	  	int m = atoi(argv[ (currentArg + 1)])-1;
  	  	currentArg++;
  	  	int n = atoi(argv[ currentArg + 1 ])-1;
  	  	if (m >= lines-1|| n >= lines-1)
			usage();
  		currentArg++;
  		currentArg++;
  		swapLines(  m,  n );
  	}
  	if ( !strcmp( argv[ currentArg ], "left" )  ) {
  		rotateLinesLeft( );
		currentArg++;
  	}
  	if ( !strcmp( argv[ currentArg ], "right" ) ) {
  		rotateLinesRight( );
  		currentArg++;
  	}  	
  	if ( !strcmp( argv[ currentArg ], "reverse" )  ) {
  		reverseLines( );
  		currentArg++;
  	}  	  	 
  
  	 	
  }
  
  FILE *outfile;
  //if output doesn't = -		
	if ( !strcmp( argv[ argc-1 ], "-" )  ){
  		outfile =  stdout;
	}
	else{
  		outfile =  stdout;
  		outfile = fopen( argv[ argc-1 ], "wb" );
  		if ( !outfile ) {
   			fprintf( stderr, "Can't open file: %s\n", argv[ argc-1 ] );
    		exit(1);
  		}
  	}
	writeFile( outfile );
	
	fclose(infile);
	fclose(outfile);
	
    return EXIT_SUCCESS;
}
