/*F2 ДЗ 2
Четные в начало
Написать функцию и программу, демонстрирующую работу данной функции, которая ставит в
начало массива все четные элементы, а в конец – все нечетные. Не нарушайте порядок
следования чисел между собой. Строго согласно прототипу:
void sort_even_odd(int n, int a[])
Данные на входе: Функция принимает на вход целые числа
Данные на выходе: Отсортированный исходный массив
Пример №1
Данные на входе: 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
Данные на выходе: 20 18 16 14 12 10 8 6 4 2 19 17 15 13 11 9 7 5 3 1
Пример №2
Данные на входе: 1 0 1 0 1
Данные на выходе: 0 0 1 1 1*/

#include <stdio.h>
#define N 20
//#define N 5 //for primer 2

void input_dig(int a[])
{
    puts("Put in elements in array:\n");
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    puts("\narray is:\n");
    for(int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }

}

void sort_even_odd(int n, int a[])
{
    for(int k = 1; k < n; k++)
        for(int i = 0;i < n-k;i++)
            if(a[i]%2 > a[i + 1]%2)
            {
               int temp = a[i];
               a[i] = a[i + 1];
               a[i + 1] = temp;
            }
    puts("\n\nResult:\n");
    for(int i = 0;i < n;i++)
        printf("%d ", a[i]);
}

int main()
{
    int a[N] = {0};
    input_dig(a);
    sort_even_odd(N, a);
    return 0;
}





