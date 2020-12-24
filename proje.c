#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<conio.h>
#include <unistd.h>
#include <Windows.h>



FILE *file,*temp;
void KisiEkle();
void Kisilerim();
void KisiGuncelle();
void KisiSil();
char isim[20];
char numara[20];
char temp_isim[20];
char temp_numara[20];

int main( void )                                                                                      
{
      while (true){
            
            system("clear");
            int a;
            printf("----Islemler----\n");
            printf("1.Kisi Ekle\n");
            printf("2.Kisilerim\n");
            printf("3.Kisi Guncelle\n");
            printf("4.Kisi Sil\n");
            printf("5.Arama\n");
            printf("Lutfen Isleminizi Giriniz: ");
            scanf("%d",&a);
            system("clear");

            switch (a)
            {
            case 1:
                  printf("---Kisi Ekle---\n");
                  printf("Ad Soyad: ");
                  scanf("%s",&isim);
                  printf("Tel Number: ");
                  scanf("%s",&numara);
                  KisiEkle(isim,numara);
                  printf("Islem Basarili...\n\n\n");
                  sleep(1);
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
                  /* code */
                  break;
            
            default:
                  break;
            }

      }

      return 0;
}

void KisiEkle(char name[20],char tel[20]){
      file = fopen("kisiler.txt","a");
      
      system("clear");
      fprintf(file,"%s %s\n",name,tel);

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