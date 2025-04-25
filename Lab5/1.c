#include <stdio.h>
#include <math.h>
#include <locale.h>


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    double num, prevNum = 0; // Змінні для зберігання поточного та попереднього чисел
    int isOrdered = 1; // Флаг для відстеження впорядкованості

    printf("Введіть послідовність дійсних чисел (0 для завершення):\n");

    // Цикл продовжується доки користувач не введе 0
    while (num != 0) {
        scanf("%lf", &num);

        // Перевірка на перше число
        if (prevNum != 0 && num < prevNum) {
            isOrdered = 0;
            break; // Якщо послідовність не впорядкована, перериваємо цикл
        }

        prevNum = num;
    }

    if (isOrdered) {
        printf("Програму виконав студент гр. АІ-243 Гаврилов О.В\n");
        printf("Послідовність впорядкована за зростанням.\n");
    } else {
        printf("Програму виконав студент гр. АІ-243 Гаврилов О.В\n");
        printf("Послідовність не впорядкована.\n");
    }

    return 0;
}       
