#include <malloc.h>
#include <pthread.h>

struct lavoro {
  struct lavoro* prossimo;
  char *messaggio;
};

struct lavoro* coda_lavori;
pthread_mutex_t mutex_coda_lavori = PTHREAD_MUTEX_INITIALIZER;

void esegui_lavoro(struct lavoro* tmp) {
  printf("Thread %ld ha completato il lavoro %s\n", pthread_self(), tmp->messaggio);
}

void* funzione_thread(void* arg) {
  while (1) {
    pthread_mutex_lock(&mutex_coda_lavori);
    struct lavoro* prossimo_lavoro = coda_lavori;
    if (prossimo_lavoro) coda_lavori = prossimo_lavoro->prossimo;
    pthread_mutex_unlock(&mutex_coda_lavori);
    
    if (!prossimo_lavoro) break;
    esegui_lavoro(prossimo_lavoro);
    free(prossimo_lavoro);
  }
  return NULL;
}

int main(void) {
  struct lavoro *uno = malloc(sizeof(struct lavoro)), *due = malloc(sizeof(struct lavoro)), *tre = malloc(sizeof(struct lavoro));
  uno->messaggio = "1"; due->messaggio = "2"; tre->messaggio = "3";
  
  coda_lavori = malloc(sizeof(struct lavoro));
  coda_lavori->messaggio = "4"; coda_lavori->prossimo = tre;
  tre->prossimo = due; due->prossimo = uno; uno->prossimo = NULL;

  pthread_t t1, t2;
  pthread_create(&t1, NULL, funzione_thread, NULL);
  pthread_create(&t2, NULL, funzione_thread, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  return 0;
}