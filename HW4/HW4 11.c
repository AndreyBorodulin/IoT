// є11 —уществует ли треугольник?

#include <stdio.h>
#include <locale.h>

int main()

{
    int a = 0, b = 0, c = 0;
    setlocale(LC_ALL, "Rus");
    puts("¬ведите длины сторон:\n");
    scanf("%d%d%d", &a, &b, &c);
    if (((a + b) > c) && ((a + c) > b) && ((b + c ) > a)) //сумма длин любых двух сторон треугольника должна быть больше длины третьей стороны
    {
        puts("YES");
    }
    else
        printf("NO");
    return 0;
}
