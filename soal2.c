#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[5];
char a[100];
char b[100];
int x[16];
int y[16];
void* mine(void *arg)       
{
   unsigned long i = 0;
   pthread_t id = pthread_self();
   int iter;
   if(pthread_equal(id,tid[0]))       
   { while(1){
     printf("Giliran %s, silahkan pilih mau pasang berapa ranjau ? ",a);
     printf("Giliran %s, silahkan pilih mau pasang berapa ranjau ? ",b);
   }
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
   printf("Masukkan nama pemain pertama : ");scanf("%s",a);
   printf("\nMasukkan nama pemain kedua  :  ");scanf("%s",b);
   
   while(1)           
   {
   
      err = pthread_create(&(tid[0]), NULL, &mine,NULL);   

   
 /*  if(strcmp(command,"help")==0){
      err = pthread_create(&(tid[1]), NULL, &mine, NULL);   
   }
   else if(strcmp(command,"beri_makan")==0){
      err = pthread_create(&(tid[2]), NULL, &mine,NULL);   
   }
   else if(strcmp(command,"pause")==0){
     err = pthread_create(&(tid[3]), NULL, &mine,NULL);
   }
   else if(strcmp(command,"continue")==0){
     err = pthread_create(&(tid[4]), NULL, &mine,NULL);
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


