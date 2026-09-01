#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s;
float hiv,hcv;

void *test(void *p){
    sem_wait(&s);
    printf("\n--- %s REPORT ---\n",(char*)p);
    printf("Sample processed successfully\n");
    printf("Result stored in patient database\n");
    sem_post(&s);
    return NULL;
}

int main(){
    pthread_t a,b;
    sem_init(&s,0,1);

    printf("Enter two test values:\n");
    printf("HIV value: "); scanf("%f",&hiv);
    printf("HCV value: "); scanf("%f",&hcv);

    pthread_create(&a,0,test,hiv>=1?"HIV: REACTIVE":"HIV: NON-REACTIVE");
    pthread_create(&b,0,test,hcv>=1?"HCV: POSSIBLE INFECTION":"HCV: NON-REACTIVE");

    pthread_join(a,0);
    pthread_join(b,0);
}
