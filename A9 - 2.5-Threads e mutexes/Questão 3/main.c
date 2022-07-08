#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <sys/time.h>
#define n 50000

long int busca_vetor(long int *v, int tamanho){
    int i;
    long int v_max = v[0];
    for ( i = 1; i < tamanho; i++)
    {
        if (v[i] > v_max){
            v_max = v[i];
        }
    }
    return v_max;    
}

struct max_thread_parms
{
    long int *v;
    int tam;
    long int v_max_thread;
};

void *max_thread(void *parms){
    struct max_thread_parms* p =(struct max_thread_parms*) parms;
    p->v_max_thread = busca_vetor(p->v,p->tam);
    return NULL;
}


int main(){
    pthread_t thread_id1,thread_id2,thread_id3,thread_id4;
    long int v[n];
    long int v_max, v_max_thread;
    int i;
    struct max_thread_parms max_1,max_2,max_3,max_4;

    srandom(time(NULL));
    for ( i = 0; i < n; i++)
    {
        v[i] = random();
    }

    v_max = busca_vetor(v,n);
    printf("Realizando a busca completa no vetor, temos que o valor máximo é de %ld\n",v_max);

// *****************************************************
    max_1.v = &(v[0*n/4]);
    max_1.tam = n/4;
    max_2.v = &(v[0*n/4]);
    max_2.tam = n/4;
    max_3.v = &(v[0*n/4]);
    max_3.tam = n/4;
    max_4.v = &(v[0*n/4]);
    max_4.tam = n/4;
    
    pthread_create(&thread_id1,NULL,&max_thread,&max_1);
    pthread_create(&thread_id2,NULL,&max_thread,&max_2);
    pthread_create(&thread_id3,NULL,&max_thread,&max_3);
    pthread_create(&thread_id4,NULL,&max_thread,&max_4);

    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    pthread_join(thread_id3, NULL);
    pthread_join(thread_id4, NULL);

    v_max_thread = max_1.v_max_thread;
    if (max_2.v_max_thread > v_max_thread)
    {
        v_max_thread = max_2.v_max_thread;
    }
    if (max_3.v_max_thread > v_max_thread)
    {
        v_max_thread = max_3.v_max_thread;
    }
    if (max_4.v_max_thread > v_max_thread)
    {
        v_max_thread = max_4.v_max_thread;
    }
    
    printf("Utilizando o cálculo paralelizado, temos que o valor máximo é de %ld\n",v_max_thread);
    
    return 0;
}