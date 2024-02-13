/*G7 Практ 2
Количество букв
В файле .txt считать символьную строку, не более 10 000 символов. Посчитать количество строчных
(маленьких) и прописных (больших) букв в введенной строке. Учитывать только английские буквы.
Результат записать в файл .txt.
Данные на входе: Строка состоящая из английских букв, цифр, пробелов и знаков препинания.
Данные на выходе: Два целых числа. Количество строчных букв и количество заглавных букв.
Пример №1
Данные на входе: aabbAB
Данные на выходе: 4 2
Пример №2
Данные на входе: HELLO WORLD
Данные на выходе: 0 10*/

#include <stdio.h>
#include <string.h>
#define N 10000

void str_from_file(FILE * fptr, char*arr)
{
   while( feof(fptr) == 0 )
   {
        fgets(arr, N, fptr);
   }
   printf("string: %s", arr);
}

void is_open_file(FILE*fptr)
{
    if (fptr == NULL)
        printf ("ERROR\n");
    else
        printf ("FILE IS OPEN\n");
}

int main()
{
    char arr[N];
    size_t len = 0;
    int count_a = 0;
    int count_A = 0;
    FILE * fptr;
    fptr = fopen("input.txt", "w+b");
    is_open_file(fptr);
    fputs("HELLO WORLD", fptr);
    fclose(fptr);
    fptr = fopen("input.txt", "a+b");
    is_open_file(fptr);
    str_from_file(fptr, arr);
    len = strlen(arr);
    for(int i = 0; i < len; i++)
    {
       if(arr[i] >= 'a' && arr[i] <= 'z')
            count_a++;
       if(arr[i] >= 'A' && arr[i] <= 'Z')
            count_A++;
    }
    fprintf(stdout, " %d %d ", count_a, count_A);
    fprintf(fptr, " %d %d ", count_a, count_A);
    fclose(fptr);
    return 0;
}



