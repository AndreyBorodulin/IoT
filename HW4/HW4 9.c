// �9 � ������� �����������: YES or NO

#include <stdio.h>
#include <locale.h>

int main(void)
{
    int a = 0, b = 0, c = 0;
    setlocale(LC_ALL, "Rus");
    printf("������� 3 ����� �����:\n");
    scanf("%d%d%d", &a, &b, &c);
    printf("��������� �������� � ������� �����������: %s", (a < b) && (b < c) ? "YES" : "NO");


    return 0;
}

