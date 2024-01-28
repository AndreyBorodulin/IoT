/*
E12
По убыванию и по возрастанию
Считать массив из 10 элементов и отсортировать первую половину по возрастанию, а вторую – по убыванию.

Данные на входе: 		10 целых чисел через пробел
Данные на выходе: 	Исходный массив. Первая часть отсортирована по возрастанию, вторая половина по убыванию.

Пример №1
Данные на входе: 		14 25 13 30 76 58 32 11 41 97
Данные на выходе: 	13 14 25 30 76 97 58 41 32 11

Пример №2
Данные на входе: 		5 4 3 2 1 6 7 8 9 10
Данные на выходе: 	1 2 3 4 5 10 9 8 7 6
*/
#include <stdio.h>
#define N 10

void SwapArr(int arr[], int i, int j) // функция переставляет элементы массива
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}

void BubbleSort_to_high(int* arr,int n) // сортировка по возрастанию
{
    int noSwap;
    for (int i = 0; i < n; i++)
    {
        noSwap = 1;
        for (int j = n-1; j > i; j--)
        {
            if(arr[j-1]> arr[j])
            {
                SwapArr(arr,j-1,j);
                noSwap = 0;
            }
        }
        if(noSwap)
            break;
    }
}

void BubbleSort_to_low(int* arr,int n) // сортировка по убыванию
{
    int noSwap;
    for (int i = n/2; i < n - 1; i++)
    {
        noSwap = 1;
        for (int j = n-1; j > i; j--)
        {
            if(arr[j-1] <= arr[j])
            {
                SwapArr(arr,j-1,j);
                noSwap = 0;
            }
        }
        if(noSwap)
            break;
    }
}

void input(int arr[], int size)
{
    puts("Put in elements of array: ");
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

void output(int arr[], int size)
{
    puts("\nRESULT: ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main(void)
{
   int arr[N];
   input(arr, N);
   BubbleSort_to_high(arr, N/2);
   BubbleSort_to_low(arr, N);
   output(arr, N);
   return 0;
}
