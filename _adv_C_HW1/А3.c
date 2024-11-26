//À3

#include <stdio.h>

int main()
{
    unsigned n = 0;
    unsigned k = 0;
    unsigned result = 0;
    unsigned mask = 0;

    scanf("%u %u", &n, &k);
    mask = (1 << k) - 1;

    if(k >=1 && k <= 31)
    {
        result = mask&n;
    }
    printf ("%u\n", result);

    return 0;
}
