// 123, произведение цифр равно ли их сумме - счастливые числа
#include <stdio.h>

int is_happy_number(int a)
{
   int digit = 0;
   scanf("%d", &a);
   int sum = 0; int mult = 1;
   while(a)
   {
        digit = a%10;
        sum = sum + digit;
        mult = mult * digit;
        a = a/10;
   }
   if (sum == mult)
        puts("YES");
    else
        puts("NO");
    return 0;
}


int main(void)
{
    int n = 0;
    is_happy_number(n);
    return 0;
}
