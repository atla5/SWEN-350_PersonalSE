#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "health.h"

/*
* health_util.c - Helper functions for the Health Monitoring System
*/
void addPatient( int patientID ){
 
    //allocate a new chart with set id
    Chart * newPatient = (Chart *) malloc(sizeof(Chart));
    newPatient->id = patientID;    

    //if list is empty, set to new head.
    if(patientList == NULL){ 
        newPatient->next = NULL;
        patientList = newPatient;
    //if list is not empty, add to front
    }else{ 
        newPatient->next = patientList;
        patientList = newPatient;
    }

}

/*
* addHealthType: add a new health type buffer for a given patient
*/
void addHealthType( int patientID, int newType ){

    //get relevant chart
    Chartptr chart = getChart(patientID);

    //do nothing if chart does not exist
    if(chart == NULL){ return; }

    //create and initialize buffer
    CBuffptr newBuffer = (CBuffptr) malloc(sizeof(CircularBuffer));
    newBuffer->type = newType;
    newBuffer->next = chart->buffer;
    
    int i;
    for(i=0; i<MAXREADINGS; i++){
        Element e; 
        e.value = 0; 
        strcpy(e.timestamp, "00:00:00");
        
        newBuffer->reading[i] = e;
    }

    //link buffer to chart
    chart->buffer = newBuffer;
  
}
  
/*
*  getChart: given a patientID, return a pointer to their Chart
*/
Chartptr getChart( int patientID ){

    //set foundChart to head of patientList
    Chartptr foundChart = patientList;

    //walk to correct chart or end of patientList (NULL)
    while(foundChart != NULL && foundChart->id != patientID){
        foundChart=foundChart->next;
    }
  
    //return correct chart or NULL (conditions of break)
    return foundChart;
}

/* 
*  getHealthType: given a patientID & healthType, return a pointer 
*  to the CircularBuffer for that type. If the health type does NOT exist 
*  for that patient, return NULL
*/
CBuffptr getHealthType( int patientID, int healthType ){
    
    //get appropriate chart
    Chartptr foundChart = getChart(patientID);
    if( foundChart == NULL){ return NULL; }

    //try to find CBuffer
    CBuffptr CBuffHead = foundChart->buffer;
    CBuffptr current = CBuffHead;

    while(current != NULL){
        
        //if types are equal, return current CBuffptr
        if( current->type==healthType){ return current; }

        current = current->next;

    }
  
    //correct CBuffptr not found (does not exist)
    return NULL;
}
 
/*
*  addHealthReading: given a pointer to CircularBuffer, add the passed
*  timestamp and health data type reading to the buffer
*/
void addHealthReading( CBuffptr buffer, char* timestamp, int reading ){

    //*note* buffer assumed correct as NULL tossing done in getHealthType above

    /*
    //check start and end
    if( cmpTimes(timestamp, buffer->start) < 0){ 
        strcpy(buffer->start, timestamp);
    } 

    if( cmpTimes(timestamp, buffer->end) > 0){
        strcpy(buffer->end, timestamp);
    }
    */

    //create new reading and edit buffer's
    Element * newReading = (Element *) malloc(sizeof(Element));
    strcpy(newReading->timestamp, timestamp);
    newReading->value = (float) reading;

    int i = 0;
    while( strcmp(buffer->reading[i].timestamp, "00:00:00") != 0 ){ i++; }

    buffer->reading[i] = *newReading;   

}
  
/*
*  removePatient: check-out an existing patient
*	  (1) delete the patient's Chart & accompanying 
*         health data readings.
*     (2) update the list of current patients
*/
void removePatient( int patientID ){

    Chartptr chart = getChart(patientID);
    free(chart);

}

// --- OPTIONAL FUNCTIONS --- // 

/*read a line of csv and write to remote variables*/
int read_line(int *id, char *time[], int *type, int *val){

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

void printAll(){

    Chartptr current = patientList;
    while(current != NULL){
        printf(">Patient with ID = %d\n",current->id);
        current = current->next;
    }

}

void printPatient(int id){

    //print header
    printf("Readings for Patient ID = %d are:\n", id);

    //make printing headers easier
    char *typeKey[7]; 
      typeKey[0] = "<none>";
      typeKey[1] = "Temperature";
      typeKey[2] = "Heart Rate";
      typeKey[3] = "Systolic Pressure";
      typeKey[4] = "Diastolic Pressure";
      typeKey[5] = "Respiration Rate";

    //print each type
    int i, j;
    for(i=1;i<=5;i++){
        
        //print header for reading
        printf("%s:\n",typeKey[i]);
        
        //get and print readings
        CBuffptr cBuff = getHealthType(id, i);
        
        if(cBuff == NULL){
            printf("%s\n",typeKey[0]);
        }else{
            
            j=0;
            while( strcmp(cBuff->reading[j].timestamp, "00:00:00") != 0 ){
            
                Element e = cBuff->reading[j];
                printf("%s: ", e.timestamp);

                //account for temperature
                if(i==1){ 
                    printf("%.1f\n",e.value/10.0);
                }else{
                    printf("%d\n",e.value);
                }
                
                j++;
            }
        }
    }
}

void resetPatient(int id){

    free( getChart(id) );
    addPatient(id);

}

/* ---------- MISC HELPERS ----------------- */

/*
* converts timestamps into integers, compares, returns + if t1>t2
*   and - if t1<t2. return 0 if timestamp is an incorrent length
*
*  |note: atoi() stops converting to an integer at first non-digit|
*/
int cmpTimes(char t1[], char t2[]){

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

    return t;

}
