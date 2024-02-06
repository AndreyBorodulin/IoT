/*F4 ����� 1
����� � ������
�������� ������� � ���������, ��������������� ������ ������ �������.
������� � ������� ����������� �����, �������� � ������. ����� - ����������. ������� ������
������ ��������������� ���������:
void print_digit(char s[])
������ �� �����: ������ �� ���������� ����, ��������, ������ ���������� � ����
������ �� ������: ������� ������ ��������� �� ���� ������ � �������� �� ������ ��
�������: ����� ������ ����������.
������
������ �� �����: Hello123 world77.
������ �� ������: 1 1 2 1 3 1 7 2*/

#include <stdio.h>
#include <string.h>
#define N 50

char*input(char c, char str[])
{
    int i = 0;
    str[N] = 0;
    puts("Put in simbols: \n");
    while((c = getchar()) != '\n')
    {
       str[i++] = c;
    }
    str[i] = '\0';
    puts("\n");
    return 0;
}


void print_digist(int s[])
{
    for (int i = 0; i < 10; i++)
        if (s[i] > 0)
            printf("%d%d", i, s[i]);
}

void count_digits(char n[], int* res)
{
    for (int i=0;n[i]!=0;i++)
        res[n[i] - '0']++;
}

int main(void)
{
    char c = 0;
    char str[N] = {0};
    int r[10] = {0};
    input(c, str);
    count_digits(str, r);
    print_digist(r);
    return 0;
}
