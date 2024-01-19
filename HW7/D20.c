/*D20 ДЗ
Возвести в степень
Написать рекурсивную функцию возведения целого числа n в степень p.
int recurs_power(int n, int p)
Используя данную функцию, решить задачу.

Данные на входе: 		Два целых числа -100 >= n >= 100 и 0 >= p >= 100
Данные на выходе: 	Одно целое число n в степени p

Пример №1
Данные на входе: 		2 3
Данные на выходе: 	8

Пример №2
Данные на входе: 		3 4
Данные на выходе: 	81*/

#include <stdio.h>

int recurs_power(int n, int p)
{
    if(p == 0)
       return 1;
    if(p >= 1)
    {
       return n * recurs_power(n, --p);
    }
    return 0;
}



int main(void)
{
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d raise to a power %d - %d", x, y, recurs_power(x, y));
    return 0;
}
