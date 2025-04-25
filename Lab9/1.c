#include <stdio.h>
#include <math.h>
#include <locale.h>


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char text[256]; // Масив для введеного тексту
    int wordCount = 0; // Кількість слів у рядку
    int countA = 0;    // Кількість букв 'а' в останньому слові

    // Введення тексту
    printf("Введіть текст: ");
    fgets(text, sizeof(text), stdin);

    // Видалення символу нового рядка, якщо він є
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    // (а) Підрахунок кількості слів у рядку
    int inWord = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (isspace(text[i])) {
            inWord = 0; // Вихід із слова
        } else if (!inWord) {
            inWord = 1; // Увійшли у нове слово
            wordCount++;
        }
    }

    // (б) Підрахунок літер 'а' в останньому слові
    int lastWordStart = -1; // Індекс початку останнього слова
    for (int i = 0; text[i] != '\0'; i++) {
        if (!isspace(text[i]) && (i == 0 || isspace(text[i - 1]))) {
            lastWordStart = i; // Запам'ятовуємо початок останнього слова
        }
    }

    // Якщо знайдено останнє слово, рахуємо 'а'
    if (lastWordStart != -1) {
        for (int i = lastWordStart; text[i] != '\0' && !isspace(text[i]); i++) {
            if (text[i] == 'а' || text[i] == 'А') {
                countA++; // Рахуємо 'а' або 'А'
            }
        }
    }

    // (в) Заміна всіх 'а' на 'А'
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == 'а') {
            text[i] = 'А'; // Замінюємо малу літеру 'а' на велику 'А'
        }
    }

    // Виведення результатів
    printf("Кількість слів у тексті: %d\n", wordCount);
    printf("Кількість букв 'а' в останньому слові: %d\n", countA);
    printf("Модифікований текст: %s\n", text);

    // Виведення інформації про виконавця
    printf("Програму виконав студент гр. АІ-243 Гаврилов О.В\n");

    return 0;
}

