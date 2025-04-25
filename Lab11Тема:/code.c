#include <stdio.h>
#include <stdlib.h>
// Функція для обчислення середнього арифметичного масиву
double calculate_average(int *arr, int size) {
int sum = 0;
for (int *ptr = arr; ptr < arr + size; ptr++) {
sum += *ptr; // Додаємо значення елемента
}
return (double)sum / size;
}
int main() {
int N;
printf("Введіть кількість елементів масиву: ");
if (scanf("%d", &N) != 1 || N <= 0) {
printf("Некоректне значення N!\n");
return 1;
}
// Виділення пам'яті для масиву
int *A = (int *)malloc(N * sizeof(int));
if (A == NULL) {
printf("Помилка виділення пам'яті!\n");
return 1;
}
// Введення елементів масиву
printf("Введіть %d цілих чисел: ", N);
for (int *ptr = A; ptr < A + N; ptr++) {
if (scanf("%d", ptr) != 1) {
printf("Помилка введення даних!\n");
free(A);
return 1;
}
}
// Обчислення середнього арифметичного
double average = calculate_average(A, N);
printf("Середнє арифметичне: %.2f\n", average);
// Замінюємо негативні елементи
for (int *ptr = A; ptr < A + N; ptr++) {
if (*ptr < 0) {
*ptr = (int)average; // Заміна на середнє значення
}
}
// Виведення результатів
printf("Результат: ");
for (int *ptr = A; ptr < A + N; ptr++) {
printf("%d ", *ptr);
}
printf("\n");
// Звільнення пам'яті
free(A);
return 0;
}
