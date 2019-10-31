/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw15.h"

/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// input argv[1] contains the name of the input file.
	// Check for the right number of input arguments. 
	if (argc<2){
		return EXIT_FAILURE;
	}
	//Initialize a linked list Node and use the file name from input arguments to create a linked list
	Node * head = NULL;
	LinkedListCreate(&head, argv[1]);
	if (head == NULL){
		return EXIT_FAILURE;
	}
	//Remove all duplicates in the linked list created above.
	RemoveDuplicate(head);
	
	// release memory
	Node * help = NULL;
	while (head != NULL){
	  help = head->next;
	  free(head);
	  head = help;
	}
	
	return EXIT_SUCCESS;
}

#endif
