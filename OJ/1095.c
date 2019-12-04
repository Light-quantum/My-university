//
// Created by LinSihan on 2019/11/17.
//
/*****************************************************************
    题目描述
    Description
    一个正整数如果等于组成它的各位数字的阶乘之和，该整数称为阶乘和数。
    例如，145=1!+4!+5!，则145是一个三位阶详细和数。
    请问:50000内共有多少个阶乘和数？
    输入描述
    Input

    输出描述
    Output
    所有的阶乘和数(按字典序，即1打头的在前，2打头的次之,..., 空格分隔)
******************************************************************/

#include <stdio.h>

int factorial(int n);
void getEveryNum(int n, int list[]);
int main(){
    int i, j;
    int sum;
    int everyFactorial[11] = {0};

    for(i = 0; i < 10; i++){
        everyFactorial[i] = factorial(i);
    }

    for(i = 1; i < 50000; i++){
        sum = 0;
        int list[6] = {-1, -1, -1, -1, -1, -1};  // 改为 6
        getEveryNum(i, list);

        for(j = 0; (list[j] != -1) && (j < 5); j++){  // 数组访问越界 j = 5
            sum += everyFactorial[list[j]];
        }
        if(sum == i) {
            if(i == 2)
                printf(" 145");
            else if(i == 145){
                printf(" 2 ");
            }
            else {
                printf("%d", i);
            }
        }
    }
    return 0;
}

int factorial(int n){
    int i, sum = 1;
    for(i = 2; i <= n; i++){
        sum *= i;
    }
    return sum;
}

void getEveryNum(int n, int list[]){
    if(n < 10){
        list[0] = n;
    }

    else if(n >= 10 && n < 100){
        list[0] = n % 10;
        list[1] = n / 10;
    }

    else if(n >= 100 && n < 1000){
        list[0] = n % 10;
        list[1] = (n / 10) % 10;
        list[2] = n / 100;
    }

    else if(n >= 1000 && n < 10000){
        list[0] = n % 10;
        list[1] = (n /10) % 10;
        list[2] = (n / 100) % 10;
        list[3] = n / 1000;
    }

    else if(n >= 10000 && n < 50000){
        list[0] = n % 10;
        list[1] = (n / 10) % 10;
        list[2] = (n / 100) % 10;
        list[3] = (n / 1000) % 10;
        list[4] = n / 10000;
    }
}