/*Два одинаковых
Написать функцию и программу, демонстрирующую работу данной функции, которая определяет,
верно ли, что среди элементов массива есть два одинаковых. Если ответ «да», функция
возвращает 1; если ответ «нет», то 0. Строго согласно прототипу:
int is_two_same(int size, int a[]);
Данные на входе: Массив из целых чисел
Данные на выходе: Функция возвращает 1 или 0
Пример №1
Данные на входе: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28
29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60
61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92
93 94 95 96 97 98 99 100
Данные на выходе: NO
Пример №2
Данные на входе: 1 2 1 4 5
Данные на выходе: YES*/

#include <stdio.h>
#include <stdlib.h>
#define N1 100 // Primer 1
#define N2 5 // Primer 2



int is_two_same(int size, int a[])
{
   int flag = 0;
   for(int i = 0; i < size; i++)
   {
       for(int j = i + 1; j < size; j++)
       {
            if(a[i] == a[j])
            {
              flag++;
              break;
            }
       }
   }
   if(flag)
   {
       puts("YES");
       return 1;
   }
   if (!flag)
   {
       puts("NO");
       return 0;
   }
   return 0;
}

void input_dig(int size, int a[])
{
    puts("Put in numbers: \n");
    for(int i = 0; i< size; i++)
    {
      scanf("%d", &a[i]);
    }
}

int main()
{
    int str[N1] = {0};
    // Primer 1
    input_dig(N1, str);
    // Primer 2
    //input_dig(N2, str);
    return is_two_same(N1, str); // for primer 1
    //return is_two_same(N2, str); // for primer 2
}
