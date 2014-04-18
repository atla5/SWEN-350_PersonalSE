#include <stdlib.h>
#include <stdio.h>

#define MAXLINE 80   /* maximum input line size */

/* function declarations */
int readline( char line[], int max );
void copy( char to[], char from[] );

/* print longest input line */

int main()
{
	int len;	       	   /* current line length */
	char line[MAXLINE];    /* current input line */

	while ( (len = readline( line, MAXLINE )) > 0 ) {
		printf("%s", line);

		}

	return 0;
}

/* readline: read a line into s, return length */
int readline( char s[], int lim )
{
    int i;

	/* your code here */
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy( char to[], char from[] )
{

	/* your code here */
}



