#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct parametri {
  int da, a;
  float dollari;
};

float* saldi;

void* transazione(void* args) {
  struct parametri* p = args;
  if (saldi[p->da] < p->dollari) return (void*) 1;
  saldi[p->a] += p->dollari;
  saldi[p->da] -= p->dollari;
  return NULL;
}

int main() {
  pthread_t t;
  struct parametri p = {0, 5, 9};
  saldi = (float*)malloc(10 * sizeof(float));

  // Inizializzazione saldi
  float valori[10] = {100, 67, 78, 10, 93, 1, 46, 90, 34, 13};
  for (int i = 0; i < 10; i++) saldi[i] = valori[i];

  for (int i = 0; i < 10; i++) printf("[%d] %.1f$\n", i, saldi[i]);

  pthread_create(&t, NULL, transazione, &p);
  pthread_join(t, NULL);

  printf("\n");
  for (int i = 0; i < 10; i++) printf("[%d] %.1f$\n", i, saldi[i]);

  free(saldi);
  return 0;
}