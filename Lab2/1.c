#include <stdio.h>
#include <math.h>
#include <windows.h> 

int main()  
{ 
SetConsoleCP(1251);
           SetConsoleOutputCP(1251);

float x, y, z; 

           printf("Введіть x значення\n"); 
           scanf("%f", &x);
           printf("Введіть y значення \n"); 
           scanf("%f", &y); 
           printf("Введіть z значення \n"); 
           scanf("%f", &z); 

          float a, b;
 
a = abs(pow(x / y, 1. / 3) - 2 * pow(y, 3 / 2)); 
b = 1 + exp(2 * z) / a + 7.8; 

           printf("Програму виконав студент гр. АІ-243 Гаврилов О.В\n")
printf("A = %.2f\nB = %.2f", a, b); 

return 0;
} 

