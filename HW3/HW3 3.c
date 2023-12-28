
// №3 Ввести 2 числа, найти их разность. Напечатать разность 2 целых чисел

#include <stdio.h>
#include <locale.h>

int main()
{
    int a = 0, b = 0, subtr = 0; // объявили переменные
    setlocale(LC_ALL, "Rus"); // перешли на русскую раскладку
    printf("Введите целые числа:\n");
    scanf("%d %d", &a, &b); // ввод чисел
    fflush(stdin);
    subtr = a - b; //разность чисел
    printf("Разность чисел: %d - %d = %d\n", a, b, subtr); // вывод разности 2 целых чисел
    return 0;
}
