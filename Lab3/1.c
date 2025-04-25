#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double x, y;
    printf("Введіть координату x: ");
    scanf("%lf", &x);
    printf("Введіть координату y: ");
    scanf("%lf", &y);

    // Перевірка, чи точка належить квадрату
    if (x >= -1 && x <= 1 && y >= -1 && y <= 1) {
        printf("Програму виконав студент гр. АІ-243 Гаврилов О.В\n");
        printf("Точка належить заштрихованій області.\n");
    } else {
        printf("Програму виконав студент гр. АІ-243 Гаврилов О.В\n");
        printf("Точка не належить заштрихованій області.\n");
    }

    return 0;
}

