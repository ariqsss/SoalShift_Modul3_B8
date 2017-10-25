#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int score[2];
int player;
int mine[2];

void *pasang(void * arg){
 int total,pasangdmn;
 int *map=arg;
 printf("Ingin pasang berapa?(1-4):");
 scanf("%d",&total);
 if (total>0 && total<5){
  for (int i=0 ; i < total ; ++i){
	scanf("%d",&pasangdmn);
	while(map[pasangdmn]!=0){
	scanf("%d",&pasangdmn);
	}
 	map[pasangdmn]=1;
	mine[player]++;
  }

 }
}

void *tebak(void *arg){
 int *map=arg;
 int dmn;
 int player2;
 int a[17]; memset(a,0,sizeof(a));
 player2=(player==0)?1:0; 
 for (int i=0; i < 4 ; ++i){
 
 scanf("%d",&dmn);while(a[dmn]!=0) {printf("Jangan milih yang sama dong!\n"); scanf("%d",&dmn);}
 //a[dmn]=1;
 if (map[dmn]==1) ++score[player]; //klo salah nebak lawan kasih point soalnya sebelum dipangil kan player masih nilai gilirannya
 else { ++score[player2]; a[dmn]=1;}
	if (score[0]>10 ||score[1]>10) break;
 }

}

int main(){
pthread_t tid[2];
int map1[17]; memset(map1,0,sizeof(map1));
int map2[17]; memset(map2,0,sizeof(map2));
char a[20];
char b[20];
printf("Nama player1 : "); scanf("%s",a);
printf("Nama player2 : "); scanf("%s",b);
player=0;
score[0]=0; score[1]=0;
mine[0]=0; mine[1]=0;
 while(1){
	if (player==0){
	printf("Giliran %s memasang ranjau\n",a);
	pthread_create(&(tid[0]),NULL,&pasang,(void *)&map1);
	pthread_join(tid[0],NULL);
	
	printf("Saatnya %s menebak ranjau\n",b);
	pthread_create(&(tid[1]),NULL,&tebak,(void *)&map1); //dalam fungsi tebak sudah otomatis set scorenya :)
	pthread_join(tid[1],NULL);

	player=1;
	}
	else if (player==1){
	printf("Giliran %s memasang ranjau\n",b);
	pthread_create(&(tid[0]),NULL,&pasang,(void *)&map2);
	pthread_join(tid[0],NULL);
	printf("Saatnya %s menebak ranjau\n",a);
	pthread_create(&(tid[1]),NULL,&tebak,(void *)&map2);
	pthread_join(tid[1],NULL);
	player=0;
	}
/*	printf("\n ------------------------ \n");
	for (int i=0; i<17 ; ++i ) printf("%d ",map1[i]); printf("\n");
	for (int i=0; i<17 ; ++i ) printf("%d ",map2[i]);
	printf("\n ------------------------ \n");
*/	printf("\n\n-----------------\n");
	printf("  Score saat ini\n");
	printf("player1 : player2\n");
	printf("   %d   :    %d\n",score[0],score[1]);
	printf("-----------------\n\n");
	
	if ((score[0]>9 || score[1]>9) || (mine[0]==16 && mine[1]==16))break;
 }
 if (score[0]==10) printf("%s menang!\n",a);
 else if (score[1]==10) printf("%s menang!\n",b);
 else{
  printf("%s menang!\n",(score[0]>score[1])?a:b);
 }
}
