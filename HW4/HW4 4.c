// �4 ����� ����� ��������� � ��������

#include <stdio.h>
#include <locale.h>

int main (void)

{
    int a = 0, b = 0, c = 0, d = 0, e = 0, max = 0, min = 0;
    setlocale(LC_ALL, "Rus");
    printf("������� ����� �����: ");
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    max = a > b ? a : b;
    max = max > c ? max : c;
    max = max > d ? max : d;
    max = max > e ? max : e;
    printf("������������ �����: %d\n", max);
    min = a < b ? a : b;
    min = min < c ? min : c;
    min = min < d ? min : d;
    min = min < e ? min : e;
    printf("����������� �����: %d\n", min);
    printf ("����� ��������� � ��������: %d", min + max);


    return 0;
}
