/*This function reads a single line of input from the given file and returns it as a string inside a block of dynamically allocated memory. 
You can use this function to read commands from the user and to read movie descriptions from a movie list file. 
Inside the function, you should implement a resizable array to read in a line of text that could be arbitrarily large. 
If there's no more input to read, this function should return NULL. Since this function returns a pointer to dynamically allocated memory, 
some other code will be responsible for eventually freeing that memory (to avoid a memory leak).

@param FILE *fp
@return char
*/
char *readLine( FILE *fp );