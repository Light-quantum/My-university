//
// Created by LinSihan on 2019/11/2.
//
/********************************
 * 输入正整数n，输出1+2+...+n的值
**********************************/

#include <stdio.h>
int main(){
    long long n,sum = 0;
    long long i;
    scanf("%lld", &n);
    for(i = 0; i <= n; i++){
        sum += i;
    }
    printf("%lld", sum);
    return 0;
}
