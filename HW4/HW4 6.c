// �6 Above, Less, Equal

#include <stdio.h>
#include <locale.h>

int main()

{
    int a = 0, b = 0;
    setlocale(LC_ALL, "Rus");
    printf("������� 2 ����� �����:\n");
    scanf("%d%d", &a, &b);
    printf("��������� a %s b", (a > b) ? "Above(������)" : (a < b) ? "Less(������)" : "Equal(�����)");
    return 0;
}
