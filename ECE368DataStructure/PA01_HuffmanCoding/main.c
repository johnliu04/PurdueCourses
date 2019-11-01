//main.c
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <values.h>
#include "main.h"
#define NUMBER 256

int main(int argc, char *argv[]) {
    //open all the files
    FILE *fptr = fopen(argv[1], "r");
    if (fptr == NULL){
        return 0;
    }
    FILE *pcount = fopen(argv[2], "w");
    FILE *ptree = fopen(argv[3], "w+");
    FILE *pcode = fopen(argv[4], "w");
    FILE *pcomp = fopen(argv[5], "w");

    encode(fptr, pcount, ptree, pcode, pcomp);

    fclose(fptr);
    fclose(pcount);
    fclose(ptree);
    fclose(pcode);
    fclose(pcomp);
    return EXIT_SUCCESS;
}