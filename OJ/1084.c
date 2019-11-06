// Created by LinSihan on 2019/10/24.
/**************************
 * 自守数问题
 **************************/

# include <stdio.h>
long long getAfterNumber(long long x);
int main()
{
    long long n;
    long long afterNumber;
    for (n = 0; n <= 200000; n++)
    {
        afterNumber = getAfterNumber(n);
        if(afterNumber == n)
        {
            printf("%d  ", n);
        }
    }
    return 0;

}

long long getAfterNumber(long long x){
    long long xSquare;

    xSquare = x * x;
    if(x <= 3)
        return xSquare;
    else if(x >= 4 && x <= 9)  // 16 ~ 81
    {
        x = xSquare % 10;
        return x;
    }
    else if(x >= 10 && x <= 99)
    {
        x = xSquare % 100;
        return x;
    }
    else if(x >= 100 && x <= 999)
    {
        x = xSquare % 1000;
        return x;
    }
    else if(x >= 1000 && x <= 9999)
    {
        x = xSquare % 10000;
        return x;
    }
    else if(x >= 10000 && x <= 99999)
    {
        x = xSquare % 100000;
        return x;
    }
    else if(x >= 100000 && x <= 200000)
    {
        x = xSquare % 1000000;
        return x;
    }
}
