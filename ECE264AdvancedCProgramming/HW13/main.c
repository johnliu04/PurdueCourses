/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw13.h"

/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// if argc is less than 2 then, return EXIT_FAILURE
	// input file is specified through the Makefile.
	 if (argc < 2){
	    return EXIT_FAILURE;
	 }
	// open file to read
	  FILE * fptr = fopen(argv[1], "r"); 
	  // check for fopen fail. If so, return EXIT_FAILURE
	  if (fptr == NULL)
	  {
	    fprintf(stderr, "fopen fail\n");
	    // do not fclose (fptr) because fptr failed
	    return EXIT_FAILURE;
	  }
	
	  int length = 0;
	  int num;
	// count the number of integers in the file.
	   while (fscanf(fptr, "%d", &num) == 1){
	    length++;
	   }
	// allocate memory to store the numbers
	   int * arr = malloc(sizeof(int) * length);
	// check for malloc fail, if so, return EXIT_FAILURE
	    if (arr == NULL){
	      fprintf(stderr, "malloc fail\n");
	      fclose (fptr);
	      return EXIT_FAILURE;
	    }
	// use fscanf to read the file, and store its contents into an array.
	     fseek (fptr, 0, SEEK_SET);
	     for (int ind = 0; ind < length; ind ++){
		if (fscanf(fptr, "%d", & arr[ind]) != 1){
		    fprintf(stderr, "fscanf fail\n");
		    fclose (fptr);
		    free (arr);
		    return EXIT_FAILURE;
		}
	      }
	      fclose(fptr);
	      
	// create head node to store the head of the linked list.
	    Node * head = NULL;
	// call the appropriate function to create the rest of the linked list, with the values of the array.
	    LinkedListCreate(&head, length, arr);
	    if (head == NULL){
		return EXIT_FAILURE;
	    }
	// Divide is a function to break the lists into smaller sublists.
		// You are supposed to find the mid-point of the list, and then break the list into two lists.
		// Then the sub-lists are broken down further into smaller sub-lists.
		// Refer to the example in the README
	Divide(&head); 

	// Tip: check for memory errors.
	//free(head); free NULL will cause error
	free(arr);
	
	return EXIT_SUCCESS;
}

#endif
