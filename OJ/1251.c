//
// Created by LinSihan on 2019/11/2.
//
/*
 * 用迭代法求。求平方根的迭代公式为：X[n+1]=1/2(X[n]+a/X[n])要求前后两次求出的得差的绝对值少于0.00001。输出保留3位小数
 */

#include <stdio.h>
#include <math.h>
int main(){
    double a;
    double X, X1;

    scanf("%ld", &a);
    X = a;
    X1 = 1.0 / 2.0 * (X + a / X);

    while((X - X1) < 0.00001){
        X1 = 1.0 / 2.0 * (X1 + a / X1);
    }

    printf("%.3lf", X1);
    return 0;
}
