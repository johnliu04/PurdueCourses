#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <values.h>
#include "main.h"
#define NUMBER 256

void encode (FILE *fptr, FILE *pcount, FILE *ptree, FILE *pcode, FILE *pcomp){
   
    //count frequency of each letter 
    long arr[NUMBER] = {0};
    long numorig = countFreq(fptr, arr, pcount); // number of elements
    // The total number of characters in the original uncompressed file
    long numtree = 0;//The total number of characters storing the topology of the Huffman coding tree
    long numcomp = 8*3;//The total number of characters in the compressed file
    fwrite(&numcomp, sizeof(long), 1, pcomp);
    fwrite(&numtree, sizeof(long), 1, pcomp);
    fwrite(&numorig, sizeof(long), 1, pcomp);


    //construct tree
    ListNode * head = Listbuild(arr, ptree); //generate linked list
    if (head == NULL){ //for empty stream
        return;
    }


    //build code
    TreeNode*root = head->trn;
    free(head); //no need for listnode
    int arrcode[NUMBER] = {0};
    Code *code = malloc(sizeof(Code)*NUMBER);//numR arrays
    codebuild(root, arrcode, code, pcode, 0);


    //compressed file
    //head information
    numtree = readhead(ptree, pcomp, 0);
    numcomp += readorig(code, fptr, pcomp, 0) + numtree;
    fseek(pcomp, 0, SEEK_SET);
    fwrite(&numcomp, sizeof(long), 1, pcomp);
    fwrite(&numtree, sizeof(long), 1, pcomp);
    fwrite(&numorig, sizeof(long), 1, pcomp);

    //free memory
    free(code);
    treedestroy(root);

    return;
}