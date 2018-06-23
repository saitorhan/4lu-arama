#include <stdio.h>
#include <stdlib.h>

int dortluara(const int const *, int, int, const int);

int main(int argc, char *argv[])
{
    system("color 70");
    int dizi[] = {20,23,4,32,45,65,34,53,543,457,64,356,34,9,8,6,78,6,4,2,1,5,0,-9,-54,5,6,5,8,7,6,-8,6};
    int i,sonuc,aranan, bas=0, son = sizeof(dizi)/sizeof(int);
    printf("Girdiginiz Dizi:\n");
    for(i=0; i<son; i++)
    printf("%d ", dizi[i]);
    while(1){
    printf("\n\nAradiginiz sayiyi giriniz: ");
    scanf("%d", &aranan);
    sonuc = dortluara(dizi, bas, son, aranan);
    if(sonuc>0 && sonuc<= son)
        printf("%d sayisi %d. sirada yer almaktadir.",aranan, sonuc);
    else
        printf("%d sayisi Bulunamadi.\n", aranan);}

  system("PAUSE");
  return 0;
}

int dortluara(const int const *dizi, int bas, int son, const int aranan)
{
     int first=bas, last=son, orta1, orta2, orta3;

     orta2 = (first+last)/2;
     orta1 = (first+orta2)/2;
     orta3 = (orta2+last)/2;

     if(aranan == dizi[first])
                return first+1;
     if(aranan == dizi[orta1])
               return orta1+1;
     if(aranan == dizi[orta2])
               return orta2+1;
     if(aranan == dizi[orta3])
              return orta3+1;
    if(aranan == dizi[last-1])
                return last;

    if(aranan > dizi[first] && aranan < dizi[orta1])
              {last = orta1;}
     if(aranan > dizi[orta1] && aranan < dizi[orta2])
              {first = orta1;   last = orta2;}
     if(aranan > dizi[orta2] && aranan < dizi[orta3])
              {first = orta2;   last = orta3;}
     if(aranan > dizi[orta3] && aranan < dizi[last])
              {first = orta3;}
        if(first+2 <= last){
     if(aranan > dizi[first] && aranan < dizi[orta1])
              return dortluara(dizi, first, last, aranan);
     if(aranan > dizi[orta1] && aranan < dizi[orta2])
              return dortluara(dizi, first, last, aranan);
     if(aranan > dizi[orta2] && aranan < dizi[orta3])
              return dortluara(dizi, first, last, aranan);
     if(aranan > dizi[orta3] && aranan < dizi[last])
              return dortluara(dizi, first, last, aranan);
                        }
    else
        return -1;

}
