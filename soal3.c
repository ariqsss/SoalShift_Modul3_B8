#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[5];
int L=100,K=100;//deklarasi untuk status awal Lohan dan Kepiting
void* kolamku(void *arg)       
{
   int j;
   unsigned long i = 0;
   pthread_t id = pthread_self();
   if(pthread_equal(id,tid[0]))       
   {
	while(1){
		if(((L<=0)||(L>100))||((K<=0)||(K>100))){printf("game over\n");exit(EXIT_SUCCESS);}
		else if( ((L>0)&&(L<=100))&&((K>0)&&(K<=100)) ){
		pthread_create(&(tid[4]), NULL, &kolamku, NULL);
		sleep(10);
		L=L-15;
		pthread_create(&(tid[4]), NULL, &kolamku, NULL);
		sleep(10);
               	L=L-15;
		K=K-10;
		pthread_create(&(tid[4]), NULL, &kolamku, NULL);

	}
	else {printf("game over\n");exit(EXIT_SUCCESS);}
		
	}
  
   }
////////////////diatas ini merupakan Fungsi untuk mengurangi status tiap satuan waktu dari lohan & kepiting
   
   else if(pthread_equal(id,tid[1]))       
   {
	printf("\nuntuk memulai game ketik init awal\nuntuk bantuan ketik help 1\nuntuk beri makan hewan formatnya beri_makan < hewan >  cth: beri_makan lohan\n");   
   }
////////////////diatas ini merupakan Fungsi dari tampilan awal game agar lebih mudah bagi pengguna
   else if(pthread_equal(id,tid[2]))       
   {   if((strcmp((char*)arg,"lohan")==0)||(strcmp((char*)arg,"Lohan")==0)){
       L=L+10;
	pthread_create(&(tid[4]), NULL, &kolamku, NULL);
   }
	else if((strcmp((char*)arg,"kepiting")==0)||(strcmp((char*)arg,"Kepiting")==0)){
       K=K+10;
	pthread_create(&(tid[4]), NULL, &kolamku, NULL);
   }
/////////////////diatas ini merupakan fungsi untuk beri_makan
      }
   else if(pthread_equal(id,tid[3]))       
   {
      while(1){
	 if(((L<=0)||(L>100))||((K<=0)||(K>100))){printf("game over\n");exit(EXIT_SUCCESS);}
	}  
     }
//////////////////diatas ini merupakan fungsi untuk selalu mengecek status, jika =0 atau >100 maka game over
   else if(pthread_equal(id,tid[4]))       
   {    system("clear");
	if((L>0)&&(L<=100)&&(K>0)&&(K<=100)){
	printf("status Lohan : %d  status Kepiting : %d \n",L,K);
	}
   }
//////////////////diatas ini merupakan fungsi untuk mengeprint status dari lohan dan kepiting saat ini
   return NULL;
}

int main(void)
{
   char command[100];
   char argument[100];
   printf("\nuntuk memulai game ketik init awal\nuntuk bantuan ketik help 1\nuntuk beri makan hewan formatnya beri_makan < hewan >  cth: beri_makan lohan\n\n");//tampilan awal game
   pthread_create(&(tid[3]), NULL, &kolamku,NULL);/////langsung jalankan thread untuk mengecek status jika tidak sesuai maka game over
   while((L>0)&&(L<=100)&&(K>0)&&(K<=100))           
   {
   
   scanf("%s%s",command,argument);
   if(strcmp(command,"init")==0){
      pthread_create(&(tid[0]), NULL, &kolamku, (void*)argument);///untuk mulai game   

   }
   else if(strcmp(command,"help")==0){
      pthread_create(&(tid[1]), NULL, &kolamku, (void*)argument);//untuk menampilkan tampilan awal   
   }
   else if(strcmp(command,"beri_makan")==0){
      pthread_create(&(tid[2]), NULL, &kolamku, (void*)argument);///untuk memberi makan
   }
 

   }                   
  
   return 0;
}

