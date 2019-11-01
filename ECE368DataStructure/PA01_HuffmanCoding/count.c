//count functions
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <values.h>
#include "main.h"
#define NUMBER 256

int countFreq (FILE *fptr, long *arr, FILE *output){
    int freq = 0;
    int count = 0;
    while ((freq = fgetc(fptr)) != EOF){
		if(freq<=256){
			arr[freq] ++;
			count++;
		}
    }
    fwrite(arr, sizeof(long), NUMBER, output);
    return count;
}