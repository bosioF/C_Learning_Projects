#include <stdio.h>
#include <math.h>

int main() {
    double area = 0;
    double perimeter = 0;
    double base1 = 0, base2 = 0;
    double height = 0;
    double side = 0;

    printf("Inserisci base 1: ");
    while (scanf("%lf", &base1) != 1) {
        printf("Input non valido. \nInserisci base 1: ");
        while (getchar() != '\n');
        }

    printf("Inserisci base 2: ");
    while (scanf("%lf", &base2) != 1) {
        printf("Input non valido. \nInserisci base 1: ");
        while (getchar() != '\n');
    }

    printf("Inserisci altezza: ");
    while (scanf("%lf", &height) != 1) {
        printf("Input non valido. \nInserisci altezza: ");
        while (getchar() != '\n');  
    }

    area = ((base1 + base2) * height) / 2;

    side = sqrt((base2 - base1) * (base2 - base1) + height * height);

    perimeter = base1 + base2 + 2 * side;

    printf("\nArea: %.2lf\n", area);
    printf("Perimetro: %.2lf\n", perimeter);

    return 0;
}

