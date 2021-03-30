/** 
    @file operations.h
    @author Ahmed Salama (asalama2)
    This program is to execute the operations that will be used to encrypt/decrypt
  */

 /*	
 	It modifies the global text representation to shift each letter by the given amount. 
	If n is positive, each letter is replaced with the letter n characters to the right in the alphabet, wrapping around as necessary, and preserving case. 
	If n is negative, the converse operation is carried out. You may assume that values of n are in the range 1 to 25 or -25 to -1, 
	inclusive (you should document that in your function).
*/
void shiftLetters( int n );
/* 
	It modifies the global text representation by reversing the order of the characters contained in each line (row).
*/
void reverseLines( );
/*
	It modifies the global text representation by swapping the contents of lines (rows) m and n. 
	You can choose exactly how you want the values of m and n to work (e.g., are they the same values given on the command line,
 	or would you rather have them count from zero for the internal workings of your program?). 
 	This function would be a good place to use the strcpy() function we talked about in class. 
 	It could help to copy lines.
*/
void swapLines( int m, int n );
 /*
 	It modifies the global text representation by moving the characters in each line one place to the left
  	and moving the first character to the end of the line.
*/
void rotateLinesLeft( );
/*
	It modifies the global text representation by moving the characters in each line one place to the right 
	and moving the last character to the beginning of the line.
*/
void rotateLinesRight( );