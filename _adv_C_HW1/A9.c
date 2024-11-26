/* �9
� ��������� ����������� ��������� ������:
struct pack_array
{   uint32_t array; // ���� ��� �������� ������������ ������� �� 0 � 1
    uint32_t count0 : 8; // ������� ����� � array
    uint32_t count1 : 8; // ������� ������ � array
}
���������� ����������� ���������, ������� ����������� ���������� �� ������ �� 32-�� ��������� 0 � 1 � ��������� ��������� ������.
������� ������ ������ ��������������� ���������: void array2struct(int [], struct pack_array *)
*/

#include <stdio.h>
#include <inttypes.h>


struct pack_array
{
    uint32_t array; // ���� ��� �������� ������������ ������� �� 0 � 1
    uint32_t count0 : 8; // ������� ����� � array
    uint32_t count1 : 8; // ������� ������ � array
};

void array2struct(int arr[], struct pack_array *ptr)
{
    for (int i = 0; i < 32; i++)
    {
        ptr -> count1 += arr[i];
        ptr -> array |= arr[i];
        if(i < 31)
        {
          ptr -> array <<= 1;
        }
    }
    ptr -> count0 = 32 - ptr -> count1;
}

int main()
{

    struct pack_array pack;

    int numer[32] = {0};

    for (int i = 0; i < 32; i++)
    {
        scanf("%d", &numer[i]);
    }
    array2struct(numer, &pack);
    printf("%" PRIu32 " %d %d\n", pack.array, pack.count0, pack.count1);
    return 0;
}
