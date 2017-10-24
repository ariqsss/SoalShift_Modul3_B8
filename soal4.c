#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


pthread_t tid[100];
//
void *faktor(void *arg){
 int *a=(int *)arg;
 int b=1;
 for (int i=a ; i>=2 ; --i){
   b=b*i;
 }
 printf("Hasil %d! = %d\n",a,b);
}

int main(int argc, char *argv[]){
for (int i=0 ; i <argc ; ++i){
  

}

}
