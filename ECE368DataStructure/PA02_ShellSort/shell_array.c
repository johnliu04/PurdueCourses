//shell_array
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <values.h>
#include "shell_array.h"
#include "sequence.h"

long *Array_Load_From_File(char *filename, int *size){
    FILE * fptr = fopen(filename, "rb");
    if (fptr == NULL){
        return NULL;
    }
    long temp; //temp
    int count = 0;
    while (!feof(fptr)){
        fread(&temp, sizeof(long), 1, fptr);
        count++;
    }
    count--; //size of the array
    *size = count;

    fseek(fptr, 0, SEEK_SET);
    long *array = malloc(sizeof(long) * (count));
    if (array == NULL){
        printf("malloc fail\n");
    }
    for (int i = 0; i < count; i ++){
        fread(&array[i], sizeof(long), 1, fptr);
    }

    fclose(fptr);
    return array;
}

int Array_Save_To_File(char *filename, long *array, int size){
    FILE * fptr = fopen(filename, "wb");
    if (fptr == NULL){
        return 0;
    }
    int num;
    num = fwrite(array, sizeof(long), size, fptr);
    if (size!=num){
        printf("ERROR: write file error\n");
    }
    
    //free memory
    fclose(fptr);
    return num;
}

void Array_Shellsort(long *array, int size, double *n_comp){
    if (!size){
      array = NULL;
      return;
    }
  
    int sortsize; 
    long *seq = Generate_2p3q_Seq(size, &sortsize);

    while (sortsize >= 0){
        long sortvalue = seq[sortsize];
        for (long j = sortvalue; j <= size-1; j++){
            long target = array[j]; //target value
            long i = j;
            while (i >= sortvalue && array[i-sortvalue]>target){
                *n_comp +=1;
                array[i] = array[i-sortvalue];
                i -= sortvalue;
            }
            array[i] = target;
        }
        sortsize --;
    }
    free(seq);
}