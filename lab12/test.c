#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 256

// Функция для нахождения длины самого длинного слова в строке
int findLongestWordLength(const char *text) {
    int maxLength = 0, currentLength = 0;
    while (*text) {
        if (isalpha(*text)) {
            currentLength++;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 0;
        }
        text++;
    }
    return (currentLength > maxLength) ? currentLength : maxLength;
}

// Функция для смены регистра букв второго слова
void changeSecondWordCase(char *text) {
    int wordCount = 0;
    int inWord = 0;
    while (*text) {
        if (isalpha(*text)) {
            if (!inWord) {
                inWord = 1;
                wordCount++;
            }
            if (wordCount == 2) {
                *text = islower(*text) ? toupper(*text) : tolower(*text);
            }
        } else {
            inWord = 0;
        }
        text++;
    }
}

// Функция для вставки пробела после каждого сова
void insertSpaces(char *text, char *newText) {
    int i = 0, j = 0;
    while (text[i]) {
        newText[j++] = text[i];
        if (isalpha(text[i]) && (text[i + 1] == ' ' || text[i + 1] == '\0')) {
            newText[j++] = ' ';
        }
        i++;
    }
    newText[j] = '\0';
}

int main() {
    char text[MAX_LEN], modifiedText[MAX_LEN * 2];
    printf("Введите текст: ");
    fgets(text, MAX_LEN, stdin);
    text[strcspn(text, "\n")] = 0; // Удаление символа новой строки

    printf("Длина самого длинного слова: %d\n", findLongestWordLength(text));
    
    changeSecondWordCase(text);
    printf("Текст после изменения регистра второго слова: %s\n", text);
    
    insertSpaces(text, modifiedText);
    printf("Текст с добавленными пробелами: %s\n", modifiedText);
    
    return 0;
}
