#include <stdio.h>
#include <math.h>
#include <locale.h>


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Задане число a
    double a;
    printf("Введіть число a (3.5 < a < 3.95): ");
    scanf("%lf", &a);

    // Перевірка діапазону для числа a
    if (a <= 3.5 || a >= 3.95) {
        printf("Число a повинно бути в діапазоні (3.5, 3.95)\n");
        return 1;
    }

    // Ініціалізація змінних
    double ni;
    int i = 1;
    double suma = 0;

    // Цикл для виведення чисел, поки ni <= a
    printf("Числа n_i поки n_i <= a:\n");
    while (1) {
        ni = (8.0 * i - 5) / (2.0 * i);
        if (ni > a) break; // Вихід з циклу, якщо ni > a
        printf("%lf\n", ni);
        suma += ni;
        i++;
    }

     printf("Програму виконав студент гр. АІ-243 Гаврилов О.В\n");
    // Виведення суми всіх чисел
    printf("Сума всіх чисел: %lf\n", suma);

    // Пошук першого ni, яке більше за a
    printf("Перше число n_i, яке більше за a: %lf, його номер i: %d\n", ni, i);

    return 0;
}

