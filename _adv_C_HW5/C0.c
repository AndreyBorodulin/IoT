//C0

#include <stdio.h>
#include <string.h>



long int del(char *str)
{
    int n = strlen(str);
    if (n < 3)
        return 0;

    int nn[1000] = {0};
    unsigned long int count = 0;

    for ( int i = 0; i < n - 2; i++)
    {
        if (str[i] == '0')
            continue;
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int num = ((str[i] - '0') * 100 + (str[j] - '0') * 10 + (str[k] - '0'));
                if(nn[num] != 1)
                {
                    nn[num] = 1;
                    count++;
                }
            }
        }
    }
    return count;
}

int main(void)
{   char buf[300];
    scanf("%s", buf);
    printf("%ld\n", del(buf));

    return 0;
}

