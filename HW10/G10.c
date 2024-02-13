/*G10
Самое длинное слово
В файле .txt дана строка слов, разделенных пробелами. Найти самое длинное слово и вывести его в
файл .txt. Случай, когда самых длинных слов может быть несколько, не обрабатывать.
Данные на входе: Строка из английских букв и пробелов. Не более 1000 символов.
Данные на выходе: Одно слово из английских букв.
Пример
Данные на входе: Hello beautiful world
Данные на выходе: beautiful*/

#include <stdio.h>
#include <string.h>
#define N 1000

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
    char * result[10];
    int len_max = 0;
    char sep[10] = " ";
    int i = 0;
    FILE * fptr;
    fptr = fopen("input.txt", "w+");
    fputs("Hello beautiful world", fptr);
    is_open_file(fptr);
    fclose(fptr);
    fptr = fopen("input.txt", "a+");
    is_open_file(fptr);
    str_from_file(fptr, arr);
    char * ptr = strtok(arr, sep);
    while(ptr != NULL)
    {
       result[i] = ptr;
       ptr = strtok(NULL, sep);
       i++;
    }
    for (int j = 0; j < i; j++)
    {
        if(strlen(result[j]) > len_max)
        {
            len_max = strlen(result[j]);
        }
    }
    printf("\n\nlen_max is %d", len_max);
    for (int k = 0; k < i; k++)
    {
        if(strlen(result[k]) == len_max)
        {
            printf("\n\nword: %s\n", result[k]);
            fprintf(fptr, "\n%s", result[k]);
        }
    }
    fclose(fptr);
    return 0;
}
