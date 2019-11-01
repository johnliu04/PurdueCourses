#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqpair.h"

ListNode * generatenode(int num){
    ListNode * ln = malloc(sizeof(ListNode));
    ln->next = NULL;
    ln->index = num;
    return ln;
}

void generatelist(Graph * arr, int size){
    for (int index = 1; index <= size; index++){
        int S1 = arr[index].S1;
        int S2 = arr[index].S2;

        ListNode * tempph, * temppv;
        for (int check = size; check > 0; check --){
            if (arr[check].S1 > S1 && arr[check].S2 > S2){
                tempph = generatenode(check);
                tempph -> next = arr[index].hcg;
                arr[index].hcg = tempph;
            } //right of x in the packing
            else if (arr[check].S1 < S1 && arr[check].S2 > S2){
                temppv = generatenode(check);
                temppv -> next = arr[index].vcg;
                arr[index].vcg = temppv;
            } //above x in packing
        }
    }
}

void DFS(Graph * arr, int * sorthor, int * sortver, int number){
    int sizeh = number;
    int sizev = number;
    for (int i = 1; i <= number; i++){
        if (arr[i].colorh == WHITE)
            dfsh(arr, i, sorthor, &sizeh);
        if (arr[i].colorv == WHITE)
            dfsv(arr, i, sortver, &sizev);
    }
}

void dfsh(Graph * arr, int index, int * sort, int * size){
    ListNode * nextnode = arr[index].hcg;
    int value;
    while (nextnode != NULL){
        value = nextnode->index;
        if (arr[value].colorh == WHITE){
            arr[value].colorh = GRAY;
            dfsh(arr, value, sort, size);
        }
        nextnode = nextnode->next;
    }
    arr[index].colorh = BLACK;
    sort[*size] = index;
    *size -= 1;
}

void dfsv(Graph * arr, int index, int * sort, int * size){
    ListNode * nextnode = arr[index].vcg;
    int value;
    while (nextnode != NULL){
        value = nextnode->index;
        if (arr[value].colorv == WHITE){
            arr[value].colorv = GRAY;
            dfsv(arr, value, sort, size);
        }
        nextnode = nextnode->next;
    }
    arr[index].colorv = BLACK;
    sort[*size] = index;
    *size -= 1;
}

void tolosort(Graph * arr, int size, int * sorthor, int * sortver){
    int target, index;
    ListNode * tmph, * tmpv;
    int newwid, newhei;

    for (int i = 1; i <= size; i ++){
        index = sorthor[i];
        newwid = arr[index].newwid + arr[index].width;
        tmph = arr[index].hcg;
        while(tmph != NULL){
            target = tmph->index;
            if (arr[target].newwid < newwid)
                arr[target].newwid = newwid;
            tmph = tmph->next;
        }

        index = sortver[i];
        newhei = arr[index].newhei + arr[index].height;
        tmpv = arr[index].vcg;
        while(tmpv != NULL){
            target = tmpv->index;
            if (arr[target].newhei < newhei)
                arr[target].newhei = newhei;
            tmpv = tmpv->next;
        }
    }
}

//helper functions
void _printarr(int * sort, int size){
    for (int index = 1; index <= size; index++){
        printf("%d: %d\n", index, sort[index]);
    }
}

void _printlist(Graph * arr, int size){
    for (int index = 0; index <= size; index++){
        printf("%d:\n(hcg) ", index);
        ListNode * temph = arr[index].hcg;
        while (temph != NULL){
            printf("%d ", temph->index);
            temph = temph->next;
        }
        printf("\n(vcg) ");
        ListNode * tempv = arr[index].vcg;
        while(tempv != NULL){
            printf("%d ", tempv->index);
            tempv = tempv->next;
        }
        printf("\n");
    }
}