#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}

int main(void){
    pid_t pid_pai = getpid();
    pid_t pid_filho[3];
    int i;

    for ( i = 0; i < 3; i++)
    {
        if (getpid()==pid_pai)
        {
            pid_filho[i] = fork();
            if(pid_filho[i]==0){
                Incrementa_Variavel_Global(getpid());
            }
            else{
            wait(NULL);
            }
        }
    }
    
    return 0;
}