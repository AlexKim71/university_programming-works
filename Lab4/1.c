#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    float speed;

    printf("Введіть швидкість вітру (м/с): ");
    scanf("%f", &speed);

    switch ((int)speed) {
        case 1 ... 4:
             printf("Програму виконав студент гр. АІ-243 Гаврилов О.В\n");
            printf("Вітер слабкий.\n");
            break;
        case 5 ... 10:
             printf("Програму виконав студент гр. АІ-243 Гаврилов О.В\n");
            printf("Вітер помірний.\n");
            break;
        case 11 ... 18:
             printf("Програму виконав студент гр. АІ-243 Гаврилов О.В\n");
            printf("Вітер сильний.\n");
            break;
        default:
             printf("Програму виконав студент гр. АІ-243 Гаврилов О.В\n");
            printf("Ураганний вітер.\n");
    }

    return 0;
}

