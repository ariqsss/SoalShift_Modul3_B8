#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>


char weapon[7][10];
int value[7];

void *beli(void *arg){
 char x[10];
 int y;
 scanf("%s %d",x,&y);
 for (int i=0 ; i < 6 ; ++i){
  if(strcmp(weapon[i],x)==0){
 	value[i]+=y;
	break;
  }
 }
}

void *show(void* arg){
 for (int i=0 ; i< 6 ; ++i){
	if (value[i]>0){
	printf("%s %d\n",weapon[i],value[i]);
	}
  }
}

void *menu(void* arg){
 printf("1. Lihat Stock Senjata(Ketik 'lihat')\n2. Tambah Stock Senjata(Ketik 'tambah')\n");
}

int main(){
for(int i=0;i<7;++i)value[i]=0;

strcpy((weapon[0]),"MP4A1");
strcpy(weapon[1],"PM2-V1");
strcpy(weapon[2],"SPR-3");
strcpy(weapon[3],"SS2-V5");
strcpy(weapon[4],"SPG1-V3");
strcpy(weapon[5],"MINE"); 


pthread_t tid[4];
char option[7];
while(1){
 pthread_create(&(tid[0]),NULL,&menu,NULL);
 pthread_join(tid[0],NULL);
 scanf("%s",option);
 if (strcmp(option,"lihat")==0){
  pthread_create(&(tid[1]),NULL,&show,NULL);
  pthread_join(tid[1],NULL);	
 }
 else if (strcmp(option,"tambah")==0){
 pthread_create(&(tid[2]),NULL,&beli,NULL);
 pthread_join(tid[2],NULL);
}

}


return 0;
}
