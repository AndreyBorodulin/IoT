/*G11
Заканчивается на a
В файле .txt дано предложение. Необходимо определить, сколько слов заканчиваются на букву 'а'.
Ответ записать в файл .txt.
Данные на входе: Строка из английских букв и пробелов не более 1000 символов.
Данные на выходе: Одно целое число
Пример
Данные на входе: Mama mila ramu
Данные на выходе: 2*/

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
    char data[N] = " ";
    FILE * fptr;
    fptr = fopen("input.txt", "w+");
    is_open_file(fptr);
    fputs("Mama mila ramu", fptr);
    fclose(fptr);
    fptr = fopen("input.txt", "a+");
    is_open_file(fptr);
    str_from_file(fptr, data);
    int i = 0;
    int count = 0;
    while(data[i] != '\0')
    {
        if((data[i] =='a' && data[i + 1] == ' ') || (data[i] =='a' && data[i + 1] == '\0'))
        {
            count++;
        }
        i++;
    }
    printf("\n%d ", count);
    fprintf(fptr, "\n%d", count);
    fclose(fptr);
    return 0;
}
