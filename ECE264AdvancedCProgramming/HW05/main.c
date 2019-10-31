// ***
// *** Please modify this file, as indicated
// ***

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "sort.h"


void printArray(int * arr, int size)
{
  int ind;
  for (ind = 0; ind < size; ind ++)
    {
      fprintf(stdout, "%d\n", arr[ind]);
    }
}



//============================ONLY EDIT BELOW THIS COMMENT============================//
#ifdef TEST_COMP
int comparator(const void *a, const void *b) 
{ 
    //type cast both the parameters to the type const int*) a: 
	//FOR EXAMPLE: const int* ia = (const int *) a;
	const int * ptra = (const void *) a;
	const int * ptrb = (const void *) b;
	
	int paraa = *ptra;
	int parab = *ptrb;
   
    	//if parameter2 > parameter1; return -1
	if (parab > paraa) { return -1;}
	
	//if parameter2 == parameter1; return 0
	if (parab == paraa) { return 0;}
	
	//if parameter2 < parameter1; return 1
	return 1;
} 
#endif


#ifdef TEST_COUNT
int countFromFile(char* file_name)
{
  // open file to read
  FILE *ffile = fopen(file_name, "r");
  
    if (ffile == NULL){
    fprintf(stderr, "need the name of input file\n");
      return EXIT_FAILURE;
    }
    
  // count the number of integers using a loop
  int value;
  int count = 0;

  while (fscanf(ffile, "%d", & value) == 1){
    count++;
  }
 
  // at the end of the loop close file_pointer
  fclose(ffile);
  
  return count;
}
#endif

#ifdef TEST_FILL
void fillArray(int* arr, int count, char* file_name)
{
  // open file to read
  FILE *fptr = fopen(file_name, "r");
  
  if (fptr == NULL){
    fprintf(stderr, "need the name of input file\n");
      return;
    }
  
  //How to read the file?
	// run a loop, from index = 0 to "count", and use: fscanf(file_pointer, "%d", &arr[index]);
	for (int index = 0; index < count; index++){
	  fscanf(fptr, "%d", &arr[index]);
	} 
	
	// at the end of the loop close file_pointer
	fclose(fptr);
	
	return;
}
#endif

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
  // input file will be specified from the terminal - test files are made available in inputs folder
  // check for missing input file, if so, "return EXIT_FAILURE;"
  if (argc != 2){
    fprintf(stderr, "need the name of input file\n");
    
    return EXIT_FAILURE;
  }
  
  // use argv[1] to save the file name, you will use this file name to call the countFromFile(), and fillArray() functions
      //FOR EXAMPLE: char* file_name = argv[1];
  char *file_name = argv[1];
  
  // call the countFromFile(file_name); and store the number of elements in the file.
  int number = countFromFile(file_name);
  
  
  // allocate memory to store the numbers (initialize an array)
  int *arr = malloc(sizeof(int) * number);


  // check for malloc fail, if so, "return EXIT_FAILURE;"
  if (arr == NULL){ // malloc fail
    fprintf(stderr, "malloc fail\n");
    return EXIT_FAILURE;
  }
  
  
  // call the fillArray(arr, count, file_name); and store the values from the file in the array.
  fillArray(arr, number, file_name);
  
  if (arr == NULL){
    return EXIT_FAILURE;
  }
  
  
  // Use qsort() function, after defining the comparator() function - "qsort (arr, count, sizeof(int), comparator);"
  qsort(arr, number, sizeof(int), comparator);
  
  
  // call the printArray() function provided to you.
  printArray(arr, number);
  free(arr);
  
  
  return EXIT_SUCCESS;
}
#endif

