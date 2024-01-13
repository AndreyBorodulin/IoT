// Определяет сумму чисел от одного до N
#include <stdio.h>

unsigned summa(void)

{
    unsigned N = 0; unsigned S = 0;
    scanf("%u", &N);
    for (int i = 1; i <= N; i++ )
    {
        S = S + i;
    }
    return (printf("%u", S));
}


int main()
{
    summa();
    return 0;
}
