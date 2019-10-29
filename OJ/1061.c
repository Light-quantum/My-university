//
// Created by LinSihan on 2019/10/24.
//
# include<stdio.h>
/*
 * 8除不尽的数
 */

int main ()
{
    int n = 0;
    int ramainder1, quotient1;
    int ramainder2, quotient2;
    int a1, a2;
    do
    {
        ramainder1 = n % 8;
        quotient1 = n / 8;
        if (ramainder1 == 1)
        {
            if (quotient1 % 8 == 1)
            {
                quotient1 = quotient1 / 8;
                if (quotient1 % 8 == 7)
                {
                    a1 = quotient1 / 8;
                }
            }
        }
        else
            continue;
        ramainder2 = n % 17;
        quotient2 = n / 17;
        if (ramainder2 == 4)
        {
            if (quotient2 % 17 == 15)
            {
                a2 = quotient2 / 17;
            }
        }
        else
            continue;
        n++;
    }while(a2 = a1 * 2);
    return 0;
}
