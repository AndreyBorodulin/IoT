
//À4
#include <stdio.h>

int main(void)
{
    unsigned k;
    unsigned n = 0;
    unsigned temp = 0, mask = 0;
    unsigned max = 0;

    scanf("%u %u", &n, &k);

    mask = (1 << k) - 1;

    if (k <= 31 && k >= 1)
    {
        for(int i = 0; i <= 32 - k; i++)
        {
            temp = (n >> i) & mask;

            if (temp > max)
                max = temp;
        }
        printf ("%u\n", max);
    }

    return 0;
}
