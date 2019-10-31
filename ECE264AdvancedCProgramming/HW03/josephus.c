// ***
// *** You MUST modify this file
// ***

#include "josephus.h"
#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_JOSEPHUS
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails,
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements
  int i;
  int a = 1;
  int number = 0;
  int count = 1;
  int getout = 0;

  for (i = 0; i < n; i++)
    arr[i] = 0;

  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked
  while (getout < n - 1)
  {
    while ((arr[number] != 'x' && number < n) && count < k + 1)
      arr[number++] = count++;
    if (count == k + 1)
    {
      printf("%d\n", number - 1);
      arr[number - 1] = 'x';
      count = 1;
      ++getout;
    }
   else if (arr[number] == 'x')
     number++;

   if (number == n)
     number = 0;
  }

  // print the last number
  for (i = 0; i < n && a; i++)
  {
    if (arr[i] != 'x')
    {
      printf("%d\n", i);
      a = 0;
    }
  }

  // release the memory of the array
  free (arr);
}
#endif
