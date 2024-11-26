//À0

#include <stdio.h>
//#include <inttypes.h>

int n = 0;
int b;
int max = 0;
int k = 0;


int main()
{

    //printf("Put in number of digits in sequence:\n");
    scanf("%d", &n);
    max = b;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &b);

        if(i == 1 || b > max)
        {
            max = b;
            k = 1;
        }
        else if(b == max)
        {
           k++;
        }
    }
    printf("%d", k);
}









