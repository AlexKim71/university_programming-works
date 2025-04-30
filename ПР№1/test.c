#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Оголошення структури "Пацієнт"
typedef struct {
    char surname[50];
    char gender[10];
    int age;
    int pressure;
} Patient;

// Функція для введення даних
void inputPatients(Patient *patients, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nВведіть дані для пацієнта %d:\n", i + 1);
        printf("Прізвище: ");
        scanf("%s", (patients + i)->surname);
        printf("Стать: ");
        scanf("%s", (patients + i)->gender);
        printf("Вік: ");
        scanf("%d", &(patients + i)->age);
        printf("Тиск: ");
        scanf("%d", &(patients + i)->pressure);
    }
}

// Функція для виведення хворих з підвищеним тиском
void printHighPressurePatients(Patient *patients, int n) {
    printf("\nПацієнти з підвищеним тиском (>140):\n");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if ((patients + i)->pressure > 140) {
            printf("Прізвище: %s, Стать: %s, Вік: %d, Тиск: %d\n", 
                   (patients + i)->surname, (patients + i)->gender, 
                   (patients + i)->age, (patients + i)->pressure);
            found = 1;
        }
    }
    if (!found) {
        printf("Немає пацієнтів з підвищеним тиском.\n");
    }
}

int main() {
    printf("Роботу виконав студент гр. АІ24Х Прізвище Ім'я\n");
    
    int n = 5; // Мінімальна кількість пацієнтів
    Patient *patients = (Patient *)malloc(n * sizeof(Patient));
    if (patients == NULL) {
        printf("Помилка виділення пам'яті!\n");
        return 1;
    }
    
    char choice;
    do {
        inputPatients(patients, n);
        printHighPressurePatients(patients, n);
        
        printf("\nБажаєте повторити введення? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    free(patients);
    return 0;
}

