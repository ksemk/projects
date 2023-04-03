
#include <stdio.h>
#include <stdlib.h>

#define ROZMIAR_SLOWNIKA 81 // Maksymalna liczba imion w slowniku

/***********************************************************
                      Prototypy funkcji
***********************************************************/
// Funkcja dodaje do slownika nowe imie wprowadzane z klawiatury
void wprowadzNoweImie(char **, int *);

// Funkcja drukuje na ekranie wszystkie imiona zapamietane w slowniku
void wyswietlWszystkieImiona(char **, int);

// Funkcja usuwa imie znajdujace sie na wskazanej pozycji w tablicy (nalezy podac
// indeks pozycji, na ktorej znajduje sie imie do usuniecia)
void usunImieZPozycji(char **, int *, int);

// Funkcja drukuje na ekranie wszystkie imiona rozpoczynające wskazaną literą alfabetu
void drukujImionaNa(char **imiona, int iloscImion, char litera);

// Funkcja usuwa z tablicy imie, wprowadzone z klawiatury (program powinien
// odszukac pozycje tablicy, na ktorej znajduje sie wskazane imie, a nastepnie wywolac
// funkcje realizujaca operacje usuwania z poprzedniego punktu)
void usunImie(char **, int *, char *);

// Funkcja sortuje wszystkie imiona zawarte w tablicy według alfabetu
void sortujImionaAlfabetycznie(char **, int);

// Funkcja sortuje wszystkie imiona zawarte w tablicy wedlug dlugosci lancuchu znakow
void sortujImionaWedlugDlugosci(char **, int);


int main() {
    char **imiona = (char **) calloc(ROZMIAR_SLOWNIKA, sizeof(char *)); // Tworzymy slownik imion
    int iloscImion = 0; // Liczba aktualnie zapamietanych imion
    int opcja; // Wybrana opcja z menu

//Menu
    do {
        printf("Wybierz opcje: \n");
        printf("1. Wprowadz nowe imie\n");
        printf("2. Wyswietl wszystkie imiona\n");
        printf("3. Wyswietl wszystkie imiona na podana litere\n");
        printf("4. Usun imie z pozycji\n");
        printf("5. Usun imie\n");
        printf("6. Sortuj imiona alfabetycznie\n");
        printf("7. Sortuj imiona wedlug dlugosci\n");
        printf("8. Zakoncz program\n\n");
        scanf("%d", &opcja);

        switch (opcja) {
            case 1:
                wprowadzNoweImie(imiona, &iloscImion);
                printf("\n");
                break;
            case 2:
                wyswietlWszystkieImiona(imiona, iloscImion);
                printf("\n");
                break;
            case 3: {
                char symbol;
                printf("Podaj symbol:\n");
                scanf(" %c", &symbol);
                drukujImionaNa(imiona, iloscImion, symbol);
                printf("\n");
                break;
            }
            case 4: {
                int pozycja;
                printf("Podaj pozycje imienia, ktore chcesz usunac: ");
                scanf("%d", &pozycja);
                usunImieZPozycji(imiona, &iloscImion, pozycja);
                printf("\n");
                break;
            }
            case 5: {
                char imie[50];
                printf("Podaj imie, ktore chcesz usunac: ");
                scanf("%s", imie);
                usunImie(imiona, &iloscImion, imie);
                printf("\n");
                break;
            }
            case 6:
                sortujImionaAlfabetycznie(imiona, iloscImion);
                printf("\n");
                break;
            case 7:
                sortujImionaWedlugDlugosci(imiona, iloscImion);
                printf("\n");
                break;
            default:
                printf("Niepoprawna opcja. Prosze wybrac opcje z menu.\n");
                break;
        }
    } while (opcja != 8);
}


// Funkcja dodaje do slownika nowe imie wprowadzane z klawiatury
void wprowadzNoweImie(char **imiona, int *iloscImion) {
    if (*iloscImion < ROZMIAR_SLOWNIKA) {
        char imie[50];
        printf("Wprowadz nowe imie: ");
        scanf("%s", imie);
        // Obliczamy dlugosc imie
        int dlugoscImie = 0;
        while (imie[dlugoscImie] != '\0') {
            dlugoscImie++;
        }
        imiona[*iloscImion] = (char *) malloc((dlugoscImie + 1) * sizeof(char));
        // Kopiujemy kolejne znaki z imie do imiona[*iloscImion]
        for (int i = 0; i < dlugoscImie; i++) {
            imiona[*iloscImion][i] = imie[i];
        }
        // Dodajemy znak konca linii
        imiona[*iloscImion][dlugoscImie] = '\0';
        (*iloscImion)++;
    } else {
        printf("Slownik pelny!\n");
    }
}

// Funkcja drukuje na ekranie wszystkie imiona zapamietane w slowniku
void wyswietlWszystkieImiona(char **imiona, int iloscImion) {
    if (iloscImion == 0) {
        printf("Slownik jest pusty!\n");
    } else {
        printf("Imiona w slowniku: \n");
        for (int i = 0; i < iloscImion; i++) {
            printf("%s\n", imiona[i]);
        }
    }
}

// Funkcja drukuje na ekranie wszystkie imiona rozpoczynające wskazaną literą alfabetu
void drukujImionaNa(char **imiona, int iloscImion, char symbol) {
    int asciiSymbol = (int) symbol;
    if (asciiSymbol >= 65 && asciiSymbol <= 90) {
        asciiSymbol += 32;
    }

    for (int i = 0; i < iloscImion; i++) {
        int asciiImie = (int) imiona[i][0];
        if (asciiImie >= 65 && asciiImie <= 90) {
            asciiImie += 32;
        }

        if (asciiImie == asciiSymbol) {
            printf("%s\n", imiona[i]);
        }
    }
}

// Funkcja usuwajaca imie z podanej pozycji w slowniku
void usunImieZPozycji(char **imiona, int *iloscImion, int pozycja) {
    if (pozycja < 0 || pozycja >= *iloscImion) {
        printf("Nieprawidlowa pozycja!\n");
    } else {
        free(imiona[pozycja]);

        // Przesuwamy pozostale imiona o jeden w lewo, aby zapelnic luke po usunietym imieniu
        for (int i = pozycja; i < *iloscImion - 1; i++) {
            imiona[i] = imiona[i + 1];
        }
        (*iloscImion)--;
    }
}

// Funkcja usuwajaca imie o podanej nazwie z slownika
void usunImie(char **imiona, int *iloscImion, char *imie) {
    int pozycja = -1;
    for (int i = 0; i < *iloscImion; i++) {
        // Porownujemy kolejne znaki z imiona[i] i imie
        int dlugosc = 0;
        while (imiona[i][dlugosc] != '\0' && imie[dlugosc] != '\0' && imiona[i][dlugosc] == imie[dlugosc]) {
            dlugosc++;
        }
        // Jesli doszlismy do konca obu lancuchow i sa one takie same, to znalezlismy pozycje
        if (imiona[i][dlugosc] == '\0' && imie[dlugosc] == '\0') {
            pozycja = i;
        }
    }
    if (pozycja == -1) {
        printf("Nie znaleziono imienia o podanej nazwie!\n");
    } else {
        usunImieZPozycji(imiona, iloscImion, pozycja);
    }
}

// Funkcja sortujaca imiona alfabetycznie
void sortujImionaAlfabetycznie(char **imiona, int iloscImion) {
    // Sortowanie babelkowe
    for (int i = 0; i < iloscImion - 1; i++) {
        for (int j = 0; j < iloscImion - i - 1; j++) {
            // Porownujemy kolejne znaki w obu imionach
            int k = 0;
            while (imiona[j][k] == imiona[j + 1][k]) {
                k++;
            }
            // Jesli znalezlismy roznice, porownujemy ASCII obu znakow
            if (imiona[j][k] > imiona[j + 1][k]) {
                // Zamieniamy miejscami imiona o nazwach wzgledem siebie nieposortowanych
                char *tmp = imiona[j];
                imiona[j] = imiona[j + 1];
                imiona[j + 1] = tmp;
            }
        }
    }
}

// Funkcja sortujaca imiona wedlug dlugosci
void sortujImionaWedlugDlugosci(char **imiona, int iloscImion) {
    // Sortowanie babelkowe
    for (int i = 0; i < iloscImion - 1; i++) {
        for (int j = 0; j < iloscImion - i - 1; j++) {
            // Obliczamy dlugosci imion
            int dlugoscImienia1 = 0;
            while (imiona[j][dlugoscImienia1] != '\0') {
                dlugoscImienia1++;
            }
            int dlugoscImienia2 = 0;
            while (imiona[j + 1][dlugoscImienia2] != '\0') {
                dlugoscImienia2++;
            }
            if (dlugoscImienia1 > dlugoscImienia2) {
                // Zamieniamy miejscami imiona o dlugosciach wzgledem siebie nieposortowanych
                char *tmp = imiona[j];
                imiona[j] = imiona[j + 1];
                imiona[j + 1] = tmp;
            }
        }
    }
}