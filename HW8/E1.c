/*E1 �� 1
������� �������������� �����
������ c ���������� ������ �� 5 ���������, ����� ������� �������������� ���� ��������� �������.

������ �� �����: 		5 ����� ��������� ����� ����� ������
������ �� ������: 	���� ����� � ������� "%.3f"

������ �1
������ �� �����: 		4 15 3 10 14
������ �� ������: 	9.200

������ �2
������ �� �����: 		1 2 3 4 5
������ �� ������: 	3.000 */

#include <stdio.h>
#define N 5

void Input(int arr[], int size) // ���� �������
{
    puts("Put in elements of array: ");
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}
int average(int arr[], int n) // ������� �������������������� ��������� �������
{
    double summ = 0;
    for(int j = 0; j < n; j++)
    {
        summ += arr[j];
    }
    printf("Average is - %.3lf\n", summ/n);
    return 0;
}

int main(void)
{
    int arr[N];
    Input(arr, N);
    average(arr, N);
    return 0;
}
