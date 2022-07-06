#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
char nome[100];
char nome_do_arquivo[100] = "";
int idade;
FILE *fp;

printf("Digite seu nome: ");
gets(nome);
printf("Digite sua idade: ");
scanf("%d", &idade);
fp = fopen(strcat(strcat(nome_do_arquivo,nome),".txt"),"w");
fprintf(fp,"Nome: %s\nIdade: %d",nome,idade);
fputc('\n',fp);
fclose(fp);

return 0;
}