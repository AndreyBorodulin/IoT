#include "temp_api.h"
#include <stdio.h>

void help(void)
{
    printf("HELLO, FRIEND!!! Programm is putting out data from temperature sensor for some periods of time: month, year.\n");
    printf("In this program release we have the parameters of command line:\n");
    puts("-h : HELP;");
}

void changeIJ(struct sensor* info, int i, int j)
{
    struct sensor temp;
    temp =    info[i];
    info[i] = info[j];
    info[j] = temp;
}

// упор€дочивающа€ по неубыванию температуры
void SortByt(struct sensor* info, int n)
{
    puts("\nSorting by the ascending temperature: \n");
    for(int i = 0; i<n; ++i)
        for(int j = i; j<n; ++j)
            if(info[i].temperature >=info[j].temperature)
                changeIJ(info, i, j);
}

unsigned long long DateToInt(struct sensor*info)
{
    return info->year << 28 | info->month <<24 |
    info-> day << 16 | info-> hours << 8 | info-> minutes;
}

// упор€дочивание его по дате
void SortByDate(struct sensor* info, int n)
{
    puts("\nSorting by the date: \n");
    for(int i = 0; i<n; ++i)
        for(int j = i; j<n; ++j)
              if(DateToInt(info+i) >= DateToInt(info + j))
                  changeIJ(info, i, j);
}

/*void AddRecord(struct sensor* info, int number,
    uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, int8_t temperature) // не дл€ работы с файлами данных
{
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].hours = hours;
    info[number].minutes = minutes;
    info[number].temperature = temperature;
}*/

/*int AddInfo(struct sensor* info, int counter) // не дл€ работы с файлами данных
{
    counter = 0;
    AddRecord(info, counter, info[counter].year, info[counter].month, info[counter].day, info[counter].hours, info[counter].minutes, info[counter].temperature);
    counter++;
    AddRecord(info, counter++, 2021, 9, 2, 17, 59, 9);
    AddRecord(info, counter++, 2021, 1, 7, 18, 49, 8);
    AddRecord(info, counter++, 2021, 9, 16, 14, 21, 1);
    AddRecord(info, counter++, 2021, 9, 16, 14, 19, -17);
    return counter;
}*/

// распечатать данные из массива структур
void print(struct sensor* info,int number)
{
    printf("===================================\n");
    for(int i=0;i<number;i++)
        printf("%04d-%02d-%02d-%02d-%02d temperature = %2d\n",
            info[i].year,
            info[i].month,
            info[i].day,
            info[i].hours,
            info[i].minutes,
            info[i].temperature
        );
}



void print_month_statistic(struct sensor* info,int number, int month, double t_av_m, int t_min_m, int t_max_m )
{
    //printf("===============================================================================================================================\n");
    //printf("%5s%15s%25s%35s%45s\n", "Year", "Month", "t_av_m", "t_min_m", "t_max_m");
    //printf("===============================================================================================================================\n");
    t_av_m = average_monthly_temp(info, number, month);
    t_min_m = min_temp_this_month(info, number, month);
    t_max_m = max_temp_this_month(info, number, month);
    for(int i = 0; i < number; i++)
    {
        if(info[i].month == month)
        {
            printf("%5d%15d%25.2lf%35d%45d\n", info[i].year, info[i].month, t_av_m, t_min_m, t_max_m);
            break;
        }
    }
}


double average_monthly_temp(struct sensor* info, int number, int month) // среднемес€чна€  температура
{
    int summa = 0;
    double average = 0;
    int count = 0;
    for(int i = 0; i < number; i++)
    {
        if(info[i]. month == month)
        {
             count++;
             summa = summa + info[i].temperature;
        }
    }
    average = (double)summa/count;
    return average;
}

int min_temp_this_month(struct sensor* info, int number, int month) // минимальна€ температура в этом мес€це
{
    int min_t = 100;
    for(int i = 0; i < number; i++)
    {
        if(info[i].month == month && min_t > info[i].temperature)
        {
            min_t = info[i].temperature;
        }
    }

    return min_t;
}

int max_temp_this_month(struct sensor* info, int number, int month) // максимальна€ температура в этом мес€це
{
    int max_t = -100;
    for(int i = 0; i < number; i++)
    {
        if(info[i].month == month && max_t < info[i].temperature)
        {
            max_t = info[i].temperature;
        }
    }
    return max_t;
}

double average_annual_temp(struct sensor* info, int number) // среднегодова€ температура
{
    int summa = 0;
    double average = 0;
    int count = 0;
    for(int i = 0; i < number; i++)
    {
        if(info[i].year == 2021)
        {
             count++;
             summa = summa + info[i].temperature;
        }
    }
    average = (double)summa/count;
    printf("\nAverage annual temperature is %.2lf degrees Celcius\n", average);
    return average;
}

int min_annual_temp (struct sensor* info, int number) // минимальна€ годова€ температура
{
    int min_t = info[0].temperature;
    for (int k = 0; k < number; k++)
    {
        if(info[k].year == 2021 && min_t > info[k].temperature)
        {
          min_t = info[k].temperature;
        }
    }

    printf("Minimal annual temperature is %d degrees Celcius\n", min_t);
    return min_t;
}

int max_annual_temp(struct sensor* info, int number) // максимальна€ годова€ температура
{
    int max_t = info[0].temperature;
    for (int k = 0; k < number; k++)
    {
        if(info[k].year == 2021 && max_t < info[k].temperature)
        {
          max_t = info[k].temperature;
        }
    }
    printf("Maximal annual temperature is %d degrees Celcius\n", max_t);
    return max_t;
}
