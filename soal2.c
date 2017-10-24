#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[5];

void* mine(void *arg)       
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

