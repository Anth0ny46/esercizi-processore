#include <pthread.h>
#include <stdio.h>

void* calcola_primo(void* arg) {
  int candidato = 2, n = *((int*) arg);

  while (1) {
    int primo = 1;
    for (int i = 2; i < candidato; ++i)
      if (candidato % i == 0) {
        primo = 0;
        break;
      }
    if (primo && --n == 0)
      return (void*) candidato;
    ++candidato;
  }
  return NULL;
}

int main() {
  pthread_t t;
  int n = 5000, primo;

  pthread_create(&t, NULL, calcola_primo, &n);
  pthread_join(t, (void*)&primo);

  printf("Il %d° primo è %d.\n", n, primo);
  return 0;
}