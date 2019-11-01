//compress functions
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <values.h>
#include "main.h"
#define NUMBER 256

long readhead(FILE * tree, FILE * output, long numtree){
    fseek(tree, 0, SEEK_SET);
    int countree = 0;
    while (fgetc(tree)!=EOF){
        countree ++;
    }
    unsigned char topo = 0;
    unsigned char infor = 0;
    unsigned char mask;
    int check = 0;
    int cont = 0;
    int i = 0;
    int getone = 0;
    fseek(tree, 0, SEEK_SET);
    while (i<=countree){
        topo = fgetc(tree);
        if (i==countree){
            infor |= (0X00 << cont);
            fwrite(&infor, sizeof(unsigned char), 1, output);
            numtree ++;
            break;
        }
        if (topo == 0X30 && !getone){
            infor |= 0X00 << cont;
            cont ++;
            check = 0;
        }
        else if (topo == 0X31 && !getone){
            infor |= 0X01 << cont;
            cont ++;
            check = 0;
            getone = 1;
        }
        else if (check){
            fwrite(&topo, sizeof(unsigned char), 1, output);
            numtree ++;
            check = 0;
            getone = 0;
        }
        else {
            mask = 0XFF;
            mask = mask >> (cont);
            infor |= (mask & topo) << (cont);
            fwrite(&infor, sizeof(unsigned char), 1, output);
            
            numtree ++;
            infor = 0;
            infor |= topo >> (8-cont);
            getone = 0;
        }

        if (cont == 8){
            cont = 0;
            fwrite(&infor, sizeof(unsigned char), 1, output);
            numtree ++;
            infor = 0;
            check = 1;
        }
        i++;
    }
    return numtree;
}

long readorig(Code * code, FILE * input, FILE * output, long numcomp){
    fseek(input, 0, SEEK_SET);
    int i;
    unsigned char orig = 0;
    //unsigned char cont = 0;
    int cont = 0;
    while((i = fgetc(input)) != EOF){
        //printf("3");
        for (int n = 0; n<code[abs(i)].len; n++){
            //printf("%d", code[abs(i)].code[n]);
            if (code[abs(i)].code[n]){
                orig |= 0X01 << (cont);
            }
            cont++;
            if (cont == 8){
                fwrite(&orig, sizeof(unsigned char), 1, output);
                numcomp++;
                orig = 0;
                cont = 0;
            }
        }
    }
    if (cont){
        fwrite(&orig, sizeof(unsigned char), 1, output);
        numcomp++;
    }
    return numcomp;
}