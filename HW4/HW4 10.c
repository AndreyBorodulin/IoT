// є10  акое врем€ года? попробовал вот так:)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>


int main(void)
{
    unsigned a;
    char * strMounth = (char*)malloc(sizeof(*strMounth)); // строка дл€ записи наименовани€ мес€ца
    setlocale(LC_ALL, "Rus");
    while (a <= 12)
    {
        printf("\n¬ведите пор€дковый номер мес€ца от 1 до 12:\n");
        puts("„тобы выйти из программы, укажи значение - а - вне пределов пор€дковых цифровых обозначений мес€ца в году");
        scanf("%u", &a);
        if (((a <= 2) && (a != 0)) || (a == 12))
        {
            strMounth = a ==  1 ? "jan":
                        a ==  2 ? "feb":
                        a == 12 ? "dec": " ";
            printf("%s\n%s","This is a winter,", strMounth);
        }
        if ((a >= 3) && (a <= 5))
        {
            strMounth = a ==  3 ? "march":
                        a ==  4 ? "apr":
                        a ==  5 ? "may": " ";
            printf("%s\n%s","This is a spring,", strMounth);
        }
        if ((a >= 6) && (a <= 8))
        {
            strMounth = a ==  6 ? "jun":
                        a ==  7 ? "jul":
                        a ==  8 ? "aug": " ";
            printf("%s\n%s","This is a summer,", strMounth);
        }
        if ((a >= 9) && (a <= 11))
        {
            strMounth = a ==  9 ? "sep":
                        a ==  10 ? "oct":
                        a ==  11 ? "nov": " ";
            printf("%s\n%s","This is a autumn,", strMounth);
        }
    }
    //free(strMounth); // освободили пам€ть
    return 0;
}








