//tree functions
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <values.h>
#include "main.h"
#define NUMBER 256

TreeNode  * TreeNodecreat(int value, int freq){
    TreeNode * tn = malloc(sizeof(TreeNode));
    tn->left = NULL;
    tn->right = NULL;
    tn->value = value;
    tn->freq = freq;
    return tn;
} //create tree
ListNode * ListNodecreat(TreeNode * tn){
    ListNode * ln = malloc(sizeof(ListNode));
    ln->next = NULL;
    ln->trn = tn;
    return ln;
} //create linked list

ListNode * Listinsert(ListNode * head, ListNode * ln){
    if (head == NULL){
        return ln;
    }
    if (ln == NULL || ln->next != NULL){
        printf("error\n");
    }
    if ((head->trn)->freq <= (ln->trn)->freq){
        head->next = Listinsert(head->next, ln);
        return head;
    }
    ln->next = head;
    return ln;
}

ListNode * Listbuild(long * arr, FILE * output){
    int ind = 0;
    while (arr[ind] == 0){
        ind++;
    }
    if (ind == NUMBER){ //no frequency
        return NULL;
    }
    
    ListNode * head = NULL;
    while (ind < NUMBER){
        if (arr[ind]){
            TreeNode * tree = TreeNodecreat(ind, arr[ind]);
            ListNode * node = ListNodecreat(tree);
            head = Listinsert(head, node);
        }
        ind ++;
    }

    while ((head->next)!=NULL){ //merge linked list to a tree
        ListNode * num2 = head->next;
        ListNode * num3 = num2->next;
        TreeNode * tn1 = head->trn;
        TreeNode * tn2 = num2->trn;
        free(head);
        free(num2);
        head = num3;
        TreeNode * merg = malloc(sizeof(TreeNode));
        merg->left = tn1;
        merg->right = tn2;
        merg->value = 0;
        merg->freq = tn1->freq+tn2->freq;
        ListNode * ln = ListNodecreat(merg);
        head = Listinsert(head, ln);
    }
    printtree(head->trn, output);
    return head;
}

void printtree (TreeNode * tn, FILE *output){
    if (tn == NULL){
        return;
    }
    TreeNode * lc = tn->left;
    TreeNode * rc = tn->right;
    if ((lc==NULL) && (rc==NULL)){
        //printf("%c", tn->value);
        fprintf(output, "1%c", (char)tn->value);
        return;
    }
    else{
        fprintf(output, "0");
    }
    printtree(lc, output);
    printtree(rc, output);
    return;
}

void treedestroy (TreeNode * tn){
    if (tn == NULL){
        return;
    }
    treedestroy(tn->left);
    treedestroy(tn->right);
    free(tn);
}