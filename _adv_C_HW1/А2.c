
//À2

#include <stdio.h>

int main()
{
    unsigned N = 0;
    unsigned K = 0;
    scanf("%d %d", &N, &K);
    N = (N >> K) | (N << (32 - K));
    printf("%u", N);
}
