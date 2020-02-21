//
// Created by LinSihan on 2019/12/11.
//
/***************************************************
    题目描述
    Description
    有一堆煤球，堆成三角棱锥形。具体：
    第一层放1个，
    第二层3个（排列成三角形），
    第三层6个（排列成三角形），
    第四层10个（排列成三角形），
    ....
    如果一共有n层，则这n层共有多少个煤球？
***************************************************/

// 思路：一个立体的三棱锥

#include <stdio.h>
long long int everyTierNumber(int Tier);
int main(){
    int n, i;
    long long sum = 0;
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        sum += everyTierNumber(i);
    }
    printf("%lld\n", sum);
    return 0;
}

long long int everyTierNumber(int Tier){
    int i;
    long long  sum = 1;
    for(i = 2; i <= Tier; i++){
        sum += i;
    }
    return sum;
}