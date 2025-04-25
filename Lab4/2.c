#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char material;
    char shape;
    double length, price_per_kg, density, area, volume, mass, cost;

    // Введення даних
    printf("Введіть матеріал (s - сталь, a - алюміній, t - титан, n - нержавіюча сталь): ");
    scanf(" %c", &material);
    printf("Введіть форму перерізу (k - квадрат, p - прямокутник, c - коло): ");
    scanf(" %c", &shape);
    printf("Введіть довжину арматури (м): ");
    scanf("%lf", &length);

    // Встановлення щільності та ціни за кг для різних матеріалів
    switch (material) {
        case 's':
            density = 7850; // кг/м³
            price_per_kg = 10.0; // Приклад ціни, змініть за необхідністю
            break;
        case 'a':
            density = 2700;
            price_per_kg = 15.0;
            break;
        case 't':
            density = 4540;
            price_per_kg = 50.0;
            break;
        case 'n':
            density = 8000;
            price_per_kg = 20.0;
            break;
        default:
            printf("Невідомий матеріал.\n");
            return 1;
    }

    // Обчислення площі перерізу та об'єму
    switch (shape) {
        case 'k':
            // Для квадрата: вводимо довжину сторони
            double side;
            printf("Введіть довжину сторони квадрата (м): ");
            scanf("%lf", &side);
            area = side * side;
            break;
        case 'p':
            // Для прямокутника: вводимо довжину і ширину
            double width, height;
            printf("Введіть ширину прямокутника (м): ");
            scanf("%lf", &width);
            printf("Введіть висоту прямокутника (м): ");
            scanf("%lf", &height);
            area = width * height;
            break;
        case 'c':
            // Для кола: вводимо діаметр
            double diameter;
            printf("Введіть діаметр кола (м): ");
            scanf("%lf", &diameter);
            area = M_PI * pow(diameter / 2, 2);
            break;
        default:
            printf("Невідома форма перерізу.\n");
            return 1;
    }

    // Обчислення об'єму, маси та вартості
    volume = area * length;
    mass = volume * density;
    cost = mass * price_per_kg;

    // Виведення результату
    printf("Програму виконав студент гр. АІ-243 Гаврилов О.В\n");
    printf("Вартість арматури: %.2lf грн\n", cost);

    return 0;
}



