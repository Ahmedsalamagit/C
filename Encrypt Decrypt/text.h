/** 
    @file text.h
    @author Ahmed Salama (asalama2)
    This program is to read and write from input/array to output/array
  */
  
/**
    It reads text from the given file and stores it in the global text representation. 
	If the program is reading from standard input, then the given file pointer will be stdin.
	
	@param *fp file to read
*/
void readFile( FILE *fp );

/*	It writes out the text from the global text representation to the given output file. 
	If the program is writing to standard output, then the given file pointer should be stdout
	
	@param *fp file to write to
*/
void writeFile( FILE *fp );

// global lines representation
extern int lines;
// global 2d array representation
extern char arr[101][10000];
