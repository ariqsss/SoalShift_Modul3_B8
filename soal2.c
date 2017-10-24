#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int score[2];
int player;

void *pasang(void * arg){
 int total,pasangdmn;
 int *map=arg;
 printf("Ingin pasang berapa?(1-4): )"
 scanf("%d",&total);
 if (total>0 && total<5){
  for (int i=0 ; i < total ; ++i){
	scanf("%d",&pasangdmn);
	while(map[pasangdmn]!=0){
	scanf("%d",&pasandmn);
	}
 	map[pasangdmn]=1;
  }

 }
}

void *tebak(void *arg){
 int *map=arg;
 int dmn;
 int player2;
 player2=(player==0)?1:0; 
 for (int i=0; i < 4 ; ++i){
 scanf("%d",&dmn);
 if (map[dmn]==1) ++score[player];
 else ++score[player2];
 }

}

int main(){
player=0;
score[0]=0; score[1]=0;

 while(score[0]!=10 || score[1]!=10){
	if (player==0){
	//thread here
	player=1;

 }

}
