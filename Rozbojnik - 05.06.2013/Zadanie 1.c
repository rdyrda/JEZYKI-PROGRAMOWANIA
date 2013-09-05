/* W poniższym programie funkcja inicjalizacja napełnia tablicę slowa losowymi słowami. W ramkę wpisać definicję 
funkcji sortowanie taką, żeby cały program drukował wygenerowane losowe słowa w kolejności od najdłuższego do 
najkrótszego, a w ramach tej samej długości w odwrotnej kolejności alfabetycznej. */

// CZĘŚĆ NAPISANA PRZEZ STEFANA

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_DLUG 30
#define ILOSC 100
#define WLK_ALFABETU 26

char slowa[ILOSC][MAX_DLUG];

void inicjalizacja (char slowa[ILOSC][MAX_DLUG]) {
int i, j, k;
for (i=0; i<ILOSC; i++) {
k = rand()%(MAX_DLUG-1);
for (j=0; j<=k; j++)
slowa[i][j] = (char)((int)'a' + rand()%WLK_ALFABETU);
slowa[i][k+1] = '\0';
}
}

/////////////////////////////////////////////////////////////////////////////////

// CZĘŚĆ NAPISANA PRZEZ MNIE

void sortowanie (char slowa[ILOSC][MAX_DLUG]) {

          int i,j;
          char pom[MAX_DLUG];

          for(j=0; j<ILOSC; j++) {
          for(i=0; i<ILOSC-1-j; i++) {

          if (strlen(slowa[i]) < strlen(slowa[i+1])) {
          strcpy(pom,slowa[i]);
          strcpy(slowa[i],slowa[i+1]);
          strcpy(slowa[i+1],pom);
          }
          else if (strlen(slowa[i]) == strlen(slowa[i+1])) {
          if(strcmp(slowa[i],slowa[i+1])<0) {
          strcpy(pom,slowa[i]);
          strcpy(slowa[i],slowa[i+1]);
          strcpy(slowa[i+1],pom);
          }
          }
          }
          }

          for (i=0; i<ILOSC; i++) {
          }
          }

/////////////////////////////////////////////////////////////////////////////////

// CZĘŚĆ NAPISANA PRZEZ STEFANA

int main () {
int i;
inicjalizacja(slowa);
sortowanie(slowa);
printf("\n WYNIK SORTOWANIA:\n\n");
for (i=0; i<ILOSC; i++)
printf(" %s\n", slowa[i]);
printf("\n");
return 0;
}

/* Uwaga: program powinien działać poprawnie również po zmianie wielkości stałych MAX_DLUG i ILOSC. */
