/*E1 ДЗ 1
Среднее арифметическое чисел
Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.

Данные на входе: 		5 целых ненулевых чисел через пробел
Данные на выходе: 	Одно число в формате "%.3f"

Пример №1
Данные на входе: 		4 15 3 10 14
Данные на выходе: 	9.200

Пример №2
Данные на входе: 		1 2 3 4 5
Данные на выходе: 	3.000 */

#include <stdio.h>
#define N 5

void Input(int arr[], int size) // ввод массива
{
    puts("Put in elements of array: ");
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}
int average(int arr[], int n) // считает среднеарифметическое элементов массива
{
    double summ = 0;
    for(int j = 0; j < n; j++)
    {
        summ += arr[j];
    }
    printf("Average is - %.3lf\n", summ/n);
    return 0;
}

int main(void)
{
    int arr[N];
    Input(arr, N);
    average(arr, N);
    return 0;
}
