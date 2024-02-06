/*F18
������ ����������
�������� ������� � ���������, ��������������� ������ ������ �������.
���� ������������� ���������� ������� 10 � 10. ����������� �������� ���������� �����
������������ ��������� �� ������ ������. ���������� �������� ���� �����. ��������������,
��� � ������ ������ ����� ������� ������������. ����������� ������� ������ ��������� �
������ �� 10 ���������
������ �� �����: 10 ����� ��������� �� 10 ����� ����� ����� ������.
������ �� ������: ���� ����� �����
������
������ �� �����: 61 75 55 2 35 34 77 93 28 49 11 34 22 78 19 14 67 67 11 0 72 39 23 53 92
51 60 34 71 63 14 27 72 6 0 79 98 56 30 15 31 16 3 4 95 59 25 17 11 20 5 93 21 61 96 30 79 38 73
40 89 4 66 19 36 99 67 67 92 36 87 54 7 35 40 43 44 46 4 69 98 57 20 75 9 66 85 9 39 31 8 90 94 25
12 30 18 10 23 15
������ �� ������: 930*/

#include <stdio.h>
#define M 10
#define N 10

void input_dig(int array[])//input array
{
    puts("Put in numbers: \n");
    for(int i = 0; i < M*N; i++)
    {
        scanf("%d", &array[i]);
    }
    puts("\nARRAY is: \n");
    for (int k = 0; k < M; k++)
    {
        for(int j = 0; j< N; j++)
            printf("%d ",  array[M*k + j]);
        printf("\n\n");
    }
}

int max_el_of_str(int array[], int start, int finish)
{
    int max = 0;
    int*ptr = array;
    for(int i = start; i < finish; i++)
    {
        if(*(ptr + i) > max)
        {
            max = *(ptr + i);
        }
    }
    return max;
}

int main()
{
    int array[M*N] = {0};
    input_dig(array);
    int max = 0;
    int summa = 0;
    for(int i = 0; i < 100; i = i+10)
    {
        max = max_el_of_str(array, i, i+10);
        summa = summa + max;
    }
    printf("\nSumma is %d", summa);
    return 0;
}
