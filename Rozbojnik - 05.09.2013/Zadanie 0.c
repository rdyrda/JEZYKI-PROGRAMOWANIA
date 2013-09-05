// GRUPA PARZYSTA

/* Napisać program, który wczytuje ciąg cyfr (niczym nieporozdzielany, nieznanej z góry długości) i za każdą cyfrę c 
drukuje cyfrę 9−c. Dowolny znak różny od cyfry oznacza koniec ciągu na wejściu.

Np. jeśli użytkownik wprowadzi dane:

0123456789 012234456

to program powinien wydrukować jako wynik

9876543210

(znakiem końca jest w tym przypadku spacja). */

#include <stdio.h>

int main ()
{
int a;
char c='0';

printf("Podaj ciag liczb:\n");

  while(c<=57 && c>=48)
  {
   scanf("%c", &c);
   a=9-(c-48);
    if(c<=57 && c>=48)
    {
     printf("%i", a);
    }
  }

  return 0;
}


// GRUPA NIEPARZYSTA

/* Napisać program, który wczytuje ciąg liter (niczym nieporozdzielany, nieznanej z góry długości) i za każdą literę 
drukuje następną w alfabecie (zakładamy, że po Z następuje znowu A). Dowolny znak różny od dużej i małej litery 
oznacza koniec ciągu na wejściu.

Np. jeśli użytkownik wprowadzi dane:

Ayctqz zqtcyA

to program powinien wydrukować jako wynik

Bzdura

(znakiem końca jest w tym przypadku spacja). */

#include<stdio.h> 
#include<string.h>

#define DUZO 10000

void zamiana(char tab[],int n)
{
 int i=0;
 
 while(((int)tab[i]>64 && (int)tab[i]<90) || ((int)tab[i]>96 && (int)tab[i]<123))
 {
  if(tab[i]!='Z'&&tab[i]!='z')
  printf("%c",(char)((int)tab[i]+1));

  if(tab[i]=='Z')
  printf("A");

  if(tab[i]=='z')
  printf("a");
  ++i;
 }
 printf("\n");
}

int main() 
{
 char tab[DUZO+1];
 scanf("%s",tab);

 int n=strlen(tab);
 zamiana(tab,n);

return 0;
}
