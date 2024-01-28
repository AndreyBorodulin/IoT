/*E11 �� 4
������������� �� ��������� �����
������� ������ �� 10 ��������� � ������������� ��� �� ��������� �����.

������ �� �����: 		10 ����� ����� ����� ������
���� �� ������ ��������������� �� ��������� �����

������ �1
������ �� �����: 		14 25 13 30 76 58 32 11 41 97
������ �� ������: 	30 11 41 32 13 14 25 76 97 58

������ �2
������ �� �����: 		109 118 100 51 62 73 1007 16 4 555
������ �� ������: 	100 51 62 73 4 555 16 1007 118 109
*/
#include <stdio.h>
#define N 10


void SwapArr(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}

void BubbleSort_last_num(int* arr,int n)
{
    int noSwap;
    for (int i = 0; i < n; i++)
    {
        noSwap = 1;
        for (int j = n-1; j > i; j--)
        {
            if(arr[j-1]%10 > arr[j]%10)
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
    puts("\nRESULT:");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main(void)
{
   int arr[N];
   input(arr, N);
   BubbleSort_last_num(arr, N);
   output(arr, N);
   return 0;
}









