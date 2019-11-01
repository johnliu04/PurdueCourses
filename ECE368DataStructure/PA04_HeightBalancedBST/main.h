#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>

typedef struct treenode{
    struct treenode * left;
    struct treenode * right;
    int key;
    int bal; //balance
    int height;
    int leaf;
}TreeNode;

typedef struct stack{
    int top; 
    int capacity; 
    TreeNode ** arr;
}Stack;

//stack functions
Stack * INITIAL();
int FULL(Stack * s);
int EMPTY(Stack * s);
TreeNode* TOP(Stack* s);
void PUSH(Stack* s, TreeNode* tn);
TreeNode* POP(Stack* s);
void FREE(Stack* s);

//evaluation functions
TreeNode  * TreeNodecreat(int key);
TreeNode * getdata(FILE * fptr);
void evaluate(FILE * fptr, Stack * s);
void treedestroy (TreeNode * tn);

//tree construct
TreeNode * constru(FILE*input);
void outputgen(TreeNode *tn, FILE *output);

//insertion functions
TreeNode * insertion(TreeNode *root , int target);
TreeNode * deletion(TreeNode *root , int target, int *none, int check);
TreeNode * bal(int change, TreeNode *node, int *none);

//rotation
TreeNode * rotation(TreeNode * young, int target, int change);
TreeNode * rightrotat(TreeNode * root);
TreeNode * leftrotat(TreeNode * root);

//helper function
void _preorder (TreeNode * tn);