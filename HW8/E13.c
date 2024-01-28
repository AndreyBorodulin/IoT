/*E13 �� 5
������ � ����� ����
������� ������ �� 10 ��������� � �������� � ������ ������ ��� �����, � ������� ������ � ����� ����� (����� ��������) � ����.

������ �� �����: 		10 ����� ����� ����� ������.
������ �� ������: 	����� ����� ����� ������, � ������� ������ � ����� ����� - ����

������
������ �� �����: 		40 105 203 1 14 1000 22 33 44 55
������ �� ������: 	105 203 1 1000 */

#include <stdio.h>
#define N 10

void input(int arr[], int size) // ���� �������
{
    puts("Put in elements of array: ");
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

void output(int arr[], int size) //����� �������
{
    puts("\nRESULT: ");
    for(int i = 0; i < size; i++)
    {
      if(arr[i] != 0)
        printf("%d ", arr[i]);
    }
}

int main(void)
{
    int arr1[N];
    int arr2[N] = {0};
    input(arr1, N);
    for(int i = 0; i < N; i++)
    {
        int digit = arr1[i]/10%10;
        if (digit == 0)
        {
            arr2[i] = arr1[i];
        }
    }
    output(arr2, N);
    return 0;
}






