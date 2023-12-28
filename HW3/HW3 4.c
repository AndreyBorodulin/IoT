
// №4 Найти среднее арифметическое 3-х целых чисел

#include <stdio.h>
#include <locale.h>

int main()
{
    int a = 0, b = 0, c = 0; // объявили переменные
    double average = 0; // для значений "среднее арифметическое"
    setlocale(LC_ALL, "Rus"); // перешли на русскую раскладку
    printf("Введите целые числа:\n");
    scanf("%d %d %d", &a, &b, &c); // ввод чисел
    fflush(stdin);
    average = (double)(a + b + c)/3;
    printf("Среднее арифметическое: (%d + %d + %d)/3 = %.2lf", a, b, c, average); // вывод среднего арифметического 3-х целых чисел
    return 0;
}
