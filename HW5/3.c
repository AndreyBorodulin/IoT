/*B4 ���� 5 �� 2
����� ��� �����
������ ����� ����� � ����������, ����� ��, ��� � ��� ����� 3 �����.

������ �� �����:		����� ������������� �����
������ �� ������:	���� �����: YES ��� NO

������ �1
������ �� �����:		123
������ �� ������:	YES

������ �2
������ �� �����:		1234
������ �� ������:	NO
*/

#include <stdio.h>
#include <locale.h>

int main()

{
    int a = 0, count = 0;
    setlocale(LC_ALL, "Rus");
    printf("Set integer: ");
    scanf("%d", &a);
    while (a != 0)
    {
      count++;
      a = a/10; // ����������� �� �����
    }
    printf("%d\n", count);
    if(count == 3)
        puts("YES!");
    else
        puts("NO!");
    return 0;
}



