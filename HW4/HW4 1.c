// №1 Найти наибольшее из двух чисел и вывести в порядке возрастания
#include <stdio.h>
#include <locale.h>

int main(void)
{
    int a = 0, b = 0, max = 0, min = 0;
    setlocale(LC_ALL, "Rus");
    printf("Введите целое число: ");
    scanf("%d%d", &a, &b);
    if (a > b)
    {
        max = a; min = b;
        printf("%d %d\n", min, max);
    }
    else
    {
        max = b; min = a;
        printf("%d %d\n", min, max);
    }
    return 0;
}



