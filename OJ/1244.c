//
// Created by LinSihan on 2019/11/1.
//
/************************************
 * 程序功能：Sn=1!+2!+3!+4!+5!+…+n!
 * 输入：n
 * 输出：Sn
 ***********************************/

#include <stdio.h>
int main(){
    int n, i, j;
    long long Sn = 0, sum = 1;

    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        sum = 1;
        for(j = 1; j <= i; j++){
            sum *= j;
        }
        Sn += sum;
    }
    printf("%lld", Sn);
    return 0;
}