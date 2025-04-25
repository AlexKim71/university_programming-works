#include <stdio.h>
#include <math.h>
#include <locale.h>


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    for (int i = 100; i <= 500; i++) {
        int sum = 0;
        int number = i;

        // Обчислення суми цифр числа
        while (number != 0) {
            sum += number % 10;
            number /= 10;
        }

        // Перевірка, чи сума цифр дорівнює 15
        if (sum == 15) {
            printf("%d\n", i);
        }
    }

    printf("Програму виконав студент гр. АІ-243 Гаврилов О.В\n");
    return 0;
}
      
