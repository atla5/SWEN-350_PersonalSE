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
 
  struct node * current = head;
  while(current->next!=NULL){ current = current->next; count++; }

  return count;
}


/************************************************************
 push - add new node at beginning of list
 ************************************************************/
void push(int data) {

    struct node * newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;

    head = newNode;
  
}

/************************************************************
 pop - delete node at beginning of non-empty list and return its data
 ************************************************************/
int pop() {
  int val = head->data;
  
  head = head->next;

  return(val);
}

/************************************************************
 appendNode - add new node at end of list
 ************************************************************/
void appendNode(int data) {
 
  struct node * curr = head;
  while(curr->next != NULL){ curr = curr->next; }
  
  struct node * newNode = (struct node *) malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;

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
  struct node* current = head;
 
  printf("List: < ");
  
  while(current->next != NULL){ 
    printf("%d, ",current->data);
    current = current->next;
  }
  printf("%d",current->data);
  
  printf(" >\n");
}

void main() {

	head = NULL;	// initialize empty list
	
	push( 2 );
	push( 3 );
    push( 4 );
    printf("Length of list = %d\n", length());
	printList();
	
	// add additional tests here....
	
}
