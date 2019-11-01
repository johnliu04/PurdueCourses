//main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>
#include "main.h"

int main (int argc, char *argv[]){
    if (argc > 4){
        return EXIT_FAILURE;
    }
    FILE *fptr = fopen(argv[1], "r");
    if (fptr == NULL){
        return EXIT_FAILURE;
    }
    FILE *output1 = fopen(argv[2], "w");
    if (output1 == NULL){
        return EXIT_FAILURE;
    }
    FILE *output2 = fopen(argv[3], "w");
    if (output2 == NULL){
        return EXIT_FAILURE;
    }

    files(fptr, output1, output2);
    //free memory
    fclose(fptr);
    fclose(output1);
    fclose(output2);
    return EXIT_SUCCESS;
}

void files(FILE * fptr, FILE * output1, FILE * output2){
    ListNode *head = readfile(fptr);
    if (head==NULL){
        return;
    }

    //output file generate
    //_postorder(head->next->tn, output2);
    preorder(head->next->tn, 0, 0, output1, output2);
    
    treedestroy(head->next->tn);
    nodedestroy(head);
}

void treedestroy (TreeNode * tn){
    if (tn == NULL){
        return;
    }
    treedestroy(tn->left);
    treedestroy(tn->right);
    free(tn);
}

void nodedestroy (ListNode * ln){
    if (ln == NULL){
        return;
    }
    nodedestroy(ln->next);
    free(ln);
}
