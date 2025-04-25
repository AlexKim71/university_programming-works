#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ROWS 3  // Кількість рядків
#define COLS 3  // Кількість стовпців

void swapRows(int matrix[ROWS][COLS], int firstRow, int secondRow) {
    int temp;
    for (int j = 0; j < COLS; j++) {
        temp = matrix[firstRow][j];
        matrix[firstRow][j] = matrix[secondRow][j];
        matrix[secondRow][j] = temp;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int matrix[ROWS][COLS] = {
        {5, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };
    int zeroRow = -1;  // Індекс рядка з першим нульовим елементом

    // Пошук першого нульового елемента в матриці
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == 0) {
                zeroRow = i;  // Запам'ятовуємо індекс рядка з нулем
                break;
            }
        }
        if (zeroRow != -1) break;  // Припиняємо пошук, якщо знайдено нуль
    }

    // Вивід початкової матриці
    printf("Початкова матриця:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Міняємо місцями перший рядок з рядком, що містить перший нульовий елемент
    if (zeroRow != -1) {
        swapRows(matrix, 0, zeroRow);
    }

    // Вивід результату
    printf("Матриця після обміну рядків:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Програму виконав студент гр. АІ-243 Гаврилов О.В\n");

    return 0;
}

