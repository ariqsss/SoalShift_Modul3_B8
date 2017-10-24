#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

pthread_t tid[10];


void *cari(void *arg){
 char novel[1500];
 strcpy(novel,"Perkenalkan nama saya, Fina, saya ingin menceritakan perjalanan saya bersama teman-teman saya waktu menuju ke Cibodas Bogor. Pengalaman tersebut menurut saya tidak bisa di lupakan begitu saja karena banyak pengalaman-pengalaman yang sangat berkesan bagi saya dan teman-teman saya. Awal perjalanan kami di awali dari depok berkumpul di kos-kosan teman saya bernama Ifah hadinata,kami berangkat malam kira-kira jam23.00 dan kami berangkat menggunakan sepeda motor,kami sampai di Cibodas kira-kira jam 01.00 pagi,setelah sampai di Cibodas kami istirahat utuk merencanakan kegiatan kami besok pagi, ternyata kami memutuskan untuk naik gunung Gede pangrango, setelah memutuskan rencana kami berangkat jam 07.00 tetapi rencana kami batal untuk menaiki gunung gede pangrango karena ada teman kami yang bernama Ifah tidak kuat untuk naik naik gunung karena penyakit Asmanya kambuh. Dengan berat hati kami batal mendaki gunung gede pangrango dan kami memutuskan untuk berangkat menuju air terjun Cilember. Setelah menempuh perjalanan yang cukup panjang untuk mencapai curug cilember akhirnya kami samai juga disana, luar biasa sekali setelah kita berjuang dan kecewa tidak jadi mendaki Gunung gede pangrango akhinya penderitaan kami terobati dengan melihat Pemandangan yang luar biasa.Dari perjalanan tersebut saya mendapat pengalaman yang luar biasa bahwa karunia Tuhan Yang Maha Esa patut kita syukuri dan juga menjaga keindahan alam tersebut agar tetap terjaga dengan baik.");
 char *target=(char *)arg;
 int tlen=strlen(target);
 int b=0;
 int counter=0;

for(int i=0; i<1468 ; ++i){ 
  while(novel[i]==target[b] && b<tlen){
	++i; ++b;
        if(b==tlen) ++counter;
  }b=0;

 }


 printf("%s : %d\n",target,counter);

}


int main(int argc, char *argv[]){


char x[20][20];
for (int i=1 ; i<argc; ++i){
strcpy(x[i],argv[i]);
pthread_create(&(tid[i]),NULL,&cari,(void *)&x[i]);}
for (int i=1 ; i<argc ; ++i){
pthread_join(tid[i],NULL);}

}
