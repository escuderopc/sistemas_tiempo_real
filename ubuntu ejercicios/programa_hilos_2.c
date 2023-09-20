//Nota: utilice  -pthread para compilar 
//gcc  thread_simple.c -o thread_simple -lpthread
//******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


char valor[5];

void *holaMundo();
void *adiosMundo();
int main()
{
   
  pthread_t hilo, hilo2;
 
  pthread_create(&hilo, NULL, holaMundo, NULL);
  pthread_create(&hilo2, NULL, adiosMundo, NULL);
  
  pthread_join(hilo,NULL);
  pthread_join(hilo2,NULL);
 // printf("Hilo principal: terminado\n\n");
   pthread_exit(NULL);
}

// Funcion cuya tarea es mostrar en consola un mensaje
void *holaMundo()
{
wait(sem);
	valor[0]='h';
	valor[1]='o';
	valor[2]='l';
	valor[3]='a';
//	printf("Hilo 1 creado\n");
	for(int i=0;i<5;i++)
	{
		printf("%c", valor[i]);
	}
   	printf("\n");
   pthread_exit(NULL);
   signal(sem);
}

void *adiosMundo()
{
   	valor[0]='A';
	valor[1]='d';
	valor[2]='i';
	valor[3]='o';
	valor[4]='s';
	//printf("Hilo 2 creado\n");
	for(int i=0;i<5;i++)
	{
		printf("%c", valor[i]);
	}
   printf("\n");
   pthread_exit(NULL);
}

