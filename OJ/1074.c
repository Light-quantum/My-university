//
// Created by LinSihan on 2019/11/26.
//
/******************************************************
    题目描述
    Description
    输入n (1<=n<=10000)计算PI
    公式pi/4=1/1-1/3+1/5-1/7....1/n*2-1
    求PI的值，并精确到小数点后6位
    输入描述
    Input
    输入多组数据，每组占一行，每行含一个整数n(1≤n≤10^5)
    输出描述
    Output
    对于每个数据，输出一行，该行仅含一个实数π(保留6位小数)
********************************************************/

#include <stdio.h>

int main(){
    int n = 0;
    int i = 0, sign = 1;
    double pi = 0;

    while(scanf("%d", &n) != EOF){
        pi = 0;
        sign = 1;
        for(i = 1; i <= 2 * n - 1; i += 2){
            pi += sign * (1.0 / i);
            sign *= -1;
        }
        printf("%.6lf\n", pi * 4);

    }
    return 0;
}