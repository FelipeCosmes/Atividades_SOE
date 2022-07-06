#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){
char nome[100],nome_do_arquivo[100],conteudo[150]={'\0'};
int idade;
int i;

printf("Digite o seu nome: ");
gets(nome);
printf("Digite a sua idade: ");
scanf("%d",&idade);

int fd = open(strcat(strcat(nome_do_arquivo,nome),".txt"),O_WRONLY | O_CREAT, S_IRWXU);
sprintf(conteudo,"Nome: %s\nIdade: %d anos\n",nome,idade);
write(fd,conteudo,150);
close(fd);
return 0;
}
