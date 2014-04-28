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


//-----<variables>------//

/*
* Health records for all patients defined here.
* The variable record is visible to all functions
* in this file, i.e. it is global.
*/
Chart record[MAXPATIENTS];	

/*
 *number of charts in record
 *
*/
int numCharts = 0;

//break line for printout
char brk[] = "--------------------------------------------------\n";

//----<main function>---//

void main(){

  //--INITIALIZATIONS--//
    
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
        record[i].id = i+1;
        
        //set each record's buffer.start and buffer.end to 0.
        for( j=0; j < MAXTYPES; j++ ){
            record[i].buffer[j].start = 0;
	        record[i].buffer[j].end = 0;
        }
    }

    //TEMPORARY - prints records and IDs to 
    /*
    printf("-printing record ids-\n");

    for(i=0;i<MAXPATIENTS;i++){
        printf("chart with id: %d\n",record[i].id);
    }
    */
    

  //--RUNNING--//

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

    //if(type==6){
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
      //}
       
    //else{
      //---STORE---//

        //find/create appropriate chart
        Chart chart;

        if(id-1>MAXPATIENTS || id < 0){ 
            printf("please enter valid id (1-%d)",MAXPATIENTS+1);
            break;
        }else{
            chart = record[id-1];
        }

        //get appropriate CircularBuffer
        CircularBuffer cBuff;

        if(type-1>MAXTYPES || type<0){
            printf("please enter valid type (1-%d)",MAXTYPES+1);
            break;
        }else{
            cBuff = chart.buffer[type-1];
        }

        //change cBuff's start/end, and reading.
        
        //update |cBuff.start| (if start==0 or if time < start)
        if(cBuff.start == 0 || compareTimes(time,cBuff.start)<0){
            cBuff.start = time;
            //strcpy(cBuff.start,time);
        }

        //update |cBuff.start| end (if end==0 or time > end)
        if(cBuff.end == 0 || compareTimes(time,cBuff.end)>0){
            cBuff.end = time;
            //strcpy(cBuff.end,time);
        }
        
        //update |cBuff.reading[]| with new element
        Element element;
        strcpy(element.timestamp,time);
        //element.timestamp = time;
        element.value = value;

        cBuff.reading[0] = element;

        //TEST STORAGE//
        printf("|CHART| id: %d, record[id-1].id: %d\n",id,chart.id);
        printf("|CBUFF| start: %d, end: %d\n",cBuff.start,cBuff.end);
        printf("|ELEMENT| time: %s, value: %d\n",
                element.timestamp, element.value);
    //}
    }

//signify end of input reached
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
            strcpy(time, field);
        }else if(i==2){ *type = (int) atoi(field); 
        }else if(i==3){ *val  = (int) atoi(field);
        }else{ break; }

        //update field and counter
        field = strtok(NULL,", ");  
        i++;
    }

    //return true after successful run
    return 1;

}

/*print all information in a chart, taking in its id*/
void printPatient(int id){
    printf("printPatient(%d) called\n",id);
}

/*
* converts timestamps into integers, compares, returns + if t1>t2
*   and - if t1<t2. return 0 if timestamp is an incorrent length
* 
*  |note: atoi() stops converting to an integer at first non-digit|
*/
int compareTimes(char t1[], char t2[]){

    //check the length of each character array. 
    //  [strlen("##:##:##") = 8]
    if(strlen(t1) != 8 || strlen(t2) != 8){
        printf("timestamp is of incorrect length\n");
        return 0;
    }
    
    else{
        if(convertTime(t1) >= convertTime(t2)) { return 1; }
        else { return -1; }
    }
}

/* convert a char[] "##:##:##" to an int ######
*   |note: atoi() stops converting to an integer at first non-digit|
*/
int convertTime(char time[]){
    
    int t = 0;
    t += atoi(time) * 10000; 
    t += atoi(time + 3) * 100; 
    t += atoi(time + 6); 

    //temporary printout to check that this works correctly
    //printf("timestamp: %s, converted: %d\n",time,t);

    return t;

}
