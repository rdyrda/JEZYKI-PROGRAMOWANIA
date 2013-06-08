/* Pliki: rys.o i rys.h stanowią one bibliotekę funkcji, potrzebnych do rysowania krzywych w grafice ASCII. 
Pierwszy z tych plików nie jest bezpośrednio czytelny, ale w drugim, czytelnym pliku nagłówkowym rys.h, 
opisane są dostępne tam funkcje.
Natomiast w pliku test.c znajduje się przykład programu, współpracującego z tą biblioteką. Proszę zwrócić uwagę 
na początkowy wiersz

#include "rys.h"

oraz na obowiązkową definicję funkcji

void inic_stale(Stale* stale);

Niżej są już tylko definicje krzywych, które chcemy rysować; oraz program główny, tworzący rysunek. */

/* Na wzór tego programu napisać i uruchomić własny, rysujący katenoidę, daną wzorem

r(t) = (t , a·cosh(t/a)) 

przy czym kosinus hiperboliczny zdefiniowany jest następująco:

cosh(x) = 0.5 · (ex + e−x) 

Dobrać takie wartości stałych w funkcji inicjalizującej oraz takie wartości zmiennej a, żeby rysunek 
wyszedł ,,przekonujący''; katenoida powina być symetryczna i podobna do paraboli. */

/* PLIK rys.h */

//==================================================
// Definicja typu  Stale :

typedef struct {
  int szerokosc;  // szerokosc rysunku, czyli dlugosc wiersza (w znakach)
  int wysokosc;   // wysokosc rysunku (w wierszach)
    // poziomy wymiar prostokata na plaszczyznie, ktory rysujemy:
  double dolny_x, gorny_x;
    // pionowy wymiar prostokata na plaszczyznie, ktory rysujemy:
  double dolny_y, gorny_y;
}  Stale;

    /* Uzytkownik programu musi sam zdefiniowac funkcje
         void  inic_stale (Stale* stale);
       ktora ustali wartosc zmiennej typu  Stale .
    */

//==================================================
// Funkcje, dostarczane przez biblioteke:

void  inicjuj ();
    /* Funkcja przygotowujaca pusta plansze.  Trzeba ja wywolac przed
       kazdym nowym rysunkiem.
    */

void  rysuj (void krzywa(double t, double* x, double* y),
             double t_pocz, double t_kon, double t_krok,
             char c
            );
    /* Funkcja rysujaca krzywa.
       Jej pierwszym parametrem ma byc funkcja wyliczajaca wspolrzedne
       olowka na plaszczyznie w chwili  t .
       Trzy kolejne parametry to chwila, kiedy zaczyna sie ruch
       olowka; chwila, kiedy sie konczy; oraz odstep czasowy miedzy
       kolejnymi chwilami.
       Ostatni parametr to znak, jakim nalezy rysowac krzywa.
    */

void  drukuj (char podpis[]);

    /* Funkcja drukujaca przygotowana plansze, dolaczajac podpis.
    */

//==================================================


