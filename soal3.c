#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_tid[5];
int L=100,K=100;
void* kolamku(void *arg)       
{
   unsigned long i = 0;
   pthread_t id = pthread_self();
   int iter;
   if(pthread_equal(id,tid[0]))       
   {
  
   }
   
   else if(pthread_equal(id,tid[1]))       
   {
   
   }
   else if(pthread_equal(id,tid[2]))       
   {   
      }
   else if(pthread_equal(id,tid[3]))       
   {
   
     }
   else if(pthread_equal(id,tid[4]))       
   {

   }
   return NULL;
}

int main(void)
{
   int i = 0;
   int err;
   char command[100];
   char argument[100];
   
   while((L>0&&L<=100&&K>0&&K<=100)           
   {
   
   scanf("%s%s",command,argument);
   printf("%s %s",command,argument);
   if(strcmp(command,"init")==0){
      err = pthread_create(&(tid[0]), NULL, &playAndCount, (void*)argument);   

   }
   else if(strcmp(command,"help")==0){
      err = pthread_create(&(tid[1]), NULL, &playAndCount, (void*)argument);   
   }
   else if(strcmp(command,"beri_makan")==0){
      err = pthread_create(&(tid[2]), NULL, &playAndCount, (void*)argument);   
   }
   else if(strcmp(command,"pause")==0){
     err = pthread_create(&(tid[3]), NULL, &playAndCount, (void*)argument);
   }
   else if(strcmp(command,"continue")==0){
     err = pthread_create(&(tid[4]), NULL, &playAndCount, (void*)argument);
   }
   else if(strcmp(command,"quit")==0){
       break;
   }
       /*if (err != 0)                           
           printf("\ncan't create thread :[%s]", strerror(err));
       else
           printf("\n Thread created successfully\n");*/

   }                   
  
   return 0;
}

