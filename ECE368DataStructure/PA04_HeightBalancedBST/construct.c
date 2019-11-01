//insert and construct balanced BST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>
#define MAX(a, b) (a>b) ? a : b
#include "main.h"

TreeNode * constru(FILE*input){
    fseek(input, 0, SEEK_END);
    int count = ftell(input);
    if (!count){ //empty file
        return NULL;
    }
    fseek(input, 0, SEEK_SET); 
    
    count /= (sizeof(int)+sizeof(char));
    int key; //key
    char oper; //operation
    TreeNode * tn = NULL;
    while (count){
        if(!fread(&key, sizeof(int), 1, input)){
            fprintf(stdout, "-1\n" );
            return tn;
        }
        if (!fread(&oper, sizeof(char), 1, input)){
            fprintf(stdout, "-1\n" );
            return tn;
        }
        if (oper == 'i') //insertion
            tn = insertion(tn, key);
        else if (oper == 'd'){ //deletion
            int none = 1;
            tn = deletion(tn, key, &none, 0);
        }
        else
          return NULL;
        count -= 1;
    }
    return tn;
}

TreeNode * insertion(TreeNode *root , int target){
    TreeNode * young = root; //youngest ancestor: the first one have bal -1, 1
    TreeNode * pyoung = NULL; //parent node of young
    TreeNode * curr = root; //current node
    TreeNode * pcurr = NULL; //parent node of current node
    TreeNode * help;

    while (curr != NULL){
        if (target <= curr->key)
            help = curr->left;
        else
            help = curr->right;
        if (help != NULL && help->bal != 0){
            pyoung = curr;
            young = help;
        }
        pcurr = curr;
        curr = help;
    } //find the right position

    TreeNode * newnode = TreeNodecreat(target);
    //place the new node to the right location
    if(pcurr == NULL){
        root = newnode; //empty tree
        return root;
    }
    else{
        if (target <= pcurr->key)
            pcurr->left = newnode;
        else
            pcurr->right = newnode;
    }

    //update the balance
    curr = young;
    while (curr != newnode){
        if (target <= curr->key){
            curr->bal += 1;
	    if (curr->bal)
		curr->height += 1;
            curr = curr->left;
        }
        else{
            curr->bal -= 1;
	    if (curr->bal)
		curr->height += 1;
            curr = curr->right;
        }
    }
    if ((young->bal < 2) && (young->bal > -2))
        return root;
    
    //rotation
    curr = rotation(young, target, 0); 
    
    if(pyoung == NULL)
        root = curr;
    else{
        if (target <= pyoung->key)
            pyoung->left = curr;
        else
            pyoung->right = curr;
    }

    return root;
}

TreeNode * deletion(TreeNode *root , int target, int *none, int check){
  if (root == NULL){ //can not find the target node
    *none = 0;
    return NULL;
  }
  
  if (target < root->key){
    root->left = deletion(root->left, target, none, check);
    if (!*none)
      return root;
    return bal(-1, root, none);
  }
  else if (target > root->key){
    root->right = deletion(root->right, target, none, check);
    if (!*none)
      return root;
    return bal(1, root, none);
  }
  if (check){ //need to find the right position to delete
    if (root->right != NULL){
      root->right = deletion(root->right, target, none, check);
      return bal(1, root, none);
    }
  }
  if (root->left == NULL && root->right == NULL){
    free(root);
    return NULL;
  } //no child
  if (root->left == NULL){
    TreeNode * temp = root->right;
    free(root);
    return temp;
  }//no left child
  if (root->right == NULL){
    TreeNode * temp = root->left;
    free(root);
    return temp;
  }//no right child
  
  TreeNode * temp = root->left; //with two children
  while(temp->right != NULL)
    temp = temp->right;
  
  root->key = temp->key;
  temp->key = target;
  root->left = deletion(root->left, target, none, 1);
  if(!*none)
    return root; //error
  return bal(-1, root, none);
}

TreeNode * bal(int change, TreeNode *node, int *none){
  int balance = node->bal;
  if (node->left != NULL && node->right != NULL){
    node->height = (MAX(node->left->height, node->right->height)) + 1;
    node->bal = node->left->height - node->right->height;
  }
  else if (node->left != NULL){
    node->height = node->left->height + 1;
    node->bal = node->left->height + 1;
  }
  else if (node->right != NULL){
    node->height = node->right->height + 1;
    node->bal = -1 - node->right->height;
  }
  else{
    node->height = 0;
    node->bal = 0;
  }
  
  if (!balance){
    *none = 0; //no need to rotate anymore
    return node;
  }

  if (node->bal < 2 && node->bal > -2)
    return node;

  if (change == -1 && node->left == NULL)
    change = 1;
  else if (change == -1 && node->right != NULL){
    if (node->left->height < node->right->height)
      change = 1;
  }
  else if (change == 1 && node->right == NULL)
    change = -1;
  else if (change == 1 && node->left != NULL){
    if (node->left->height > node->right->height)
      change = -1;
  }

  return rotation(node, 0, change);
}