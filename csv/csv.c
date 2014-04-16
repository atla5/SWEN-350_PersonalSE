/*
 * Skeleton implementation for the activity to parse and print
 * CSV formatted files read from standard input.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Boolean here - just so we don't have to import a text file.
 */
typedef enum { false, true } bool ;

#define MAX_FIELDS	(15)	/* maximum fields on a CSV input line */
#define MAX_CHARS	(20)	/* maximum characters in any one field */

/*an array of characters representing a single filed.*/
typedef char f_string[MAX_CHARS+1] ;	/* string for each field */

/*
 * A parsed CSV line, with the number of fields and upto MAX_FIELDS 
 * themselves.
 */
typedef struct {
	int nfields ;				    /* 0 => end of file */
	f_string field[MAX_FIELDS] ;	/* array of strings for fields */
} csv_line ;

/*
 * Returns true iff the character 'ch' ends a field. That is, ch is end of file,
 * a comma, or a newline.
 */
bool is_end_of_field(char ch) {
	return (ch == ',') || (ch == '\n') || (ch == EOF) ;
}

/*
 * Return the minimum of two integers.
 */
int min(int x, int y) {
	return x < y ? x : y ;
}

/*
 * Read the next field from standard input. Returns the value of getchar() that
 * stopped (terminated) the field.
 */
int get_field(f_string field) {
	
    //get the terminating character
    char terminator = field[strlen(field)];
    
    //replace terminator with null terminator
    field[strlen(field)] = '\0';

    return terminator;

}

/*
 * Read in a CSV line. No error checking is done on the number of fields or
 * the size of any one field.
 * On return, the fields have been filled in (and properly NUL-terminated), and
 * nfields is the count of the number of valid fields.
 * nfields == 0 means end of file was encountered.
 */
csv_line get_line() {
    
    //declare and initialize a valid csv_line with
    csv_line line;
    f_string field;
    int numFields = 0;
    char c,t;

    int i = 0;
    while( (c=getchar()) != EOF ){
        
        //write character from getchar() to field
        field[i] = c;

        //if 'end_of_field' character is reached
        if( is_end_of_field(c) ){ 

            //send f_line to get_field(), then add to csv_line
            t = get_field(field);
            line.field[numFields] = field;

            //clear field
            field = "";

            //increment numFields
            numFields++; 
        }
    }                
}

/*
 * Print a CSV line, associating the header fields with the
 * data line fields.
 * The minimum of the number of fields in the header and the data
 * determines how many fields are printed.
 */
void print_csv(csv_line header, csv_line data) {

    //declare int to iterate with	
    int i;

    //get the minimum number of fields
    int minFields = min(header.nfields, data.nfields);

    //print header line
    for(i=0;i<minFields;i++){ 
        printf("%s = ", header.field[i]);
        printf("%s\n ", data.field[i]);
    }

}

/*
 * Driver - read a CSV line for the header then read and print data lines
 * until end of file.
 */
int main() {
	csv_line header ;
	csv_line current ;

	header = get_line() ;
	current = get_line() ;

	while ( current.nfields > 0 ) {
		print_csv(header, current) ;
		current = get_line() ;
	}

	return 0 ;
}
