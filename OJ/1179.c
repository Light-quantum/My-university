//
// Created by LinSihan on 2019/12/7.
//
/***************************************************
    题目描述
    Description
    设有一头小母牛，从出生第四年起每年生一头小母牛，
    按此规律，第N年时有几头母牛？
    输入描述
    Input
    输入一个整数N。(1≤N≤50)
    输出描述
    Output
    第N年时母牛的数量
****************************************************/
//思路， 第0年到第4年都只有一只牛， 第4年开始到第8年，每年加1
//第八年开始每年加5 加6 加7 加8

#include <stdio.h>

int main(){
    int N, i;
    int sum = 0;
    int count = 6, bigCow = 1;

    scanf("%d", &N);

    for(i = 0; i <= N; i++){
        if(i < 4){
            sum = 1;
        }
        else if(i >= 4 && i < 8){
            sum += 1;
        }
        else{
            sum = sum + count;
            if(i >= 12) {
                bigCow++;
            }
            count += 4 * bigCow;
        }
    }
    printf("%d\n", sum);
    return 0;
}