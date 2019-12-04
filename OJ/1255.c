//
// Created by LinSihan on 2019/11/7.
//
/******************************************************************************
    题目描述
    Description
    一个含有9个元素的数组，现输入一个数要求将它插入到该排序后的数组中，然
    后输出插入后从小到大排序后的数组元素。
    输入描述
    Input
    第一行，原始数列。第二行，需要插入的数字(-10^17<=数字<=10^17)
    输出描述
    Output
    排序后的数列
********************************************************************************/

#include <stdio.h>

int main(){
    long long list[10];
    int i, j;
    long long temp;
    for(i = 0; i < 9; i++){
        scanf("%lld", &list[i]);
    }
    scanf("%lld", &list[i]);

    for(i = 0; i < 9; i++){
        for(j = 0; j < 9 - i; j++){
            if(list[j] > list[j + 1]){
                temp = list[j + 1];
                list[j + 1] = list[j];
                list[j] = temp;
            }
        }
    }

    for (i = 0; i < 10; i++){
        printf("%lld\n", list[i]);
    }

    return 0;
}