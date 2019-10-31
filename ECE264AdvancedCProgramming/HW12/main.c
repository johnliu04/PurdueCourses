/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw12.h"



/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// if argc < 4 then return EXIT_FAILURE
  if (argc < 4)
  {
    return EXIT_FAILURE;
  }
  int length = strtol(argv[1],NULL,10);
  int k = strtol(argv[2], NULL, 10);
  int elem = strtol(argv[3], NULL, 10);
	// argv[1] - length of linked list
	// argv[2] - value of k as mentioned in josephus algorithm
	// argv[3] - value of elemDivisible
	// create head node
  Node * head = NULL;
	// create Linked list with length as argv[1]
  LinkedListCreate(&head, length);
  if (head == NULL){
    return EXIT_FAILURE;
  }
	// run josephus
  Josephus(&head, k, elem);
	// free the head node
  free(head);
  
  return EXIT_SUCCESS;
}

#endif
