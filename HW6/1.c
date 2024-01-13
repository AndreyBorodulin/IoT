// Находим количество зерен на клетках шахматной доски

#include <stdio.h>
#include <inttypes.h>

unsigned long long rice_check(void)
{
    unsigned num = 0;

    scanf("%u", &num);
    int64_t rice = 1;
    for(unsigned i = 1; i <= num - 1; i++)
        rice = rice * 2;
    printf("rice = %" PRId64, rice);
    return 0;
}


int main()
{
    rice_check();
    return 0;
}
