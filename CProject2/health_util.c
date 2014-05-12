#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "health.h"

/*
* health_util.c - Helper functions for the Health Monitoring System
*
* Add any optional helper function declarations here, define 
* the functions after the required functions below.
*
* static void myOptionalFunc();   // EXAMPLE 
*
*/

/*
* addPatient: check-in a new patient
*   (1) allocate a new Chart for the patient
*   (2) initialize the chart with the passed patientID
*   (3) new patients are inserted at the start of the patient list
*
* (note that the variable patientList is globally accessible)
*/
void addPatient( int patientID ){
  
  /* YOUR CODE HERE */
}

/*
* addHealthType: add a new health type buffer for a given patient
*	(1) allocate a new CircularBuffer
*	(2) initialize the buffer
* 	(3) link it to the existing patient's Chart
*/
void addHealthType( int patientID, int newType ){
  
  /* YOUR CODE HERE */ 
}
  
/*
*  getChart: given a patientID, return a pointer to their Chart
*/
Chartptr getChart( int patientID ){
  Chartptr foundChart = NULL;
  
  /* YOUR CODE HERE */
  
  return foundChart;
}

/* 
*  getHealthType: given a patientID & healthType, return a pointer 
*  to the CircularBuffer for that type. If the health type does NOT exist 
*  for that patient, return NULL
*/
CBuffptr getHealthType( int patientID, int healthType ){
  CBuffptr foundType = NULL;
  
  /* YOUR CODE HERE */
  
  return foundType;
}
 
/*
*  addHealthReading: given a pointer to CircularBuffer, add the passed
*  timestamp and health data type reading to the buffer
*/
void addHealthReading( CBuffptr buffer, char* timestamp, int reading ){

  /* YOUR CODE HERE */
}
  
/*
*  removePatient: check-out an existing patient
*	  (1) delete the patient's Chart & accompanying 
*         health data readings.
*     (2) update the list of current patients
*/
void removePatient( int patientID ){

  /* YOUR CODE HERE */
}
 
/*
* Optional helper functions defined starting here:
*
* static void myOptionalFunc(){ }  // EXAMPLE
*  
*/

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

void printPatient(int id){

}

void resetPatient(int id){

}
