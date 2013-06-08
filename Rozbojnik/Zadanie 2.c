/* Podana niżej funkcja szyfruje słowa (czyli niepuste ciągi małych liter, bez spacji i znaków przestankowych), 
zamieniając je na pary składające się z

 - liczby oznaczającej długość słowa, oraz
 - ciągu liczb całkowitych. 

Napisać funkcję odwrotną, czyli odszyfrowującą. */

// CZĘŚĆ NAPISANA PRZEZ STEFANA

#include<string.h>

#define MAX_DL_SLOWA 30

void szyfr(char oryginalne[MAX_DL_SLOWA],
int* dlugosc,
int zaszyfrowane[MAX_DL_SLOWA+1]) {
int i;
*dlugosc = strlen(oryginalne);
for (i=0; i < *dlugosc; i++)
zaszyfrowane[i] =
((int)(oryginalne[i]) + 12 - (int)'a') % 26;
}

/* Przetestować działanie szyfrowania i odszyfrowywania wewnątrz jakichś programów, ale w poniższą ramkę wpisać 
tylko samą funkcję odszyfrowującą.
Uwaga: funkcja odszyfrowująca nie może niczego wczytywać ani drukować; to należy do programu, w którym ta funkcja 
jest wywoływana. */
