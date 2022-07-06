#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    char nome[30];

    printf("Digite o seu nome: ");
    scanf("%s", nome);
    printf("Ola %s\n", nome);

    return 0;
}