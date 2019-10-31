/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw13.h"

#ifdef LINKEDLIST
// Do not modify this function, we are using this within ifdef block for
// ease of grading.
void LinkedListPrint(Node * * source)
{

	Node *temp = * source;

	while(temp!=NULL)
	{
		if(temp->next!=NULL)
		{
			printf("%d,",temp->value);
		}
		else
		{
			printf("%d",temp->value);
		}
		temp=temp->next;
	}
	printf("\n");
}
#endif


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
//val: value of the element of the node to be created
{
	// Define a new variable of type Node
	Node * newNode = malloc(sizeof(Node));
	// Initialize "next", and "value" appropriately
	newNode -> value = val;
	newNode -> next = NULL;
	
	//return the newNode
	return newNode;
}
#endif

#ifdef TEST_LINKEDLISTCREATE
//head: the head of the singly linkedlist.
//len: the length of the array.
//arr: the array with the contents of the input file.

//This function will create and initialize the singly linkedlist with length=len,

void LinkedListCreate(Node * * source, int len, int* arr)
{
	// This function is similar to the one in HW12.
	// check if length is not negative
	if (len < 0){
	    *source = NULL;
	    return;
	}
	// create linked list of length as 'len'
	for (int index = len - 1; index >= 0; index --){
	  Node * ptr = CreateNode(arr[index]);
	  ptr -> next = *source;
	  *source = ptr;
	}
	// Tip: use CreateNode(arr[index])
}
#endif


#ifdef TEST_SPLIT
// source is the Node corresponding to the head of the list
// head1 is the list corresponding upper half of the list. (After Partition)
// head2 is the list corresponding lower half of the list. (After Partition)
void SplitList(Node* source, Node** head1, Node** head2) 
{ 
	// Find the mid point of the list.
	Node * count = source;
	int number = 0;
	while (count != NULL){
	  count = count -> next;
	  number ++;
	}
	Node * temp = source;
	*head1 = temp;
	//in case of an odd number of nodes, mid point will be <num_elements>/2
			//Example: 1,2,3,4,5
				// The list should split into 1,2,3 and 4,5	
	if (number % 2){
	  number = number / 2;
	}
	//in case of an even number of nodes, mid point will be floor(<num_elements>/2)
		//Example: 1,2,3,4
			// The list should split into 1,2 and 3,4
	else {
	  number = number / 2 - 1;
	}
	for (int index = 0; index < number; index ++){
	    temp = temp -> next;
	  }
	*head2 = temp -> next;
	temp -> next = NULL; //??

    	// Tip: head1 will point to the source node.
	// Tip: head2 will point to the mid-point of the list.
	// Tip: Ensure you break the link between the sub-lists.
} 
#endif


#ifdef TEST_DIV
void Divide(Node** source) 
{ 
	// Declare a node, to hold the current head of source list.
	Node * temp = *source;
	// Declare nodes, to hold the two the heads of the two sub-lists.
	Node * uppersub = NULL;
	Node * lowersub = NULL;
	
	// Check for the base case -- length 0 or 1
	Node * count = temp;
	int number = 0;
	while(count != NULL){
	  count = count -> next;
	  number ++;
	}
	// if so, return;
	if (number == 0 || number == 1){
	  free(temp);
	  return;
	}
	
	// Use SpiltList(...) to partition the list into sub lists.
	SplitList(temp, &uppersub, &lowersub);
	// Use LinkedListPrint(...); to print the upper sub-list.
	LinkedListPrint(&uppersub);
	// Use LinkedListPrint(...); to print the lower sub-list
	LinkedListPrint(&lowersub);
		// DO NOT USE YOUR OWN PRINT FUNCTION.
	
	 // Recursively Divide(...) both sub-lists, to find their respective mid-points
	 Divide(&uppersub);
	 Divide(&lowersub);
	 // till only one or no elements are left in the sub-lists.
} 
#endif

