// ***
// *** You MUST modify this file, only the ssort function
// ***

#include "sort.h"
#include <stdio.h>
#include <stdbool.h>

static bool checkOrder(int * arr, int size)
// a static function is visible only in this file
// This function returns true if the array elements are
// in the ascending order.
// false, otherwise
{
  int ind;
  for (ind = 0; ind < (size - 1); ind ++)
    {
      if (arr[ind] > arr[ind + 1])
	{
	  return false;
	}
    }
  return true;
}

#ifdef TEST_SORT

static void swap(int * a, int * b)
{
  int m = * a;
  * a = * b;
  * b = m;
}

void ssort(int * arr, int size)
{
  // This function has two levels of for
  // The first level specifies which element in the array
  // The second level finds the smallest element among the unsorted
  // elements
  int num1;
  int num2;
  for (num1 = 0; num1 < size - 1; num1++)
  {
    int mini = num1;
    for (num2 = num1 + 1; num2 < size; num2++)
    {
      if (arr[mini] > arr[num2])
        mini = num2; // find the smallest element
    }

  // After finding the smallest element among the unsorted elements,
  // swap it with the element of the index from the first level
      if (mini != num1)
        swap(&arr[num1],&arr[mini]);
  }

  // call checkOrder to see whether this function correctly sorts the
  // elements
  if (checkOrder(arr, size) == false)
    {
      fprintf(stderr, "checkOrder returns false\n");
    }
}
#endif
