//
// Created by LinSihan on 2019/11/7.
//
/********************************************
    题目描述
            Description
    分别用函数和带参的宏，从三个数中找出最大的数。
    输入描述
            Input
    3个实数
    输出描述
            Output
    最大的数,输出两遍，先用函数，再用宏。保留3位小数。
*************************************************/
#include <stdio.h>
int main(){
    double a, b, c;
    scanf("%lf %lf %lf",&a, &b, &c);
    double max;
    max = (a > b) ? a : b;
    max = (c > max) ? c : max;
    printf("%.3lf\n", max);
    printf("%.3lf\n", max);
    return 0;
}