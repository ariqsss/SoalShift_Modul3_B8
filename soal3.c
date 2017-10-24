#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[5];
int L=100,K=100;
void* kolamku(void *arg)       
{
   unsigned long i = 0;
   pthread_t id = pthread_self();
   int iter;
   if(pthread_equal(id,tid[0]))       
   {
	while(1){
		if((L<=0)&&(L>100)&&(K<=0)&&(K>100)){printf("game over");exit(EXIT_SUCCESS);}
		//system("clear");
		else if( (L>0)&&(L<=100)&&(K>0)&&(K<=100) ){
		pthread_create(&(tid[4]), NULL, &kolamku, NULL);
		sleep(10);
		if((L<=0)&&(L>100)&&(K<=0)&&(K>100)){printf("game over");exit(EXIT_SUCCESS);}
		L=L-15;
		if((L<=0)&&(L>100)&&(K<=0)&&(K>100)){printf("game over");exit(EXIT_SUCCESS);}
		pthread_create(&(tid[4]), NULL, &kolamku, NULL);
		if((L<=0)&&(L>100)&&(K<=0)&&(K>100)){printf("game over");exit(EXIT_SUCCESS);}
		sleep(10);
		if((L<=0)&&(L>100)&&(K<=0)&&(K>100)){printf("game over");exit(EXIT_SUCCESS);}
		L=L-15;
		if((L<=0)&&(L>100)&&(K<=0)&&(K>100)){printf("game over");exit(EXIT_SUCCESS);}
		K=K-10;
		if((L<=0)&&(L>100)&&(K<=0)&&(K>100)){printf("game over");exit(EXIT_SUCCESS);}
	}
	else {printf("game over");exit(EXIT_SUCCESS);}
		
	}
  
   }
   
   else if(pthread_equal(id,tid[1]))       
   {
	printf("\nuntuk memulai game ketik init awal\nuntuk bantuan ketik help 1\nuntuk beri makan hewan formatnya beri_makan < hewan >  cth: beri_makan lohan\n");   
   }
   else if(pthread_equal(id,tid[2]))       
   {   if(strcmp((char*)arg,"lohan")==0){
       L=L+10;
	pthread_create(&(tid[4]), NULL, &kolamku, NULL);
   }
	else if(strcmp((char*)arg,"kepiting")==0){
       K=K+10;
	pthread_create(&(tid[4]), NULL, &kolamku, NULL);
   }

      }
   else if(pthread_equal(id,tid[3]))       
   {
        
     }
   else if(pthread_equal(id,tid[4]))       
   {    system("clear");
	if((L>0)&&(L<=100)&&(K>0)&&(K<=100)){
	printf("status lohan : %d  status kepiting : %d \n",L,K);
	}
	//else if(L<=0||L>100||K<=0||K>100){ printf ("Game Over !"); return NULL;}	
   }
   return NULL;
}

int main(void)
{
   int i = 0;
   int err;
   char command[100];
   char argument[100];
   
   while(L>0&&L<=100&&K>0&&K<=100)           
   {
   
   scanf("%s%s",command,argument);
   printf("%s %s",command,argument);
   if(strcmp(command,"init")==0){
      err = pthread_create(&(tid[0]), NULL, &kolamku, (void*)argument);   

   }
   else if(strcmp(command,"help")==0){
      err = pthread_create(&(tid[1]), NULL, &kolamku, (void*)argument);   
   }
   else if(strcmp(command,"beri_makan")==0){
      err = pthread_create(&(tid[2]), NULL, &kolamku, (void*)argument);   
   }
   else if(strcmp(command,"pause")==0){
     err = pthread_create(&(tid[3]), NULL, &kolamku, (void*)argument);
   }
   else if(strcmp(command,"continue")==0){
     err = pthread_create(&(tid[4]), NULL, &kolamku, (void*)argument);
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

