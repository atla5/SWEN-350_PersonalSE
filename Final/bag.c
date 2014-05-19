#include "bag.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct node *first = NULL ;		/* initially the list is empty */


/* Create and return a new node with passed value, count 1, and next NULL */
struct node* make_node(char *value) {

    //mallocate space in the heap	
    struct node *np = (struct node*) malloc(sizeof(struct node));
    np->value = (char *) malloc(sizeof(char)*strlen(value));
    
    //set fields
    strcpy(np->value, value); 
    np->count = 1;
    np->next = NULL;
    
    //return node pointer
	return np;
}



/* insert_value
 * 
 * Traverse the linked list looking for a node matching the provided
 * string. We stop when (a) we find a matching string or (b) we hit the
 * end of the list. 
 *
 * Case (a) increments the node count and returns.
 * Case (b) insert a new node with count 1, via calling make_node
 *
 * Hint: strcmp(a,b) == 0 when strings a and b are equal
 */

void insert_value(char *value) {

    //create walker
    struct node* current = first;

    //walk through list until case (a) or (b)
    while( current !=NULL && current->next != NULL 
           && strcmp(current->value, value) != 0){
        current = current->next;
    }

    //case (a): increment current's count
    if(current != NULL && strcmp(current->value, value) == 0){
        current->count++;
    }

    //case (b): create and insert new node
    else{ 
        struct node* newNode = make_node(value);

        //if list is empty, make new head
        if(current==NULL){ first = newNode; }

        //if list is not empty, insert at end of list
        else{current->next = newNode; }
    }
}

/* total_count
 *
 * Traverse the linked list totaling the number of items.
 *
 * Case (a) returns the total count of all items in the bag
 * Case (b) return 0 if the list is empty
 */
unsigned int total_count() {
	int count = 0;

    //create walker
    struct node* current = first;
        
    //walk to end, adding each's count to sum
    while(current != NULL){ 
        count += current->count;
        current = current->next;
    }

    return count;
}

/* remove_value
 * 
 * Traverse the nexted list looking for a node matching the provided
 * string. We stop when (a) we find a matching string or (b) we hit the
 * end of the list 
 *
 * Case (a) decrements the node count (no lower than 0);
 * Case (b) simply returns.
 *
 * Note that when the count reaches 0 the node is NOT removed from the list.
 *
 */

void remove_value(char *value) {

    //create walker
    struct node* current = first;

    //walk until case (a) or (b)
    while(current != NULL && strcmp(current->value, value) != 0){
        current = current->next; 
    }
 
    //case (a): increment current's count
    if(current != NULL && strcmp(current->value, value) == 0 ){
        if((current->count)>0){ current->count--; }
    }
    
    //case(b): do nothing.
    else{ return; }

}


/* garbage_collect
 *
 * Remove and free all zero-count strings from the bag
 *
 * Traverse the list looking for a node that has a count of 0 or less. 
 * Re-assign pointers so that the linked list integrity remains intact. 
 * Free all unused memory.
 *
 * Hint: keep an extra pointer to the PREVIOUS item in the list
 */
void garbage_collect(){

    //create node pointers for previous and current
    struct node* current = first;
    struct node* previous = NULL;

    while(current != NULL){

        //remove from list
        if(current->count == 0){
    
            //if list is one entry, set head to NULL
            if(previous == NULL){ first = NULL; }

            //if the list is more than two entries, do linking
            else{ previous->next = current->next; }
        }

        //free from memory
        previous = current;
        if(previous != NULL && previous->count == 0){ 
            free(previous); 
        }

        //update previous and current for next iteration
        previous = current;
        current = current->next;   
    }

}

/* print_bag
 * 
 * Traverse the list and print it out. 
 * Delimited by tabs and newlines.
 *
 * You do not need to edit this function.
 *
 */
void print_bag(){
	struct node* walker = first;
	while(walker != NULL){
		printf("\t%s\t%i\n", walker->value, walker->count);
		walker = walker->next;
	}
}
