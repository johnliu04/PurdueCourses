/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw12.h"

#ifdef LINKEDLIST

// Do not modify the below program, we are using ifdef block for
// ease of grading. Please include this flag in your Makefile
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
			printf("%d",temp->value);
		}
		temp=temp->next;
	}
	printf("\n");

}
#endif


/********** Do Not modify the file above this line, you should modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int value)
{
	// allocate memory for the new Node*
	Node * newNode = malloc(sizeof(Node));
	// check memory allocation fails
	if (newNode == NULL)
	{
	  fprintf(stderr, "malloc fail\n");
	  return NULL;
	}
	// create a Node* with the value as 'value'(input argument).
	newNode -> value = value;
	newNode -> next = NULL;
	
	return newNode;
}
#endif

#ifdef TEST_LINKEDLISTCREATE
// 1. head: the head of the singly linkedlist.
// 2. length: the length of the singly linkedlist.

// This function creates and initializes a singly linkedlist with length as 'length'(input argument),
// The values of the nodes within the singly linkedlist will be the same as array indddices.
// For example, if the singly linkedlist length is 4, the value of the nodes will be 0 1 2 3
void LinkedListCreate(Node * * head, int length)
{
	// check if length is not negative
	if (length < 0){
	    *head = NULL;
	    return;
	}
	// create linked list of length as 'length'
	for (int index = length - 1; index >= 0; index --){
	  Node * ptr = CreateNode(index);
	  if (ptr == NULL){
	    *head = NULL;
	    return;
	  }
	  ptr -> next = *head;
	  *head = ptr;
	}
	
	// do not return anything
}
#endif



#ifdef TEST_JOSEPHUS

// 1. head: the head of the singly linkedlist.
// 2. k : this variable will be used for counting if count = k, the element will be out.
// 3. elemDivisible : this variable will be used for printing. When the number of
//    remaining nodes in linked list is divisible by elemDivisible then you should 
//    print the remaining LinkedList with print functin provided to you.

// This function should solve the josephus problem using the singly linkedlist.

void Josephus(Node ** head, int k, int elemDivisible)
{
	Node *help = *head;
	Node *delet = help -> next;
	int number = 0;
	// implement the algorithm here
	// remember to free the memory of the nodes
	do{
	  int count = 1;
	  while(count < k){
 	      if (delet == NULL){ //reach the end of head
		help = * head; //help start from head
		delet = help -> next; //delet start from second number of help
 	      }
	      else{
 		help = help -> next;
 		delet = delet -> next;
	      }
	    count++;
	  }

  	  if (delet == NULL){
		delet = *head;
		*head = delet->next;
		help = *head;
   	  }
	  else{
	    help->next=delet->next;
	    help = help->next;
	    if (help == NULL){
	      help = *head;
	    }
	  }
	  free(delet);
	  delet = help->next;
	  
	  //number of people remain
	  Node * print = *head;
	  number = 0;
	  while(print != NULL){
	    print = print -> next;
	    number ++;
	  }
	  
	// print the linked list using our function when number of nodes remaining is divisible by elemDivisible
	  if (!(number % elemDivisible)){
	    LinkedListPrint(*head); //*head
	  }
	} while (number > 1); //number != 1
}

#endif
