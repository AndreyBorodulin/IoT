/*D20 ��
�������� � �������
�������� ����������� ������� ���������� ������ ����� n � ������� p.
int recurs_power(int n, int p)
��������� ������ �������, ������ ������.

������ �� �����: 		��� ����� ����� -100 >= n >= 100 � 0 >= p >= 100
������ �� ������: 	���� ����� ����� n � ������� p

������ �1
������ �� �����: 		2 3
������ �� ������: 	8

������ �2
������ �� �����: 		3 4
������ �� ������: 	81*/

#include <stdio.h>

int recurs_power(int n, int p)
{
    if(p == 0)
       return 1;
    if(p >= 1)
    {
       return n * recurs_power(n, --p);
    }
    return 0;
}



int main(void)
{
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d raise to a power %d - %d", x, y, recurs_power(x, y));
    return 0;
}
