/*E5
Сумма положительных элементов
Считать массив из 10 элементов и подсчитать сумму положительных элементов массива.

Данные на входе: 		10 целых чисел через пробел
Данные на выходе: 	Одно целое число - сумма положительных элементов массива

Пример №1
Данные на входе: 		4 -5 3 10 -4 -6 8 -10 1 0
Данные на выходе: 	26

Пример №2
Данные на входе: 		1 -2 3 -4 5 -6 7 -8 9 0
Данные на выходе: 	25*/

#include <stdio.h>
#define N 10

void Input(int arr[], int size) // ввод массива
{
    puts("Put in elements of array: ");
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}
int summa_positiv(int arr[], int n) // считает сумму положительных чисел массива
{
    int summ = 0;
    for(int j = 0; j < n; j++)
    {
        if(arr[j] > 0)
        {
         summ += arr[j];
        }
    }
    printf("Summary - %d", summ);
    return 0;
}

int main(void)
{
    int arr[N];
    Input(arr, N);
    summa_positiv(arr, N);
    return 0;
}
