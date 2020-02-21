//
// Created by LinSihan on 2019/12/6.
//
/***************************************
    题目描述
    Description
    解一元二次方程ax^2+bx+c=0的解。
    输入描述
    Input

    a,b,c的值。
****************************************/

#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c;
    double  discriminant;
    double x1, x2;

    scanf("%d %d %d",&a, &b, &c);
    discriminant = b * b - 4 * a * c;
    x1 = (-b + sqrt(discriminant)) / (2.0 * a);
    x2 = (-b - sqrt(discriminant)) / (2.0 * a);

    printf("%.2f %.2f", x1, x2);
    return 0;
}