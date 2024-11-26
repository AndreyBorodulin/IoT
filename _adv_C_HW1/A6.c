// À6


#include <stdio.h>


int main()
{
    unsigned a = 0;

    scanf("%u", &a);

    unsigned result = a ^ 0xFF000000;

    printf ("%u\n", result);

    return 0;
}
