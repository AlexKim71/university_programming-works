#include <stdio.h>
#include <math.h>
#include <locale.h>


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double e;
    printf("Введіть число e (0.0001 < e < 0.01): ");
    scanf("%lf", &e);

    // Перевірка діапазону для числа e
    if (e <= 0.0001 || e >= 0.01) {
        printf("Число e повинно бути в діапазоні (0.0001, 0.01)\n");
        return 1;
    }

    // Ініціалізація змінних
    double ni, ni_1;
    int i = 1;

    // Початкове значення n1
    ni = (8.0 * i - 5) / (2.0 * i);
    printf("Числа n_i, для яких виконується умова |n_i - n_(i-1)| >= e:\n");

    // Цикл для виведення чисел, поки |n_i - n_(i-1)| >= e
    while (1) {
        ni_1 = ni;
        i++;
        ni = (8.0 * i - 5) / (2.0 * i);

        if (fabs(ni - ni_1) < e) break; // Вихід з циклу, якщо |n_i - n_(i-1)| < e

        printf("%lf\n", ni);
    }

    printf("Програму виконав студент гр. АІ-243 Гаврилов О.В\n");
    // Виведення першого числа, яке відповідає умові
    printf("Перше число n_i, яке відповідає умові |n_i - n_(i-1)| < e: %lf, його номер i: %d\n", ni, i);


    return 0;
}

