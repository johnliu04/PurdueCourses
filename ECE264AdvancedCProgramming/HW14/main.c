/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw14.h"


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

/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// if argc is less than 2 then, return EXIT_FAILURE
	// input file is specified through the Makefile.
        if (argc < 2){
	  return EXIT_FAILURE;}
	  
	// open file to read
	FILE * fptr = fopen(argv[1], "r");
	// check for fopen fail. If so, return EXIT_FAILURE
	if (fptr == NULL){
	  return EXIT_FAILURE;}
	  
	// count the number of integers in thLinkedListPrint(Node * * source)e file.
	int length = 0;
	int num;
	// allocate memory to store the numbers
	while (fscanf(fptr, "%d", &num) == 1){
	    length ++;}
	int *arr = malloc(sizeof(int) * length);
	// check for malloc fail, if so, return EXIT_FAILURE
	if (arr == NULL){
	  fprintf(stderr, "malloc fail\n");
	  fclose(fptr);
	  return EXIT_FAILURE;
	}
	
	// use fscanf to read the file for its contents.
	fseek (fptr, 0, SEEK_SET);
	for (int ind = 0; ind < length; ind++){
	  if (fscanf(fptr, "%d", & arr[ind]) != 1){
	    fprintf(stderr, "fscanf fail\n");
	    fclose (fptr);
	    free (arr);
	    return EXIT_FAILURE;
	  }
	}
	fclose(fptr);

	// create head node, which corresponds to the head of the linked-list.
	Node * head = NULL;
	// You must now use the appropriate function to construct the remaining list.
	LinkedListCreate(&head, length, arr);
	if (head == NULL){
	  return EXIT_FAILURE;
	}
	
	// call MergerSort() function for final output.
		// This will call a recursive function.
		// The input list will be divided into two sub-lists recursively,
		// Then the contents of the sub-lists are compared and merged back to form the
		// sorted output list.
	MergeSort(&head);
	
	// use the provided function to print the final list.
	LinkedListPrint(&head);
	
	// Tip: Check for memory errors.
	free(arr);
	Node * help = NULL;
	while (head != NULL){
	  help = head->next;
	  free(head);
	  head = help;
	}
	
	return EXIT_SUCCESS;
}

#endif
