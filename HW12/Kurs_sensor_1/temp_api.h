//#ifndef TEMP_API_H_INCLUDED
//#define TEMP_API_H_INCLUDED

#include <stdint.h>
#include <stdio.h>

struct sensor // ���������� ���� ������
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hours;
    uint8_t minutes;
    int8_t temperature;
};

void help(void); // �������� ����
double average_monthly_temp(struct sensor* info, int n, int month); // ��������������  �����������
int min_temp_this_month(struct sensor* info, int n, int month); // ����������� ����������� � ���� ������
int max_temp_this_month(struct sensor* info, int n, int month); // ������������ ����������� � ���� ������
double average_annual_temp(struct sensor* info, int n); // ������������� �����������
int min_annual_temp(struct sensor* info, int n); // ����������� ������� �����������
int max_annual_temp(struct sensor* info, int n); // ������������ ������� �����������
void print_month_statistic(struct sensor* info,int number, int month, double t_av_m, int t_min_m, int t_max_m);
void changeIJ(struct sensor* info, int i, int j); // ��������������� ��� ����������
void SortByt(struct sensor* info, int n); // �������������� ����������� �� �������������
unsigned long long DateToInt(struct sensor*info); // ��������������� ��� ���������� �� ���� (������ �������)
void SortByDate(struct sensor* info, int n); // ���������� �� ����
//void AddRecord(struct sensor* info, int number, uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, int8_t temperature);// ���������� ������ ��������
//int AddInfo(struct sensor* info, int counter);//��������� ������� ������ ��������
void print(struct sensor* info,int number);// �������� ������ �� �������� �������

//#endif // TEMP_API_H_INCLUDED
