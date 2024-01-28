/*E13 ДЗ 5
Вторая с конца ноль
Считать массив из 10 элементов и отобрать в другой массив все числа, у которых вторая с конца цифра (число десятков) – ноль.

Данные на входе: 		10 целых чисел через пробел.
Данные на выходе: 	Целые числа через пробел, у которых вторая с конца цифра - ноль

Пример
Данные на входе: 		40 105 203 1 14 1000 22 33 44 55
Данные на выходе: 	105 203 1 1000 */

#include <stdio.h>
#define N 10

void input(int arr[], int size) // ввод массива
{
    puts("Put in elements of array: ");
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

void output(int arr[], int size) //вывод массива
{
    puts("\nRESULT: ");
    for(int i = 0; i < size; i++)
    {
      if(arr[i] != 0)
        printf("%d ", arr[i]);
    }
}

int main(void)
{
    int arr1[N];
    int arr2[N] = {0};
    input(arr1, N);
    for(int i = 0; i < N; i++)
    {
        int digit = arr1[i]/10%10;
        if (digit == 0)
        {
            arr2[i] = arr1[i];
        }
    }
    output(arr2, N);
    return 0;
}






