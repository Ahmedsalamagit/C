
/*

*/
typedef struct MoviesStruct {
	int id[ 6 ];
	char title[ 39 ]; 
	int year[ 4 ];
	int len[ 3 ];
	 
} Movie;


 typedef struct DatabaseStruct {
	int count;
	int capacity ;
	Movie  **movies;
} Database;
/*	This function dynamically allocates storage for the database, 
	initializes its fields (to store a resizable array) and returns a pointer to it.


*/
void readDatabase( Database *dat, char const *filename );
/*	This function dynamically allocates storage for the database, 
	initializes its fields (to store a resizable array) and returns a pointer to it.
*/
Database *makeDatabase();
/*	This function frees the memory used to store the database, including freeing space for all the movies, 
	freeing the resizable array of movie pointers and freeing space for the database struct itself.

	@param *dat
*/
void freeDatabase( Database *dat );
/*	This function lists all the movies in the database, sorted by ID number.
	The movies component can call this in response to the user entering the database command.

	@param *dat
*/
void listAll( Database *dat );
/*	This function lists all the movies with a year between the given min and max values (inclusive). 
	Your movies component can call this when the user enters the year command. 
	In the output, movies should be sorted by year, and by ID if they have the same year.

	@param *dat
	@param min
	@param max
*/
void listYear( Database *dat, int min, int max );
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
void listTitle( Database *dat, char const *title );
/*	This is a static function in the database component. 
	It is used by the listAll(), listYear(), listTitle(), and listGenre() functions to actually report the list of movies in the right format.
	In addition to a pointer to the database, this function also takes a pointer to a function (test) 
	and a pointer to an arbitrary block of data (data) to let the caller tell the function which particular movies it should print out. 
	This is described in more detail in the "Selecting Movies to Report" section below.

	@param *dat
*/
static void listDatabase( Database *dat, bool (*test)( Movie const *movie, void const *data ), void const *data );