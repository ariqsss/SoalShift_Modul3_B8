#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>


char weapon[7][10];
int value[7];
memset(value,0,sizeof(value));
strcpy(weapon[0],"MP4A1");
strcpy(weapon[1],"PM2-V1");
strcpy(weapon[2],"SPR-3");
strcpy(weapon[3],"SS2-V5");
strcpy(weapon[4],"SPG1-V3");
strcpy(weapon[5],"MINE"); 


void *beli(void *arg){
 char x[10];
 int y;
 scanf("%s %d",x,&y);
 for (int i=0 ; i < 6 ; ++i){
  if(strcmp(weapon[i],y)==0){
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

int main(){



return 0;
}
