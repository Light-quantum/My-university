//
// Created by LinSihan on 2019/11/7.
//
/*******************************************************
    题目描述
    Description
    求以下三数的和,保留2位小数1~a之和1~b的平方和1~c的倒数和
    输入描述
    Input
    abc三个整数(1<=a,b,c<=1000)
    输出描述
    Output
    1+2+...+a+1^2+2^2+...+b^2+1/1+1/2+...+1/c
******************************************************/
//思路 3个数组，分别存1~a 1~b的平方 1~c的倒数

#include <stdio.h>
int main(){
    int a, b, c;
    double sum0 = 0, sum1 = 0, sum2 = 0, sum;
    scanf("%d %d %d", &a, &b, &c);
    int i;
    for( i = 1; i <= a; i++ ){
        sum0 += i;
    }
    for(i = 1; i <= b; i++){
        sum1 += i*i;
    }
    for(i = 1; i <= c; i++){
        sum2 += 1.0 / i;
    }

    sum = sum0 + sum1 + sum2;

    printf("%.2f", sum);

}