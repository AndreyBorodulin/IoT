/*E5
����� ������������� ���������
������� ������ �� 10 ��������� � ���������� ����� ������������� ��������� �������.

������ �� �����: 		10 ����� ����� ����� ������
������ �� ������: 	���� ����� ����� - ����� ������������� ��������� �������

������ �1
������ �� �����: 		4 -5 3 10 -4 -6 8 -10 1 0
������ �� ������: 	26

������ �2
������ �� �����: 		1 -2 3 -4 5 -6 7 -8 9 0
������ �� ������: 	25*/

#include <stdio.h>
#define N 10

void Input(int arr[], int size) // ���� �������
{
    puts("Put in elements of array: ");
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}
int summa_positiv(int arr[], int n) // ������� ����� ������������� ����� �������
{
    int summ = 0;
    for(int j = 0; j < n; j++)
    {
        if(arr[j] > 0)
        {
         summ += arr[j];
        }
    }
    printf("Summary - %d", summ);
    return 0;
}

int main(void)
{
    int arr[N];
    Input(arr, N);
    summa_positiv(arr, N);
    return 0;
}
