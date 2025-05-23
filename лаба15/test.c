#include <stdio.h>

// Функція для виведення числа у двійковому вигляді
void printBinary(unsigned char num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

// Функція для виведення числа у десятковому вигляді
void printDecimal(unsigned char num) {
    printf("%d", num);
}

// Функція для виділення бітів
unsigned char isolateBits(unsigned char num, unsigned char mask) {
    return num & mask; // Виділяємо біти за допомогою маски
}

// Функція для обнулення бітів
unsigned char clearBits(unsigned char num, unsigned char mask) {
    return num & ~mask; // Обнуляємо біти за допомогою інвертованої маски
}

// Функція для встановлення бітів
unsigned char setBits(unsigned char num, unsigned char mask) {
    return num | mask; // Встановлюємо біти за допомогою маски
}

// Функція для інвертування бітів
unsigned char invertBits(unsigned char num, unsigned char mask) {
    return num ^ mask; // Інвертуємо біти за допомогою маски
}

int main() {
    // Приклад числа з таблиці
    unsigned char number = 250; // Число з таблиці

    // Маски для операцій
    unsigned char isolateMask = (1 << 5) | (1 << 3); // Виділити 3 і 5 біти
    unsigned char clearMask = (1 << 6) | (1 << 4); // Обнулити 6 і 4 біти
    unsigned char setMask = (1 << 2); // Встановити 2 біт
    unsigned char invertMask = (1 << 5) | (1 << 2); // Інвертувати 2 і 5 біти

    // Виконання операцій
    unsigned char isolatedBits = isolateBits(number, isolateMask);
    unsigned char clearedBits = clearBits(number, clearMask);
    unsigned char resultSetBits = setBits(number, setMask); // Перейменована змінна
    unsigned char invertedBits = invertBits(number, invertMask);

    // Виведення результатів
    printf("Число: ");
    printDecimal(number);
    printf(" (");
    printBinary(number);
    printf(")\n");

    printf("Виділити біти: ");
    printDecimal(isolatedBits);
    printf(" (");
    printBinary(isolatedBits);
    printf(")\n");

    printf("Обнулити біти: ");
    printDecimal(clearedBits);
    printf(" (");
    printBinary(clearedBits);
    printf(")\n");

    printf("Встановити біти: ");
    printDecimal(resultSetBits);
    printf(" (");
    printBinary(resultSetBits);
    printf(")\n");

    printf("Інвертувати біти: ");
    printDecimal(invertedBits);
    printf(" (");
    printBinary(invertedBits);
    printf(")\n");
		printf("Виконав Гаврилов О.В. з групи AI-243\n");

    return 0;
}
