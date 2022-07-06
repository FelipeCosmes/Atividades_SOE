#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){
    char str[100] = "Ola mundo!";
    int i;

    int fd = open("ola_mundo.txt",O_WRONLY | O_CREAT, S_IRWXU);
    for ( i = 0; str[i] != '\0'; i++)
    {
        write(fd,&(str[i]),1);
    }
    write(fd,"\n",1);
    close(fd);
    
    return 0;
}