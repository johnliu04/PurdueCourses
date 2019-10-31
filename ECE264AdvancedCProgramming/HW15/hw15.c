/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw15.h"

#ifdef LINKEDLIST
// Do not modify this function.
void LinkedListPrint(Node * head)
{

	Node *temp = head;

	while(temp!=NULL)
	{
		if(temp->next!=NULL)
		{
			printf("%d,",temp->value);
		}
		else
		{
			printf("%d\n",temp->value);
		}
		temp=temp->next;
	}
}
#endif


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
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

void LinkedListCreate(Node ** head, char* name)
{
	/*
	Create a linked list from the input file referenced by `name`.
	*/
	FILE *fptr = fopen(name, "r");
	if (fptr == NULL){
		return;
	}
	int arr;
	fscanf(fptr, "%d", &arr);
	*head = CreateNode(arr);
	Node *help=*head;
	while (fscanf(fptr, "%d", &arr) == 1){
		Node *temp = CreateNode(arr);
		help->next = temp;
		help = help->next;
	}
	fclose(fptr);
}
#endif
#ifdef TEST_REMOVED
//This function will remove repetitions of a linked list value.

void RemoveDuplicate(Node *headRef)
{
	/*
	This function will remove repetitions from the linked list referenced by headRef.
	Each time we check for a new Node in the linked list, we will check if it is distinct from
	the Nodes already present in the list ( upto the previous Node).
	So for each occurrence after its first, we will be deleting that node.
	To delete a node: we will map the next Node of the previous Node to the Node after the current Node.
	Print the linked list after all repetitions have been removed. Use the function given to you for priniting.
	*/

	Node * search = headRef;
	Node * help = headRef;
	Node * delete = help -> next;

	while (search!= NULL && delete!=NULL){
		while (delete != NULL){
			if (delete->value == search->value){
			    help->next = delete->next;
			    free(delete);
			    delete = help->next;
			}
			else{
			  delete = delete->next;
			  help = help->next;
			}
		}
		
		search = search->next;
		help = search;
		delete = help->next;
	}
	LinkedListPrint(headRef);
}
#endif
