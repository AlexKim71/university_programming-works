#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 3  // Размер квадратной матрицы

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void sortMatrix(int matrix[SIZE][SIZE]) {
    int totalSum = 0, count = 0;
    int i, j;

    // Подсчёт суммы всех элементов для нахождения среднего арифметического
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            totalSum += matrix[i][j];
            count++;
        }
    }

    // Нахождение среднего арифметического
    float avg = (float)totalSum / count;

    // Создаем массив для всех элементов матрицы
    int elements[SIZE * SIZE];
    int index = 0;

    // Заполнение массива элементами матрицы
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            elements[index++] = matrix[i][j];
        }
    }

    // Сортировка массива элементов по возрастанию
    quicksort(elements, 0, SIZE * SIZE - 1);

    // Заполнение матрицы отсортированными элементами
    index = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = elements[index++];
        }
    }
}

int main() {
    int matrix[SIZE][SIZE];

    // Ввод значений матрицы с клавиатуры
    printf("Введите элементы матрицы 3x3:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("Элемент [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Вывод начальной матрицы
    printf("Начальная матрица:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Вызов функции сортировки
    sortMatrix(matrix);

    // Вывод отсортированной матрицы
    printf("Отсортированная матрица:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Программу выполнил студент гр. АИ-243 Гаврилов О.В\n");

    return 0;
}

