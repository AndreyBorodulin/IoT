//C1

#include <stdio.h>
#include <string.h>

unsigned _counter(char* str1, char* str2)
{
    unsigned j = 0;
    unsigned i = 0;
    unsigned k = 0;

    int counter = 0, count = 0;
    for (i = 0; i < strlen(str2); i++)
    {
        if(str2[i] == str1[0])
        {
            for (j = i; j < strlen(str2); j++)
            {
                if (str1[k++] != str2[j])
                {
                    counter = 0;
                    k = 0; break;
                }
                counter++;
            }
        }
        else continue;
        if (counter > count)
            count = counter;
    }
    return (count);
}


int main(void)
{
    char str1[2100];
    char str2[2100];

    scanf("%s", str1);
    scanf("%s", str2);

    printf("%u ", _counter(str1, str2));
    printf("%u", _counter(str2, str1));

    return (0);
}
