//
// Created by LinSihan on 2019/10/24.
//

/*
 * 自守数问题
 * 未解决
 * 已知bug 76的平方无法处理
 */
# include <stdio.h>

int getAfterNumber(int x);
int main()
{
    int n, nSqure;
    int afterNumber;
    for (n = 0; n <= 200000; n++)
    {
        nSqure = n * n;
        afterNumber = getAfterNumber(nSqure);
        if(afterNumber == n)
        {
            printf("%d  ", n);
        }
    }
    return 0;

}

int getAfterNumber(int x){
    int a;
    if(x < 10)
        return x;
    else if(x >= 10 && x <= 99)
    {
        a = x / 10;
        x = x - a * 10;
        return x;
    }
    else if(x >= 100 && x <= 999)
    {
        a = x / 100;
        x = x - a * 100;
        return x;
    }
    else if(x >= 1000 && x <= 9999)
    {
        a = x / 1000;
        x = x - a * 1000;
        return x;
    }
    else if(x >= 10000 && x <= 99999)
    {
        a = x / 10000;
        x = x - a * 10000;
        return x;
    }
    else if(x >= 100000 && x <= 999999)
    {
        a = x / 100000;
        x = x - a * 100000;
        return x;
    }
}
