/*G4 ДЗ 1
По одному разу
В файле .txt даны два слова не более 100 символов каждое, разделенные одним пробелом. Найдите
только те символы слов, которые встречаются в обоих словах только один раз. Напечатайте их через
пробел в файл .txt в лексикографическом порядке.
Данные на входе: Два слова из маленьких английских букв через пробел. Длинна каждого слова
не больше 100 символов.
Данные на выходе: Маленькие английские буквы через пробел.
Пример №1
Данные на входе: hello world
Данные на выходе: o
Данные на входе: aabcd bcef
Данные на выходе: b c*/

#include <stdio.h>
#include <string.h>
#define N 200

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
    char str[N];
    char sep[10] = " ";
    char*istr;
    int i = 0;
    char arr_1[N] = {0};
    char arr_2[N] = {0};
    char reserv[N]= {'0'};
    FILE * fptr;
    fptr = fopen("input.txt", "w+");
    is_open_file(fptr);
    fputs("hello world", fptr);
    fclose(fptr);
    fptr = fopen("input.txt", "a+");
    is_open_file(fptr);
    str_from_file(fptr, str);
    istr = strtok(str,sep);
    strncpy (arr_1, istr, strlen(istr));
    printf("\n%s\n", arr_1);
    while (istr != NULL)
    {
      strncpy (arr_2, istr, strlen(arr_1));
      istr = strtok (NULL,sep);
    }
    printf("%s\n", arr_2);
    puts("\nOne time simbol:");
    for(i = 0; i < strlen(arr_1); i++)
    {
        for(int j = 0; j < strlen(arr_2); j++)
        {
           if(arr_1[i] == arr_2[j] && arr_1[i] != arr_1[j])
           {
                reserv[i] = arr_2[j];
                printf("%c ", reserv[i]);
                fputs(" ", fptr);
                fputc(reserv[i], fptr);
           }
        }
    }
    fclose(fptr);
    return 0;
}
