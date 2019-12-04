//
// Created by LinSihan on 2019/11/27.
//
/**************************************************************
    题目描述
    Description
    给出任意的人民币(>10元)的整币兑换成5元、2元和1元币值
    （要求三种币值均有）的方法有多少种。
    输入描述
    Input
    输入任意的人民币(>10元)的整币100,50,20,10
    输出描述
    Output
    计算出兑换成5元、2元和1元币值（要求三种币值均有）的方法有多少种
****************************************************************/
#include <stdio.h>

int main(){
    int count = 0;
    int sumMoney = 0;
    int i, n;

    scanf("%d", &sumMoney);
    n = (sumMoney - 5) / 5;

    for(i = 1; i <= n; i++){
        count += ((sumMoney - i*5) - 1) / 2;
    }
    printf("%d\n", count);
    return 0;
}