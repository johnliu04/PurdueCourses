// You can modify this file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw19.h"

// DO NOT MODIFY THIS FUNCTION
void PrintAns(ListNode* head, ListNode* min1, ListNode* min2)
{
	int i;
	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min1->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d) <-> ", min1->treenode->data[i]);
		else
			printf("%d, ", min1->treenode->data[i]);
		i+=1;
	}

	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min2->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d)\n", min2->treenode->data[i]);
		else
			printf("%d, ", min2->treenode->data[i]);
		i+=1;
	}
}

/*
MODIFY BELOW THIS COMMENT
*/


#ifdef TEST_CENT
ListNode* FindCentroid(TreeNode* x, TreeNode* y)
{
	// Create a new node
	ListNode * newnode = malloc(sizeof(ListNode));
	TreeNode * newtree = malloc(sizeof(TreeNode));
	if (newnode == NULL || newtree == NULL){
		return NULL; //malloc fail
	}
	int dim = x->dimension;
	newtree->dimension = dim;
	int i = 0;
	while (x->data[i]==y->data[i] && i<dim){
		++i;
	}
	// x -> treenode.data should be less than y -> treenode.data (refer to README)
	if (x->data[i]<y->data[i]){
		// new -> treenode.left should be x
		newtree->left = x;
		// new -> treenode.right should be y
		newtree->right = y;
	}
	else {
		newtree->left = y;
		newtree->right = x;
	}
	// Use a loop to average the data from the two parameters (x and y).
	/*
	EXAMPLE
	Average x->treenode.data[0] and y->treenode.data[0] to new->treenode.data[0]
	Average x->treenode.data[1] and y->treenode.data[1] to new->treenode.data[1]
	and so on
	*/
	newtree->data = malloc(sizeof(int)*dim);
	for (int j = 0; j < dim; ++j){
		newtree->data[j]= (x->data[j]+y->data[j])/2;
	}

	// Return the new node
	newnode->next = NULL;
	newnode->treenode = newtree;
	return newnode;
}
#endif


#ifdef TEST_DIST
int FindDist(TreeNode* x, TreeNode* y)
{
	//find the eucledian distance between
	// x->data and y->data
	// DO NOT FIND SQUARE ROOT (we are working with int)
	// return the distance
	int distance = 0;
	for (int i = 0; i < x->dimension; i++){
		distance += ((x->data[i])-(y->data[i]))*((x->data[i])-(y->data[i]));
	}
	return distance;
}
#endif


#ifdef TEST_FUSE
ListNode* Fuse(ListNode* head, ListNode* fuse1, ListNode* fuse2)
{

	// Create a new ListNode element using findCentroid function.
	// The new->treenode.data will hold the averaged values of the two parameters' data (fuse1, and fuse2)
	ListNode * newnode = FindCentroid(fuse1->treenode, fuse2->treenode);
	// add the new ListNode to the list.
	
	// remove the fuse1 and fuse2 from the list. (Do NOT free)
	// remove fuse1
	ListNode * help = head;
	ListNode * delete = help -> next;
	if (help == fuse1){
		head = delete;
	}
	else {
		while (delete != fuse1 && help != fuse1 && delete != NULL){
			help = help->next;
			delete = delete->next;
		}
		help->next = delete->next;
	}
	free(fuse1);
	
	// remove fuse2
	ListNode *help2 = head;
	ListNode *delete2 = help2->next;
	if (help2 == fuse2){
		head = delete2;
	}
	else {
		while (delete2 != fuse2 && help2 != fuse2 && delete2 != NULL){
			help2 = help2->next;
			delete2 = delete2->next;
		}
		help2->next = delete2->next;
	}
	free(fuse2);
	
	// you may want to return head from this function (depending on your implementation)
	newnode->next = head;
	return newnode;
}
#endif


#ifdef TEST_CREATENODE
ListNode* CreateNode(int n, int dim, int* arr)
{
	// check for malloc error
	ListNode * newnode = malloc(sizeof(ListNode));
	TreeNode * newtree = malloc(sizeof(TreeNode));
	if (newnode == NULL || newtree == NULL){
		return NULL; //malloc fail
	}

	newnode->next = NULL;
	// initialize dim
	newtree->dimension = dim;
	// both left and right childern will be NULL
	newtree->left = newtree->right = NULL;
	// allocate memory for data
	newtree->data = malloc(sizeof(int)*dim);
	for (int i = 0; i < dim; ++i){
		newtree->data[i]= arr[i];
	}
	newnode->treenode = newtree;
	// return a ListNode
	return newnode;
}
#endif


#ifdef TEST_LINKEDLISTCREATE
void LinkedListCreate(ListNode ** head, int n, int dim, FILE* fptr)
{
	// create temp node using CreateNode
	// read from file into an array, pass array to CreateNode
	// assign temp to that node
	ListNode* temp = NULL;
	int *arr = malloc(sizeof(int)*dim);
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < dim; ++j){
			if (fscanf(fptr, "%d", &arr[j]) != 1){
				return;
			}
		}
		if (i == 0){
			*head = CreateNode(n, dim, arr);
			temp = *head;
		}
		else{
			ListNode *help = CreateNode(n, dim, arr);
			temp->next = help;
			temp = temp->next;
		}
	}
	// use a loop to create nodes for the remaining elements of the list.
	free(arr);
}
#endif

#ifdef TEST_CLUSTER
void MakeCluster(ListNode** head)
{
	ListNode *countnode = *head;
	int num = 0;
	while (countnode){
		countnode = countnode->next;
		num++;
	}
	//int length = num;
	// Walk through the linked list.
	// find pair of nodes with minimum distance.
	while (num > 1){
		ListNode *temp = *head;
		ListNode *min1 = NULL;
		ListNode *min2 = NULL;
		int inidis = FindDist(temp->treenode, (temp->next)->treenode);
		while (temp != NULL){
			ListNode * count = temp->next;
			while (count != NULL){
				int dis = FindDist(temp->treenode, count->treenode);
				if (dis<=inidis){
					inidis = dis;
					min1 = temp;
					min2 = count;
				}
				count = count->next;
			}
			temp = temp->next;
		}
		// call print function
		int i = 0;
		while (min1->treenode->data[i]==min2->treenode->data[i]){
			++i;
		}
		if (min1->treenode->data[i]<min2->treenode->data[i])
			PrintAns(*head, min1, min2);
		else 
			PrintAns(*head, min2, min1);
		// fuse the two nodes into one node.
		if (num != 2){
			*head = Fuse(*head, min1, min2);
		}
		--num;
		// repeat till one node is remaining.
	}
}
#endif