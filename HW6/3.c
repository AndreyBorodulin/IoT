
// Находим факториал !

#include <stdio.h>

int factorial(void)
{
    int a = 0;
    scanf("%d", &a);
    int x = 0;
    int i = 0;
    int mult = 1;
    while(i < a)
    {
        x = (x+1);
        mult = mult * x;
        i++;
    }
       printf("%d", mult);
       return 0;
}

int main(void)
{
    factorial();
    return 0;
}
