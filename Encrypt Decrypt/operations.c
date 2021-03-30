/** 
    @file operations.c
    @author Ahmed Salama (asalama2)
    This program is to execute the operations that will be used to encrypt/decrypt
  */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "operations.h"
#include "text.h"

 /*	
 	It modifies the global text representation to shift each letter by the given amount. 
	If n is positive, each letter is replaced with the letter n characters to the right in the alphabet, wrapping around as necessary, and preserving case. 
	If n is negative, the converse operation is carried out. You may assume that values of n are in the range 1 to 25 or -25 to -1, 
	inclusive (you should document that in your function).
	
	@param n amount to shift
*/
void shiftLetters( int n ){
	if (1 <= n ){
		if(n <= 25 ){
			for (int i = 0; i < lines ; i++) {
	 			for (int j = 0; j < strlen(arr[i]) ; j++){
	 				int num = 0;
	 				while( n > num ){
						if ( arr[i][j] == 'Z' || arr[i][j] == 'z' || arr[i][j] < 'A'||
						( arr[i][j] > 'Z' && arr[i][j] < 'a') || arr[i][j] > 'z'){
							if(arr[i][j] < 'A'||( arr[i][j] > 'Z' && arr[i][j] < 'a') || arr[i][j] > 'z')
								arr[i][j] = arr[i][j];
							if ( arr[i][j] == 'Z' )
								arr[i][j] = 'A';
							if (arr[i][j] == 'z' )
								arr[i][j] = 'a';
								}
						else {
							arr[i][j]++;
						}
						num++;
	 					}
	 				}
	 			}
	 		}
		}
	if (-1 >= n){
		if( n  >= -25){
			for (int i = 0; i < lines ; i++) {
	 			for (int j = 0; j < strlen(arr[i]) ; j++){
	 				int countter = (n*-1);
	 				int num = 0;
	 				while( countter > num ){
						if ( arr[i][j] == 'A' || arr[i][j] == 'a' || arr[i][j] < 'A'||
						( arr[i][j] > 'Z' && arr[i][j] < 'a') || arr[i][j] > 'z'){
							if(arr[i][j] < 'A'||( arr[i][j] > 'Z' && arr[i][j] < 'a') || arr[i][j] > 'z')
								arr[i][j] = arr[i][j];
							if ( arr[i][j] == 'A' )
								arr[i][j] = 'Z';
							if (arr[i][j] == 'a' )
								arr[i][j] = 'z';
								}
						else {
							arr[i][j]--;
						}
						num++;
	 				}
	 			}
	 		}
		}
	}
}
/* 
	It modifies the global text representation by reversing the order of the characters contained in each line (row).
*/
void reverseLines( ){

	for (int i = 0; i < lines ; i++) {
		int k = 0;
		int num = strlen(arr[i]);
		for (int j = 0, x = num - 1; j < x; j++ , x-- ) {
            char temp = arr[i][j];
            arr[i][j] = arr[i][x];
            arr[i][x] = temp;
        }
    }
}
/*
	It modifies the global text representation by swapping the contents of lines (rows) m and n. 
	You can choose exactly how you want the values of m and n to work (e.g., are they the same values given on the command line,
 	or would you rather have them count from zero for the internal workings of your program?). 
 	This function would be a good place to use the strcpy() function we talked about in class. 
 	It could help to copy lines.
 	
 	@param m line to swap
 	@param n line to swap
*/
void swapLines( int m, int n ){
	
	int len = strlen(arr[m]);
	int len2 = strlen(arr[n]);
	if (len == 0 )
		len = 1;
	if (len2 == 0 )
		len2 = 1;
    char temp1[len];
    char temp2[len2];
    strcpy(temp1, arr[m]);
	strcpy(temp2, arr[n]);
	strcpy(arr[m],temp2);
	strcpy(arr[n],temp1);
	
}

 /*
 	It modifies the global text representation by moving the characters in each line one place to the left
  	and moving the first character to the end of the line.
*/
void rotateLinesLeft( ){
	for (int i = 0; i < lines ; i++) {
		int num = strlen(arr[i]);
		for (int j=0; j < num-1; j++) {
            char temp = arr[i][j];
            arr[i][j] = arr[i][j+1];
            arr[i][j+1] = temp;
    	}
	}
}
/*
	It modifies the global text representation by moving the characters in each line one place to the right 
	and moving the last character to the beginning of the line.
*/
void rotateLinesRight( ){
	for (int i = 0; i < lines ; i++) {
		int num = strlen(arr[i]);
		for (int j=num-1; j > 0; j--) {
            char temp = arr[i][j-1];
            arr[i][j-1] = arr[i][j];
            arr[i][j] = temp;
        }
    }
}
