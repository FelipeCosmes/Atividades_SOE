#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){
    char nome_do_arquivo[100] = "";
    char conteudo[150]={'\0'};

    int fd = open(strcat(strcat(nome_do_arquivo,argv[1]),".txt"),O_WRONLY | O_CREAT,S_IRWXU);
    sprintf(conteudo,"Nome: %s\nIdade: %s anos\n",argv[1],argv[2]);
    write(fd,conteudo,150);
    close(fd);

    return 0;
}