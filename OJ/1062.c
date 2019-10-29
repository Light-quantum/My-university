//
// Created by LinSihan on 2019/10/27.
//
/*
 * 亲密数问题
 */
#include <stdio.h>
int main(){
    int a, b = 0, c,sum1, sum2;
    int m = 3000;
    int i, j;
    while (m--)
    {
        sum1 = 0;
        sum2 = 0;

        for (i=1; i<a; i++)
        {
            if (a % i == 0)
            {
                sum1 += i;
            }
        }
        c = sum1;

        for (j=1; j<c; j++)
        {
            if (c % j == 0)
            {
                sum2 += j;
            }
        }

        if (sum1 == c && sum2 == a && a != c && a != b) {
            printf("(%d,%d)", a, c);
            b = c;
        }
        a++;
    }
}