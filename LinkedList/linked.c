/* linked - linked list functions
   Mark Ardis, RIT, 10/30/2006
   T. Reichlmayr, RIT, 12/13/2010
   Aidan Sawyer, RIT, 05/02/2014
*/

#include <stdio.h>
#include <stdlib.h>

static int length();
static void push( int data);
static int pop();
static void appendNode( int data);
static struct node *copyList();
static void printList();

struct node {
  int data;
  struct node* next;
};

struct node *head;		// pointer to head of linked list
	        			// head is visible to all functions in this file

/************************************************************
 length - return length of a list
 ************************************************************/
int length() {
  int count = 0;

  //create pointing node, iterate through list incrementing count 
  struct node * current = head;
  while(current->next!=NULL){ current = current->next; count++; }

  //return count+1 to account for ending at the second to last node
  return count+1;
}


/************************************************************
 push - add new node at beginning of list
 ************************************************************/
void push(int data) {

    //create new node with next of current head
    struct node * newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;

    //set new node to the new head
    head = newNode;
  
}

/************************************************************
 pop - delete node at beginning of non-empty list and return its data
 ************************************************************/
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

/************************************************************
 appendNode - add new node at end of list
 ************************************************************/
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

/************************************************************
 copyList - return new copy of list
 ************************************************************/
struct node* copyList() {
 
 // YOUR CODE HERE

  return NULL;
}


/************************************************************
 printList - print linked list as "List: < 2, 5, 6 >" (example)
 ************************************************************/
void printList() {

    //create pointer to current head
    struct node* current = head;

    //begin printout 
    printf("List: < ");
    
    //traverse entire list, printing each value
    while(current->next != NULL){ 
      printf("%d, ",current->data);
      current = current->next;
    }
    printf("%d",current->data);
  
    //end printout
    printf(" >\n");
}

void main() {

	head = NULL;	// initialize empty list
	
    push( 1 );
	push( 2 );
    printf("Length of list = %d\n", length());
    printList();
    push( 3 );
    push( 4 );
    printf("Length of list = %d\n", length());
	printList();
	
	// add additional tests here....
	
}
