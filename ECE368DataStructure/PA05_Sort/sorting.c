#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "sorting.h"

//quick sort help functions
static void quicks(long * arr, int lb, int ub);
//static void insertion(long * arr, int lb, int ub);
//static void quicksort(long *arr, int lb, int ub);
//static void medianofthree(long *arr, int lb, int ub);
static int partition(long * arr, int lb, int ub);
//static int partition1(long * arr, int lb, int ub);

//merge sort help functions
static void mergeasc_sort(long *arr, long *temp, int lb, int ub);
static void mergedec_sort(long *arr, long *temp, int lb, int ub);
static void mergeasc(long * arr, long * temp, int lb, int mid, int ub);
static void mergedec(long * arr, long * temp, int lb, int mid, int ub);

//quick sort
void Quick_Sort(long *Array, int Size){
    if (Array == NULL)
        return;
    //quicksort(Array, 0, Size-1);
    quicks(Array, 0, Size-1);
    //insertion(Array, 0, Size - 1);
}

static void quicks(long * arr, int lb, int ub){
  while (ub > lb){
    int index = partition(arr, lb, ub);
    //int index = (rand() % (ub - lb + 1)) + lb;
    if (index < (lb+ub)/2){
      quicks(arr, lb, index-1);
      lb = index+1;
    }
    else{
      quicks(arr, index+1, ub);
      ub = index-1;
    }
  }
}
/*
static void insertion(long * arr, int lb, int ub) {
  long temp;
  for (int c = lb; c <= ub; c++){
   for (int d = c; d > lb && arr[d-1] > arr[d]; d--){
     temp = arr[d];
     arr[d] = arr[d-1];
     arr[d-1] = temp;
   }
 }
}
static void quicksort(long *arr, int lb, int ub){
    if (lb >= ub)
        return;

    int index = partition(arr, lb, ub);
    quicksort(arr, lb, index-1);
    quicksort(arr, index+1, ub);
}
*/
static int partition(long * arr, int lb, int ub){
    int index = (rand() % (ub - lb + 1)) + lb;
    long pivot = arr[index];
    arr[index] = arr[lb];
    arr[lb] = pivot;
    int down = lb;
    int up = ub;
    long temp; //swap value
    
    while (down < up){
        while (arr[down] <= pivot && down < ub)
            down += 1;
        while (arr[up] > pivot)
            up -= 1;
        if (down < up){ //sway value
            temp = arr[down];
            arr[down] = arr[up];
            arr[up] = temp;
        }
    }
    arr[lb] = arr[up];
    arr[up] = pivot;
    return up;
}
/*
static void medianofthree(long *arr, int lb, int ub){
    long a = arr[lb];
    long b = arr[(ub+lb)/2];
    long c = arr[ub];
    
    int median; //median
    if (a<b){
        if (b<c)
            median = (ub+lb)/2;
        else if (a<c)
            median = ub;
        else   
            median = lb;
    }
    else if (c<b)
        median = (ub+lb)/2;
    else if (c<a)
        median = ub;
    else 
        median = lb;
    
    arr[lb] = arr[median];
    arr[median] = a;
}

static int partition1(long * arr, int lb, int ub){
    //medianofthree(arr, lb, ub);
    int index = (rand() % (ub - lb + 1)) + lb;
    long pivot = arr[index];
    arr[index] = arr[ub];
    arr[ub] = pivot;
    long temp;
    int i = lb -1;
    for (int j = lb; j < ub; j++){
      if (arr[j] <= pivot){
	i++;
	temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    
    temp = arr[i+1];
    arr[i+1] = arr[ub];
    arr[ub] = temp;
  
    return i+1;
}
*/

//merge sort 
void Merge_Sort(long *Array, int Size){
    if (Array == NULL)
        return;
    long * temp = malloc(sizeof(long) * Size);
    memcpy(temp, Array, sizeof(long) * Size);
    mergeasc_sort(Array, temp, 0, Size-1);
    
    free(temp);
}

static void mergeasc_sort(long *arr, long *temp, int lb, int ub){
    if (lb >= ub)
        return;
    int mb = (lb+ub)/2;
    mergeasc_sort(temp, arr, lb, mb);
    mergedec_sort(temp, arr, mb+1, ub);

    //memcpy(&temp[lb], &arr[lb], sizeof(long)*(ub-lb+1)); //how to delete this?
    mergeasc(arr, temp, lb, mb, ub);
}

static void mergedec_sort(long *arr, long *temp, int lb, int ub){
    if (lb >= ub)
        return;
    int mb = (lb+ub)/2;
    mergeasc_sort(temp, arr, lb, mb);
    mergedec_sort(temp, arr, mb+1, ub);
    
    //memcpy(&temp[lb], &arr[lb], sizeof(long)*(ub-lb+1));
    mergedec(arr, temp, lb, mb, ub);   
}

static void mergeasc(long * arr, long * temp, int lb, int mid, int ub){
    int i = lb;
    int j = ub;
    for (int k = lb; k <= ub; k++){
        if (temp[j]<temp[i])
            arr[k] = temp[j--];
        else
            arr[k] = temp[i++];
    }
}

static void mergedec(long * arr, long * temp, int lb, int mid, int ub){
    int i = lb;
    int j = ub;
    for (int k = ub; k >= lb; k--){
        if (temp[j]<temp[i])
            arr[k] = temp[j--];
        else 
            arr[k] = temp[i++];
    }
}