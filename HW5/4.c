/*B6 Урок 5 Практика №2
Две одинаковые цифры рядом
Ввести целое число и определить, верно ли, что в его записи есть   две одинаковые цифры, стоящие рядом.

Данные на входе:		Одно целое число
Данные на выходе:	Единственное слов: YES или NO

Пример №1
Данные на входе:		1232
Данные на выходе:	NO

Пример №2
Данные на входе:		1224
Данные на выходе:	YES
*/
#include <stdio.h>
#include <locale.h>

int main()
{
    int a = 0, c;
    puts("Put in variable of value: \n");
    scanf("%d", &a);
    while (a)
    {
        c = a%10;
        a = a/10;
        if (a%10 == c)
        {
            printf("YES: The same numbers next to each other\n");
            break;
        }
    }
    if(!a)
    {
        {
            printf("NO: the same numbers next to each other\n");
        }
    }
    return 0;
}




