/*B4 Урок 5 ДЗ 2
Ровно три цифры
Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.

Данные на входе:		Целое положительное число
Данные на выходе:	Одно слово: YES или NO

Пример №1
Данные на входе:		123
Данные на выходе:	YES

Пример №2
Данные на входе:		1234
Данные на выходе:	NO
*/

#include <stdio.h>
#include <locale.h>

int main()

{
    int a = 0, count = 0;
    setlocale(LC_ALL, "Rus");
    printf("Set integer: ");
    scanf("%d", &a);
    while (a != 0)
    {
      count++;
      a = a/10; // отбрасываем по цифре
    }
    printf("%d\n", count);
    if(count == 3)
        puts("YES!");
    else
        puts("NO!");
    return 0;
}



