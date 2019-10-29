//Created by LinSihan on 2019/10/28.
/*********************
 * 亲和数问题
 *********************/

#include <stdio.h>
int main()
{
    int m, i, j;
    int sum1, sum2, a, b;
    scanf("%d", &m);
    while (m--)
    {
        sum1 = 0;
        sum2 = 0;
        scanf("%d %d", &a, &b);

        for (i=1; i<a; i++)
        {
            if (a % i == 0)
            {
                sum1 += i;
            }
        }

        for (j=1; j<b; j++)
        {
            if (b % j == 0)
            {
                sum2 += j;
            }
        }

        if (sum1 == b && sum2 == a)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

