#include <pthread.h>
#include <stdio.h>

struct parametri {
  char carattere;
  int count;
};

void* stampa(void* p) {
  struct parametri* param = p;
  for (int i = 0; i < param->count; ++i)
    fputc(param->carattere, stderr);
  return NULL;
}

int main() {
  pthread_t t1, t2;
  struct parametri p1 = {'x', 30000}, p2 = {'o', 20000};

  pthread_create(&t1, NULL, stampa, &p1);
  pthread_create(&t2, NULL, stampa, &p2);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  return 0;
}