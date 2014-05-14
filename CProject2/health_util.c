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
*	(1) allocate a new CircularBuffer
*	(2) initialize the buffer
* 	(3) link it to the existing patient's Chart
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

    //check start and end
    /*
    if( cmpTimes(timestamp, buffer.start) < 0){ 
        strcpy(buffer.start, timestamp);
    } 

    if( cmpTimes(timestamp, buffer.end) > 0){
        strcpy(buffer.end, timestamp);
    }
    */

    //create new reading and edit buffer's
    Element * newReading = (Element *) malloc(sizeof(Element));
    strcpy(newReading->timestamp, timestamp);
    newReading->value = (float) reading;

    buffer->reading[0] = *newReading;   

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
    int i;
    for(i=1;i<=5;i++){
        
        //print header for reading
        printf("%s:\n",typeKey[i]);
        
        //get and print readings
        CBuffptr cBuff = getHealthType(id, i);
        
        if(cBuff == NULL){
            printf("%s\n",typeKey[0]);
        }else{
            Element e = cBuff->reading[0];
            printf("%s: ", e.timestamp);

            //account for temperature
            if(i==1){ 
                printf("%.1f\n",e.value/10.0);
            }else{
                printf("%d\n",e.value);
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

    return t;

}


/* ---------- LINKED LIST CODE ------------- */


/************************************************************
 length - return length of a list
 ************************************************************
int length() {
  int count = 0;

  //create pointing node, iterate through list incrementing count 
  struct node * current = head;
  while(current->next!=NULL){ current = current->next; count++; }

  //return count+1 to account for ending at the second to last node
  return count+1;
}
*/


/************************************************************
 push - add new node at beginning of list
 ************************************************************
void push(int data) {

    //create new node with next of current head
    struct node * newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;

    //set new node to the new head
    head = newNode;
  
}
*/

/************************************************************
 pop - delete node at beginning of non-empty list and return its data
 ************************************************************
int pop() {

    //store value and address
    struct node * oldHead = head;
    int val = oldHead->data;
    struct node * ptr = oldHead->next;
  
    //delete node and set head
    free(oldHead);
    head = ptr;

    //return data of old head
    return(val);
}
*/

/************************************************************
 appendNode - add new node at end of list
 ************************************************************
void appendNode(int data) {

    //create node pointer to traverse to end of list
    struct node * curr = head;
    while(curr->next != NULL){ curr = curr->next; }
  
    //create new node with passed in data and next of NULL
    struct node * newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    //link new node to the end of the LinkedList
    curr->next = newNode;
  
}
*/

/************************************************************
 appendNodeToLList - add a new node to the end of a passed in list
 ************************************************************
void appendNodeToList(struct node *newNode, struct node *list){
    
    struct node * current = list;

    if(current == NULL){ current = newNode; return; }
    while(current->next != NULL){ current = current->next; }

    newNode->next = NULL;
    current->next = newNode;

}
*/

/************************************************************
 printList - print linked list as "List: < 2, 5, 6 >" (example)
 ************************************************************
void printList() {
 
    //create pointer to current head
    struct node* current = head;

    //begin printout 
    printf("List: < ");
    
    if(current==NULL){ printf(" >\n"); return; }

    //traverse entire list, printing each value
    while(current->next != NULL){ 
      printf("%d, ",current->data);
      current = current->next;
    }
    printf("%d",current->data);
  
    //end printout
    printf(" >\n");
}
*/
