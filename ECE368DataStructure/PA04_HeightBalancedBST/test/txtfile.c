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
        what = fread(&key, sizeof(int), 1, input);
        what = fread(&value, sizeof(char), 1, input);
        what --;
        //if (!feof(input)){
            //printf("%d %d\n", key, value);
        //}
	what = fprintf(output, "%d %c\n", key, value);
    }
    fclose(input);

    return EXIT_SUCCESS;
}