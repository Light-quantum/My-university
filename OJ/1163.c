//
// Created by LinSihan on 2019/12/9.
//
/***************************************************
    题目描述
    Description
    已知一个数列的前3个数为3，4，5，
    以后每个数为前3个数的和，编程序求此数列的第N项
    输入描述
    Input
    输入N(N<=35)
    输出描述
    Output
    求出第N项的值
***************************************************/

#include <stdio.h>

int main(){
    int list[36] = {3, 4, 5};
    int i, n;

    for(i = 3; i < 35; i++){
        list[i] = list[i - 3] + list[i - 2] + list[i - 1];
    }

    scanf("%d", &n);
    printf("%d\n", list[n - 1]);
    return 0;
}