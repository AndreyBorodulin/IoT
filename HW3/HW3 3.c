
// �3 ������ 2 �����, ����� �� ��������. ���������� �������� 2 ����� �����

#include <stdio.h>
#include <locale.h>

int main()
{
    int a = 0, b = 0, subtr = 0; // �������� ����������
    setlocale(LC_ALL, "Rus"); // ������� �� ������� ���������
    printf("������� ����� �����:\n");
    scanf("%d %d", &a, &b); // ���� �����
    fflush(stdin);
    subtr = a - b; //�������� �����
    printf("�������� �����: %d - %d = %d\n", a, b, subtr); // ����� �������� 2 ����� �����
    return 0;
}
