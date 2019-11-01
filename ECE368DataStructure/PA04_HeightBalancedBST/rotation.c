//rotation.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>
#define MAX(a, b) (a>b) ? a : b
#include "main.h"

TreeNode * rotation(TreeNode * young, int target, int change){
    TreeNode * help;
    TreeNode * curr = NULL;
  
    if (change){
        if (change == 1)
            help = young->right;
        else
            help = young->left;
    }
    else{
        //find where the new node insert
        if (target <= young->key)
            help = young->left;
        else 
            help = young->right;
    }
    if (help == NULL)
        return young; //error

    if((young->bal == 2) && (help->bal == 1 || help->bal == 0)){ //right rotation
        curr = rightrotat(young);
    }
    
    if((young->bal == -2) && (help->bal == -1 || help->bal == 0)){//left rotation
        curr = leftrotat(young);
    }
    
    if ((young->bal == 2) && (help->bal == -1)){
        curr = leftrotat(help);
        young->left = curr;
        curr = rightrotat(young);
    }
    
    if ((young->bal == -2) && (help->bal == 1)){
        curr = rightrotat(help);
        young->right = curr;
        curr = leftrotat(young);
    }
    
    if (young->left != NULL && young->right != NULL){
      young->height = (MAX(young->left->height, young->right->height)) + 1;
      young->bal = young->left->height - young->right->height;
    }
    else if (young->left != NULL){
      young->height = young->left->height + 1;
      young->bal = young->left->height + 1;
    }
    else if (young->right != NULL){
      young->height = young->right->height + 1;
      young->bal = -1 - young->right->height;
    }
    else{
      young->height = 0;
      young->bal = 0;
    }
    
    if (help->left != NULL && help->right != NULL){
      help->height = (MAX(help->left->height, help->right->height)) + 1;
      help->bal = help->left->height - help->right->height;
    }
    else if (help->left != NULL){
      help->height = help->left->height + 1;
      help->bal = help->left->height + 1;
    }
    else if (help->right != NULL){
      help->height = help->right->height + 1;
      help->bal = -1 - help->right->height;
    }
    else{
      help->height = 0;
      help->bal = 0;
    }
    
    if (curr->left != NULL && curr->right != NULL){
      curr->height = (MAX(curr->left->height, curr->right->height)) + 1;
      curr->bal = curr->left->height - curr->right->height;
    }
    else if (curr->left != NULL){
      curr->height = curr->left->height + 1;
      curr->bal = curr->left->height + 1;
    }
    else if (curr->right != NULL){
      curr->height = curr->right->height + 1;
      curr->bal = -1 - curr->right->height;
    }
    else{
      curr->height = 0;
      curr->bal = 0;
    }
    
    return curr;
}

TreeNode * rightrotat(TreeNode * root){
    TreeNode * newroot = root->left;
    root->left = newroot->right;
    newroot->right = root;
    return newroot;
}

TreeNode * leftrotat(TreeNode * root){
    TreeNode * newroot = root->right;
    root->right = newroot->left;
    newroot->left = root;
    return newroot;
}