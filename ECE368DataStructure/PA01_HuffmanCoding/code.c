//build code
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <values.h>
#include "main.h"

void codebuild(TreeNode * tn, int *arr, Code * code, FILE *output, int len){
    if (tn == NULL){
        return;
    }
    TreeNode * lc = tn->left;
    TreeNode * rc = tn->right;
    if (!(lc && rc)){
        //code[*cha].value = tn->value;
        fprintf(output, "%c:", tn->value);
        
        for(int n=0; n < len; n++){
            code[(int)tn->value].code[n] = arr[n];
            //fprintf(output, "%d", arr[n]);
            fprintf(output, "%d", code[(int)tn->value].code[n]);
        }
        code[(int)tn->value].len = len;
        fprintf(output, "\n");
        return;
    }
    codebuild(lc, arr, code, output, len+1);
    arr[len] = 1;
    codebuild(rc, arr, code, output, len+1);
    arr[len] = 0;
}