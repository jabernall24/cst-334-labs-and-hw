
/* 
 * skeleton code for a pthreads synchronization barrier
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
  // state variables
    // YOUR CODE HERE
    int counter;
    int total;

  // sync variables
    // YOUR CODE HERE
    pthread_mutex_t lock;
    pthread_cond_t cv;

} BARR;

BARR *barr_create(int num_t) {
  BARR *barr;
  barr = malloc(sizeof(BARR));
  assert(barr != NULL);
 
  // YOUR CODE HERE
    barr->counter = 0;
    barr->total = num_t;
    pthread_mutex_init(&barr->lock, NULL);
    pthread_cond_init(&barr->cv, NULL);
    
  return(barr);
}

void check_in(BARR *barr) {
  // YOUR CODE HERE
    pthread_mutex_lock(&barr->lock);
    barr->counter++;
    
    while(barr->counter != barr->total) {
        pthread_cond_wait(&barr->cv, &barr->lock);
    }
    pthread_cond_signal(&barr->cv);
    
    pthread_mutex_unlock(&barr->lock);
} 

// actor: prints something, waits for everyone, prints something else
void *actor(void *arg) {
  BARR *barr = (BARR *)arg;
  printf("before barrier\n");
  check_in(barr);
  printf("after barrier\n");

  pthread_exit(NULL);
}

// test the barrier
int main(int argc, char *argv[]) {
  int n = 10;
  pthread_t actors[n];

  BARR *barr = barr_create(n);

  // create some actors
  int i;
  for (i = 0; i < n; i++) {
    pthread_create(&actors[i], NULL, actor, (void *)barr);
  }

  pthread_exit(NULL);
}
