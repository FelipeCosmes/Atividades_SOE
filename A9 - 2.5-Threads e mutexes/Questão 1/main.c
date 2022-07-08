#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

void* funcao (void* arg){
    int *valor = (int *) arg;
    printf("%d\n", *valor);

    return NULL;
}

int main(void){
    pthread_t thread1_id;
    int i;
    for ( i = 1; i < 11; i++)
    {
        pthread_create(&thread1_id, NULL,funcao,&i);
        sleep(1);
    }
    sleep(1);

    return 0;
}