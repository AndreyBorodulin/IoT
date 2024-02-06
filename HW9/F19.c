/*F19 ДЗ 6
Больше среднего
Написать функцию и программу, демонстрирующую работу данной функции.
Определить количество положительных элементов квадратной матрицы, превышающих по
величине среднее арифметическое всех элементов главной диагонали. Реализовать функцию
среднее арифметическое главной диагонали.
Данные на входе: 5 строк по 5 целых чисел через пробел
Данные на выходе: Одно целое число
Пример
Данные на входе: 1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5
Данные на выходе: 10*/

#include <stdio.h>
#define M 5
#define N 5


void input_dig(int array[]) // input
{
    puts("Put in elements in array:\n");
    for(int i = 0; i < (M * N); i++)
    {
        scanf("%d", &array[i]);
    }
    puts("\narray is:\n");
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
            printf("%d ", array[i*N + j]);
        printf("\n");
    }

}

int f_aver_diag_array(int array[])
{
    int summa = 0;
    int aver_diag_array = 0;
    int* ptr = &array[0];
    for(int k = 0; k < 5; k++)
    {
       summa = summa + *(ptr + k * 5);
    }
    aver_diag_array = summa/5;
    return aver_diag_array;
}

int main()
{
    int aver = 0;
    int counter = 0;
    int array[M * N] = {0};
    input_dig(array);
    f_aver_diag_array(array);
    aver = f_aver_diag_array(array);
    for(int i = 0; i < M * N; i++)
    {
        if(array[i] > aver)
        {
            counter++;
        }
    }
    printf("\nElements of array larger than average of diagonal array elements is  %d\n", counter);
    return 0;
}





