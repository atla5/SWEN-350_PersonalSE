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
#define MAXLINE     (100)

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

    //declare counter and character	
    char c;
    int i = 0;

    //write getchar() to field until an end_of_field character.
    while( !is_end_of_field(c=getchar()) ){

        //add to field
        field[i] = c;
        i++;
    }
    //replace terminator with null terminator
    field[i] = '\0';

    //return the end_of_field character.
    return c;

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
    csv_line csvLine;
    csvLine.nfields = 0;
    char c;

    //get and write field until it returns EOF
    while( (c=get_field(csvLine.field[csvLine.nfields++])) == ',' ){ }

    if(c==EOF){ csvLine.nfields = 0; }

    return csvLine;
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
        printf("%5s = ", header.field[i]);
        printf("%s\n ", data.field[i]);
    }

    printf("\n");

}

/*
 * Driver - read a CSV line for the header then read and print data lines
 * until end of file.
 */
int main() {
	csv_line header ;
	csv_line current ;

	header = get_line() ;
	current= get_line() ;

	while ( current.nfields > 0 ) {
		print_csv(header, current) ;
		current = get_line() ;
	}

	return 0 ;
}

/* using fgets and strtok 
csv_line getLine(){

    csv_line csvL;
    csvL.nfields=0;
 
    char line[MAXLINE+1];
    char * result;  

    fgets(line,MAXLINE,stdin);
    result = strtok(line,",");

    int n;
    while(result != NULL){
    
        f_string f;        
        
        //create f_string 'f'
        int i;
        for(i=0;i<strlen(result)-1;i++){
            f[i] = result[i];
        }
        f[i] = '\0'; 

        //set field at nfields, then increment nfields
        csvL.field[csvL.nfields][i] = f;
        csvL.nfields++;

        //move to next field
        result=strtok(line,",");
    }

    printf("nfields: %d\n",csvL.nfields);
    return csvL;
}
*/
