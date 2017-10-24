#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
char weapon[7][10]; //LIST DAGANGAN
pthread_t tid[8];

void *tambah(void *arg){
 char x[10];
 int y;
 int *a=(int *)arg;
 scanf("%s %d",x,&y);
  for (int i=0 ; i < 6 ; ++i){
  if(strcmp(weapon[i],x)==0){
     a[i]+=y;
     break;}
 }
}

void *beli(void *arg){
 char x[10];
 int y;
 int *a=(int *)arg;
 scanf("%s %d",x,&y);
 y=-y;
  for (int i=0 ; i < 6 ; ++i){
  if(strcmp(weapon[i],x)==0){
  if (a[i]+y<0) {printf("barang di stock tidak cukup\n"); break;}

     a[i]+=y;
     break;}
 }
}




void *show_jual(void* arg){
  int *a=(int *)arg;
 //pthread_t id=pthread_self();
 for (int i=0 ; i< 6 ; ++i){
	//if (pthread_equal(id,tid[5]))printf("%s %d\n",weapon[i],a[i]);
	//else if (pthread_equal(id,tid[1])){
	  if (a[i]>0){
		printf("%s %d\n",weapon[i],a[i]);
		}
//	}
  }
}

void *show_beli(void* arg){
  int *a=(int *)arg;
 //pthread_t id=pthread_self();
 for (int i=0 ; i< 6 ; ++i){
        printf("%s %d\n",weapon[i],a[i]);
        //else if (pthread_equal(id,tid[1])){
         // if (a[i]>0){
           //     printf("%s %d\n",weapon[i],a[i]);
             //   }
//      }
  }
}




void *menu_stok(void* arg){
 printf("1. Lihat Stock Senjata(Ketik 'lihat')\n2. Tambah Stock Senjata(Ketik 'tambah')\n>>");
}

void *siapa(void *arg){
printf("Kamu siapa? Ketik penjual jika kamu khawari , pembeli jika kamu aidil\n>>");}

void *menu_beli(void *arg){
printf("1. Lihat stok senjata(Ketik 'lihat')\n2. Beli Senjata(Ketik 'beli')\n>>");
}



int main(){
key_t key;
int *value;
key=ftok("~/.bashrc",1);
int shmid = shmget(key, sizeof(int)*7 , IPC_CREAT|0666);
value=(int *)shmat(shmid,NULL,0);
for (int i=0 ; i <7 ; ++i) value[i]=0;
strcpy((weapon[0]),"MP4A1");
strcpy(weapon[1],"PM2-V1");
strcpy(weapon[2],"SPR-3");
strcpy(weapon[3],"SS2-V5");
strcpy(weapon[4],"SPG1-V3");
strcpy(weapon[5],"MINE"); 

char option[7];
while(1){
 pthread_create(&tid[3],NULL,&siapa,NULL);
 pthread_join(tid[3],NULL);
 scanf("%s",option);
 if (strcmp(option,"penjual")==0){
	 pthread_create(&(tid[0]),NULL,&menu_stok,NULL);
	 pthread_join(tid[0],NULL);
	 scanf("%s",option);
	 if (strcmp(option,"lihat")==0){
  		 pthread_create(&(tid[1]),NULL,&show_jual,(void *)value);
		 pthread_join(tid[1],NULL);	
 	}
	 else if (strcmp(option,"tambah")==0){
		 pthread_create(&(tid[2]),NULL,&tambah,(void *)value);
		 pthread_join(tid[2],NULL);
	}
 }
 else if (strcmp(option,"pembeli")==0){
  pthread_create(&(tid[4]),NULL,&menu_beli,NULL);
  pthread_join(tid[4],NULL);
  scanf("%s",option);
  if (strcmp(option,"lihat")==0){
  pthread_create(&(tid[5]),NULL,&show_beli,(void*)value);
 pthread_join(tid[5],NULL);
  }
  else if (strcmp(option,"beli")==0){
  pthread_create(&(tid[6]),NULL,&beli,(void *)value);
 pthread_join(tid[6],NULL);
  }

 }
}

//
shmdt(value);
//shmct1(shmid, IPC_RMID , NULL);
return 0;
}
