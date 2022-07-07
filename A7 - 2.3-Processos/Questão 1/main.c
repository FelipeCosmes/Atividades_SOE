#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv){
    pid_t pid_filho[3];
    pid_t pid_pai = getpid();
    int i;

    printf("PID do pai: %d \n \n",pid_pai);

    for ( i = 0; i < 3; i++)
    {
        if (getpid()==pid_pai)
        {
            pid_filho[i] = fork();
            printf("PID do pai: %d \nPID do filho: %d\n", getpid(), pid_filho[i]);
        }
        
        
    }
    
}