//
// Created by LinSihan on 2019/11/7.
//
/*课后习题求三个数的最大值*/

#include <stdio.h>
int main(){
    long long a, b, c, max;
    scanf("%lld %lld %lld", &a, &b, &c);
    max = (a > b) ? a : b;
    max = (c > max) ? c : max;
    printf("%lld", max);
}
