/*F20
Четные и нечетные
Написать функцию и программу, демонстрирующую работу данной функции.
Дан целочисленный массив из 10 элементов. Необходимо определить количество четных и
нечетных чисел. Если количество чётных чисел больше, чем количество нечётных, заменить
каждое нечетное число на произведение нечетных цифр в его десятичной записи. Если
количество нечётных чисел больше или равно количеству чётных, заменить каждое чётное число
на произведение чётных цифр в его десятичной записи.
Данные на входе: 10 целых чисел через пробел
Данные на выходе: 10 целых чисел через пробел
Пример №1
Данные на входе: 48 31 20 61 97 12 18 100 200 123
Данные на выходе: 48 3 20 1 63 12 18 100 200 3
Пример №2
Данные на входе: 48 25 57 34 23 91 90 85 30 79
Данные на выходе: 32 25 57 4 23 91 0 85 0 79*/

#include <stdio.h>
#define N 10

void input_dig(int a[]) // input
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

int even_num_calc(int a[], int count_even) //calсul. even numbers
{
    count_even = 0;
    for(int i = 0; i < N; i++)
    {
        if(a[i]%2 == 0)
        {
          count_even++;
        }
    }
    puts("\n");
    return count_even;
}

int odd_num_calc(int a[], int count_odd) //calсul. odd numbers
{
    count_odd = 0;
    for(int i = 0; i < N; i++)
    {
        if(a[i]%2 != 0)
        {
          count_odd++;
        }
    }
    puts("\n");
    return count_odd;
}

void array_odd_num_change_by_mult_of_odd_dig_of_num(int arr[])
{
    int digit = 0;
    int j = 0;
    puts("\nResult, ex.1:\n");
    for(int i = 0; i < N; i++)
    {
        int mult = 1;
        if(arr[i]%2 == 1)
        {
            int numer = arr[i];
            while(numer!=0)
            {
                digit = numer%10;
                mult = mult * digit;
                numer = numer/10;
                j++;
                if(mult%2 == 1)
                {
                    arr[i] = mult;
                }
            }
        }
    }

}

void array_even_num_change_by_mult_of_even_dig_of_num(int arr[])
{
    int digit = 0;
    int j = 0;
    puts("\nResult, ex.2:\n");
    for(int i = 0; i < N; i++)
    {
        int mult = 1;
        if(arr[i]%2 == 0)
        {
            int numer = arr[i];
            while(numer!=0)
            {
                digit = numer%10;
                mult = mult * digit;
                numer = numer/10;
                j++;
                if(mult%2 == 0 && digit%2 == 0)
                {
                    arr[i] = mult;
                }
            }
        }
    }
}

void print(int arr[])
{
    for(int i =0; i < N; i++)
    printf("%d ", arr[i]);
    puts("\n");
}

int main()
{
    int arr[N] = {0};
    int even = 0;
    int odd = 0;
    input_dig(arr);
    even = even_num_calc(arr, even); // even numbers
    printf("number of even numbers - %d", even);
    odd = odd_num_calc(arr, odd); // odd numders
    printf("number of odd numbers - %d\n", odd);
    (even > odd) ? array_odd_num_change_by_mult_of_odd_dig_of_num(arr) : array_even_num_change_by_mult_of_even_dig_of_num(arr);
    print(arr);
    return 0;
}
