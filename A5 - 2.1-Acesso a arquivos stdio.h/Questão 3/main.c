#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    char nome_do_arquivo[100] = "";
    FILE *fp;

    fp = fopen(strcat(strcat(nome_do_arquivo,argv[1]),".txt"),"w");
    fprintf(fp,"Nome: %s\nIdade: %s anos",argv[1],argv[2]);
    fputc('\n',fp);
    fclose(fp);

    return 0;
}