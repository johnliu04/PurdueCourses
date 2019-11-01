#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv){
    FILE * input = fopen(argv[1], "r");
    FILE * output = fopen(argv[2], "w");
	
    long key;
    int what;

    while (!feof(input)){
        what = fread(&key, sizeof(long), 1, input);
        what --;
        if (!feof(input)){
            fprintf(output, "%ld\n", key);
        }
    }
    fclose(input);
    fclose(output);

    return EXIT_SUCCESS;
}