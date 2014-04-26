/*
* Health Monitoring System
*/

//imports
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//given defines
#define MAXPATIENTS 5
#define MAXREADINGS 10
#define MAXTYPES 5
#define MAXTIME 8

//own defines
#define MAX_LINE (25)   //'#, ##:##:##, #, #####'


//------<structs>------//

/* One health type reading: timestamp + actual value */
typedef struct{
	char timestamp[MAXTIME+1];
	int value;
}Element;

/* Circular buffer of health type readings */
typedef struct{
	int start;	/* index of oldest reading */
	int end;	/* index of most current reading */
	Element reading[MAXREADINGS];
}CircularBuffer;

/* Patient's health chart: ID + multiple health type readings */
typedef struct{
	int id;
	CircularBuffer buffer[MAXTYPES];
}Chart;


/*
* Health records for all patients defined here.
* The variable record is visible to all functions
* in this file, i.e. it is global.
*/
Chart record[MAXPATIENTS];	

//-----<variables>------//

//break line for printout
char brk[] = "--------------------------------------------------\n";

//----<main function>---//

void main(){

  //key for the type
  char *typeKey[7];  // and array of char *
    typeKey[0] = "<none>";
    typeKey[1] = "Temperature";
    typeKey[2] = "Heart Rate";
    typeKey[3] = "Systolic Pressure";
    typeKey[4] = "Diastolic Pressure";
    typeKey[5] = "Respiration Rate";
    typeKey[6] = "Print command entered";


    int i, j;

    /* initialize health data records for each patient */

    for( i=0; i < MAXPATIENTS; i++ ){
        
        //increment id for each index
        record[i].id++;
        
        //set each record's buffer.start and buffer.end to 0.
        for( j=0; j < MAXTYPES; j++ ){
            record[i].buffer[j].start = 0;
	        record[i].buffer[j].end = 0;
        }
    }

    //print Welcome line
    printf("Welcome to the Health Monitoring System\n\n");

    //declare variables in a valid csv line (assumed)
    //  input FORMAT: "ID, HH:MM:SS, TYPE, VALUE"
    //         TYPES: int,  char[] , int ,  int
    int id, type;
    float value;
    char time[8+1] = "00:00:00";

    //read_line until EOF [CTRL-D]
    while( read_line(&id, &time, &type, &value) ){

        //---PRINT---//
      
        //print "#{time}: #{type} for PatientID = #"
        printf("%s: %s for PatientID = %d",
                time, typeKey[type],id);

        //no 'is #{value}' for PRINT command
        if(type==6){ 
            printf("\n");
        }else{
            printf(" is %.1f\n",value); 
        }
      
    
        //---STORE---//
        //@ToDo
     
    }
//
/*
*  YOUR CODE GOES HERE:
*  (1) Read a csv line of health data from stdin 
*  (2) Parse csv line into appropriate fields
*  (3) Store health data in patient record or print if requested
*  (4) Continue (1)-(3) until EOF
*/

printf("\nEnd of Input\n");

}

//---<helper functions>---//

/*read a line of csv and write to remote variables*/ 
int read_line(int *id, char *time[], int *type, float *val){

    //'line' for fgets()
    char line[MAX_LINE];
    char * field;     

    //get line from stdin using fgets(), return 'false' if EOF reached
    if( fgets(line,MAX_LINE,stdin) == NULL){ return 0; }
    
    //tokenize line and write to appropriate fields
    int i = 0;
    field = strtok(line,", ");
    while(field != NULL){
        
        //write to appropriate field
        if(i==0){       *id   = (int) atoi(field);
        }else if(i==1){ 
            //printf("%s\n",field);
            char src[40];
            char dest[100];
  
            memset(dest, '\0', sizeof(dest));
            strcpy(src, "This is tutorialspoint.com");
            strcpy(dest, field);

            printf("Final copied string : %s\n", dest);
            *time = dest; 
          
           // printf("%s\n",f);

            int j; char f[9];
            //for( j=0; j<=strlen(field); j++){ f[j] = field[j]; }
            //*time = f;
            //printf("%s\n",f);
        }else if(i==2){ *type = (int) atoi(field); 
        }else if(i==3){ 
            if( atoi(field) >= 1000){ *val = atoi(field)/10.0; }
            else{ *val  = (float) atoi(field); }
        }else{ break; }

        //update field and counter
        field = strtok(NULL,", ");  
        i++;
    }

    //return true after successful run
    return 1;

}
