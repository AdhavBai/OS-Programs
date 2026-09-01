#include <stdio.h>
#include <pthread.h>
char dna[3][30]; int n=0,readers=0;
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER,w=PTHREAD_MUTEX_INITIALIZER;
void *reader(void *p){pthread_mutex_lock(&m); readers++; if(readers==1)pthread_mutex_lock(&w); pthread_mutex_unlock(&m);
    printf("Reader: DNA = %s\n",dna[0]); pthread_mutex_lock(&m); if(--readers==0)pthread_mutex_unlock(&w); pthread_mutex_unlock(&m); return NULL;}
    void *writer(void *p){pthread_mutex_lock(&w); printf("Writer: New DNA = %s\n",dna[n++]); pthread_mutex_unlock(&w); return NULL;}
    int main(){pthread_t r1,r2,w1; printf("Enter 2 DNA samples: "); scanf("%s %s",dna[0],dna[1]); n=2;
        pthread_create(&r1,0,reader,0); pthread_create(&r2,0,reader,0); printf("Enter new DNA sample: "); scanf("%s",dna[2]); pthread_create(&w1,0,writer,0);
        pthread_join(r1,0); pthread_join(r2,0); pthread_join(w1,0);}
