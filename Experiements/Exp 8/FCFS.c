#include <stdio.h>
int main(){int type[3],t[3],w=0,i;char *v[]={"","Advertisement","Movie","Trailer"};
for(i=0;i<3;i++){printf("Enter type (1-Ad,2-Movie,3-Trailer) and time: ");scanf("%d%d",&type[i],&t[i]);}
printf("\nFCFS Schedule:\n");for(i=0;i<3;i++){printf("%s - Waiting %d\n",v[type[i]],w);w+=t[i];}}
