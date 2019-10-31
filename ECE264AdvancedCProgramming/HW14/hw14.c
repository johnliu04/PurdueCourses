/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw14.h"


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
//source: the head of the singly linkedlist.
//len: the length of the array.
//arr: the array with the contents of the input file.

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
// source is the head of the list to be split.
// head1 is the head of the upper sub-list.
// head2 is the head of the lower sub-list.

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
	temp -> next = NULL;

    	// Tip: head1 will point to the source node.
	// Tip: head2 will point to the mid-point of the list.
	// Tip: Ensure you break the link between the sub-lists.
} 
#endif

#ifdef TEST_MERGE
// upper is the upper sub-list to be merged
// lower is the lower sub-list to be merged
Node* Merge(Node* upper, Node* lower) 
{ 
	// Check for the base cases. (When either sub-list is NULL)
	Node * merge = NULL;
	if (upper == NULL){
	  return lower; //take remaining lowersub
	}
	else if (lower == NULL){
	  return upper; //take remaining uppersub
	}
	
	// Pick the larger between upper and lower, and recur appropriately.
	  if (upper->value > lower->value){
	    merge = lower; // keep the smaller one
	    merge->next = Merge(upper, lower->next);
	  }
	  else {
	    merge = upper;
	    merge->next = Merge(upper->next, lower);
	  }
	    
	// return the merged array
	return merge;
} 
#endif

#ifdef TEST_SORT
// source is the head of the list to for which MergeSort is to be performed.
void MergeSort(Node** source) 
{ 
	// Declare a node, to hold the current head of the source list.
	Node * temp = *source;
	// Declare nodes, to hold the two the heads of the two sub-lists.
	Node * uppersub = NULL;
	Node * lowersub = NULL;
	
	// Check for the base case -- length 0 or 1
	//another way to write following code:
	// if (temp == NULL || temp->next == NULL){return;}
	
	Node * count = temp;
	int number = 0;
	while(count != NULL){
	  count = count -> next;
	  number ++;
	}
	// if so, return;
	if (number == 0 || number == 1){
	  return;
	} 
	  
	// Use SpiltList() to partition the list into sub lists.
		// This will partiton the source list, into two lists (As done in the previous homework)
	  SplitList(temp, &uppersub, &lowersub);
	// Recursively sort the sub-lists by calling MergeSort() on the upper and lower sub-lists.
		// MergeSort() is a recursive function, and MergeSort() needs to be called
		// on both sub-lists (obtained after partitioning)
	 MergeSort(&uppersub);
	 MergeSort(&lowersub);
	 
	// Merge the two sorted lists together, using the Merge()
	*source = Merge(uppersub, lowersub);
} 
#endif

