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

#define MAX_LINE (80)

void read_data( char *c, int *i, double *d ) {

    //'line' for fgets(), 'field' for strtok
    char line[MAX_LINE];
    char * field;

    //get line from stdin using fgets(), return 'false' if EOF reached
    if( fgets(line,MAX_LINE,stdin) == NULL){ return ; }
    
    //store c
    *c = line[0];
    
    char temp[MAX_LINE];
    int j = 1; int k = 0; int t = 1;
    while(line[j] != EOF && line[j] != '\n'){
        temp[k] = line[j];
        
        //end of field reached
        if(line[j] == '$'){

            //terminate temp string
            temp[k] = '\0';
            
            //write to appropraite field.
            if(t==1){       *i = atoi(temp);
            }else if(t==2){ *d = (double) atof(temp);
            }else{ break; }

            //reset k
            k = 0;

            //increment t
            t++;
        }

        j++;
                
            
    }

    return;
}
