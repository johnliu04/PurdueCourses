//edit this file as required
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw18.h"

//Do Not Change this function
void PrintAnswer(ListNode* head, ListNode* min1, ListNode* min2)
{
	ListNode* temp = head;
	int i;
	while(temp!=NULL)
	{
		i = 0;
		while(i < head -> treenode->dimension)
		{
			if(i == 0)
				printf("(%d, ", temp->treenode->data[i]);
			else if(i == head -> treenode->dimension-1)
				printf("%d)\n", temp->treenode->data[i]);
			else
				printf("%d, ", temp->treenode->data[i]);
			i+=1;

		}
		temp = temp->next;
	}

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
YOU CAN EDIT BELOW THIS COMMENT
*/

#ifdef TEST_MIN
void FindMin(ListNode* head)
{
	// find pair of ListNodes with least distance between them.
	ListNode *temp = head;
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

	// call print Function
	/*
	ENSURE the 2nd parameter of the print function (min1) is smaller than
	the 3rd parameter (min2). 
	Look at README, and expected output for more details.
	*/
	int i = 0;
	while (min1->treenode->data[i]==min2->treenode->data[i]){
		++i;
	}
	if (min1->treenode->data[i]<min2->treenode->data[i])
		PrintAnswer(head, min1, min2);
	else 
		PrintAnswer(head, min2, min1);
	
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