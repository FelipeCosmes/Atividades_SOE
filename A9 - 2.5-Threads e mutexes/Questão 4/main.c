#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#define n 50000

double calcula_media(long int *v, int tamanho){
    int i;
    long int sum=0;
    double media=0.0;
    for ( i = 0; i < tamanho; i++)
    {
        sum +=v[i];
    }
    media += (double) sum/tamanho;

    return media;
}

struct media_thread_parms
{
    long int *v;
    int tam;
    long int v_media_thread;
};

void *media_thread(void *parms){
    struct media_thread_parms* p =(struct media_thread_parms*) parms;
    p->v_media_thread = calcula_media(p->v,p->tam);
    return NULL;
}
    
int main(){
    long int v[n];
    double media;
    pthread_t thread1,thread2,thread3,thread4;
    struct media_thread_parms media_1,media_2,media_3,media_4;

    srandom(time(NULL));
    for (size_t i = 0; i < n; i++)
    {
        v[i] = random();
    }
    media = calcula_media(v,n);
    printf("O valor médio encontrado foi de %lf\n",media);
    
//*********************************
    media_1.v = &(v[0*n/4]);
    media_1.tam = n/4;
    media_2.v = &(v[0*n/4]);
    media_2.tam = n/4;
    media_3.v = &(v[0*n/4]);
    media_3.tam = n/4;
    media_4.v = &(v[0*n/4]);
    media_4.tam = n/4;

    pthread_create(&thread1,NULL,&media_thread, &media_1);
    pthread_create(&thread2,NULL,&media_thread, &media_2);
    pthread_create(&thread3,NULL,&media_thread, &media_3);
    pthread_create(&thread4,NULL,&media_thread, &media_4);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);
    pthread_join(thread4,NULL);

    media = (media_1.v_media_thread + media_2.v_media_thread + media_3.v_media_thread + media_4.v_media_thread)/4;
    printf("O valor média encontrado paralelamente foi de %lf\n",media);

    return 0;
}