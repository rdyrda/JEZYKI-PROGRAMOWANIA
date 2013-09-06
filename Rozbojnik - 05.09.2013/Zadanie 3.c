/* Napisać program, wczytujący liczbę naturalną n i drukujący literę X wysokości zależnej od n:

n=2: n=4:

X   X
 X X
  X
 X X
X   X



X       X
 X     X
  X   X
   X X
    X
   X X
  X   X
 X     X
X       X

(w powyższym przykładzie liczba n określa liczbę wierszy pod i nad punktem przecięcia ,,ramion'' litery X). */

#include <stdio.h>

int
main (int argc, char *argv[])
{
int n, i,j,z,q;

printf("wprowadz liczbe N: \n");
scanf("%i", &n);
j = n*2-1;
q=n;
printf("\n");
/* Gora X-a */
for (i = 0; i < n; i += 1)
{
z=q;
while (z < n)
{
printf(" ",z);
z++;
}
printf("X");
z=j;
while (z > 0)
{
printf(" ",z);
z--;
}
printf("X");
printf("\n");
j -= 2;
q -= 1;
}
/* Srodek X-a */
for (i = 0; i < n; i += 1) printf(" ");
printf("X\n");

/*Dol X-a */
j=1;
for (i = 0; i < n; i += 1)
{
z=q;
while (z < n-1)
{
printf(" ");
z++;
}
printf("X");
z=j;
while (z > 0)
{
printf(" ");
z--;
}
printf("X");
printf("\n");
j += 2;
q += 1;
}

return 0;
}

/* LUB */

#include <stdio.h>

int main(){
int n, i, j, p1, p2;
scanf("%i", &n);
p1=0;
p2=n*2;
for(i=0;i<n*2+1;i++){
for(j=0;j<n*2+1;j++){
if(j==p1 || j==p2){
printf("X");
}else{
printf(" ");
}
}
p1+=1;
p2-=1;
printf("\n");
}
return 0;
}


// GRUPA NIEPARZYSTA

/* Napisać program, wczytujący liczbę naturalną n i drukujący literę Y wysokości zależnej od n:

n=2: n=4:

Y   Y
 Y Y
  Y
  Y



Y       Y
 Y     Y
  Y   Y
   Y Y
    Y
    Y
    Y
    Y

(w powyższym przykładzie liczba n określa wysokość ,,pnia'' litery Y, poniżej rozgałęzienia). */

#include<stdio.h>

int main(){
int n;
printf("podaj n: ");
scanf("%d",&n);
printf("\n\n\n");
int j,i=0,x=2*n-1;
while(i<n){
for(j=0;j<i;++j)
printf(" ");
printf("Y");
for(j=0;j<x;++j)
printf(" ");
printf("Y\n");
x=x-2;
++i;
}
for(i=0;i<n;++i){
for(j=0;j<n;++j)
printf(" ");
printf("Y\n");
}
return 0;
}
