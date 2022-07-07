#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv){
    int i;
    pid_t pid_pai = getpid();
    pid_t pid_filho;
    char *argumentos[] = {NULL, NULL};

    for ( i = 1; i < argc; i++)
    {
        pid_filho = fork();
        if (pid_filho==0)
        {
            argumentos[0] = argv[i];
            execvp(argumentos[0], argumentos);
        }
        else{
            wait(NULL);
        }
        
    }
    
    return 0;
}