#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "check.h"

int x[5] = {1,2,3,4,5};

void allocate()
{
    int i;
    int *p;
    for (i = 1; i < 1000000; i++)
    {
        p = malloc(500 * sizeof(int));
        if (p == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        free(p);  // makes sure that the free is always activated
    }
}



void allocate1()
{
    int i;
    int *p;
    for (i = 1; i < 10000; i++)
    {
        p = malloc(1000 * sizeof(int));
        if (p == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        free(p);  // makes sure that the free is always activated
    }
}



void allocate2()
{
  int i;
  int *p;
  for (i=1 ; i<300000 ; i++)
  {
    p = malloc(10000 * sizeof(int));
    free (p);
  }
}


int main(int argc, char const *argv[]) {
  int i;
  int *p;
  printf("Executing the code ......\n");
  allocate();

  for (i=0 ; i<10000 ; i++)
  {
    p = malloc(1000 * sizeof(int));
    free (p);
  }
  printf("Program execution successfull\n");
  return 0;
}
