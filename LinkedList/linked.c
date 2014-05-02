
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

typedef struct node {
  int data;
  struct node* next;
}node ;

node *head;		        // pointer to head of linked list
						// head is visible to all functions in this file

/************************************************************
 length - return length of a list
 ************************************************************/
int length() {
  int count;
  
  // YOUR CODE HERE
  
  return count;
}


/************************************************************
 push - add new node at beginning of list
 ************************************************************/
void push(int data) {

    node * newNode = (node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    head = newNode;
  
}

/************************************************************
 pop - delete node at beginning of non-empty list and return its data
 ************************************************************/
int pop() {
  int val;
  
// YOUR CODE HERE

  return(val);
}

/************************************************************
 appendNode - add new node at end of list
 ************************************************************/
void appendNode(int data) {
 
  // YOUR CODE HERE
  
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
  struct node* current;
 
  printf("List: < ");
  
  // YOUR CODE HERE
  
  printf(" >\n");
}

void main() {

	head = NULL;	// initialize empty list
	
	push( 2 );
	printf("Length of list = %d\n", length());
	printList();
	
	// add additional tests here....
	
}
