//shell list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>
#include "shell_list.h"
#include "sequence.h"

static Node * buildlist(long value);
Node *List_find (Node *list, long size, Node ** pre);
void List_swap(Node **list, Node *curra, Node *preva, Node *currb, Node *prevb);
void _print_list (Node *list);

Node *List_Load_From_File(char *filename){
    FILE * fptr = fopen(filename, "rb");
    if (fptr == NULL){
        printf("error opening input file\n");
        return NULL;
    }
    long temp; //temp
    Node * head;
    Node * help = NULL;
    //int count = 0;
    while (!feof(fptr)){
        fread(&temp, sizeof(long), 1, fptr);
        head = buildlist(temp);
	head -> next = help;
	help = head;
    }
    Node * delet = head;
    head = delet->next;
    free(delet);

    /*
    //inverse the linked list
    Node * rev = NULL; 
    Node * sec; // orig->next
    while (head != NULL){
        sec = head->next;
        head->next = rev;
        rev = head;
        head = sec;
    }
    */
    fclose(fptr);
    return head;
}

static Node * buildlist(long value){
    Node * nd = malloc (sizeof (Node));
    nd->value = value;
    nd->next = NULL;
    return nd;
}

int List_Save_To_File(char *filename, Node *list){
    FILE * fptr = fopen(filename, "wb");
    if (fptr == NULL){
        printf("error opening output file\n");
        return 0;
    }
    Node * print = list;
    int num = 0;
    while (print != NULL){
        fwrite(&print->value, sizeof(long), 1, fptr);
        print = print->next;
        num++;
    }
    fclose(fptr);
    return num;
}

Node *List_Shellsort(Node *list, double *n_comp){
    if (list==NULL){
        return NULL;
    }
    int sortsize;
    int size = 0;
    Node * count = list;
    while (count!=NULL){
        size++;
        count = count->next;
    }
    long *seq = Generate_2p3q_Seq(size, &sortsize);
    
    while (sortsize >= 0){
        long sortvalue = seq[sortsize]; //k value
        long loca = 0;
        Node * target_pre = NULL;
	    Node * target = list;
        Node * compar_pre;
	    Node * compar = List_find(target, sortvalue, &compar_pre);
        do{
            Node * firstcompar = compar;
	        long targetvalue = target->value; //target value to change

            if (compar != NULL && (targetvalue > compar->value)){
		        *n_comp +=1; //number of swaps
		        List_swap(&list, target, target_pre, compar, compar_pre); //swap linked list
                compar_pre = target;
                compar = target->next;
                target_pre = firstcompar;
                target = firstcompar->next;
	        }
            else if (compar!=NULL){
                compar_pre = compar;
                compar = compar->next;
                target_pre = target;
                target = target->next;
            }
            loca++;
        }while (loca<size);
        sortsize--;
    }

    free(seq);
    return list;
}

Node *List_find (Node *list, long size, Node ** pre){
    if (size < 0){
        return NULL; //error
    }
    int i = 1;
    Node * prepoint = list;
    Node * pointer = list->next;//pointer to find the target value
    while (i<size && pointer!=NULL){
        prepoint = prepoint->next;
	pointer = pointer->next;
        i++;
    }
    *pre = prepoint;
    return pointer;
}

void List_swap(Node **list, Node *curra, Node *preva, Node *currb, Node *prevb){
    if (curra == NULL || currb == NULL){
        return;
    }

    //if a is the start of the linked list
    if (preva == NULL)
        *list = currb;
    else
        preva -> next = currb;

    //if b is the start of the linked list
    if (prevb == NULL)
        *list = curra;
    else 
        prevb -> next = curra;

    Node * temp = curra ->next;
    curra->next = currb->next;
    currb->next = temp;
}

void _print_list (Node *list){
    Node * help = list;
    while(help!=NULL){
        printf("%ld\n", help->value);
        help = help->next;
    }
}