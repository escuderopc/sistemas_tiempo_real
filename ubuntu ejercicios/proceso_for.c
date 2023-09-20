#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main (void) {
int i = 1, n = 4;
pid_t childpid;
printf("**Proc. PID=%d comienza **\n",getpid()); 
for (i = 1; i < n; i++) {
childpid = fork();
if (childpid > 0) { //Código del padre.
break;
 }}


 // ¿PID == 1?
printf("Proceso %d con padre %d\n", getpid(), getppid());

pause();

return 0;
}
