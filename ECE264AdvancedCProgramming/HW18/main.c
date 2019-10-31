// Edit this file as required
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw18.h"


#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
	// check for input error
	if (argc < 2){
		return EXIT_FAILURE;
	}
	// open the file
	// input file is in argv[1]
	FILE * ptr = fopen(argv[1], "r");
	if (ptr == NULL){
		fprintf(stderr, "fopen %s fail\n", argv[1]);
		return EXIT_FAILURE;
	}
	// n is the first element in the file
	int n;
	if (fscanf(ptr, "%d", &n) != 1){
		return EXIT_FAILURE;
	}

	// dim is the second element in the file
	int dim;
	if (fscanf(ptr, "%d", &dim) != 1){
		return EXIT_FAILURE;
	}
	// the rest of the data in the file are the datapoints.

	// call LinkedListCreate
	ListNode * head = NULL;
	LinkedListCreate(&head, n, dim, ptr);
	fclose(ptr);

	// call FindMin
	FindMin(head);
	
	// free memory
	ListNode * help = head;
	while (help != NULL){
		TreeNode * tree = help->treenode;
		free(tree->data); 
		ListNode * node = help->next;
		free(tree);
		free(help);
		help = node;
	}
}
#endif
