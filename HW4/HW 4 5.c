// �5 ���������� ��������� ������ �� ����������� 2-� �����

#include <stdio.h>
#include <locale.h>

int main (void)

{
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0, k = 0, b = 0;
    setlocale(LC_ALL, "Rus");
    printf("������� ���������� 2-� ����� � ������� x1, y1 � x2, y2:\n");
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    k = (y2 - y1)/(x2 - x1); // ��������� ����. ������� ������
    b = y1 - k*x1; // ��������� ���������� ����� ��������� ������
    printf("k = %.2lf b = %.2lf", k, b);
    return 0;
}
