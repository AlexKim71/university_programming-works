#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    // Введення значення k з клавіатури
    int k;
    printf("Введіть значення k: ");
    scanf("%d", &k);

    // Ініціалізація змінних для суми і добутку
    double sum = 0;
    double product = 1;
    int has_nonzero_term = 0;  // Прапорець для перевірки наявності ненульового доданку

    // Цикл for для обчислення суми та добутку
    for (int i = -2; i <= k; i++) {
        // Обчислення доданка
        double term = pow(-1, i) * tgamma(i + 4) / (2 * (i - 4));

        // Перевірка, чи доданок не є нулем або нескінченністю
        if (isfinite(term) && term != 0) {
            sum += term;
            product *= term;
            has_nonzero_term = 1;
        }
    }

    // Виведення результатів
    printf("Сума: %lf\n", sum);
    if (has_nonzero_term) {
        printf("Добуток: %lf\n", product);
    } else {
        printf("Добуток не визначений, оскільки всі доданки дорівнюють нулю або нескінченності.\n");
    }

    printf("Програму виконав студент гр. АІ-243 Гаврилов О.В\n");
    return 0;
}

