/*
 * Implementation of the read_data module.
 *
 * See read_data.h for a description of the read_data function's
 * specification.
 *
 * Note that the parameter declarations in this module must be
 * compatible with those in the read_data.h header file.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "read_data.h"

#define MAX_LINE (25+1)

int read_data( char *c, int *i, double *d ) {

    //'line' for fgets(), 'field' for strtok
    char line[MAX_LINE];
    
    //get line from stdin using fgets(), return 'false' if EOF reached
    if( fgets(line,MAX_LINE,stdin) == NULL){ return 0; }
    
    //store c
    if(line[0]==EOF){return 0;}
    //else{*c = line[0];}
    
    //use strtok with '$' 
    char * field = NULL;
    field = strtok(line,"$");
    int nField = 0;
    while(field != NULL){
        if(nField == 0){      *c = field[0]; }
        else if(nField == 1){ *i = atoi(field); }
        else if(nField == 2){ *d = (double) atof(field); }
        else{ break; }
        field = strtok(NULL, "$");
        nField++;
    }
    
    return 1;
}
