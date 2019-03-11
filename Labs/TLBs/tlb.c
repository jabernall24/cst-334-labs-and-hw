#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

/*
 * TLB timing tests
 */

#define PAGESIZE 4096
#define NUMPAGES_DEF 10
#define NUMTRIALS_DEF 1000000

int main(int argc, char *argv[]) {
   long int num_pages = NUMPAGES_DEF;
   long int num_trials = NUMTRIALS_DEF;

   /* process command-line args */
   if (argc > 3) {
     fprintf(stderr, "tlb: usage: tlb [num_pages] [num_trials]\n");
     exit(EXIT_FAILURE);
   }
   if (argc > 1) {
     num_pages = strtol(argv[1], NULL, 10);
   }
   if (argc > 2) {
     num_trials = strtol(argv[2], NULL, 10);
   }

   printf("num_pages %d\nnum_trials %d\n", num_pages, num_trials);

   /* run the program on a single CPU 0 */
   cpu_set_t cpuset;
   CPU_ZERO(&cpuset);
   CPU_SET(0, &cpuset);
   pthread_t thread = pthread_self();
   int s = pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);
   if (s != 0) {
      fprintf(stderr, "pthread error\n");
      exit(EXIT_FAILURE);
   }

   /* run the trials */
   int i, j;
   int jump = PAGESIZE/sizeof(int);
   int a[jump*num_pages];
   for (i = 0; i < num_pages * jump; i ++) {
      a[i] = 0;
   }

   struct timeval start, end;
   gettimeofday(&start, NULL);
   for (j = 0; j < num_trials; j++) {
      for (i = 0; i < num_pages * jump; i += jump) {
   	 a[i]++;
      }
   }
   gettimeofday(&end, NULL);

   /* this is to avoid compiler optimizations to the preceding loop */
   long int sum = 0;
   for (i = 0; i < num_pages * jump; i++) {
      sum += a[i];
   } 

   /* compute result, in nanoseconds per access */
   long int elapsed_time = (end.tv_sec * 1000000 + end.tv_usec)
		         - (start.tv_sec * 1000000 + start.tv_usec);
   float time_per_access = (1000.0 * elapsed_time)/(num_trials * num_pages);
   printf("%4.2f\n", time_per_access);

   return 0;
}


