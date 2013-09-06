// GRUPA PARZYSTA

/* Napisać program, który wczytuje

liczbę naturalną n, oraz
ciąg liter długości n,

następnie z obrazu bitowego każdej litery drukuje 4 pierwsze (najbardziej znaczące) bity.

Np. jeśli użytkownik wprowadzi dane:

3 Kot

to program powinien wydrukować ciąg

0100 0110 0111

ponieważ obrazami bitowymi liter K, o i t są kolejno 01001011, 01101111 i 01110100. */

#include<stdio.h>
#include<string.h>

void nabity(int x);

int main(void)
{
 int i;
 int n;
 printf("Podaj dlugosc slowa i slowo:\n");
 scanf("%i",&n);
 
 char slowo[n];
 scanf("%s",slowo);

 for(i=0;i<n;i++)
 {
  nabity(slowo[i]);
 }
 printf("\n");
 
 return 0;
}

void nabity(int x)
{
 int t[8]; int i;
 
 for (i=0; i<8; i++)
 { 
  t[i]=(x&1); x = x >> 1; 
  }
 for (i=7;i>=4;i--)
 { 
  printf ("%d",t[i]); 
 } 
 printf(" ");
}

/* LUB */

#include <stdio.h>
#include <string.h>

void binarne(int a[], int k)
{
 int i, j, bin[80];
 
 for(i=0;i<k;i++)
 {
 j=0;
  while(a[i]!=0)
  {
   bin[j]=a[i]%2;
   a[i]=a[i]/2;
   j++;
  }
  for(j=7;j>=4;j--)
  {
   printf("%i", bin[j]);
  }
  printf(" ");
 }
}

int main() 
{
 int n, k, i;

 printf("Podaj długość słowa: \n");
 scanf("%i", &n);

 char napis[40];
 printf("A teraz podaj to słowo: \n");
 scanf("%s", napis);
 printf("\n");

 k=strlen(napis);
 int a[k];

 for(i=0;i<k;i++)
 {
  a[i]=(int)napis[i];
 }

 binarne(a, k);
 printf("\n");

 return 0;
}


// GRUPA NIEPARZYSTA

/* Napisać program, który wczytuje

liczbę naturalną n, oraz
ciąg liter długości n,

następnie z obrazu bitowego każdej litery drukuje 4 ostatnie (najmniej znaczące) bity.

Np. jeśli użytkownik wprowadzi dane:

3 Kot

to program powinien wydrukować ciąg

1011 1111 0100

ponieważ obrazami bitowymi liter K, o i t są kolejno 01001011, 01101111 i 01110100. */

#include <stdio.h>
#include <string.h>

void wypisz_ostatnie_4_bity(int liczba);

int main(void)
{
    int n;
    int i;


    printf("Prosze podac dlugosc slowa i slowo:\n");
    scanf("%i",&n);
    char slowo[n];
    scanf("%s",slowo);

    for(i=0;i<n;i++)
    {
        wypisz_ostatnie_4_bity(slowo[i]);
    }

    printf("\n");
    return 0;

}

void wypisz_ostatnie_4_bity(int liczba)
{
        printf("%i",(liczba&8)>>3);
        printf("%i",(liczba&4)>>2);
        printf("%i",(liczba&2)>>1);
        printf("%i",(liczba&1));
        printf(" ");
} 

/* LUB */

int main() {
int n;
printf("podaj n\n");
scanf("%d",&n);

char tab[n];

int i;
printf("\npodaj ciag liter\n");
scanf("%s",tab);

int j;
for(j=0;j<n;j++){

   //obrazy bitowe
   for(i=3;i>=0;i--){
   int x;
   x=(tab[j]>>i)&1;
   printf("%d",x);
   }
   printf(" ");
}
printf("\n");

   return 0;
}
