#include <malloc.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

struct lavoro {
  struct lavoro* next; 
  char *messaggio;
};

struct lavoro* coda_lavori;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t coda_count;

void* funzione_thread(void* arg) {
  while (1) {
    sem_wait(&coda_count);
    pthread_mutex_lock(&mutex);
    struct lavoro* lavoro = coda_lavori;
    coda_lavori = coda_lavori->next;
    pthread_mutex_unlock(&mutex);
    printf("Thread %ld ha completato %s\n", pthread_self(), lavoro->messaggio);
    free(lavoro);
  }
  return NULL;
}

void aggiungi_lavoro(char* messaggio) {
  struct lavoro* nuovo = (struct lavoro*) malloc(sizeof(struct lavoro));
  nuovo->messaggio = messaggio;
  pthread_mutex_lock(&mutex);
  nuovo->next = coda_lavori;
  coda_lavori = nuovo;
  sem_post(&coda_count);
  pthread_mutex_unlock(&mutex);
}

int main(void) {
  sem_init(&coda_count, 0, 0);

  aggiungi_lavoro("1");
  aggiungi_lavoro("2");
  aggiungi_lavoro("3");
  aggiungi_lavoro("4");

  pthread_t t1, t2;
  pthread_create(&t1, NULL, funzione_thread, NULL);
  pthread_create(&t2, NULL, funzione_thread, NULL);

  sleep(60);

  aggiungi_lavoro("5");
  aggiungi_lavoro("6");
  aggiungi_lavoro("7");
  aggiungi_lavoro("8");

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  
  return 0;
}