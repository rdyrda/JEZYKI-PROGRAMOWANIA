/* Napisać program, który wczytuje:

 - dodatnią liczbę naturalną n; następnie
 - dwa ciągi zer i jedynek, każdy z nich długości n 

po czym drukuje bitową różnicę symetryczną tych dwóch ciągów. Np. jeśli użytkownik wprowadzi takie dane:

5
01010
00110

to program powinien wydrukować jako wynik

01100

Wskazówka: można zastosować działanie bitowej różnicy symetrycznej języka C, ale nie ma takiego obowiązku; jeśli jakaś inna metoda daje poprawny wynik, to jest równie dobra. */

#include <stdio.h>

  int main() {

  int n;

  printf("Podaj dlugosc ciagow: ");
  scanf("%i", &n);

  int ciag_a[n];
  int ciag_b[n];

  int i;

  printf("Podaj elementy do 1 ciagu: ");
  for (i=0; i<n; i++) {
  scanf("%i",&ciag_a[i]);
  }

  printf("Podaj elementy do 2 ciagu: ");
  for (i=0; i<n; i++) {
  scanf("%i", &ciag_b[i]);
  }

  printf("Wynik roznicy symetrycznej podanych ciagow to: \n");
  for(i=0; i<n; i++) {
  printf("%i",ciag_a[i]^ciag_b[i]);
  }

  printf("\n");

  return 0;
  }
  
