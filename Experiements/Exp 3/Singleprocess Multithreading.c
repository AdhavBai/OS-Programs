#include <stdio.h>
#include <pthread.h>
void *sat(void *a){printf("ISRO Satellite: Heat anomaly detected!\n"); return NULL;}
void *drone(void *a){printf("Drone dispatched to fire location\n");
    printf("Drone harvesting thermal energy\n"); printf("Monitoring forest fire\n"); return NULL;}
    int main(){
        pthread_t s,d; pthread_create(&s,NULL,sat,NULL); pthread_join(s,NULL);
        pthread_create(&d,NULL,drone,NULL); pthread_join(d,NULL);
    }
