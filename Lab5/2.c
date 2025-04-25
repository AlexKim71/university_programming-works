#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <windows.h>  // Для использования SetConsoleCP и SetConsoleOutputCP на Windows

int main() {

    // Установка локали для корректного вывода текста на Windows
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double a, x = 2, h = 13, f;

    // Введення значення a
    printf("Введіть значення a: ");
    scanf("%lf", &a);

    // Заголовок таблиці
    printf("Програму виконав студент гр. АІ-243 Гаврилов О.В\n");
    printf("|   x   |   f(x)   |\n");
    printf("|------------------|\n");

    // Цикл while для обчислення значень функції
    while (x <= 315) {
        // Перевірка на ділення на нуль та корінь з від'ємного числа
        if (a - x == 0 || a + pow(x, 3) <= 0) {
            printf("|   %.2lf   |   Помилка обчислень   |\n", x);
        } else {
            // Обчислення значення функції
            f = sqrt(a + pow(x, 3)) / (a - x) + cbrt(x);
            printf("|   %.2lf   |   %.2lf   |\n", x, f);
        }

        // Увеличиваем значение x на шаг h
        x += h;
    }

    return 0;
}

