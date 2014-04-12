#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define FALSE (0)
#define TRUE  (1)
#define MAX_LINE (200)

int main() {

    //initialize counter variables
	int tot_chars = 0 ;  /* total characters */
	int tot_lines = 0 ;  /* total lines */
	int tot_words = 0 ;	 /* total words */

    //declare character array to hold a line of text
    char line[MAX_LINE+1]; /* line from file */
    line[MAX_LINE] = '\0';

    //for every line in the file
    while( fgets(line,MAX_LINE+1,stdin) != NULL){
        
        //increment num_lines 
        tot_lines++;
        
        //add the length of the line to num_chars
        tot_chars+=strlen(line);

        //tokenize the line and add to num_words by " ";
        char * result = NULL;
        result = strtok(line, " \n\t");
        while(result != NULL){
            tot_words++;
            result = strtok( NULL, " \n\t");
        }
 
    }

    printf(" %d  %d %d\n",tot_lines,tot_words,tot_chars);

	return 1;
}
