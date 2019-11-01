#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqpair.h"

int main (int argc, char **argv){
  if (argc > 3)
    return EXIT_FAILURE;
  
  FILE * input = fopen(argv[1], "r");
  if (input == NULL)
    return EXIT_FAILURE;
  FILE * output = fopen(argv[2], "w");
  if (output == NULL)
    return EXIT_FAILURE;

  int number; //the number of rectanlges to pack
  if (!fscanf(input, "%d\n", &number))
    printf("ERROR\n");
  if (!number){
    fclose(input);
    fclose(output);
    return EXIT_SUCCESS; //empty file
  }

  //Graph *arr = malloc(sizeof(Graph)*(number+2));
  Graph *arr = malloc(sizeof(Graph)*(number+1));
  if (arr == NULL)
    return EXIT_FAILURE;
  arr[0].width = arr[0].height = arr[0].S1 = arr[0].S2 = 0; //Sourse
  arr[0].hcg = arr[0].vcg = NULL;

  //dimensions of the rectangles
  int pair;
  for (int dimension = 1; dimension <= number; dimension++){
    if (!fscanf(input, "%d(%le,%le)\n", &pair, &arr[dimension].width, &arr[dimension].height))
      printf("ERROR\n"); //label is the same as dimension
    arr[dimension].hcg = arr[dimension].vcg = NULL;
    arr[dimension].newhei = arr[dimension].newwid = 0;
    arr[dimension].colorh = arr[dimension].colorv = WHITE;
  }

  //sequence pair
  int sequence;
  for (sequence = 1; sequence < number; sequence ++){
    if (!fscanf(input, "%d ", &pair))
        printf("ERROR\n");
    arr[pair].S1 = sequence; //index
  }
  if (!fscanf(input, "%d\n", &pair))
      printf("ERROR\n");
  arr[pair].S1 = sequence; //index

  for (sequence = 1; sequence < number; sequence ++){
    if (!fscanf(input, "%d ", &pair))
        printf("ERROR\n");
    arr[pair].S2 = sequence; //index
  }
  if (!fscanf(input, "%d\n", &pair))
      printf("ERROR\n");
  arr[pair].S2 = sequence; //index

  generatelist(arr, number);
  int *sortarryh = malloc(sizeof(int*)*number);
  if (sortarryh == NULL)
    printf("ERROR\n");
  
  int *sortarryv = malloc(sizeof(int*)*number);
  if (sortarryv == NULL)
    printf("ERROR\n");
  
  DFS(arr, sortarryh, sortarryv, number);
  tolosort(arr, number, sortarryh, sortarryv);
  printoutput(arr, number, output);

  destroy(arr, number);
  free(sortarryh);
  free(sortarryv);
  free(arr);
  fclose(input);
  fclose(output);
}

void printoutput(Graph * arr, int number, FILE * output){
  int index;
  for (index = 1; index <= number; index++)
    fprintf(output, "%d(%le,%le)\n", index, arr[index].newwid, arr[index].newhei);
}

void destroy(Graph * arr, int number){
  for (int index = 0; index <= number; index++){
    destroylist(arr[index].hcg);
    destroylist(arr[index].vcg);
  }
}

void destroylist(ListNode * list){
  ListNode * tmp;
  while (list != NULL){
    tmp = list;
    list = list->next;
    free(tmp);
  }
}