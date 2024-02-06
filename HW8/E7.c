/*E7 ������� 2
�������� ���������
������� ������ �� 10 ��������� � ��������� �������� �������� ��� 1-�� � 2-�� ������� �������. ���������� �������� ��������� ������ � ���������� ��� ����� ������.

������ �� �����: 		10 ����� ��������� ������� ����� ������.
������ �� ������: 	10 ����� ��������� ������� ����� ������.

������ �1
������ �� �����: 		4 -5 3 10 -4 -6 8 -10 1 0
������ �� ������: 	-4 10 3 -5 4 0 1 -10 8 -6

������ �2
������ �� �����: 		1 2 3 4 5 6 7 8 9 10
������ �� ������: 	5 4 3 2 1 10 9 8 7 6*/
#include <stdio.h>
#define N 10

void SwappArr(int arr[], int i, int j) // ������� ������������ ������ �������
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int Input (int arr[], int n) //�������� ������� �����
{
    int i;
    puts("Put in elements of array: ");
    for (i = 0; i < n; i++) //���� �������
        scanf ("%d", &arr[i]);
    return i;
}

void print(int arr[], int n) // ������� ������� ������ � �������
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(void)
{
    int arr[N];
    Input(arr, N); // ���� ��������� �������
    for(int j = 0; j < N/4; j++)
    {
       SwappArr(arr, j, N/2 - 1 - j);
    }
    for(int k = 0; k <= N/4; k++)
    {
       SwappArr(arr, N/2+k, N - 1 - k);
    }
    puts("\n");
    print(arr, N); // ����� �������
    return 0;
}