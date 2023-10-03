#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int var = 20;  
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;  
int turno = 1;  

void *incrementThread(void *arg) {
    for (int i = 0; i < 10; ++i) {
        pthread_mutex_lock(&mutex);
        while (turno != 1) {
            pthread_cond_wait(&condition, &mutex);
        }
        var += 10;
        printf("Primer hilo esta incrementando en: %d\n", var);
        turno = 2;
        pthread_cond_signal(&condition);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *decrementThread(void *arg) {
    for (int i = 0; i < 10; ++i) {
        pthread_mutex_lock(&mutex);
        while (turno != 2) {
            pthread_cond_wait(&condition, &mutex);
        }
        var -= 5;
        printf("Segundo hilo esta decrementando en: %d\n", var);
        turno = 1;
        pthread_cond_signal(&condition);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t incrementThreadID, decrementThreadID;

    // Crear hilos
    if (pthread_create(&incrementThreadID, NULL, incrementThread, NULL) != 0) {
        perror("Error al crear el hilo de incremento");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&decrementThreadID, NULL, decrementThread, NULL) != 0) {
        perror("Error al crear el hilo de decremento");
        exit(EXIT_FAILURE);
    }

    // Esperar a que los hilos terminen
    pthread_join(incrementThreadID, NULL);
    pthread_join(decrementThreadID, NULL);

    return 0;
}
