#include <stdio.h>
#include <string.h>
#include <math.h>
#include <locale.h>

#define MAX_PEOPLE 100 // Максимальна кількість записів
#define MAX_LENGTH 100 // Максимальна довжина текстових полів

// Структура для збереження даних про людину
typedef struct {
    char surname[MAX_LENGTH];    // Прізвище
    char city[MAX_LENGTH];       // Місто
    char street[MAX_LENGTH];     // Вулиця
    int house;                   // Номер будинку
    int apartment;               // Номер квартири
} Person;

// Функція для пошуку людей за назвою вулиці
void findPeopleByStreet(Person people[], int count, char* targetStreet) {
    int found = 0; // Флаг для відстеження, чи знайдено хоч один запис
    for (int i = 0; i < count; i++) {
        if (strcmp(people[i].street, targetStreet) == 0) {
            printf("Прізвище: %s\n", people[i].surname);
            found = 1;
        }
    }
    if (!found) {
        printf("Немає людей із вказаною вулицею.\n");
    }
}

// Функція для пошуку адреси за прізвищем
void findAddressBySurname(Person people[], int count, char* targetSurname) {
    int found = 0; // Флаг для відстеження, чи знайдено хоч один запис
    for (int i = 0; i < count; i++) {
        if (strcmp(people[i].surname, targetSurname) == 0) {
            printf("Адреса: %s, %s, буд. %d, кв. %d\n",
                   people[i].city, people[i].street,
                   people[i].house, people[i].apartment);
            found = 1;
        }
    }
    if (!found) {
        printf("Немає людей із вказаним прізвищем.\n");
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Person people[MAX_PEOPLE]; // Масив для збереження даних про людей
    int count;                 // Кількість записів
    char inputStreet[MAX_LENGTH];
    char inputSurname[MAX_LENGTH];

    // Введення кількості записів
    printf("Введіть кількість записів: ");
    scanf("%d", &count);

    // Введення даних про людей
    for (int i = 0; i < count; i++) {
        printf("Запис %d:\n", i + 1);
        printf("Введіть прізвище: ");
        scanf("%s", people[i].surname);
        printf("Введіть місто: ");
        scanf("%s", people[i].city);
        printf("Введіть вулицю: ");
        scanf("%s", people[i].street);
        printf("Введіть номер будинку: ");
        scanf("%d", &people[i].house);
        printf("Введіть номер квартири: ");
        scanf("%d", &people[i].apartment);
    }

    // Пошук людей за вулицею
    printf("Введіть назву вулиці для пошуку: ");
    scanf("%s", inputStreet);
    findPeopleByStreet(people, count, inputStreet);

    // Пошук адреси за прізвищем
    printf("Введіть прізвище для пошуку адреси: ");
    scanf("%s", inputSurname);
    findAddressBySurname(people, count, inputSurname);

    return 0;
}                                             Результати тестування

