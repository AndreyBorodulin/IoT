
// Найти эквивалент для XOR
// A^B = (!A&&B)||(A&&!B)
// Доказать истинность тождества

#include <stdio.h>

int main()
{
    printf("A   B   A^B\
           \n\n0   0    0\
           \n\n0   1    1\
           \n\n1   0    1\
           \n\n1   1    0\n\n\n");

    printf("A    B    !A       !B    !A&&B           A&&!B      (!A&&B)||(A&&!B)\
           \n\n0    0     1       1       0               0                0\
           \n\n0    1     1       0       1               0                1\
           \n\n1    0     0       1       0               1                1\
           \n\n1    1     0       0       0               0                0\n\n\n");

    printf("A^B = (!A&&B)||(A&&!B)\n");



    return 0;
}
