#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "health.h"

/*
* Main function for the Health Monitoring System. Primarily responsible for
* processing input of csv lines and printing as required. Data structures are
* maintained using the helper functions in health_util.c
* 
*/

Chartptr patientList = NULL;    /* Define global variable patientList (declared in health.h) */
								/* patientList is globaaly accessible in health_util.c    */

void main(){

printf("Welcome to the Health Monitoring System\n\n");

/*
*  YOUR CODE GOES HERE:
*  (1) Read an input csv line from stdin 
*  (2) Parse csv line into appropriate fields
*  (3) Take action based on input type:
*  		 - Check-in or check-out a patient with a given ID
*        - Add a new health data type for a given patient
*        - Store health data in patient record or print if requested
*  (4) Continue (1)-(3) until EOF
*/

//declare variables in a valid csvLine
//  input FORMAT: "ID, HH:MM:SS, TYPE, VALUE"
//        TYPES: int,  char[] , int , float
int id, type;
float value;
char time[8+1] = "00:00:00\0";

//read_line until EOF [CTRL-D]
while( read_line(&id, &time, &type, &value) ){

    switch(type){
      
      //ADD READING (e.g. Temp)
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:

            //get appropriate cBuffer
            CBuff * buffer;

            //add reading
            addHealthReading(buffer, time, value);
            break;
        
      //PRINT COMMAND
        case 6:
            printPatient(id);
            break;

      //CHECK-IN Patient
        case 7:
            addPatient(id);
            break;

      //CHECK-OUT Patient
        case 8:
            removePatient(id);
            break;
        
      //ADD HEALTH DATA TYPE
        case 9:
            addHealthType(id, value);
            break;

      //RESET Patient
        case 0:
            resetPatient(id);

    }
        
  }


  printf("\nEnd of Input\n");

}
