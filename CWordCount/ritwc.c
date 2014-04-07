#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define FALSE (0)
#define TRUE  (1)
#define MAX_LINE (100)

int main() {
	int tot_chars = 0 ;	/* total characters */
	int tot_lines = 0 ;	/* total lines */
	int tot_words = 0 ;	/* total words */
    char line[MAX_LINE];

	/* REPLACE WITH ADDITIONAL VARIABLE DECLARATIONS YOU NEED */

    while( fgets(line,MAX_LINE,stdin) != NULL){
        
        //increment num_lines
        tot_lines++;
        
        //add the length of the line to num_chars
        tot_chars+=strlen(line);

        //tokenize the line and add to num_words
        
    }

    printf(" %d  %d %d\n",tot_lines,tot_words,tot_chars);

	return 0 ;
}
