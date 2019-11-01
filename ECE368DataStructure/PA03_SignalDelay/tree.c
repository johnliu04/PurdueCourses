#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>
#include "main.h"

TreeNode  * TreeNodecreat(int label, double capa, double leftwire, double rightwire){
    TreeNode * tn = malloc(sizeof(TreeNode));
    if (tn == NULL){
      return NULL;
    }
    tn->left = NULL;
    tn->right = NULL;
    tn->capa = capa; //sink node capacitance
    tn->label = label; //label of the sink
    tn->rightwire = rightwire; //wire length to the left child
    tn->leftwire = leftwire; //wire length to the right child
    tn->rpath = 0;
    tn->cpath = 0;
    return tn;
} //create tree

ListNode * ListNodecreat(TreeNode *tn){
    ListNode * ln = malloc(sizeof(ListNode));
    if (ln == NULL){
      return NULL;
    }
    ln->next = NULL;
    ln->prev = NULL;
    ln->tn = tn;
    return ln;
} //create linked list

void Listconstruct(TreeNode *tree, ListNode **head){
    ListNode *newnode = ListNodecreat(tree);
    if (newnode == NULL){
      return;
    }
    ListNode *help = *head;
    newnode -> prev = help;
    help -> next = newnode;
}

ListNode* readfile(FILE *fptr){
    fseek(fptr, 0, SEEK_END);
    if (!ftell(fptr)){ //empty file
        return NULL;
    }
    fseek(fptr, 0, SEEK_SET); 

    double arr[3] = {0};    
    int i;
    for(i = 0; i < 3; i++){
        fscanf(fptr, "%le", &arr[i]);
    } 
    //[0]: output resistance at the source -rd
    //[1]: per-unit-length resistance of a wire -r
    //[2]: per-unit-length capacitance of a wire -c

    TreeNode * tree = NULL;
    ListNode * head = ListNodecreat(tree);
    ListNode * help = head;
    char value;
    fgetc(fptr); //'\n'
    while ((value = fgetc(fptr)) != EOF){
        if (value == '('){ //non-leaf node
            double leftwire, rightwire;
            fscanf(fptr, "%le %le)\n", &leftwire, &rightwire);
            tree = TreeNodecreat(0, 0, leftwire, rightwire);
	    if(tree == NULL){
	      return NULL;
	    }
            Listconstruct(tree, &help);
            help = help->next;
            
            ListNode * num2 = help->prev; //right child
            ListNode * num1 = num2->prev; //left child
            ListNode * prev = num1->prev; //prev child
            prev->next = help;
            num1->tn->cpath += leftwire * arr[2] / 2;
            num1->tn->rpath = leftwire * arr[1];
            num2->tn->cpath += rightwire * arr[2] / 2;
            num2->tn->rpath = rightwire * arr[1];
            help->tn->cpath = num1->tn->cpath + num2->tn->cpath + (leftwire + rightwire)*arr[2] / 2;
            (help->tn)->left = num1->tn;
            (help->tn)->right = num2->tn;
            help->prev = prev;
            free(num1);
            free(num2);
        }
        else{ //leaf node
            int label;
            double capa;
            fseek(fptr, -(sizeof(char)), SEEK_CUR);
            fscanf(fptr, "%d(%le)\n", &label, &capa);
            tree = TreeNodecreat(label, capa, 0, 0);
	    if(tree == NULL){
	      return NULL;
	    }
            Listconstruct(tree, &help); 
            help = help->next;
            help->tn->cpath = capa;
        }
    }
    if (head->next!=NULL){
      head->next->tn->rpath = arr[0];
    }
    else{
      free(head);
      return NULL;
    }
    //_print_list(head);
    return head;
}

void preorder (TreeNode *tn, double olddelay, double oldpath, FILE *output1, FILE *output2){
    double delay;
    
    while (tn->left!=NULL){
        tn->rpath += oldpath;
        delay = (olddelay - oldpath * oldpath * (tn->cpath)) + (tn->rpath)*(tn->rpath)*(tn->cpath);
        fprintf(output1, "(%le %le)\n", tn->leftwire, tn->rightwire);
        preorder(tn->left, delay, tn->rpath, output1, output2);
        olddelay = delay; //update delay for tail recursion
        oldpath = tn->rpath;
        tn = tn->right;
    }
    tn->rpath += oldpath;
    delay = (olddelay - oldpath * oldpath * (tn->cpath)) + (tn->rpath)*(tn->rpath)*(tn->cpath);
    int label = tn->label;
    fprintf(output1, "%d(%le)\n", label, tn->capa);
    //double path = tn->rpath;
    double printdelay = delay/(tn->rpath);
    //fprintf(output2, "%d(%le)\n", label, printdelay);
    fwrite(&label, sizeof(int), 1, output2);
    fwrite(&printdelay, sizeof(double), 1, output2);
}

void _postorder (TreeNode *tn, FILE *output){
    if (tn == NULL){
        return;
    }
    if (tn->left == NULL){
        fwrite(&tn->label, sizeof(int), 1, output);
	fwrite(&tn->capa, sizeof(double), 1, output);
        return;
    }
    _postorder(tn->left, output);
    _postorder(tn->right, output);
    fwrite(&tn->leftwire, sizeof(double), 1, output);
    fwrite(&tn->rightwire, sizeof(double), 1, output);
}

void _postorder2 (TreeNode *tn){
    if (tn == NULL){
        return;
    }
    if (tn->left == NULL){
        printf("%d(%le %le)\n", tn->label, tn->cpath, tn->rpath);
        return;
    }
    _postorder2(tn->left);
    _postorder2(tn->right);
    printf("(%le %le)\n", tn->cpath, tn->rpath);
}

void _print_list (ListNode *list){
    ListNode * help = list->next;
    ListNode *prev = list;
    while(help!=NULL){
        printf("%d %le %le %le\n", (help->tn)->label, (help->tn)->capa, (help->tn)->leftwire, (help->tn)->rightwire);
        help = help->next;
        prev = prev->next;
    }
    printf("\n\n");
    while((prev->tn)!=NULL){
        printf("%d %le %le %le\n", (prev->tn)->label, (prev->tn)->capa, (prev->tn)->leftwire, (prev->tn)->rightwire);
        prev = prev->prev;
    }
}
