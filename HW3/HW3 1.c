
// �1 ������ 3 �����, ����� �� �����. ���������� ����� 3 ����� �����

#include <stdio.h>
#include <locale.h>

int main()
{
    int a = 0, b = 0, c = 0, summ = 0; // �������� ����������
    setlocale(LC_ALL, "Rus"); // ������� �� ������� ���������
    printf("������� ����� �����:\n");
    scanf("%d %d %d", &a, &b, &c); // ���� �����
    fflush(stdin);
    summ = a + b + c;
    printf("����� �����: %d + %d + %d = %d", a, b, c, summ); // ����� ����� 3 �����
    return 0;
}
