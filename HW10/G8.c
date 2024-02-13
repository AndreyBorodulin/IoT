/*G8 ДЗ 3
Числа в массив
В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы.
Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив.
Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. Вывести
массив по возрастанию в файл .txt.
Данные на входе: Строка из английских букв, цифр и знаков препинания
Данные на выходе: Последовательность целых чисел отсортированная по возрастанию
Пример
Данные на входе: data 48 call 9 read13 blank0a
Данные на выходе: 0 9 13 48*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define NUM 1000


void sort_bubble(int arr[], int n) //sorting
{
   puts("\n\nresultat of sorting");
   for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - 1 - i; j++)
   {
       if(arr[j] > arr[j+1])
       {
           int temp = arr[j];
           arr[j] = arr[j+1];
           arr[j+1] = temp;
       }
   }
}

void str_from_file(FILE * fptr, char*arr) //copy str from file
{
   while(feof(fptr) == 0)
   {
        fgets(arr, NUM, fptr);
   }
   printf("string: %s", arr);
}

void is_open_file(FILE*fptr) //check file opening
{
    if (fptr == NULL)
        printf ("ERROR\n");
    else
        printf ("FILE IS OPEN\n");
}

int main()
{
    char data[NUM] = " ";
    char *p = data;
    char tmp[100];
    int i=0, j=0;
    int arr_int[NUM];
    FILE * fptr;
    fptr = fopen("input.txt", "w+");
    is_open_file(fptr);
    fputs("data 48 call 9 read13 blank0a", fptr);
    fclose(fptr);
    fptr = fopen("input.txt", "a+");
    is_open_file(fptr);
    str_from_file(fptr, data);
    for(; *p ; p++)
    {
        while(isdigit(*p))
            tmp[j++] = *p++;

        if(j != 0 )
        {
            tmp[j++] = '\0';
            arr_int[i] = atoi(tmp) ;
            j=0;
            i++;
        }
    }
    puts("\nNumbers of string ");
    for(int k = 0; k < i; k++)
        printf("%d ", arr_int[k]); // without sorting
    sort_bubble(arr_int, i);// sorting to Up
    for(int k = 0; k < i; k++)
    {
        printf("%d ", arr_int[k]); // with sorting
        fprintf(fptr, "  %d ", arr_int[k]);
    }
    fclose(fptr);
    return 0;
}



