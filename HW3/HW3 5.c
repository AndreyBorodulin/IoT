
// �5 ���������� ������������ ���� ������������� ������ ������������ �����

#include <stdio.h>
#include <locale.h>

int main()
{
    int d = 0, mult = 0; // �������� ����������
    setlocale(LC_ALL, "Rus"); // ������� �� ������� ���������
    printf("������� ����� ����������� �����:\n");
    scanf("%d", &d); //������ ����� ����������� �����
    fflush(stdin);
    mult= d%10; //5 � 2
    mult *= (d/10)%10; //5*3 = 15 � 2*0
    mult *= (d/100)%10; //5*3*4 = 60 � 2*0*1 = 0
    printf("������������ ���� = %d", mult); // ����� ������������*/
    return 0;
}
