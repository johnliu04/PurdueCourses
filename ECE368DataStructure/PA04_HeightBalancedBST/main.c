//main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>
#include "main.h"

int main (int argc, char *argv[]){
    if (argc < 3){
        return EXIT_FAILURE;
    }
    if (strcmp(argv[1], "-e") && strcmp(argv[1], "-b")){
        return EXIT_FAILURE;
    }
    FILE * fptr = fopen(argv[2], "r");
    Stack * s = INITIAL(); //memory stack

    if (!(strcmp(argv[1], "-e"))){
        if (fptr == NULL){
            fprintf(stdout, "-1, 0, 0\n" );
            FREE(s);
            return EXIT_FAILURE;
        }
        evaluate(fptr, s);
    }
    else if (!(strcmp(argv[1], "-b"))){
        if (fptr == NULL){
            fprintf(stdout, "-1\n" );
            FREE(s);
            return EXIT_FAILURE;
        }
        FILE * output = fopen(argv[3], "w");
        if (output == NULL){
            fprintf(stdout, "-1\n" );
            FREE(s);
            return EXIT_FAILURE;
        }
        TreeNode * tn = constru(fptr); //construct tree
        outputgen(tn, output); //write to the output file
        treedestroy(tn); //free memory
        fclose(output);
    }
    
    FREE(s); //free memory
    fclose(fptr);
    return EXIT_SUCCESS;
}

void outputgen(TreeNode *tn, FILE *output){ //preorder
    if (tn == NULL){
        return;
    }
    Stack * s = INITIAL();
    TreeNode * node = tn;
    PUSH(s, node);
    while (!EMPTY(s)){
        node = POP(s);
        if (node->right == NULL && node->left == NULL)
            node->leaf = 0;
        else if (node->right == NULL)
            node->leaf = 2;
        else if (node->left == NULL)
            node->leaf = 1;
        else
            node->leaf = 3;
        
        //fprintf(output, "%d %d %d %d\n", node->key, node->leaf, node->bal, node->height);
        fwrite(&node->key, sizeof(int), 1, output);
        fwrite(&node->leaf, sizeof(char), 1, output);
        if(node->right != NULL){
            PUSH(s, node->right);
        }
        if(node->left != NULL){
            PUSH(s, node->left);
        }
    }
    FREE(s);
}