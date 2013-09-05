/* Napisać program, który wczytuje ciąg cyfr (niczym nieporozdzielany, nieznanej z góry długości) i za każdą cyfrę c drukuje cyfrę 9−c. Dowolny znak różny od cyfry oznacza koniec ciągu na wejściu.

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
