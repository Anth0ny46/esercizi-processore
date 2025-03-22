#include <stdio.h>
#include <malloc.h>
#include <pthread.h>

void* allocare_buffer(size_t dim) {
  return malloc(dim);
}

void deallocare_buffer(void* buf) {
  free(buf);
}

void* fare_lavoro() {
  void* buf = allocare_buffer(1024);
  pthread_cleanup_push(deallocare_buffer, buf);
  pthread_exit(0);
  pthread_cleanup_pop(1);
  return NULL;
}

int main() {
  pthread_t t;
  pthread_create(&t, NULL, fare_lavoro, NULL);
  pthread_join(t, NULL);
  return 0;
}