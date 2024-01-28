/*
E12
�� �������� � �� �����������
������� ������ �� 10 ��������� � ������������� ������ �������� �� �����������, � ������ � �� ��������.

������ �� �����: 		10 ����� ����� ����� ������
������ �� ������: 	�������� ������. ������ ����� ������������� �� �����������, ������ �������� �� ��������.

������ �1
������ �� �����: 		14 25 13 30 76 58 32 11 41 97
������ �� ������: 	13 14 25 30 76 97 58 41 32 11

������ �2
������ �� �����: 		5 4 3 2 1 6 7 8 9 10
������ �� ������: 	1 2 3 4 5 10 9 8 7 6
*/
#include <stdio.h>
#define N 10

void SwapArr(int arr[], int i, int j) // ������� ������������ �������� �������
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}

void BubbleSort_to_high(int* arr,int n) // ���������� �� �����������
{
    int noSwap;
    for (int i = 0; i < n; i++)
    {
        noSwap = 1;
        for (int j = n-1; j > i; j--)
        {
            if(arr[j-1]> arr[j])
            {
                SwapArr(arr,j-1,j);
                noSwap = 0;
            }
        }
        if(noSwap)
            break;
    }
}

void BubbleSort_to_low(int* arr,int n) // ���������� �� ��������
{
    int noSwap;
    for (int i = n/2; i < n - 1; i++)
    {
        noSwap = 1;
        for (int j = n-1; j > i; j--)
        {
            if(arr[j-1] <= arr[j])
            {
                SwapArr(arr,j-1,j);
                noSwap = 0;
            }
        }
        if(noSwap)
            break;
    }
}

void input(int arr[], int size)
{
    puts("Put in elements of array: ");
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

void output(int arr[], int size)
{
    puts("\nRESULT: ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main(void)
{
   int arr[N];
   input(arr, N);
   BubbleSort_to_high(arr, N/2);
   BubbleSort_to_low(arr, N);
   output(arr, N);
   return 0;
}
