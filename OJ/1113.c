//
// Created by LinSihan on 2019/12/6.
//
/*******************************************************************
    题目描述
    Description
    根据输入的半径值，计算球的体积。
    输入描述
    Input
    输入数据有多组，每组占一行，每行包括一个实数，表示球的半径。
    输出描述
    Output
    输出对应的球的体积，对于每组输入数据，输出一行，计算结果保留三位小数。
*******************************************************************/

#include <stdio.h>
#define PI 3.1415926535

int main(){
    double r;
    double V;

    while (scanf("%lf", &r) != EOF){
        V = (4.0 / 3.0) * PI * r * r * r;
        printf("%.3f\n", V);
    }
    return 0;
}