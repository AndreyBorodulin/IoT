//#ifndef TEMP_API_H_INCLUDED
//#define TEMP_API_H_INCLUDED

#include <stdint.h>
#include <stdio.h>

struct sensor // объявление типа данных
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hours;
    uint8_t minutes;
    int8_t temperature;
};

void help(void); // описание меню
double average_monthly_temp(struct sensor* info, int n, int month); // среднемесячная  температура
int min_temp_this_month(struct sensor* info, int n, int month); // минимальная температура в этом месяце
int max_temp_this_month(struct sensor* info, int n, int month); // максимальная температура в этом месяце
double average_annual_temp(struct sensor* info, int n); // среднегодовая температура
int min_annual_temp(struct sensor* info, int n); // минимальная годовая температура
int max_annual_temp(struct sensor* info, int n); // максимальная годовая температура
void print_month_statistic(struct sensor* info,int number, int month, double t_av_m, int t_min_m, int t_max_m);
void changeIJ(struct sensor* info, int i, int j); // вспомогательная для сортировки
void SortByt(struct sensor* info, int n); // упорядочивание температуры по невозрастанию
unsigned long long DateToInt(struct sensor*info); // вспомогательная для сортировки по дате (сдвиги битовые)
void SortByDate(struct sensor* info, int n); // сортировка по дате
//void AddRecord(struct sensor* info, int number, uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, int8_t temperature);// инициируем массив структур
//int AddInfo(struct sensor* info, int counter);//заполняем данными массив структур
void print(struct sensor* info,int number);// печатаем данные из структур массива

//#endif // TEMP_API_H_INCLUDED
