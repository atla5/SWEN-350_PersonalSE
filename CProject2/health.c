#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "health.h"

/*
* Main function for the Health Monitoring System. Primarily responsible for
* processing input of csv lines and printing as required. Data structures are
* maintained using the helper functions in health_util.c
*/

//Define global variable patientList (also available in health_util)
Chartptr patientList = NULL; 


void main(){

  printf("Welcome to the Health Monitoring System\n\n");

  //declare variables in a valid csvLine
  int id, type;
  float value;
  char time[8+1] = "00:00:00";

  //extras for streamlining printing
  char brk[] = "--------------------------------------------------";
  char *typeKey[7];  // and array of char *
    typeKey[0] = "<none>";
    typeKey[1] = "Temperature";
    typeKey[2] = "Heart Rate";
    typeKey[3] = "Systolic Pressure";
    typeKey[4] = "Diastolic Pressure";
    typeKey[5] = "Respiration Rate";
    typeKey[6] = "Print command entered";

  //read_line until EOF [CTRL-D]
  while( read_line(&id, &time, &type, &value) ){

    //temporary print statement
    printf("patient: %d, timestamp: %s, type: %d, value: %.1f\n",
            id, time, type, value);
   

    //perform various tasks based on the value of type
    switch(type){
      
      //ADD READING (e.g. Temp)
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:

            //get appropriate cBuffer
            CBuffptr buffer = getHealthType(id, type);
            if(buffer == NULL){ break; }


            //add reading
            addHealthReading(buffer, time, value);
            
            break;
        
      //PRINT COMMAND
        case 6:

            printf("%s\n", brk);
            printPatient(id);
            printf("%s\n", brk);

            break;

      //CHECK-IN Patient
        case 7:
            
            //call helper function
            addPatient(id);

            //print user
            printf("%s\n",brk);
            printf("%s: Patient ID = %d checking in\n", time, id);
            printf("%s\n",brk);

            //exit case
            break;

      //CHECK-OUT Patient
        case 8:
            removePatient(id);
            
            printf("%s\n",brk);
            printf("%s: Patient ID = %d checking out\n", time, id);
            printf("%s\n",brk);
        
            break;

      //ADD HEALTH DATA TYPE
        case 9:
            addHealthType(id, value);
            break;

      //RESET Patient
        case 0:

            resetPatient(id);
            
            printf("%s\n",brk);
            printf("%s: Patient ID = %d reset data\n", time, id);
            printf("%s\n",brk);

            break;

     //print error line if type is not recognized
        default:
            printf("type not recognized by switch()\n");
            break;
    }
        
  }

  printf("\nEnd of Input\n");

}
