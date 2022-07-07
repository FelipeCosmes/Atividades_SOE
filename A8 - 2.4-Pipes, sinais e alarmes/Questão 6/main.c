#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

int fim_espera=0;

void tratamento_SIGUSR1()
{
	fim_espera=1;
}

int main(void){
    pid_t pid_pai = getpid();
    pid_t pid_filho[2];
    int i,j;
    int fd[2],fp[2];
    char msg_in[100],msg_out[100];
    signal(SIGUSR1, tratamento_SIGUSR1);
    
    pipe(fd);
    pipe(fp);
    pid_filho[0] = fork();
    if(getpid() == pid_pai){
        pid_filho[1] = fork();
    }
    if(pid_filho[0] == 0){ 
        strcpy(msg_out,"FILHO1: Quando o vento passa, é a bandeira que se move.");
        write(fd[1],msg_out,100);
        fim_espera = 0;
        while(fim_espera == 0);
        read(fd[0],msg_in,100);
        printf("%s\n",msg_in);
    }
    else if (pid_filho[1] == 0)
    {
        strcpy(msg_out,"FILHO2: Não, é o vento que se move.");
        write(fp[1],msg_out,100);
    }
    else if (getpid() == pid_pai){ 
        read(fd[0],msg_in,100);
        printf("%s\n",msg_in);
        read(fp[0],msg_in,100);
        printf("%s\n",msg_in);
        strcpy(msg_out,"PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...");
        write(fd[1],msg_out,100);
        kill(pid_filho[0],SIGUSR1);
        wait(NULL);
    }
    

    return 0;
}