#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "health.h"

/*
* health_util.c - Helper functions for the Health Monitoring System
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
 
    //allocate a new chart with set id
    Chart * newPatient = (Chart *) malloc(sizeof(Chart));
    newPatient->id = patientID;    

    //add to global 'patientList'

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

// --- OPTIONAL FUNCTIONS --- // 

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
