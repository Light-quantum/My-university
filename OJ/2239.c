//
// Created by LinSihan on 2019/12/6.
//
/*******************************************************************
    题目描述
    Description
    Jq不懂高数，其实他也不懂数学，最近他又被一道数学题难倒了。请你帮帮他吧。
    找出小于等于正整数N的使得(2^n-1)能被7整除的正整数n的个数。
    输入描述
    Input
    输入整数N(0 < N < 2^30).处理到文件结束
    输出描述
    Output
    对于每个N，输出相应的答案.
*********************************************************************/

#include <stdio.h>
#include <math.h>
int getIntPow(int n);
int main(){
    int N, i;
    int ret = 0;
    int count = 0;
    int power = 0;

    while(scanf("%d", &N) != EOF) {
        power = getIntPow(1);
        for (i = 2; i <= N; i++) {
            ret = 0;
            if(power % 7 == 0){
                ret = 1;
            }
            if(ret){
                count++;
            }
            power = getIntPow(i-1);
        }
        printf("%d\n", count);
    }
    return 0;
}

int getIntPow(int n){

    int i, sum = 1;
    for(i = 1; i <= n; i++){
        sum *= 2;
    }
    return sum;
}