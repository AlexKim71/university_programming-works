#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    double a, x, y;

    // Вводимо значення a
    printf("Введіть значення a: ");
    scanf("%lf", &a);

    // Вводимо значення x
    printf("Введіть значення x: ");
    scanf("%lf", &x);

    // Обчислюємо значення y за заданою формулою
    if (fabs(x - 3) > a) {
        y = x / 5;
    } else if (fabs(x - 3) == a) {
        y = a * 5;
    } else {
        y = a - 12;
    }    
          // Виводимо результат у вигляді таблиці
     printf("Програму виконав студент гр. АІ-243 Гаврилов О.В\n"); 
     printf("| %.2lf | %.2lf |\n", x, y);

    return 0;
}

