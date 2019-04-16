#include <stdio.h>
#include <pthread.h>
#include "mythreads.h"
 
static volatile int counter = 0;
pthread_mutex_t *lock;

void *mythread(void *arg) {
   printf("%s: begin\n", (char *) arg);
   int i;
   for (i = 0; i < 1e7; i++) {
       Pthread_mutex_lock(&lock);
      counter = counter + 1;
       Pthread_mutex_unlock(&lock);
   }
   printf("%s: done\n", (char *) arg);
   return NULL;
}

int main(int argc, char *argv[]) {
    Pthread_mutex_init(&lock, NULL);
   pthread_t p1, p2, p3, p4;
   printf("main: begin (counter = %d)\n", counter);
   Pthread_create(&p1, NULL, mythread, "A");
   Pthread_create(&p2, NULL, mythread, "B");
    Pthread_create(&p3, NULL, mythread, "C");
    Pthread_create(&p4, NULL, mythread, "D");

   // join waits for the threads to finish
   Pthread_join(p1, NULL);
   Pthread_join(p2, NULL);
    Pthread_join(p3, NULL);
    Pthread_join(p4, NULL);
   printf("main: done with both (counter = %d)\n", counter);
   return 0;
}

