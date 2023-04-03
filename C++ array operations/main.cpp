#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;
#define ROZMIAR	5
float tab[ROZMIAR];

void wczytaj_tablice(float* t) {
    printf("Prosze podac %d liczb: \n", ROZMIAR);
    for (int i = 0; i < ROZMIAR; i++) scanf_s("%f", i + t);
    printf("\n");
}
void wyswietlij_elementy(float* t) {
    for (int i = 0; i < ROZMIAR; i++) printf("Tab[%d] = %f\n", i, *(i + t));
    printf("\n");
    printf("Press Enter to Continue\n");
    _getch();
}
void wyswietlij_tablice(float* t) {
    printf("Tab = [ ");
    for (int i = 0; i < ROZMIAR; i++) printf(" %.1f ", *(i + t));
    printf(" ]\n\n");
    printf("Press Enter to Continue\n");
    _getch();
}
void znaki_elementow_tablicy() {
    int dod = 0, uj = 0;
    float dod_sum = 0, uj_sum = 0;
    for (int i = 0; i < ROZMIAR; i++) {
        if (tab[i] >= 0) {
            dod += 1;
            dod_sum += tab[i];
        }
        else {
            uj += 1;
            uj_sum += tab[i];
        }
    }
    printf("Ilosc liczb dodatnich i rownych zero wynosi: %d\n", dod);
    printf("Ilosc liczb ujemnych wynosi: %d\n", uj);
    printf("Srednia liczb dodatnich i rownych zero wynosi: %f\n", dod_sum / float(dod));
    printf("Srednia liczb ujemnych wynosi: %f\n\n", uj_sum / float(uj));
    printf("Press Enter to Continue\n");
    _getch();
}
void uporzadkowanie_elementow_tablicy() {
    bool mal, rosn, stal, nieup = false;
    for (int i = 1; i < ROZMIAR; i++) {
        if (tab[i] == tab[i - 1]) stal = true;
        else {
            stal = false;
            break;
        }
    }
    if (stal) printf("Wszystkie elementy maja jednakowa wartosc\n");
    for (int i = 1; i < ROZMIAR; i++) {
        if (tab[i] > tab[i - 1]) rosn = 1;
        else {
            rosn = false;
            break;
        }
    }
    if (rosn) printf("Wszystkie elementy tablicy sa uporzadkowane rosnaco\n");
    for (int i = 1; i < ROZMIAR; i++) {
        if (tab[i] < tab[i - 1]) mal = true;
        else {
            mal = false;
            break;
        }
    }
    if (mal) printf("Wszystkie elementy tablicy sa uporzadkowane malejaca\n");
    if (!mal && !rosn && !stal) nieup = true;
    if (nieup) printf("Wszystkie elementy tablicy sa nieuporzadkowane\n");
    if (!nieup && !mal) printf("Wszystkie elementy tablicy sa uporzadkowane niemalejaco\n");
    if (!nieup && !rosn) printf("Wszystkie elementy tablicy sa uporzadkowane nierosnaco\n");

    printf("\nPress Enter to Continue\n");
    _getch();
}
void wypelnienie_liczbami_losowymi() {
    float min, max;
    srand(time(NULL));
    printf("Podaj granicy zakresu losowania min i max\n");
    scanf_s("%f %f", &min, &max);
    for (int i = 0; i < ROZMIAR; i++) {
        tab[i] = min + (max - min) * rand() / ((float)RAND_MAX);
    }
}
void sortowanie() {
    float temp;
    for (int i = 0; i < ROZMIAR - 1; i++) {
        for (int x = 0; x < ROZMIAR - i - 1; x++) {
            if (tab[x] > tab[x + 1]) {
                temp = tab[x];
                tab[x] = tab[x + 1];
                tab[x + 1] = temp;
            }
        }
    }
}
void zaliczenie_syboli() {
    int Tab[26] = { 0 };
    short num = 0;
    char znak;
    do {
        znak = _getch();
        printf("%c", znak);
        if (znak >= 'A' && znak <= 'Z') Tab[znak - 'A']++;
        if (znak >= 'a' && znak <= 'z') Tab[znak - 'a']++;
        if (znak != 27) num++;
    }
    while (znak != 27);
    for (int i = 0; i < 26; i++) {
        printf("\n Litera %c %d ", 'A' + i, Tab[i]);
        for (int k = 0; k < Tab[i]; k++) printf("#");
    }
    printf("\n");
}
int main() {
    wczytaj_tablice(tab);
    bool stop = false;
    while(!stop) {
        int zad;
        cout << "Prosze wybrac numer funkcji: \n\n"
                "1 - ktora wyszwietla podane elementy tablicy;\n"
                "2 - ktora umozliwia wypisanie na ekranie wszystkich elementow tablicy;\n"
                "3 - ktora sprawdzi i wypisze na ekranie komunikaty;\n"
                "4 - ktora sprawdzi i wyswietli na ekranie informacje o uporzadkowaniu elementow tablicy;\n"
                "5 - ktora umozliwia wypelnienie tablicy liczbami losowymi z zadanego przedzialu;\n"
                "6 - ktora uporzadkuje elementy tablicy rosnaco;\n"
                "7 - ktora oblicza ilosc liter we wpisanym tekscie;\n"
                "0 - Wyjscie z programu;\n";
        cin >> zad;
        switch (zad) {
            case 1:
                cout << "Funkcja, ktora wyszwietla podane elementy tablicy\n\n";
                wyswietlij_elementy(tab);
                break;
            case 2:
                cout << "Funkcja, ktora umozliwia wypisanie na ekranie wszystkich elementow tablicy\n\n";
                wyswietlij_tablice(tab);
                break;
            case 3:
                cout << "Funkcja, ktora sprawdzi i wypisze na ekranie komunikaty\n\n";
                znaki_elementow_tablicy();
                break;
            case 4:
                cout << "Funkcja, ktora sprawdzi i wyswietli na ekranie informacje o uporzadkowaniu elementow tablicy\n\n";
                uporzadkowanie_elementow_tablicy();
                break;
            case 5:
                cout << "Funkcja, ktora umozliwia wypelnienie tablicy liczbami losowymi z zadanego przedzialu\n\n";
                wypelnienie_liczbami_losowymi();
                break;
            case 6:
                cout << "Funkcja, ktora uporzadkuje elementy tablicy rosnaco\n\n";
                sortowanie();
                break;
            case 7:
                cout << "Funkcja, ktora oblicza ilosc liter we wpisanym tekscie\n\n";
                zaliczenie_syboli();
                break;
            case 0:
                stop = true;
                break;
            default:
                cout << "Nie ma takiego zadania!\n\n";
        }
    }
}