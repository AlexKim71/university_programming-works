#include <stdio.h>  
#include <stdlib.h>  
#define M 10  

// Прототипы функций
void fun3(int *, int num);  
void fun4(int *, int num);  
int fun5(int *, int num);  
int productOfOdd(int *, int num);

int main()  
{  
    int nums[M], i;  
    for(i = 0; i < M; i++)  
        nums[i] = i + 1;  

    puts("begin:");  
    for(i = 0; i < M; i++)  
        printf("\n nums=%d", nums[i]);  
     
    fun3(nums, M);  
    fun4(nums, M);  
    printf("\nvalue=%d", fun5(nums, M)); 
    printf("\nProduct of odd elements: %d", productOfOdd(nums, M)); 
     
    return 0;  
}  

void fun3(int *n, int num)  
{  
    while (num)  
    {  
        *n = *n * *n * *n;  
        num--;  
        n++;  
    }  
}  

void fun4(int *n, int num) 
{ 
    int i;  
    puts("\nresult");  
    for(i = 0; i < num; i++)  
    { 
        printf("\nnums=%d", *n);  
        n++;  
    }  
}  

int fun5(int *n, int num)  
{ 
    return (n[num-1] - *n);  
} 

int productOfOdd(int *arr, int num) 
{ 
    int product = 1; 
    for(int i = 0; i < num; i++) 
    { 
        if(arr[i] % 2 != 0) // Проверка на нечетность 
        { 
            product *= arr[i]; 
        } 
    } 
    return product; 
}