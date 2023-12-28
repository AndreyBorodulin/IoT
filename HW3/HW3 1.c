
// є1 ¬вести 3 числа, найти их сумму. Ќапечатать сумму 3 целых чисел

#include <stdio.h>
#include <locale.h>

int main()
{
    int a = 0, b = 0, c = 0, summ = 0; // объ€вили переменные
    setlocale(LC_ALL, "Rus"); // перешли на русскую раскладку
    printf("¬ведите целые числа:\n");
    scanf("%d %d %d", &a, &b, &c); // ввод чисел
    fflush(stdin);
    summ = a + b + c;
    printf("—умма чисел: %d + %d + %d = %d", a, b, c, summ); // вывод суммы 3 чисел
    return 0;
}
