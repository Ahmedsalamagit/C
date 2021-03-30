/** 
    @file database.c
    @author Ahmed Salama (asalama2)
    
    This is to alter database
  */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"
#include "input.h"


void error(char const *filename){
	fprintf( stderr, "Invalid movie list: %s\n" , filename);
	exit(1);
}
/*	This function reads all the movies from a movie list file with the given name. 
	It makes an instance of the Movie struct for each one and stores a pointer to that movie in the resizable array

	@param *dat
	@param *filename 
*/
void readDatabase( Database *dat, char const *filename ){
	FILE *fp = fopen( filename, "r" );
	if ( !fp ) {
    		fprintf( stderr, "Can't open file: %s\n", filename);
    		exit(1);
  		}
	int index1 = 0;
	while ( index1 >= 0 ){
	
			
		//re allocating movies array 
		if ( dat->count >= dat->capacity ) {
			dat->capacity *= 2;
			
			*dat->movies = ( Movie **)realloc( *dat->movies, dat->capacity * sizeof( Movie*) );
				
		//for ( int i = 0; i < dat->capacity; i++ )
		//		dat->movies[ i ] = (Movie *)realloc( dat->movies[i], dat->capacity * sizeof( Movie ) );
  	 	}
  	 	
  	 	dat->movies[ index1 ] = (Movie *)malloc( sizeof( Movie ) );

		char *check = readLine(fp);
		if( check != NULL ) {
		
			char id[6];
		    char year[4];
		    char len[3];
			int pos;
			char ch;

		    
		    if (sscanf(check ,"%s\t%n", id, &pos) == 1){	
		    	for( int j = 0 ; j < (sizeof(id)/sizeof(id[0])); j++){
		 			dat->movies[ index1 ]->id[j] = (id[j]- '0');
		 		}
			}
		 		
			for( int i = 0 ; i < sizeof(dat->movies[index1]->title); i++){
				 if (sscanf(check + pos,"%c", &ch ) == 1){
				 
		 			if(ch == '\t')
		 				break;
		 				
		 			dat->movies[index1]->title[i] = ch;
		 			pos++;
		 		}
				else{
				
		 			if ((check+pos)[i+1] != '\t'){
		 				dat->movies[index1]->title[i-1] = '.';
		 				dat->movies[index1]->title[i] = '.';
		 			}
		 			
		    	break;
		   	 }
		    }
		    pos++;
		    if (sscanf(check + pos,"%s\t%s", year, len ) == 2){	
		    	for( int j = 0 ; j < (sizeof(year)/sizeof(year[0])); j++){
		 			dat->movies[ index1 ]->year[j] = (year[j]- '0');
		 		}
		 		for( int j = 0 ; j < (sizeof(len)/sizeof(len[0])); j++){
		 			dat->movies[ index1 ]->len[j] = (len[j]- '0');
		 		}
		    }
		    
		 	//check for errors
			if ((sizeof(id)/sizeof(id[0])) == 0 || strlen(dat->movies[index1]->title) == 0 || (sizeof(year)/sizeof(year[0])) == 0 || (sizeof(len)/sizeof(year[0])) == 0  )	   			
				error(filename); 
			
		 	free(check);   			
			dat->count++;
			index1++;
		}
		
		else
			index1 = -1;
		}
		fclose(fp);
		
}
/*	This function dynamically allocates storage for the database, 
	initializes its fields (to store a resizable array) and returns a pointer to it.
*/
Database *makeDatabase(){

	Database *dat;
	dat = (Database *)malloc(1*sizeof(Database));
	dat->count = 0;
	dat->capacity = 5;
	dat->movies = (Movie **)malloc( dat->capacity * sizeof( Movie*) );
	
	return dat;
}
/*	This function frees the memory used to store the database, including freeing space for all the movies, 
	freeing the resizable array of movie pointers and freeing space for the database struct itself.

	@param *dat
*/
void freeDatabase( Database *dat ){
	for ( int i = 0; i <  dat->count; i++ )
		free( dat->movies[ i ] );
		
	free( dat->movies );
	free(dat);
}
/*	This function isTitle

	@param Movie const *movie
	@param const void *data
*/
static bool isTitle( Movie const *movie, void const *data ){
// assign data back to char[]
	char* title = (char) data;
	return strstr(movie->title, title) != NULL;
}
/*	This function nothingSpecial

	@param Movie const *movie
	@param const void *data
*/
static bool nothingSpecial( Movie const *movie, void const *data){
    return true;
}
/*	This function is year

	@param Movie const *movie
	@param const void *data
*/
static bool isYear( Movie const *movie, void const *data ){
// assign data back to arr[]
	int *arr = (int *) data;
	
	int result2 = 0;
    for( int temp = 0; temp < 4; temp++){
		result2 *= 10;
		result2 += movie->year[temp];
	}
	if(result2 >= arr[0] && result2 <= arr[1])
		return true;
		
	return false;
	} 
/*	This function sortByYear

	@param const void **aptr
	@param const void **bptr 
*/
static int sortByYear( const void *aptr, const void *bptr ){
  
	Movie  *a = (Movie *)aptr;
	Movie  *b = (Movie *)bptr;
  
	int result1 = 0;
	for( int temp = 0; temp < 6; temp++){
		result1 *= 10;
		result1 += a->year[temp];
	}
	
	int result2 = 0;
  	for( int temp=0; temp < 6; temp++){
		result2 *= 10;
    	result2 += b->year[temp];
	}
   
  if ( result1 < result2 )
    	return -1;
  if ( result1 > result2 )
    	return 1;
    
  return 0;
}
/*	This function sorts by id

	@param const void **aptr
	@param const void **bptr 
*/
static int sortById( const void **aptr, const void **bptr ){

  Movie  *a = (Movie *)aptr;
  Movie  *b = (Movie *)bptr;
  
  int result1 = 0;
  for( int temp=0; temp < 6; temp++){
  	result1 *= 10;
  	result1 += a->id[temp];
	}
  int result2 = 0;
  for( int temp=0; temp < 6; temp++){
    result2 *= 10;
    result2 += b->id[temp];
  }
   
  if ( result1 < result2 )
    return -1;
  if ( result1 > result2 )
    return 1;
  return 0;
}

/*	This function lists all the movies in the database, sorted by ID number.
	The movies component can call this in response to the user entering the database command.

	@param *dat
*/
void listAll( Database *dat ){
	//qsort( dat, dat->count, sizeof( dat ), sortById );
	listDatabase( dat, nothingSpecial, NULL );
}
/*	This function lists all the movies with a year between the given min and max values (inclusive). 
	Your movies component can call this when the user enters the year command. 
	In the output, movies should be sorted by year, and by ID if they have the same year.

	@param *dat
	@param min
	@param max
*/
void listYear( Database *dat, int min, int max ){
	int *arr = (int *)malloc(2* sizeof(int));
	arr[0] = min;
	arr[1] = max;
	
	qsort( dat, dat->count, sizeof( dat->movies[0] ), sortByYear );
    listDatabase( dat, isYear, arr );
}
/*	This function lists all the movies where the given title string occurs in the movie's title field. 
	In the output, the movies should be listed in order by ID. 
	For this function (and the extra credit listGenre() function),
	you may find the strstr() function useful for finding a short string inside a larger one. 
	We will talk about this function briefly in class, but, if you want to use it, you may need to do some reading on your own. 
 	You'll find it on page 620 of your textbook, or, if you're on a Linux machine, 
	you can just type man strstr at the shell prompt to look at the online documentation.

	@param *dat
	@param *title
*/
void listTitle( Database *dat, char const *title ){
	qsort( dat, dat->count, sizeof(  dat->movies[0]), sortById );
    listDatabase( dat, isTitle, title );
}

/*	This is a static function in the database component. 
	It is used by the listAll(), listYear(), listTitle(), and listGenre() functions to actually report the list of movies in the right format.
	In addition to a pointer to the database, this function also takes a pointer to a function (test) 
	and a pointer to an arbitrary block of data (data) to let the caller tell the function which particular movies it should print out. 
	This is described in more detail in the "Selecting Movies to Report" section below.

	@param *dat
*/
static void listDatabase( Database *dat, bool (*test)( Movie const *movie, void const *data ), void const *data ){
	
	int count = 0;
	int id=0;
	int len=0;
	int  year = 0;
	for(int i = 0; i < dat->count; i++){
		bool check = test(dat->movies[i], data);
		if( check ){	
			count++;
			for( int j = 0 ; j < (sizeof(dat->movies[ i ]->id)/sizeof(dat->movies[ i ]->id[0])); j++){
		 			id *= 10;
    				id += dat->movies[ i ]->id[j];
		 		}
		 	for( int j = 0 ; j < (sizeof(dat->movies[ i ]->year)/sizeof(dat->movies[ i ]->year[0])); j++){
		 			year *= 10;
    				year += dat->movies[ i ]->year[j];
		 		}
		 	for( int j = 0 ; j < (sizeof(dat->movies[ i ]->len)/sizeof(dat->movies[ i ]->len[0])); j++){
		 			len *= 10;
    				len += dat->movies[ i ]->len[j];
		 		}	
			if(count == 1)
				printf("    ID                                  Title Year Len");
				
			printf("\n%6d %38s %4d %3d", id, dat->movies[ i ]->title, year, len);
		   }
		
			}
		if( count == 0)
			printf("No matching movies");
			
		printf("\n");
	}

