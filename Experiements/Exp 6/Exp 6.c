#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t tool[5]; char *part[]={"Solar Panel","Antenna","Camera","Battery","Sensor"}; int choice[5];
void *robot(void *p){int i=*(int*)p; sem_wait(&tool[i]); sem_wait(&tool[(i+1)%5]);
    printf("Robot %d repairing %s\n",i+1,part[choice[i]-1]); sem_post(&tool[i]); sem_post(&tool[(i+1)%5]); return NULL;}
    int main(){pthread_t t[5]; int id[5]; for(int i=0;i<5;i++){sem_init(&tool[i],0,1); printf("Robot %d choose part (1-5): ",i+1); scanf("%d",&choice[i]); id[i]=i; pthread_create(&t[i],0,robot,&id[i]);} for(int i=0;i<5;i++) pthread_join(t[i],0);}
