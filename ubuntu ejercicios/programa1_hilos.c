//Nota: utilice  -pthread para compilar 
//gcc  thread_simple.c -o thread_simple -lpthread
//******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void *holaMundo();


int main()
{
   pthread_t hilo;
   
  pthread_create(&hilo, NULL, holaMundo, NULL);

  pthread_join(hilo,NULL);
  printf("Hilo principal: terminado\n\n");
   pthread_exit(NULL);
}

// Funcion cuya tarea es mostrar en consola un mensaje
void *holaMundo()
{
   printf("Hilo creado: ¡Hola mundo! \n");
   pthread_exit(NULL);
}


