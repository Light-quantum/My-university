//
// Created by LinSihan on 2019/12/6.
//
/*****************************************************************
    题目描述
    Description
    有一个长度为n(n<=100)的数列，
    该数列定义为从2开始的递增有序偶数（公差为2的等差数列），
    现在要求你按照顺序每m个数求出一个平均值，如果最后不足m个，
    则以实际数量求平均值。编程输出该平均值序列。
    输入描述
    Input
    输入数据有多组，每组占一行，包含两个正整数n和m，n和m的含义如上所述。
    输出描述
    Output
    对于每组输入数据，输出一个平均值序列，每组输出占一行
*******************************************************************/

#include <stdio.h>
int main(){
    int list[100] = {2};
    int i, j;

    for(i = 1; i < 100; i++){
        list[i] = list[i - 1] + 2;
    }

    int n, m;
    int sum = 0, count = 0;
    int meanValue = 0;

    while(scanf("%d %d", &n, &m) != EOF){
        for(i = 0; i < n;){
            sum = 0;
            count = 0;
            for(j = i; 1 ; j++){
                sum += list[j];
                count++;
                if(count == m){
                    meanValue = sum / count;
                    printf("%d ", meanValue);
                    i += count;
                    if(j == n - 1){
                        printf("\n");
                    }
                    break;

                }
                if(j == n - 1){
                    i += count;
                    break;
                }
            }
        }
        if(count != m){
            meanValue = sum / count;
            printf("%d\n", meanValue);
        }
    }
    return 0;
}