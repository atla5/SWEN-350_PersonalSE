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
#define MAXLINE (25)   //'#, ##:##:##, #, #####'


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
char brk[] = "--------------------------------------------------";

//----<main function>---//

void main(){

  //--INITIALIZATIONS--//
    
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

      if(type==6){  //---PRINT---//

        printPatient(id);

      }
       
      else{  //---STORE---//

        //find/create appropriate chart
        Chart * chart;

        if(id-1>MAXPATIENTS || id < 0){ 
            printf("#ERROR#: invalid id (must be 1-%d)",MAXPATIENTS+1);
            break;
        }else{
            chart = &record[id-1];
        }

        //get appropriate CircularBuffer
        CircularBuffer * cBuff;

        if(type-1>MAXTYPES || type<0){
            printf("#ERROR#: invalid type (must be 1-%d)",MAXTYPES+1);
            break;
        }else{
            cBuff = &(chart->buffer[type-1]);
        }

        //change cBuff's start/end, and reading.
        
        /*
        //update |cBuff.start| (if start==0 or if time < start)
        if(cBuff->start == 0 || compareTimes(time,cBuff->start)<0){
            cBuff->start = time;
            //strcpy(cBuff.start,time);
        }

        //update |cBuff.start| end (if end==0 or time > end)
        if(cBuff->end == 0 || compareTimes(time,cBuff->end)>0){
            cBuff->end = time;
            //strcpy(cBuff.end,time);
        }
        */
        
        //update |cBuff.reading[]| with new element
        Element element;
        strcpy(element.timestamp,time);
        element.value = value;

        //add element to reading 
        addToReading(cBuff->reading, element);

      }
    }

//signify end of input reached
printf("\nEnd of Input\n");

}

//---<helper functions>---//

/*read a line of csv and write to remote variables*/ 
int read_line(int *id, char *time[], int *type, float *val){

    //'line' and 'field' for fgets() and strtok()
    char line[MAXLINE];
    char * field;     

    //get line from stdin using fgets(), return 'false' if EOF reached
    if( fgets(line,MAXLINE,stdin) == NULL){ return 0; }
    
    //tokenize line and write to appropriate fields
    int i = 0;
    field = strtok(line,", ");
    while(field != NULL){
        
        //write to appropriate field
        if(i==0){       *id   = (int) atoi(field);
        }else if(i==1){       strcpy(time, field);
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
    printf("%s\n",brk);
    printf("Readings for Patient ID = %d are:\n",id);

    //key for the type
    char *typeKey[7];  // and array of char *
    typeKey[0] = "<none>";
    typeKey[1] = "Temperature";
    typeKey[2] = "Heart Rate";
    typeKey[3] = "Systolic Pressure";
    typeKey[4] = "Diastolic Pressure";
    typeKey[5] = "Respiration Rate";
    typeKey[6] = "Print command entered";


    //create chart pointer to appropriate chart
    Chart * chart = &(record[id-1]);

    //indexes for type and element respectively
    int i, j = 0;
    
    //for every type 
    for(i=0;i<=MAXTYPES-1;i++){
        
        //print type header
        printf("%s:\n",typeKey[i+1]);

        //print all readings per type
        while(chart->buffer[i].reading[j].value != 0 
                    && j<MAXREADINGS){
            Element e = chart->buffer[i].reading[j];
            printElement(e,i);
            j++;
        }

        //if there were no readings for this type, print "<none>"
        if(j==0){ printf("<none>\n"); }
    
        //reset element index
        j = 0;
            
    }

    //print break line
    printf("%s\n",brk);
}

/*print an Element*/
void printElement(Element e, int type){
    
    //print out 
    if(type+1==1 && e.value >= 200){
        double val = (double) e.value/10.0;
        printf("%s: %.1f\n", e.timestamp, val);
    }else{
        printf("%s: %d\n", e.timestamp, e.value);
    }
}

/*
* adds an element to a full list by making a new list, adding 
*   the l1[1..] 
*/ 
void addToReading(Element reading[], Element e){

    //scroll to last reading in list 
    int i = 0;
    while(reading[i].value != 0 && i<=MAXREADINGS){ i++; }

    //if you're not at the end of the list, just append
    if(i <= MAXREADINGS){ reading[i] = e; }

    //if you are at the maximum index, shift all valuse back one, 
    //  then append
    else{

        //indexes for reading and writing respectively
        i=0;
        int j=1;

        //shift reading's elements back one slot
        while(j<MAXREADINGS){
            reading[i] = reading[j];
            i++; j++;
        }
    
        //add new element to the now-empty end slot
        reading[i] = e;
    }
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
        //return comparison
        if(convertTime(t1) >= convertTime(t2)) { return 1; }
        else { return -1; }
    }
}

/* convert a char[] "##:##:##" to an int ######
*   |note: atoi() stops converting to an integer at first non-digit|
*/
int convertTime(char time[]){
    
    //multiply by factors of ten to maintain hierarchy of hour/min
    int t = atoi(time) * 10000; 
    t += atoi(time + 3) * 100; 
    t += atoi(time + 6); 

    //temporary printout to check that this works correctly
    //printf("timestamp: %s, converted: %d\n",time,t);

    return t;

}
