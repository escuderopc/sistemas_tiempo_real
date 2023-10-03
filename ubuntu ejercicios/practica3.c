#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Declaración de variables globales
int variable = 1;
sem_t sem;

// Función para incrementar la variable
void* incrementar(void* arg) {
    for (int i = 0; i < 10; i++) {
        // Bloquea el semáforo para que el otro hilo no pueda decrementar
        sem_wait(&sem);
        variable++;
        printf("Hilo de incremento: %d\n", variable);
        // Libera el semáforo para permitir que el otro hilo de decrecimiento pueda actuar
        sem_post(&sem);
    }
    pthread_exit(NULL);
}

// Función para decrementar la variable
void* decrementar(void* arg) {
    for (int i = 0; i < 9; i++) {
        // Bloquea el semáforo para que el hilo de incremento no pueda incrementar
        sem_wait(&sem);
        variable--;
        printf("Hilo de decremento: %d\n", variable);
        // Libera el semáforo para permitir que el otro hilo de incremento pueda actuar
        sem_post(&sem);
    }
    pthread_exit(NULL);
}

int main() {
    // Inicializa el semáforo
    sem_init(&sem, 0, 1);

    // Crea los hilos
    pthread_t hilo_incremento, hilo_decremento;

    // Crea el hilo de incremento
    pthread_create(&hilo_incremento, NULL, incrementar, NULL);
    // Crea el hilo de decremento
    pthread_create(&hilo_decremento, NULL, decrementar, NULL);

    // Espera a que los hilos terminen
    pthread_join(hilo_incremento, NULL);
    pthread_join(hilo_decremento, NULL);

    // Destruye el semáforo
    sem_destroy(&sem);

    return 0;
}