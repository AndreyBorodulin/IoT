//À5
#include <stdio.h>


int main()
{

    unsigned N = 0;
    unsigned K = 0;
    unsigned mask = 0;
    unsigned temp = 0;
    unsigned count = 0;

    scanf("%d", & N);
    mask = ((1 << 1) - 1);

    for(K = 0; K <= 31; K++)
    {
       temp = (N >> K) & mask;
       if(temp == 1)
       {
           count++;
       }
    }
    printf("%u", count);
}
