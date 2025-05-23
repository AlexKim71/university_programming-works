#include <stdio.h>

// Функція для обчислення виразу Y = 9(3a + b/4)
int calculateExpression(int a, int b) {
    // Обчислення значення виразу без розкриття дужок і скорочення доданків
    int result = 9 * (3 * a + (b >> 2)); // Використовуємо зсув вправо для ділення на 4
    return result;
}

int main() {
    FILE *fileA, *fileB;
    int a, b;

    // Відкриваємо файл А для читання
    fileA = fopen("A.txt", "r");
    if (fileA == NULL) {
        printf("Помилка відкриття файлу А.\n");
        return 1;
    }

    // Відкриваємо файл В для запису
    fileB = fopen("B.txt", "w");
    if (fileB == NULL) {
        printf("Помилка відкриття файлу В.\n");
        fclose(fileA);
        return 1;
    }

    // Зчитуємо значення a і b з файлу А
    if (fscanf(fileA, "%d %d", &a, &b) != 2) {
        printf("Помилка зчитування даних з файлу А.\n");
        fclose(fileA);
        fclose(fileB);
        return 1;
    }

    // Обчислюємо значення виразу
    int result = calculateExpression(a, b);

    // Записуємо результат у файл В
    fprintf(fileB, "%d\n", result);

    // Закриваємо файли
    fclose(fileA);
    fclose(fileB);

    printf("Результат обчислення записано у файл В.\n");
    printf("Виконав Гаврилов О.В. з групи AI-243\n");

    return 0;
}