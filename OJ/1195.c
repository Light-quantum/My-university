//
// Created by LinSihan on 2019/12/6.
//
/*************************************************
    题目描述
    Description
    有一堆正整数，统计其中有多少立方数。
    输入描述
    Input
    输入数据有一些正整数，其每个数都小于2^32。
    若该数为0，则应结束统计。
    输出描述
    Output
    输出所统计的立方数个数
*************************************************/

#include <stdio.h>
#include <math.h>

int main(){
    long long int legislativeNumber[1630];

    int i;
    for(i = 0; i < 1630; i++){
        legislativeNumber[i] = pow(i+1, 3);
    }

    long long int n;
    int count = 0;
    while(scanf("%lld", &n), n != 0){
        for(i = 0; n >= legislativeNumber[i]; i++){
            if(n == legislativeNumber[i]){
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}