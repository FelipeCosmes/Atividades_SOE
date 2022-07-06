#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){
    char c, conteudo[150]={'\0'};
    int i=1;
    int j=0;
    int count =0;

    int fd = open(argv[2],O_RDONLY, S_IRWXU);
    read(fd,conteudo,150);
    c = conteudo[0];
    while (c != EOF)
    {        
        if (c == argv[1][j]){
            if (j == ((int) strlen(argv[1])) - 1)
            {
                count += 1;
                j = 0;
            } else {
                j += 1;    
            }
        } else
        {
            j = 0;
        }
        c = conteudo[i];
        i+=1;
    }
    
    printf("'%s' ocorre %d vezes no arquivo '%s'.\n", argv[1], count, argv[2]);

    close(fd);

    return 0;
}