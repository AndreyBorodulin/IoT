// Цифры числа в порядке возрастания (Yes/ NO)

#include <stdio.h>

int grow_up(int a)
{
   int b = 0, flag = 0;
    scanf("%d", &a);
    b = a%10;
    a /= 10;
    while (a != 0)
    {
        if(a%10 >= b)
        {
            flag = 1;
            break;
        }
        b = a%10;
        a /= 10;
    }
    printf("%s", flag ? "NO" : "YES");
    return 0;
}


int main(void)
{
    int n = 0;
    grow_up(n);
    return 0;
}
