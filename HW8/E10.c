/*E10 ДЗ 3
Циклический сдвиг массива вправо на 4
Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента.

Данные на входе: 		12 целых чисел через пробел
Данные на выходе: 	12 целых чисел через пробел

Пример №1
Данные на входе: 		4 -5 3 10 -4 -6 8 -10 1 0 5 7
Данные на выходе: 	1 0 5 7 4 -5 3 10 -4 -6 8 -10

Пример №2
Данные на входе: 		1 2 3 4 5 6 7 8 9 10 11 12
Данные на выходе: 	9 10 11 12 1 2 3 4 5 6 7 8
*/

#include <stdio.h>
#define N 12


void shiftArray(int arr[], int size, int shift) // функция циклического сдвига вправо
{
    for (int i = 0; i < shift; i++)
{
    int temp = arr[size -1];
    for (int j = size -1; j > 0; j--)
    {
        arr[j] = arr[j - 1];
    }
    arr[0] = temp;
}
}

int Input (int arr[], int n) //описание функции ввода
{
    int i;
    puts("Put in elements of array: ");
    for (i = 0; i < n; i++) //ввод массива
        scanf ("%d", &arr[i]);
    return i;
}

void print(int arr[], int n) // функция печатает массив
{
    puts("\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(void)
{
    int arr[N];
    Input(arr, N);
    int shift = 4; // сдвиг на 4 вправо
    shiftArray(arr, N, shift);
    print(arr, N);
    return 0;
}



