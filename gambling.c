#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

bool playagain() {
    char answer[10];
    printf("\nVuoi giocare ancora? (s/n): ");
    if (fgets(answer, sizeof(answer), stdin) != NULL) {
        answer[strcspn(answer, "\n")] = 0;
        for (int i = 0; answer[i]; i++)
            answer[i] = tolower(answer[i]);
        if (strcmp(answer, "s") == 0)
            return true;
        else if (strcmp(answer, "n") == 0) {
            printf("Grazie per aver giocato!\n");
            return false;
        }
    }
    printf("Input non valido, assumo che tu voglia uscire.\n");
    return false;
}

int main(void) {
    srand(time(NULL));

    char buffer[1000];
    char *endP;
    int balance = 1000;
    int bet = 0;

    printf("Benvenuto in gambling simulator. Bilancio iniziale di 1000.\n");

    while (1) {
        double quote = 1.0 + ((double)rand() / RAND_MAX) * 4.0;
        int N = (rand() % 100) + 1;
        bool greater = false;
        bool smaller = false;

        while (1) {
            printf("\nQuanto vuoi scommettere? ");
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                buffer[strcspn(buffer, "\n")] = 0;
                bet = strtol(buffer, &endP, 10);

                if (endP == buffer) {
                    printf("Non hai inserito un numero valido!\n");
                    continue;
                }

                if (bet <= 0) {
                    printf("stai provando ad hackerarmi!1!!!11!!1");
                }
                
                if (bet > balance) {
                    printf("Il tuo conto non tiene così tanti soldi broke ass.\n");
                    continue;
                }
                break;
            } else {
                printf("Errore nell'input\n");
                continue;
            }
        }

        printf("\nSelezionando la quota...");
        fflush(stdout);
        for (int i = 0; i < 3; i++) {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
        printf("\nQuota selezionata: %.2f\n", quote);

        while (1) {
            printf("\nMaggiore o minore di 50 il numero? ");
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                buffer[strcspn(buffer, "\n")] = 0;
                for (int i = 0; buffer[i]; i++)
                    buffer[i] = tolower(buffer[i]);

                if (strcmp(buffer, "maggiore") == 0) {
                    greater = true;
                    break;
                }
                else if (strcmp(buffer, "minore") == 0) {
                    smaller = true;
                    break;
                }
                else
                    printf("Input non valido!\n");
                continue;
            }
            break;
        }

        printf("\nGirando la ruota");
        fflush(stdout);
        for (int i = 0; i < 4; i++) {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
        printf("\nNUMERO GENERATO: %d\n", N);

        if (greater) {
            if (N > 50) {
                printf("Hai indovinato! Numero maggiore di 50.\n");
                balance += (int)(bet * quote);
            } else {
                printf("Hai perso! Numero non maggiore di 50.\n");
                balance -= bet;
            }
        } else if (smaller) {
            if (N < 50) {
                printf("Hai indovinato! Numero minore di 50.\n");
                balance += (int)(bet * quote);
            } else {
                printf("Hai perso! Numero non minore di 50.\n");
                balance -= bet;
            }
        }

        printf("Bilancio aggiornato: %d\n", balance);

        if (!playagain())
            break;
    }

    return 0;
}