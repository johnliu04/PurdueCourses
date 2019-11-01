#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"

//void Merge_Sort1(long *Array, int Size);
long *Load_Into_Array(char *Filename, int *size);
int Save_From_Array(char *Filename, long *Array, int size);

int main (int argc, char **argv){
    if (argc>4){
        return EXIT_FAILURE;
    }
    if (!strcmp(argv[1], "-q")){
        int size; 
        long * array;
        array = Load_Into_Array(argv[2], &size);
        Quick_Sort(array, size);
        int num = Save_From_Array(argv[3], array, size);
        printf("number of compression: %d\n", num);
        free(array);
    }
    else if (!strcmp(argv[1], "-m")){
        int size;
        long * array;
        array = Load_Into_Array(argv[2], &size);
        Merge_Sort(array, size);
        int num = Save_From_Array(argv[3], array, size);
        printf("number of compression: %d\n", num);
        free(array);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

long *Load_Into_Array(char *Filename, int *size){
  FILE * fptr = fopen(Filename, "r");
    if (fptr == NULL){
        return NULL;
    }
    long temp; //temp
    int count = 0;
    int m;
    while (!feof(fptr)){
        m = fread(&temp, sizeof(long), 1, fptr);
        m++;
        count++;
    }
    count--; //size of the array
    *size = count;

    fseek(fptr, 0, SEEK_SET);
    long *array = malloc(sizeof(long) * (count));
    if (array == NULL){
        printf("malloc fail\n");
        return NULL;
    }
    for (int i = 0; i < count; i ++){
        m = fread(&array[i], sizeof(long), 1, fptr);
    }

    fclose(fptr);
    return array;
}

int Save_From_Array(char *Filename, long *Array, int size){
    FILE * fptr = fopen(Filename, "wb");
    if (fptr == NULL){
        return 0;
    }
    int num;
    
    num = fwrite(Array, sizeof(long), size, fptr);
    /*
    for (int i = 0; i < size; i++){
      printf("%ld\n", Array[i]);
    }*/
    if (size!=num){
        printf("ERROR: write file error\n");
    }
    
    //free memory
    fclose(fptr);
    return num;
}