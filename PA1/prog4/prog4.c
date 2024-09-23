#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

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
    struct rusage usage;
    struct timeval;
    int i, j, k = 0;

    // Get resource usage before the execution
    // Get resource usage before the execution
    getrusage(RUSAGE_SELF, &usage);
    long start = usage.ru_nivcsw;   // Starting voluntary context switches

    int *p;
    printf("Executing the code ......\n");
    allocate();

    for (i = 0; i < 10000; i++) {
        p = malloc(1000 * sizeof(int));
        free(p);
    }

    // Get resource usage after the execution
    getrusage(RUSAGE_SELF, &usage);
    long end = usage.ru_nivcsw;   // Ending voluntary context switches

    long total_voluntary_context_switches = end - start;
    printf("start voluntary context switches: %ld\n", start);
    printf("end voluntary context switches: %ld\n", end);
    printf("Program execution successful\n");

    return 0;
}