//
// Created by LinSihan on 2019/11/11.
//
/***********************************************************
    题目描述
    Description
    编写一个程序，计算n！的值(1<=n<=10000)
    输入描述
    Input
    多组数据，每组数据占一行，每行仅含一个整数n(1<=n<=10000)
    输出描述
    Output
    对于每组数据，输出n的阶乘。你应该保证每组输出各占一行。
***********************************************************/

#include <stdio.h>
void calculatFactorial(int n);
void printResult(long long result[], int x);
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        calculatFactorial(n);
    }
}

void calculatFactorial(int n){

    int i, k, x = 0;  // i：用来计数 1 到 n 作为乘数
                      // x：用来统计最高位的下标
                      // k：用来计数当前是数组第几个元素进行计算
    long long carry = 0;  //carry：用来储存进位数值
    long long result[5000] = {1};  // 计算结果拆成每14位一组存在数组里

    for(i = 1; i <= n; i++){
        for(k = 0; k <= x; k++){
            result[k] = result[k] * i + carry;  // 计算
            carry = 0;
            if(result[k] > 100000000000000){  // 进位判断
                carry = result[k] / 100000000000000;
                result[k] = result[k] % 100000000000000;
                if(k == x){  // 如果需要进位并且此进位是最高位
                    x++;  // 最高位数加 1
                }
            }
        }
    }
    printResult(result, x);
}

void printResult(long long result[], int x){
    int i;
    for(i = x; i >= 0; i--) {
        if(i == x){  // 最高位前面不应该有 0
            printf("%lld", result[i]);
        }
        else{  // 不是最高位应该打出14位，不够左补 0
            printf("%014lld", result[i]);
        }
    }
    printf("\n");
}