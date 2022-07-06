#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    char c;
    int i=0;
    int j=0;
    int count =0;
    FILE *fp;

    fp = fopen(argv[2],"r");
    c = getc(fp);
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
        c = getc(fp);
    }
    
    printf("'%s' ocorre %d vezes no arquivo '%s'.\n", argv[1], count, argv[2]);

    fclose(fp);

    return 0;
}