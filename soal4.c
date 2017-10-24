#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t tid[100];
//
void *faktor(void *arg){
 int *a=arg;
 int b=1;
 for (int i=*a ; i>=2 ; --i){
   b=b*i;
 }
 printf("Hasil %d! = %d\n",*a,b);
}
//

int main(int argc, char *argv[]){

int target[100];//,max=0,j;
for (int i=1 ; i <argc ; ++i){
 target[i]=atoi(argv[i]);
 //if(target[i]>max){ max=target[i]; j=i;}
// //printf("%s %d\n",argv[i],target[i]);
 pthread_create(&(tid[i]),NULL,&faktor,(void *)&target[i]);
}

for (int i=1 ; i < argc ; ++i)pthread_join(tid[i],NULL);

return 0;
}
