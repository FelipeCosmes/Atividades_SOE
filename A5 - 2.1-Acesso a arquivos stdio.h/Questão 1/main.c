#include <stdio.h>
#include <stdlib.h>

int main(){
    char string[100] = "Ola mundo!";
    FILE *fp;
    fp = fopen("ola_mundo.txt","w");
    fputs(string,fp);
    fputc('\n',fp);
    fclose(fp);

    return 0;
}