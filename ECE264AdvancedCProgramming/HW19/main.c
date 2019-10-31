// Please modify this file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw19.h"

void FreeBinaryTree(TreeNode *root);
#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
	// check for input error
	if (argc < 2){
		return EXIT_FAILURE;
	}
	// open the file
	FILE * ptr = fopen(argv[1], "r");
	if (ptr == NULL){
		return EXIT_FAILURE;
	}
	//  n is the first element in the file
	int n;
	if (fscanf(ptr, "%d", &n)!=1){
		return EXIT_FAILURE;
	}
	// dim is the second element in the file
	int dim;
	if (fscanf(ptr, "%d", &dim)!=1){
		return EXIT_FAILURE;
	}
	
	// Create linkedList
	ListNode * head = NULL;
	LinkedListCreate(&head, n, dim, ptr);
	fclose(ptr);

	// call MakeCluster
	MakeCluster(&head);

	//free head
	ListNode * delete = head;
	ListNode * help = delete ->next;
	while (delete!=NULL){
		FreeBinaryTree(delete->treenode);
		free(delete);
		delete = help;
		if (delete!=NULL){
			help = help->next;
		}
	}
	

	return EXIT_SUCCESS;
}

void FreeBinaryTree(TreeNode *root)
{
    if (root == NULL){
      return;
    }
    FreeBinaryTree(root->left);
    FreeBinaryTree(root->right);
    free(root->data);
	free(root);
}
#endif
