// GRUPA PARZYSTA

/* Napisać program, który wczytuje

liczbę naturalną n, oraz
ciąg n słów porozdzielanych spacjami lub zmianami wiersza

(można założyć sobie jakąś górną granicę długości słowa), a następnie drukuje je w kolejności a tergo (od końca).
To znaczy wg alfabetycznej kolejności ostatniej litery, a jeśli dla dwóch słów jest ona taka sama, to wg przedostatniej, 
itp.

Np. poniższa piątka słów jest uporządkowana a tergo:

wrona
pies
pokos
kot
pokot */

#include<stdio.h>
#include<string.h>

void reverse(char napis[][100], int n){
int k, i, j;
char temp[1][100];
for(i=0;i<n;i++){
k=strlen(napis[i]);
j=0;
k=k-1;
while(k>=0){
temp[0][j]=napis[i][k];
k--;
j++;
}
temp[0][j]='\0';
j=0;
k=strlen(napis[i]);
while(j<k){
napis[i][j]=temp[0][j];
j++;
}
}
}

void sortowanie(char slowa[][100], int n){
reverse(slowa, n);
int i, j;
char temp[n][100];
for (i=0;i<n;i++){
for (j=0;j<n-1-i;j++){
if(strcmp(slowa[j],slowa[j+1])>0){
strcpy(temp[0],slowa[j+1]);
strcpy(slowa[j+1],slowa[j]);
strcpy(slowa[j],temp[0]);
}
}
}
reverse(slowa, n);
}

int main(){
int n, i;
printf("Podaj liczbe: ");
scanf("%i", &n);
char napis[n][100];
printf("Podaj ciag slow:\n");
for(i=0;i<n;i++){
scanf("%s", napis[i]);
}
sortowanie(napis, n);
printf("Posortowane slowa:\n");
for(i=0;i<n;i++){
printf("%s\n", napis[i]);
}
return 0;
}


// GRUPA NIEPARZYSTA

/* Napisać program, który wczytuje

liczbę naturalną n, oraz
ciąg n liczb całkowitych dodatnich,

a następnie drukuje je w kolejności określonej następująco: liczba p jest wcześniejsza od liczby q w następujących 
przypadkach:

jeśli suma cyfr p jest mniejsza od sumy cyfr q; np. 111 (suma cyfr 3) jest wcześniejsze niż 22 (suma cyfr 4);
jeśli sumy cyfr są równe ale q jest ,,bardziej parzyste'' niż p, czyli podzielne przez wyższą potęgę liczby 2;
np. 44 (suma cyfr 8, podzielne przez 22) jest wcześniejsze niż 8 (suma cyfr 8, podzielne przez 23);
jeśli sumy cyfr i parzystości są równe, to decyduje wielkość liczby (im mniejsza tym wcześniejsza);
np. 3 jest wcześniejsze niż 111 (suma cyfr 3, podzielne przez 20). */

#include<stdio.h>

int sumacyfr(int a){
if (a==0)
return 1;
int i=0;
while(a!=0){
a=a/10;
++i;
}
return i;
}

int parzystosc(int a){
int i=0;
if(a==0)
return 9999;
while(!(a%2)){
a=a/2;
++i;
}
return i;
}


int warunek(int a, int b){
if(sumacyfr(b)>sumacyfr(a))
return 1;
if(sumacyfr(b)==sumacyfr(a)){
if(parzystosc(b)<parzystosc(a))
return 1;
if(parzystosc(b)==parzystosc(a))
if(b<a)
return 1;
}

return 0;
}

void sortowanie(int tab[],int n){
int i, j;
int pom;
for (i = 0; i<n; i++)
{
for (j=0; j<n-1-i; j++)
{
if (warunek(tab[j], tab[j+1]))// warunek
{
// zamiana
pom=tab[j];
tab[j]=tab[j+1];
tab[j+1]=pom;

}
}

}
}


int main(){
int n,i;
printf("podaj n: ");
scanf("%d",&n);
int tab[n];
for(i=0;i<n;++i)
scanf("%d",&tab[i]);
sortowanie(tab,n);
printf("\n\n\n");
printf("posortowane:\n");
for(i=0;i<n;++i)
printf("%d\n",tab[i]);

return 0;
}

/* LUB */

#include <stdio.h>
#include <string.h>

int return_wartosc_cyfr_liczby(int liczba);
int return_najwzszy_parzysty_dzielnik(int liczba);

void sortuj_tab(int tab[],int n);

int main(void)
{
    unsigned int n;
    printf("Prosze podac N:\n");
    scanf("%i",&n);
    unsigned int tab[n];
    int i;
    for(i=0;i<n;i++)
    {
        printf("Podaj tab[%i]\n",i);
        scanf("%i",&tab[i]);
    }
    sortuj_tab(tab,n);
    for(i=0;i<n;i++)
    {
        printf("%i \n",tab[i]);
    }

    return 0;
}

    int return_wartosc_cyfr_liczby(int liczba)
    {
        int wynik;
        wynik = 0;
        while (liczba != 0)
        {
            wynik += liczba%10;
            liczba /= 10;
        }
        return wynik;
    }

    int return_najwzszy_parzysty_dzielnik(int liczba)
    {
        int i;
        if( ((liczba%10)==0) || ((liczba%10)== 2) || ((liczba%10)==4) || ((liczba%10)==6) || ((liczba%10)==8))
        {
            for(i=2;liczba%i==0;i*=2);

            return i;
        }
        else
            return 0;
    }

    void sortuj_tab(int tab[],int rozmiar)
    {
        int i, j, temp;
        for (i = 0; i<rozmiar; i++)
        {
                for (j=0; j<rozmiar-1-i; j++)
                {
                        if (return_wartosc_cyfr_liczby(tab[j]) > return_wartosc_cyfr_liczby(tab[j+1]))
                        {
                                temp = tab[j+1];
                                tab[j+1] = tab[j];
                                tab[j] = temp;
                        }
                        else if((return_wartosc_cyfr_liczby(tab[j]) == return_wartosc_cyfr_liczby(tab[j+1]))  && (return_najwzszy_parzysty_dzielnik(tab[j]) > return_najwzszy_parzysty_dzielnik(tab[j+1])))
                        {
                                temp = tab[j+1];
                                tab[j+1] = tab[j];
                                tab[j] = temp;
                        }
                        else if (tab[j] > tab[j+1])
                        {
                                temp = tab[j+1];
                                tab[j+1] = tab[j];
                                tab[j] = temp;
                        }
                }
        }
    }
