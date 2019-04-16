
/* 
 * reading and writing to a simple single cell buffer
 * Readers must wait until the buffer is non-empty.
 * Writers must wait until the buffer is empty.
 * A simple condition variable problem.
 * 
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// state variables
int buf;        // value in buffer
int count = 0;  // number of things in buffer (0 or 1)
// sync variables
pthread_mutex_t lock;
pthread_cond_t read_go;
pthread_cond_t write_go;

void *reader(void *arg) {
  int i;
  int val;
  for (i = 0; i < 100; i++) {
    
    // your code here

    // read/write shared state
      pthread_mutex_lock(&lock);
      while(count != 1){
          pthread_cond_wait(&read_go, &lock);
      }
      count = 0;
      val = buf;

      pthread_cond_signal(&write_go);
      pthread_mutex_unlock(&lock);

    

    // your code here

  } 
}

void *writer(void *arg) {
  int i;
  for (i = 0; i < 100; i++) {
     
    // your code here
    
    // read/write shared state
      pthread_mutex_lock(&lock);
      while(count != 0){
          pthread_cond_wait(&write_go, &lock);
      }
      count = 1;
      buf = i;
      
      pthread_cond_signal(&read_go);
      pthread_mutex_unlock(&lock);


    // your code here

  } 
}

// run reader and writer
int main(int argc, char *argv[]) {
  pthread_t p1, p2;

  pthread_mutex_init(&lock, NULL);
  pthread_cond_init(&read_go, NULL);
  pthread_cond_init(&write_go, NULL);

  int rc; 
  rc = pthread_create(&p1, NULL, reader, NULL);
  if (rc) {
    printf("ERROR: return code from pthread_create() is %d\n", rc);
    exit(-1);
  }
  rc = pthread_create(&p2, NULL, writer, NULL);
  if (rc) {
    printf("ERROR: return code from pthread_create() is %d\n", rc);
    exit(-1);
  }
  pthread_join(p1, NULL);
  pthread_join(p2, NULL);
    printf("done\n");
}
