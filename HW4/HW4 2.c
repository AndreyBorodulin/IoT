// �2 ����� ���������� �� ���� �����
#include <stdio.h>
#include <locale.h>

int main(void)
{
    int a = 0, b = 0, c = 0, max = 0;
    setlocale(LC_ALL, "Rus");
    printf("������� ����� �����: ");
    scanf("%d%d%d", &a, &b, &c);
    if ((a >= b) && (a >= c))
    {
        max = a;
        printf("������������ �����: %d\n", max);
    }

    if ((b > a) && (b > c))
    {
        max = b;
        printf("������������ �����: %d\n", max);
    }

    if ((c > a) && (c > b))
    {
       max = c;
       printf("������������ �����: %d\n", max);
    }
    return 0;
}
