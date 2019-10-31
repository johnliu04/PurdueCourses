#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

void FreeBinaryTree(treeNode *root);
//***** YOU NEED TO MODIFY main() FUNCTION BELOW *******//
#ifdef TEST_MAIN
int main(int argc, char **argv)
{

	/*
	 *  1. Check for number of arguments. If less than 2, do not proceed further.
	 *  
	 *  2. The program should create a binary search tree from the numbers in input file. The input file 
	 *  	also contains a number for search query at the end. 
	 *
	 *  3. The input file has one number per line. If there are 'n' lines in the file, the first n-1 numbers 
	 *  	are the elements of the binary search tree and the nth line is the search query. 
	 *  	NOTE: n is not given to you. 
	 *
	 *  4. Create an array of the first n-1 numbers and store the last number in a variable.
	 *
	 *  5. Create a Binary Search Tree. It takes four arguments:
	 *  	1. The array
	 *  	2. the first element of the array
	 *  	3. start index (index of first element of the array)
	 *  	4. end index ( index of last element of the array)
	 *
	 *  6. Print the created tree in Inorder fashion. Quick check if you have created the tree right: the output of
	 *  	will be a sorted array of numbers. 
	 *
	 *  7. Compute the distance of the 'search query' node by passing it to the function.
	 *
	 *  8. Use PrintDistance() function to print the distance of the node from the root node in the right format.
	 *
	 *  9. Free all memory.
	 *
	 */
	
	if (argc < 2){
	  return EXIT_FAILURE;
	}
	
	// open file to read
	FILE * fptr = fopen(argv[1], "r");
	// check for fopen fail. If so, return EXIT_FAILURE
	if (fptr == NULL){
	  return EXIT_FAILURE;}
	  
	int length = -1;
	int last;
	// allocate memory to store the numbers
	while (fscanf(fptr, "%d", &last) == 1){
	    length ++;}
	int *arr = malloc(sizeof(int) * length);
	// check for malloc fail, if so, return EXIT_FAILURE
	if (arr == NULL){
	  fprintf(stderr, "malloc fail\n");
	  fclose(fptr);
	  return EXIT_FAILURE;
	}
	
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
	
	//Create a Binary Search Tree
	treeNode * tree = CreateBST(arr, 0 ,1, length - 1);
	BinaryTreeInOrderPrint(tree);
	//Compute the distance of the 'search query'
	PrintDistance(FindDistance(tree, last, 0));
	
	free(arr);
	FreeBinaryTree(tree);
}
#endif
