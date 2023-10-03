#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t id;
    int var = 20;  // Valor inicial para el proceso padre

    for (int i = 0; i < 10; ++i) {
        id = fork();

        if (id == 0) {
            // Proceso hijo
            var -= 5;
            printf("Soy el proceso hijo: PID=%d, var=%d del padre: PID=%d\n", getpid(), var, getppid());
            exit(EXIT_SUCCESS);
        } else if (id > 0) {
            // Proceso padre
            var += 5;
            printf("Hola, soy el proceso padre: PID=%d, var=%d\n", getpid(), var);
            wait(NULL);  // Esperar a que el proceso hijo termine
        } else {
            printf("\nProceso no creado\n");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
