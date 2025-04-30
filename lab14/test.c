#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *fa, *fb, *fc;
    int n, i, j, k;
    float a[100], b[100], c[100];

    // Инициализация генератора случайных чисел
    srand(time(NULL));

    // Відкриття файлу A для запису
    fa = fopen("A.txt", "w");
    if (fa == NULL)
    {
        printf("Помилка відкриття файлу A\n");
        return 1;
    }
    // Запис 10 чисел у файл A
    for (i = 0; i < 10; i++)
    {
        a[i] = (float)(rand() % 201 - 100) / 10.0;
        fprintf(fa, "%.2f ", a[i]);
    }
    fclose(fa);

    // Відкриття файлу A для читання
    fa = fopen("A.txt", "r");
    if (fa == NULL)
    {
        printf("Помилка відкриття файлу A\n");
        return 1;
    }
    // Читання даних з файлу A
    n = 0;
    while (fscanf(fa, "%f", &a[n]) != EOF)
    {
        n++;
    }
    fclose(fa);

    // Відкриття файлу B для запису від'ємних чисел з A
    fb = fopen("B.txt", "w");
    if (fb == NULL)
    {
        printf("Помилка відкриття файлу B\n");
        return 1;
    }
    // Запис від'ємних чисел у файл B
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            b[j++] = a[i];
            fprintf(fb, "%.2f ", b[j - 1]);
        }
    }
    fclose(fb);

    // Відкриття файлу C для запису додатніх чисел з A
    fc = fopen("C.txt", "w");
    if (fc == NULL)
    {
        printf("Помилка відкриття файлу C\n");
        return 1;
    }
    // Запис додатніх чисел у файл C
    k = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            c[k++] = a[i];
            fprintf(fc, "%.2f ", c[k - 1]);
        }
    }
    fclose(fc);

    // Відкриття файлу A для додавання чисел з B
    fa = fopen("A.txt", "a");
    if (fa == NULL)
    {
        printf("Помилка відкриття файлу A\n");
        return 1;
    }
    // Додавання чисел з B до A, якщо перед ними є додатні числа
    for (i = 0; i < j; i++)
    {
        for (k = 0; k < n; k++)
        {
            if (b[i] == a[k])
            {
                if (k > 0 && a[k - 1] > 0)
                {
                    fprintf(fa, "%.2f ", b[i]);
                }
                break;
            }
        }
    }
    fclose(fa);

    return 0;
}