// №9 В порядке возрастания: YES or NO

#include <stdio.h>
#include <locale.h>

int main(void)
{
    int a = 0, b = 0, c = 0;
    setlocale(LC_ALL, "Rus");
    printf("Введите 3 целых числа:\n");
    scanf("%d%d%d", &a, &b, &c);
    printf("Введенные значения в порядке возрастания: %s", (a < b) && (b < c) ? "YES" : "NO");


    return 0;
}

