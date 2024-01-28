/*E8 ���� 2
�������� ������ �����
������� ������ �� 12 ��������� � ��������� �������� ��� ������ ����� �������.

������ �� �����: 		12 ����� ����� ����� ������
������ �� ������: 	12 ����� ����� ����� ������

������ �1
������ �� �����: 		4 -5 3 10 -4 -6 8 -10 1 0 5 7
������ �� ������: 	10 3 -5 4 -10 8 -6 -4 7 5 0 1

������ �2
������ �� �����: 		1 2 3 4 5 6 7 8 9 10 11 12
������ �� ������: 	4 3 2 1 8 7 6 5 12 11 10 9*/
#include <stdio.h>
#define N 12

void Swapp(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

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
   int arr[N];
   input(arr, N);
   for(int j = 0; j < N/6; j++) // ����������� ����� �������
   {
        Swapp(arr, j, N/3 -1 -j);
        Swapp(arr, N/3 + j, N/3 + N/3 -1 - j);
        Swapp(arr, N/3 + N/3 + j, N - 1 - j);
   }
   output(arr, N); //�������� ���������
   return 0;
}
