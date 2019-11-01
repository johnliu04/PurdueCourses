//main.h
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#define NUMBER 256

void encode (FILE *fptr, FILE *pcount, FILE *ptree, FILE *pcode, FILE *pcomp);

//count frequency
int countFreq (FILE *fptr, long *arr, FILE *output);

//construct tree
typedef struct treenode{
    struct treenode * left;
    struct treenode * right;
    int value;
    int freq;
}TreeNode;

typedef struct listnode{
    struct listnode * next;
    TreeNode* trn;
}ListNode;

TreeNode  * TreeNodecreat(int value, int freq);
ListNode * ListNodecreat(TreeNode * tn);
ListNode * Listinsert(ListNode * head, ListNode * ln);
ListNode * Listbuild(long * arr, FILE * output);
//ListNode * Listbuild(long * arr, FILE * output, int * count);
void printtree (TreeNode * ln, FILE *output);
//void printtree (TreeNode * tn, FILE *output, int *count);
//free memory
void treedestroy (TreeNode * tn);

//build code
typedef struct{
    int len; //number of elements
    int code[NUMBER];
}Code;
//void buildcode(TreeNode * tn, int ** code, int * row, int left, int col, FILE *output);
//void printcode (int ** code, int num, FILE * output);
void codebuild(TreeNode * tn, int *arr, Code * code, FILE *output, int len);

//compress
long readhead(FILE * tree, FILE * output, long numtree);
//long readhead(FILE * tree, FILE * output, long numtree, int countree);
long readorig(Code * code, FILE * input, FILE * output, long numcomp);