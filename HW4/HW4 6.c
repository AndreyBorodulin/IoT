// є6 Above, Less, Equal

#include <stdio.h>
#include <locale.h>

int main()

{
    int a = 0, b = 0;
    setlocale(LC_ALL, "Rus");
    printf("¬ведите 2 целых числа:\n");
    scanf("%d%d", &a, &b);
    printf("¬веденные a %s b", (a > b) ? "Above(больше)" : (a < b) ? "Less(меньше)" : "Equal(равны)");
    return 0;
}
