/*ћногомодульное консольное приложение. ќбработка данных измерений датчика температуры.
  ѕрограмма работает с использование аргументов командной строки. ¬ыводит статистику показателей температуры
  по году и мес€цам. "—обираетс€" при помощи утилиты "make"*/
  //јвтор: Ѕородулин јндрей —ергеевич
  //Version 1.0
  //04.03.2024 г.

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "temp_api.h"
#include <locale.h>
#include <unistd.h>
#define SIZE 550000


int main(int argc, char * argv[])
{
    FILE* fptr; //указатель на файл
    double t_av_m = 0;// среднемес€чна€  температура
    int t_min_m = 0; // минимальна€ температура в этом мес€це
    int t_max_m = 0; // максимальна€ температура в этом мес€це
    int month = 0;
    int r = 0;
    int i = 0;
    int k = 1;
    setlocale(LC_ALL, "Rus");
    struct sensor* info = malloc(SIZE*sizeof(struct sensor));
    if(!info) //проверка выделени€ пам€ти
    {
        printf("Memory is not allocated");
        return -1;
    }
    help();// описание меню программы
    int rez=0;
    //opterr=0;
    while ((rez = getopt(argc,argv,"hf:m:tde")) != -1)
    {
        switch (rez)
        {
            case 'h':
                printf("Programm is putting out data from temperature sensor for some periods of time: month, year.\n");
                printf("In a program release we have the parameters of command line:\n");
                puts("-h : HELP;");
                puts("-f : it processes the input file name csv format for data processing;");
                puts("-m <month number>, it is putting statistic for the month, use with -f;");
                puts("-t : Sorting data by temperature, use with -f ;");
                puts("-d : Sorting data by date, use with -f;");
                puts("-e : Exit");
            break;
            case 'f':
                printf("Name of <csv> file is \"%s\" ",optarg);
                fptr = fopen(optarg, "r");
                if(fptr == NULL) // проверка файла на открытие
                {
                    printf("\nERROR of open");
                    return 1;
                }
                puts("\nScanned:");
                while((r = fscanf(fptr,"%d;%d;%d;%d;%d;%d",&info[i].year, &info[i].month, &info[i].day, &info[i].hours, &info[i].minutes, &info[i].temperature ))> 0) // сохран€ем данные в массив структур
                {
                    if(r<6)
                    {
                        char s[100];
                        r = fscanf(fptr, "%[^\n]", s);
                        printf("\n\nERROR %d=%s\n", r, s);
                        printf("Exception line for statistic: = %d\n", k);
                        i--;
                    }
                    i++;
                    k++;
                }
                printf("\ncorrect strings for data analysis: %d\n", i);
                t_av_m = average_monthly_temp(info, i, month); // среднемес€чна€  температура
                t_min_m = min_temp_this_month(info, i, month); // минимальна€ температура в этом мес€це
                t_max_m = max_temp_this_month(info, i, month); // максимальна€ температура в этом мес€це
                if(!argv[3])
                {
                    printf("\n\n%5s%15s%25s%35s%45s\n", "Year", "Month", "t_av_m", "t_min_m", "t_max_m");
                    for(month = 1; month <= 12; month++)
                        print_month_statistic(info,i, month, t_av_m, t_min_m, t_max_m );
                    average_annual_temp(info, i); // среднегодова€ температура
                    min_annual_temp(info, i); // минимальна€ годова€ температура
                    max_annual_temp(info, i); // максимальна€ годова€ температура
                }
                fclose(fptr);
            break;
            case 'm':
                printf("\nNumber of month is %d\n",atoi(optarg));
                month = atoi(optarg);
                t_av_m = average_monthly_temp(info, i, month); // среднемес€чна€  температура
                t_min_m = min_temp_this_month(info, i, month); // минимальна€ температура в этом мес€це
                t_max_m = max_temp_this_month(info, i, month); // максимальна€ температура в этом мес€це*/
                printf("\n\n%5s%15s%25s%35s%45s\n", "Year", "Month", "t_av_m", "t_min_m", "t_max_m");
                print_month_statistic(info, i, month, t_av_m, t_min_m, t_max_m);
            break;
            case 't':
                SortByt(info, i);
                print(info, i);
            break;
            case 'd':
                SortByDate(info, i);
                print(info, i);
            break;
            case 'e':
                printf("EXIT");
                return 0;
            case '?':
                printf("Error found ! See HELP: -h\n");
            break;
        }
    }
    free(info);
    return 0;
}








