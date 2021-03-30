/** 
    @file movies.c
    @author Ahmed Salama (asalama2)
    
    main function movies
  */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"
#include "input.h"
/*usage

*/

int capacity = 5;

void usage()
{
  fprintf( stderr, "usage: movies <movie-list>*" );
  exit(1);
}
/**
    
    @return EXIT_SUCCESS
  */
int main( int argc, char *argv[] )
{
	// create watchlist and database
	Database *dat = makeDatabase();
	Database *watchlist = makeDatabase();

	//read file
	int i = 1;
	while(i < argc) {
		// scan and store line from FILE
		readDatabase(dat,argv[ i ]);
  		i++;
	}
  
  //reading from input commands
	int loop = 0;
  
	while ( loop == 0 ){
		printf("cmd> ");
  		int len = 0;

  		// Allocate an array big enough to get us started.
    	char *str = (char *)malloc( capacity * sizeof( char ) );
 		// Keep reading chars.
  		char ch;
  		while ( scanf( "%c", &ch ) == 1 ) {
   		// Grow the array if we're out of space.

   			if ( len >= capacity ) {
				capacity *= 2;
				str = (char *)realloc( str, capacity * sizeof( char ) );
  	 		}	
  	 		if (ch == '\n')
  	 			break;
  	 	
 	 		str[ len++ ] = ch;
 	 		printf("%c", ch);
    	}

  		printf("\n");
  		if (strstr(str, "database") != NULL) {
  			listAll( dat );
		} 
  		else if (strstr(str, "list") != NULL) {
  			listAll( watchlist );
		} 
		else if (strstr(str, "year") != NULL){
			int min;
			int max;
			if (sscanf(str, "%*s %d %d", &min, &max) == 2){
  				listYear( dat, min, max );
  			}
  			else
				printf("Invalid command\n");
		}
		else if (strstr(str, "title") != NULL){
  			char *title = (char *)malloc( 20 * sizeof( char ) );
			if (sscanf(str, "%*s %s", title) == 1){
  				listTitle( dat ,title);
  			}
  			else
				printf("Invalid command\n");
			free(title);
}
		else if (strstr(str, "add") != NULL){
			int id;
			if (sscanf(str, "%*s %dl", &id) == 1){
				//add to watchlist
  				add( watchlist,  &dat,  id );
  			}
  			else
				printf("Invalid command\n");
	
		}
		else if (strstr(str, "remove") != NULL){
			int id;
			if (sscanf(str, "%*s %d", &id) == 1){
  				//remove from watchlist
  				remover(watchlist,  id );
  			}
  			else
				printf("Invalid command\n");

		}
		else if (strstr(str, "quit") != NULL){
  			loop = -1;
}
		else {
			printf("Invalid command\n");
		}
  
	free(str);
  }
	for ( int i = 0; i <  watchlist->count; i++ )
		free( watchlist->movies[ i ] );
		
	free( watchlist->movies );
	free(watchlist);
	freeDatabase( dat );
	freeDatabase( watchlist );
  }
  
  void remover( Database *watchlist, int id ){
  int num = id;
  int count = 0;
  do {
        count++;
        num /= 10;
    } while(num != 0);
    
  	int array[count];
	for (int i = (count-1); i >= 0; i--) {
    	array[i] = id % 10;
    	id /= 10;
	}
	
	int check = 0;
	for(int i = 0; i < watchlist->count; i++){
		for(int j = 0; j < watchlist->movies[i]->id ; j++){
			if(array[j] != watchlist->movies[i]->id[j] ){
				check = 0;
				break;
			}
			check = j;
		}
		if (check != 0)
			break;
	}
	if (check == 0)
		printf("Movie ID is not on the watch list");
		
	else{
		free(watchlist->movies[watchlist->count++]);
		watchlist->count--;
	}
  }
  
  void add( Database *watchlist, Database *dat, int id ){
  int num = id;
  int count = 0;
  do{
        count++;
        num /= 10;
    } while(num != 0);
    
  	int array[count];
	for (int i = (count-1); i >= 0; i--) {
    	array[i] = id % 10;
    	id /= 10;
	}
	int check = 0;
	for(int i = 0; i < dat->count; i++){
		for(int j = 0; j < dat->movies[i]->id ; j++){
			if(array[j] != dat->movies[i]->id[j] ){
				check = 0;
				break;
			}
			check = j;
		}
		if (check != 0)
			break;
	}
		if ( watchlist->count >= watchlist->capacity ) {
			watchlist->capacity *= 2;
			watchlist->movies = ( Movie *)realloc( watchlist->movies, watchlist->capacity * sizeof( Movie*) );
			}
			
	if (check == 0)
		printf("Movie ID is not in the database");
		

	else{		
		watchlist->movies[watchlist->count++] = dat->movies[check] ;
		dat->count++;
	}
  }