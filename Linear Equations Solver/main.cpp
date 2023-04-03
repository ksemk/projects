#include <iostream>
#include <stdio.h>

/**********************************************************
Program oblicza pierwiastki ukladu dwoch rownan liniowych metoda wyznacznikow
                a1 * x + b1 * y = c1
                a2 * x + b2 * y = c2
***********************************************************/



/***********************************************************
                      Prototypy funkcji
***********************************************************/

// Funkcja CzytajRownanie1 wczytuje wspolczynniki rownania pierwszego
//  a1 * x + b1 * y = c1
//  Parametry:
//      a1, b1, c1 - wspolczyniki okreslajace postac rownania.
void CzytajRownanie1(float &a1, float &b1, float &c1);

// Funkcja CzytajRownanie2 wczytuje wspolczynniki rownania drugiego
//  a2 * x + b2 * y = c2
//  Parametry:
//      a2, b2, c2 - wspolczyniki okreslajace postac rownania
void CzytajRownanie2(float &a2, float &b2, float &c2);

// Funckja Wyznacznik oblicza wyznacznik macierzy
//  Parametry:
//      p1 i p2 - wspolczynniki przy, odpowiednio, x1 i y1
//      p3 i p4 - wspolczynniki przy, odpowiednio,  x2 i y2
float Wyznacznik(float p1, float p2, float p3, float p4);

// Funckja WypiszRozwiazanie wypisuje rozwiazanie ukladu rownan oraz ich liczbe
//   Parametry:
//       N - liczba rozwiazan
//       x,y - rozwiazania ukladu
void WypiszRozwiazanie(int N, float x, float y);

// Funkcja ObliczRozwiazanie oblicza rozwiazanie ukladu rownan i zwraca:
//  2 - nieskonczenie wiele rozwiazan
//  1 - jest jedno rozwiazanie
//  0 - brak rozwiazan (uklad sprzeczny)
//  Parametry: a1, b1, c1 - wspolczyniki rownania pierwszego ukladu
//             a2, b2, c2 - wspolczyniki rownania drugiego ukladu
//             x,y - rozwiazanie ukladu
int ObliczRozwiazanie(float a1, float b1, float c1, float a2, float b2, float c2, float &x, float &y);


int main(int argc, char *argv[]) {
    printf("Program liczy pierwistki ukladu dwoch rownan liniowych\n\n");
    printf("\ta1 * X + b1 * y = c1\n");
    printf("\ta2 * X + b2 * y = c2\n");
    float a1, b1, c1; // pierwsze równanie,
    float a2, b2, c2; // drugie równanie,
    float x, y; // rozwiązanie,
    int N; // liczba rozwiazan.
    CzytajRownanie1(a1, b1, c1);
    CzytajRownanie2(a2, b2, c2);
    N = ObliczRozwiazanie(a1, b1, c1, a2, b2, c2, x, y);
    WypiszRozwiazanie(N, x, y);
    printf("\n");
    system("PAUSE");
}

void CzytajRownanie1(float &a1, float &b1, float &c1) {
    printf("\nPodaj wspolczynniki a1, b1, c1 pierwszego rownania ukladu: \n");
    scanf("%f%f%f", &a1, &b1, &c1);
    printf("\nPierwsze rownanie:\n\n\t%0.2f * X %+0.2f * y = %0.2f\n", a1, b1, c1);
}

void CzytajRownanie2(float &a2, float &b2, float &c2) {
    printf("\nPodaj wspolczynniki a2, b2, c2 drugiego rownania ukladu: \n");
    scanf("%f%f%f", &a2, &b2, &c2);
    printf("\nDrugie rownanie:\n\n\t%0.2f * X +%0.2f * y = %0.2f\n", a2, b2, c2);
}

float Wyznacznik(float p1, float p2, float p3, float p4) {
    return p1 * p4 - p3 * p2;
}

int ObliczRozwiazanie(float a1, float b1, float c1, float a2, float b2, float c2, float &x, float &y) {
    float det, det_x, det_y;
    det = Wyznacznik(a1, b1, a2, b2);
    det_x = Wyznacznik(c1, b1, c2, b2);
    det_y = Wyznacznik(a1, c1, a2, c2);
    if (det == 0 && det_x == 0 && det_y == 0) return 2;
    if (det != 0) {
        x = (det_x / det);
        y = (det_y / det);
        return 1;
    } else return 0;
}

void WypiszRozwiazanie(int N, float x, float y) {
    switch (N) {
        case 2:
            printf("\nUklad posiada nieskonczenie wiele rozwiazan\n");
            break;
        case 1:
            printf("\nUklad posiada jedno rozwiazanie: \n\n");
            printf("x = %0.2f\n", x);
            printf("y = %0.2f\n", y);
            break;
        case 0:
            printf("\nUklad nie posiada rozwiazan\n");
            break;
        default:
            printf("\nWystapil blad!\n");
    }
}