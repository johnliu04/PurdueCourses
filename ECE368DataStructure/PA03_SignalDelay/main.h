#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

void files(FILE * fptr, FILE * output1, FILE * output2);
//construct tree
typedef struct treenode{
    struct treenode * left;
    struct treenode * right;
    int label;
    double capa;
    double leftwire;
    double rightwire;
    double rpath; //rpath
    double cpath; //c_down
}TreeNode;

//construct linked list
typedef struct listnode{
    struct listnode * next;
    struct listnode * prev;
    TreeNode* tn;
}ListNode;

ListNode* readfile(FILE *fptr);
TreeNode  * TreeNodecreat(int label, double capa, double leftwire, double rightwire);
ListNode * ListNodecreat(TreeNode *tn);
void Listconstruct(TreeNode *tree, ListNode **head);

void preorder (TreeNode *tn, double olddelay, double oldpath, FILE *output1, FILE *output2);
//helper functions
void _postorder (TreeNode *tn, FILE *output);
void _print_list (ListNode *list);
void _postorder2 (TreeNode *tn);

void treedestroy (TreeNode * tn);
void nodedestroy (ListNode * ln);