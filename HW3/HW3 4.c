
// �4 ����� ������� �������������� 3-� ����� �����

#include <stdio.h>
#include <locale.h>

int main()
{
    int a = 0, b = 0, c = 0; // �������� ����������
    double average = 0; // ��� �������� "������� ��������������"
    setlocale(LC_ALL, "Rus"); // ������� �� ������� ���������
    printf("������� ����� �����:\n");
    scanf("%d %d %d", &a, &b, &c); // ���� �����
    fflush(stdin);
    average = (double)(a + b + c)/3;
    printf("������� ��������������: (%d + %d + %d)/3 = %.2lf", a, b, c, average); // ����� �������� ��������������� 3-� ����� �����
    return 0;
}
