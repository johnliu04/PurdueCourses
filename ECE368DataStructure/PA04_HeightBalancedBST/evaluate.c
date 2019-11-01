//evaluate.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>
#include "main.h"

TreeNode  * TreeNodecreat(int key){
    TreeNode * tn = malloc(sizeof(TreeNode));
    tn->left = tn->right = NULL;
    tn->key = key;
    tn->bal = tn->height = tn->leaf = 0;
    return tn;
} //create tree

TreeNode * getdata(FILE * fptr){
    int key; //value of the tree
    char binvalue; //2&3 left child 1&3 right child
    if (!fread(&key, sizeof(int), 1, fptr)){
        return NULL;
    }
    if (!fread(&binvalue, sizeof(char), 1, fptr)){
        return NULL;
    }
    if(binvalue < 0 || binvalue > 3){
        return NULL;
    }
    TreeNode *node = TreeNodecreat(key);
    node->leaf = binvalue;
    return node;
}

void evaluate(FILE * fptr, Stack * s){
    TreeNode *tn = getdata(fptr);
    if (tn == NULL){
        fprintf(stdout, "empty: 0,0,0\n");
        return; // empty file
    }
    TreeNode * node = tn;
    TreeNode *child;
    int second = 1; //if BST
    int third = 1; //if balanced
    PUSH(s, node);
    while (!EMPTY(s)){
        node = POP(s);
        if (node->leaf > 0){
            child = getdata(fptr);
            if (child == NULL){
                //tree build fail
                fprintf(stdout, "tree build fail: 0,0,0\n");
                treedestroy(tn);
                return;
            }
            if (node -> leaf >= 2){ //left child
                node -> left = child;
                if (node->key < child->key)
                    second = 0;
            }
            else if (node -> leaf == 1){ //right child
                node -> right = child;
                if (node->key > child->key)
                    second = 0;
            }
            node -> leaf -= 2;
            PUSH(s, node);
            PUSH(s, child);
        }
        //height & balanced
        if(node->left == NULL && node->right == NULL){
        }
        else if (node->right == NULL){ //no left child
            node->height = node->left->height + 1;
            node->bal = node->left->height + 1;
            if (node->left->bal != 0 && node->left->bal != 1 && node->left->bal != -1){
                third = 0;
            }
        }
        else {
            if (node->left == NULL){ //no right child
                node->height = node->right->height + 1;
                node->bal = 0 - 1 - node->right->height;
            }
            else{
                if (node->left->height >= node->right->height) //max(leftheight, rightheight)
                    node->height = node->left->height + 1;
                else 
                    node->height = node->right->height + 1;
                node->bal = (node->left->height) - (node->right->height);
            }
            if (node->right->bal != 0 && node->right->bal != 1 && node->right->bal != -1){
                third = 0;
            }
        }
    }
    if (tn->bal != 0 && tn->bal != 1 && tn->bal != -1){ //head node
        third = 0;
    }
    fprintf(stdout, "1,%d,%d\n", second, third);
    treedestroy(tn); //free memory
}

void treedestroy (TreeNode * tn){
    if (tn == NULL){
        return;
    }
    treedestroy(tn->left);
    treedestroy(tn->right);
    free(tn);
}

//helper function
void _preorder (TreeNode * tn){
    if (tn ==  NULL){
        return;
    }
    printf("%d %d\n", tn->key, tn->bal);
    _preorder(tn->left);
    _preorder(tn->right);
}