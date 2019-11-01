#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  if(argc != 3)
  {
    printf("not enough arg\n");
    return EXIT_FAILURE;
  }

  FILE* in = fopen(argv[1], "r");
  if(in == NULL)
  {
    printf("Error opening input fille\n");
    return EXIT_FAILURE;
  }
  FILE* out = fopen(argv[2], "w");
  long temp;

  while(fread(&temp, sizeof(long), 1, in) == 1)
  {
    //fread(&delay, sizeof(double), 1, in);
    fprintf(out, "%ld\n", temp);
  }


  fclose(in);
  fclose(out);

  return EXIT_SUCCESS;
}
