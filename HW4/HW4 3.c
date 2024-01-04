// №3 Найти максимальную цифру трехзначного числа
#include <stdio.h>
#include <locale.h>

int main(void)
{
    int a = 0, b = 0, c = 0, d = 0, max = 0;
    setlocale(LC_ALL, "Rus");
    printf("Введите целое положительное число: ");
    scanf("%d", &d); // вводим число, которое будем "разбирать" на цифры
    b = d%10; printf("%d\n", b); // единицы
    a = (d/10)%10; printf("%d\n", a); // десятки
    c = (d/100)%10; printf("%d\n", c); // сотни
    if ((a >= b) && (a >= c))
    {
        max = a;
        printf("Максимальная цифра: %d\n", max);
    }
    if ((b > a) && (b > c))
    {
        max = b;
        printf("Максимальная цифра: %d\n", max);
    }
    if ((c > a) && (c > b))
    {
       max = c;
       printf("Максимальная цифра: %d\n", max);
    }
    return 0;
}
