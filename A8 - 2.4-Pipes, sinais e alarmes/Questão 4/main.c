#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void){
    pid_t pid_pai = getpid();
    pid_t pid_filho;
    int i,j;
    int fd[2];
    int lido = 0;
    
    pipe(fd);
    pid_filho = fork();
    if(pid_filho == 0){
        while (lido < 10)
        {
            read(fd[0],&lido, sizeof(lido));
            printf("%d\n",lido);
        }
            
        
    }
    else{
        for ( i = 1; i < 11; i++)
        {
            write(fd[1],&i,sizeof(i));
            sleep(1);
            
        }
        sleep(1);
    }

    return 0;
}