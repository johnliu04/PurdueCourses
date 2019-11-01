//sequence.c
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <values.h>
#include "sequence.h"

long *Generate_2p3q_Seq(int length, int *seq_size){
    long power3 = 1;
    long row = 0;
    while (power3 < length){
        power3 *= 3;
        row ++;
    }
    long *seq = (long *)malloc(sizeof(long)*row*(row+1));
    
    //generate array from 2q
    long Pow3 = 1;
    int inde = 0;
    for (int numrow = 0; numrow < row; numrow++){
        seq[inde] = Pow3;
        while (seq[inde] < length){
            inde ++;
            seq[inde] = seq[inde-1] * 2;
        }
        Pow3 *= 3;
    }

    *seq_size = inde;
    long key; //key element
    long next; //next key element

    //insertion sort the array
    for (int i = 1; i<*seq_size; i++){
        key = seq[i];
        next = i - 1;
        while (next >= 0 && seq[next] > key){
            seq[next+1] = seq[next];
            next --;
        }
        seq[next+1] = key;
    }
    return seq; 
}