//
// Created by LinSihan on 2019/11/10.
//
/*******************************************************
    题目描述
    Description
    输入n(n<=100)个整数，按照绝对值从大到小排序后输出。
    题目保证对于每一个测试实例，所有的数的绝对值都不相等。
    输入描述
    Input
    输入数据有多组，每组占一行，
    每行的第一个数字为n,接着是n个整数，
    n=0表示输入数据的结束，不做处理。
    输出描述
    Output
    对于每个测试实例，输出排序后的结果，
    两个数之间用一个空格隔开。每个测试实例占一行
*******************************************************/
#include <stdio.h>
#include <math.h>
int main(){
    int num[100];
    int i, n;

    while(scanf("%d", &n), n != 0){
        for(i = 0; i < n; i++){
            scanf("%d", &num[i]);
        }

        int temp, j;
        for(i = 0; i < n - 1; i++){
            for(j = 0; j < n - 1 - i; j++){
                if(abs(num[j]) < abs(num[j + 1])){
                    temp = num[j + 1];
                    num[j + 1] = num[j];
                    num[j] = temp;
                }
            }
        }

        for(i = 0; i < n; i++){
            printf("%d  ", num[i]);
        }
        printf("\n");
    }
    return 0;
}
