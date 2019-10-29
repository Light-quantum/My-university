//Created by LinSihan on 2019/10/28.
/*************
 *一个分段函数
 **************/

#include <stdio.h>

int main()
{
    long long x, y;
    scanf("%d", &x);
    if (x < 1)
    {
        y = x;
    }
    else if (1 <= x && x <= 10)
    {
        y = 2 * x - 1;
    }
    else
    {
        y = 3 * x - 11;
    }
    printf("%lld", y);
    return 0;
}


