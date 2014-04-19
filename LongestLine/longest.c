#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 80   /* maximum input line size */

/* function declarations */
int readline( char line[], int max );
void copy( char to[], char from[] );

/* print longest input line */
int main(){
	int len;	       	   /* current line length */
	char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest input line */
    //longest = "\0";

	while ( (len = readline( line, MAXLINE )) > 0 ) {

        //print the current line
		//printf("%s", line);
 
        //update longest if it's longer than longest
        if (len > strlen(longest)){
            copy(longest,line);
        }

	}

    //print the longest line
    printf("%s\n",longest);

	return 0;
}

/* readline: read a line into s, return length */
int readline( char s[], int lim ){
    int i;
    
    //get line from stdin, return length(line) or 0 if EOF reached
    if( fgets(s,MAXLINE,stdin) != NULL ){
        return strlen(s);
    }else{
        return 0;
    }
    
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy( char to[], char from[] ){
    
    int i;
    int n = strlen(from);
    
    for(i=0;i<n;i++){
        to[i] = from[i];
    }

    return;
	
}



