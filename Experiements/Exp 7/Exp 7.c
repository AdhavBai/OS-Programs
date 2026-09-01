#include <stdio.h>
int main(){int av,max[3],al[3],need[3],done[3]={0},i,j,count=0;
printf("Available batteries: ");scanf("%d",&av);
for(i=0;i<3;i++){printf("EV%d Max and Allocated: ",i+1);scanf("%d%d",&max[i],&al[i]);need[i]=max[i]-al[i];}
while(count<3){for(i=0;i<3;i++)if(!done[i]&&need[i]<=av){av+=al[i];done[i]=1;count++;printf("EV%d completed, Available=%d\n",i+1,av);}}
printf("System is SAFE\n");}
