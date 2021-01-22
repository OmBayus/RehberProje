#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<conio.h>
#include <unistd.h>
#include <Windows.h>



FILE *file,*temp,*mesajlar;
void KisiEkle();
void Kisilerim();
void KisiGuncelle();
void KisiSil();
void MesajGonderme();
void GonderilenMesajlar();
void MesajlariTemizle();
void CikisYap();
char isim[20];
char numara[20];
char mesaj[500];
char temp_isim[20];
char temp_numara[20];

int main( void )                                                                                      
{
      while (true){
            
            system("cls");
            int a;
            printf("----Islemler----\n");
            printf("1.Kisi Ekle\n");
            printf("2.Kisilerim\n");
            printf("3.Kisi Guncelle\n");
            printf("4.Kisi Sil\n");
            printf("5.Mesaj Gonder\n");
            printf("6.Gonderilen Mesajlar\n");
            printf("7.Gonderilen Mesajlari Temizle\n");
            printf("8.Cikis Yap\n");
            printf("Lutfen Isleminizi Giriniz: ");
            scanf("%d",&a);
            system("cls");

            switch (a)
            {
            case 1:
                  printf("---Kisi Ekle---\n");
                  printf("Ad Soyad: ");
                  scanf("%s",&isim);
                  printf("Tel Number: ");
                  scanf("%s",&numara);
                  KisiEkle(isim,numara);
                  printf("Cikis Yapmak icin herhangi bir şey yaziniz ve enterlayiniz...");
                  scanf("%s",&isim);
                  break;
            case 2:
                  printf("---Kisilerim---\n");
                  Kisilerim();
                  printf("Cikis Yapmak icin herhangi bir şey yaziniz ve enterlayiniz...");
                  scanf("%s",&isim);
                  break;
            case 3:
                  printf("---Kisi Guncelle---\n");
                  printf("Degisiklik Yapilacak Kisinin ismi: ");
                  scanf("%s",&isim);
                  KisiGuncelle(isim);
                  printf("Cikis Yapmak icin herhangi bir şey yaziniz ve enterlayiniz...");
                  scanf("%s",&isim);
                  break;
            case 4:
                  printf("---Kisi Sil---\n");
                  printf("Silinecek Kisinin ismi: ");
                  scanf("%s",&isim);
                  KisiSil(isim);
                  printf("Cikis Yapmak icin herhangi bir şey yaziniz ve enterlayiniz...");
                  scanf("%s",&isim);
                  break;
            case 5:
                  printf("---Mesaj Gönder---\n");
                  printf("Mesaj Gonderilecek Kisinin ismi: ");
                  scanf("%s",&isim);
                  MesajGonderme(isim);
                  printf("Cikis Yapmak icin herhangi bir şey yaziniz ve enterlayiniz...");
                  scanf("%s",&isim);
                  break;

            case 6:
                  printf("---Gonderilen Mesajlar---\n");
                  GonderilenMesajlar();
                  printf("Cikis Yapmak icin herhangi bir şey yaziniz ve enterlayiniz...");
                  scanf("%s",&isim);
                  break;
            case 7:
                  MesajlariTemizle();
                  sleep(1);
                  printf("Mesajlar Basariyla Silindi...\n");
                  printf("Cikis Yapmak icin herhangi bir şey yaziniz ve enterlayiniz...");
                  scanf("%s",&isim);
                  break;
            case 8:
                  printf("Program Kapaniyor...\n");
                  sleep(1);
                  exit(EXIT_SUCCESS);
                  break;
            
            default:
                  break;
            }

      }

      return 0;
}

void KisiEkle(char name[20],char tel[20]){

      int sayac;
      
      file = fopen("kisiler.txt","a+");


      while(fscanf(file,"%s%s",&temp_isim,&numara)!= EOF){
            if(strcmp(temp_isim, name) == 0){
                  sayac = 1;
            }
      }

      if(sayac != 1){
            fprintf(file,"%s %s\n",name,tel);
            printf("Kisi Eklendi.\n");
            
      }
      else{
            printf("Kisi Rehberde Bulunuyor.\n");
      }

      fclose(file);
}

void Kisilerim(){
      file = fopen("kisiler.txt","r");

      while(fscanf(file,"%s%s",&isim,&numara)!= EOF){
            printf("Isim: %s Numara: %s\n",isim,numara);
      }

      fclose(file);
}

void KisiGuncelle(char name[20]){

      int sayac;

      file = fopen("kisiler.txt","r");

      temp = fopen("temp.txt","w");


      while(fscanf(file,"%s%s",&temp_isim,&numara)!= EOF){
            if(strcmp(temp_isim, name) == 0){
                  printf("Yeni Isim:");
                  scanf("%s",&isim);
                  printf("Yeni Numara:");
                  scanf("%s",&numara);
                  fprintf(temp,"%s %s\n",isim,numara);
                  sayac = 1;
            }
            else{
                  fprintf(temp,"%s %s\n",temp_isim,numara);
            }
      }

      if(sayac != 1){
            printf("Kisi Bulunamadi\n");
      }

      fclose(file);
      fclose(temp);
      remove("kisiler.txt");//İlk txt dosyaysı silinir
	rename("temp.txt", "kisiler.txt");
}

void KisiSil(char name[20]){

      int sayac;

      file = fopen("kisiler.txt","r");

      temp = fopen("temp.txt","w");


      while(fscanf(file,"%s%s",&temp_isim,&numara)!= EOF){
            if(strcmp(temp_isim, name) == 0){
                  sayac = 1;
            }
            else{
                  fprintf(temp,"%s %s\n",temp_isim,numara);
            }
      }

      if(sayac != 1){
            printf("Kisi Bulunamadi\n");
      }else{
            printf("Kisi Basariyla Silindi\n");
      }

      fclose(file);
      fclose(temp);
      remove("kisiler.txt");//İlk txt dosyaysı silinir
	rename("temp.txt", "kisiler.txt");
}

void MesajGonderme(char name[20]){

      int sayac;

      file = fopen("kisiler.txt","r");

      mesajlar = fopen("mesajlar.txt","a");


      while(fscanf(file,"%s%s",&temp_isim,&numara)!= EOF){
            if(strcmp(temp_isim, name) == 0){
                  sayac = 1;
            }
      }

      if(sayac != 1){
            printf("Kisi Rehberde Bulunmuyor\n");
      }
      else{
            printf("Mesaj: ");
            scanf("%s",&mesaj);
            fprintf(mesajlar,"%s %s\n",name,mesaj);
      }

      fclose(file);
      fclose(mesajlar);
}

void GonderilenMesajlar(){

      mesajlar = fopen("mesajlar.txt","r");

      while(fscanf(file,"%s %s",&isim,&mesaj)!= EOF){
            printf("\n-------\n");
            printf("Gonderilen Kisi: %s\nMesaj: %s",isim,mesaj);
            printf("\n-------\n");
      }

      fclose(mesajlar);
}

void MesajlariTemizle(){
      mesajlar = fopen("mesajlar.txt","w");

      fclose(mesajlar);
}