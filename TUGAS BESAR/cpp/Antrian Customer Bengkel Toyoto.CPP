#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct mobil{
       char platnomor[10];
       char pemilik[30];
       char merk_mobil[20];
       char keluhan[100];
       struct mobil *next;
       };

struct queue{
       mobil *head;
       int count;
       mobil *tail;
       };

int isFull(queue *queue);
int isEmpty(queue *queue);
void mobil_masuk(queue *queue);
void cetak(queue *queue);
void mobilout(queue *queue);
void kosongkan(queue *queue);
void mobil2an(queue *queue);
void mobil2an_out(queue *queue);

int main(){
    system("color 70");
    queue queue;
    queue.count=0;
    queue.head=NULL;
    queue.tail=NULL;

    char pilih;
    int isfull,isempty;
do{system("cls");
cout<<"|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|"<<endl;
cout<<"|   o  o  o  oooo  o      ooooo  ooooo  ooo   ooo  oooo       |"<<endl;
cout<<"|   o  o  o  o     o      o      o   o  o  o o  o  o          |"<<endl;
cout<<"|   o  o  o  oooo  o      o      o   o  o   o   o  oooo       |"<<endl;
cout<<"|   o  o  o  o     o      o      o   o  o       o  o          |"<<endl;
cout<<"|    oo oo   oooo  ooooo  ooooo  ooooo  o       o  oooo       |"<<endl;
cout<<"|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|"<<endl;
cout<<"|                      _______________                        |"<<endl;
cout<<"|-------------------->> NASMONO TOYOTO <<---------------------|"<<endl;
cout<<"|                 Jl. Cinta Allah,Bantul, Yogyakarta          |"<<endl;
cout<<"|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|"<<endl;
cout<<"|                1.Cek antrian(full/tidak)                    |"<<endl;
cout<<"|                2.Cek antrian(kosong/tidak)                  |"<<endl;
cout<<"|                3.Kosongkan Bengkel                          |"<<endl;
cout<<"|                4.Pendftaran                                 |"<<endl;
cout<<"|                5.Mobil keluar                               |"<<endl;
cout<<"|                6.Lihat semua mobil                          |"<<endl;
cout<<"|                7.Exit                                       |"<<endl;
cout<<"|                                                             |"<<endl;
cout<<"|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|"<<endl;

cout<<"Silahkan Pilih Menu Di atas	: ";cin>>&pilih; fflush(stdin);
if(pilih=='1'){clrscr();isfull=isFull(&queue);
               system("color 70");
               if(isfull==1){
               cout<<"|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|"<<endl;
               cout<<"|~~~~~~~~~~| Mohon Maaf, Saat ini Bengkel penuh |~~~~~~~~~~~~~|"<<endl;
               cout<<"|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|"<<endl;
               cout<<endl;
               cout<<"Tekan sembarang untuk kembali ke Menu";
               getch();}
               else {
               cout<<"|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|"<<endl;
               cout<<"|~~~~~~~~~| Selamat, Saat ini Bengkel tidak penuh |~~~~~~~~~~~|"<<endl;
               cout<<"|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|"<<endl;
               cout<<endl;
               cout<<"Tekan sembarang untuk kembali ke Menu";
               getch();}
               }
else if(pilih=='2'){clrscr();isempty=isEmpty(&queue);

					system("color 70");
               if(isempty==1){
               cout<<"|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|"<<endl;
               cout<<"|---------------> Saat ini Bengkel Kosong <-------------------|"<<endl;
               cout<<"|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|"<<endl;
               cout<<endl;
               cout<<"Tekan sembarang untuk kembali ke Menu";
               getch();}
               else {
               cout<<"|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|"<<endl;
               cout<<"|-------------> Saat ini Bengkel Tidak Kosong <---------------|"<<endl;
               cout<<"|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|"<<endl;
               cout<<endl;
               cout<<"Tekan sembarang untuk kembali ke Menu";
                getch();}
               }
else if(pilih=='3'){kosongkan(&queue);}
else if(pilih=='4'){mobil_masuk(&queue);}
else if(pilih=='5'){mobilout(&queue); mobil2an_out(&queue);}
else if(pilih=='6'){ cetak(&queue);}
}while(pilih!='7');
}

int isFull(queue *queue){
     if(queue->count==5) return 1;
     else return 0;
     }

int isEmpty(queue *queue){
    if(queue->count==0) return 1;
    else return 0;
}

void mobil_masuk(queue *queue){
clrscr();
system("color 70");
     mobil *pNew;
     pNew=(mobil*)malloc(sizeof(mobil));
     if(pNew!=NULL){
     if(queue->count==5) {cout<<"Ruang Bengkel full"; getch();}
     else{
          pNew->next=NULL;
          cout<<"|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|"<<endl;
          cout<<"|                  MENU REGISTRASI CUSTOMER                   |"<<endl;
          cout<<"|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|"<<endl;
          cout<<"|Nama Pemilik	: "; scanf("%[^\n]",&pNew->pemilik);fflush(stdin);
          cout<<"|Plat Nomor  	: "; scanf("%[^\n]",&pNew->platnomor);fflush(stdin);
          cout<<"|merk Mobil  	: "; scanf("%[^\n]",&pNew->merk_mobil);fflush(stdin);
          cout<<"|Keluhan        : "; scanf("%[^\n]",&pNew->keluhan);fflush(stdin);

          if(queue->count==0){
          queue->head=pNew;
          }
          else{
          queue->tail->next=pNew;

          }
          queue->tail=pNew;
          queue->count=(queue->count)+1;
          }
          }
}

void mobilout(queue *queue){clrscr();
system("color 70");
      mobil *dltPtr;


     dltPtr = queue->head;

     if(queue->count == 1){
            queue->head = queue->tail =NULL;
     }
     else {
     queue->head=queue->head->next;


     }

     queue->count--;

     free(dltPtr);

}

void cetak(queue *queue){
     mobil *pWalker;
     int i=1;
     pWalker=queue->head;
     if(queue->count==0){printf("\nBengkel kosong");getch();}
     else{ system("cls");
     mobil2an(queue);
     gotoxy(1,7);
     cout<<"|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|"<<endl;
     cout<<"|                  DAFTAR ANTRIAN CUSTOMER                    |"<<endl;
     cout<<"|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|"<<endl;
     while(pWalker!=NULL){

                           cout<<"mobil ke "<<i<<endl;
                           cout<<"plat nomor:"<<pWalker->platnomor<<endl;
                           cout<<"Pemilik	  :"<<pWalker->pemilik<<endl;
                           cout<<"keluhan	  :"<<pWalker->keluhan<<endl;
                           cout<<endl;
                           pWalker=pWalker->next; i++;
                           }
                           getch();
         }
}

void kosongkan(queue *queue){
  while(queue->head!=NULL){
                       mobilout(queue);

                       }
}

//animasi mobil2an
void mobil2an(queue *queue){
int jml;
jml=queue->count;
int a;int z=65;
int n;
printf("     IN  ");gotoxy(68,1);printf("  OUT  ");
gotoxy(1,6); printf("--------------------------------------------------------------------------------");
for(n=0;n<jml;n++){ //pengulangan untuk jumlah mobil
   for(a=1;a<=z;a++){//pengulangan agar mobil terlihat bergerak
  int sleep(30);
  gotoxy(a+2,2);printf(" _______");
  gotoxy(a,3);printf(" |        |_");
  gotoxy(a,4);printf(" |          |");
  gotoxy(a,5);printf(" ---0-----0--");
  }
  z=z-15;
}
}

void mobil2an_out(queue *queue){
int jml;
jml=queue->count+1;
int a;int z=65;int y;
int n;
gotoxy(1,13);printf("     IN  ");gotoxy(68,13);printf("  OUT  ");
gotoxy(1,20); printf("--------------------------------------------------------------------------------");
for(n=0;n<jml;n++){ //pengulangan untuk jumlah mobil
   for(a=1;a<=z;a++){//pengulangan agar mobil terlihat bergerak
  gotoxy(a+2,16);printf("_________");
  gotoxy(a,17);printf("|          |_");
  gotoxy(a,18);printf("|				|");
  gotoxy(a,19);printf(" --0------0--");
  }
  z=z-15;
}
getch();

for(n=0;n<=1;n++){//pengulangan ketika 1 paling depan keluar
if (jml==1){
  gotoxy(a+2,16);printf("        ");
  gotoxy(a,17);printf("             ");
  gotoxy(a,18);printf("             ");
  gotoxy(a,19);printf("             ");
}
else{
y=50; z=65;
for(n=0;n<jml-1;n++){

   for(a=y;a<=z;a++){
  int sleep(30);
  gotoxy(a+2,16);printf(" _____________");
  gotoxy(a,17);printf(" |              |_");
  gotoxy(a,18);printf(" |                |");
  gotoxy(a,19);printf(" ---0---------0---");
}
  y=y-15; z=z-15;
}
}
}
   getch();

}
