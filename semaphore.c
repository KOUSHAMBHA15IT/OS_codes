#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t semaphore;

void *thread_func(void *arg) {
    sem_wait(&semaphore);
    printf("Thread %ld in critical section\n", (long)arg);
    sem_post(&semaphore);
    return NULL;
}

int main() {
    sem_init(&semaphore, 0, 1);
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread_func, (void *)1);
    pthread_create(&t2, NULL, thread_func, (void *)2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&semaphore);
    return 0;
}
