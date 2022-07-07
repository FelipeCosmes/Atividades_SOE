#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void){
    pid_t pid_pai = getpid();
    pid_t pid_filho;
    int i,j;
    int fd[2],fp[2];
    char msg_in[100],msg_out[100];
    
    pipe(fd);
    pipe(fp);
    pid_filho = fork();
    if(pid_filho == 0){ 
        strcpy(msg_out,"FILHO: Pai, qual é a verdadeira essência da sabedoria?");
        write(fd[1],msg_out,100);
        read(fp[0],msg_in,100);
        printf("%s\n",msg_in);
        strcpy(msg_out, "FILHO: Mas até uma criança de três anos sabe disso!");
        write(fd[1],msg_out,100);
        read(fp[0],msg_in,100);
        printf("%s\n",msg_in);
        
    }
    else{ 
        read(fd[0],msg_in,100);
        printf("%s\n",msg_in);
        strcpy(msg_out,"PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.");
        write(fp[1],msg_out,100);
        read(fd[0],msg_in,100);
        printf("%s\n",msg_in);
        strcpy(msg_out,"PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...");
        write(fp[1],msg_out,100);
        wait(NULL);
    }

    return 0;
}