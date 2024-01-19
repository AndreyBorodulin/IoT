/*D16 ������� 3
������ ������� ������
�������� ���������� ����������� ������� � ��������� �� ���������� �������� �� ��������� ����������� ����� ������ �������� ������.
int is2pow(int n)
������ �� �����: 		���� ����������� �����.
������ �� ������: 	YES ��� NO

������ �1
������ �� �����: 		8
������ �� ������: 	YES

������ �2
������ �� �����: 		7
������ �� ������: 	NO
*/

#include <stdio.h>

int is2pow(double k)
{
    if(k == 2)
       return 1;
    if((int)k % 2 == 1)
    {
        puts("NO");
        return 1;
    }
    k = k/2;
    is2pow(k);
    if(k == 2)
    {
       //printf("%.lf\n", k);
       puts("Yes");
    }
    return 0;
}

int main()
{
    double a;
    scanf("%lf", &a);
    is2pow(a);
    return 0;
}
