/*B8
Ровно одна цифра 9
Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9».
Данные на входе:		Одно целое число
Данные на выходе:	Одно слово: YES или NO

Пример №1
Данные на входе:		193
Данные на выходе:	YES

Пример №2
Данные на входе:		1994
Данные на выходе:	NO */

#include <stdio.h>
#include <locale.h>

int main()
{
    int a = 0, count = 0;
    puts("Put in variable of value: \n");
    scanf("%d", &a);
    while(a)
    {
       count += (a%10) == 9;
       a = a/10;
    }
    if(count == 1)
        printf("Yes");
    else
        printf("No");
    return 0;
}
