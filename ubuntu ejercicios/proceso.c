#include <unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include<stdlib.h>

int main(){
	int *valor=malloc(sizeof(int));
	*valor=0;
   printf("**Proc. PID=%d, valor=%d  comienza**\n", getpid(),*valor);
//creacion de proceso
			fork();
    
    *valor=13;
	printf("**Proc. PID=%d, valor=%d **\n", getpid(),*valor);
	free(valor);
		return 0;
}

