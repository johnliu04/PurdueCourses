//main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>

int main (int argc, char *argv[]){
    FILE * input = fopen(argv[1], "r");
    FILE * output = fopen(argv[2], "w");
    
    int key;
    char value;
    int what;

    while (!feof(input)){
        what = fscanf(input, "%d %c\n", &key, &value);
        what --;
        fwrite(&key, sizeof(int), 1, output);
        fwrite(&value, sizeof(char), 1, output);
    }
    fclose(input);
    fclose(output);

    return EXIT_SUCCESS;
}