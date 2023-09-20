#include <unistd.h>
#include<stdio.h>
#include <sys/types.h>
//using namespace std;
int var=22; //varaible global
int main(){
	pid_t id; //Se crea una variable que guarda un valor con signo
	
	printf("**Proc. PID=%d comienza **\n",getpid()); //Mandamos a imprimir el identificador del proceso
	
	id=	fork(); // creamos un proceso
	
//	printf("proc. PID=%d, id=%d ejecutandose \n", getpid(), id);

	if(id==0)
	{
		//proceso hijo decrementar
	  var=12;
	}
	else if(id>0)
	{
		//proceso padre
		 var=50;
		// printf("Hola");
	}
	else
	{
		printf("Proceso no creado");
	}
	
	while(1)
	{
		sleep(2); //dormir el proceso por 2 segundos
		printf("proc. PID=%d, var=%d ejecutandose \n", getpid(), var);
		
	}
	return 0;
}
