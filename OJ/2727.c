//
// Created by LinSihan on 2019/11/23.
//
/*****************************************************************
    题目描述
    Description
    输入一个数字n(0<n<=8)，输出所有n位数的各位数字的n次方等于本身的数。
    输入描述
    Input
    输入多组数据，每组占一行，每行含一个整数n(1≤n≤8)
    输出描述
    Output
    对于每个数据，输出一行，
    即所有n位数的各位数的n次方和等于本身的数，两个数之间用空格隔开。
    如果没有这样的数字，请打印 Not Find
****************************************************************/
//优化减少pow的计算次数
#include <stdio.h>
#include <math.h>

void getEveryNumber(int num, int everyNum[]);
int main(){
    int n, haveThisNum, number1, number2;
    long long sum;
    int i;
    int everyNum[8] = {0};

    while(scanf("%d", &n) != EOF) {
        haveThisNum = 0;
        number1 = pow(10, n);
        if(n == 1){
            number2 = 0;
        }
        else{
            number2 = pow(10, n - 1);
        }
        for(i = (0+number2); i < number1; i++){
            getEveryNumber(i, everyNum);
            sum = 0;
            for(i = 0; i < n; i++){
                sum += pow(everyNum[i], n);
            }
            if(sum == i){
                haveThisNum = 1;
                printf("%d ", i);
            }
        }
        printf("\n");
        if(haveThisNum == 0){
            printf("Not Find\n");
        }
    }
    return 0;
}

void getEveryNumber(int num, int everyNum[]){
    int i;
    for(i = 0; i < 8; i++){
        everyNum[i] = 0;
    }
    if(num < 10){
        everyNum[0] = num;
    }
    else if((num >= 10) && (num < 100)){
        everyNum[0] = num % 10;
        everyNum[1] = num / 10;
    }
    else if((num >= 100) && (num < 1000)){
        everyNum[0] = num % 10;
        everyNum[1] = (num % 100) / 10;
        everyNum[2] = num / 100;
    }
    else if((num >= 1000) && (num < 10000)){
        everyNum[0] = num % 10;
        everyNum[1] = (num % 100) / 10;
        everyNum[2] = (num % 1000) / 100;
        everyNum[3] = num / 1000;
    }
    else if((num >= 10000) && (num < 100000)){
        everyNum[0] = num % 10;
        everyNum[1] = (num % 100) / 10;
        everyNum[2] = (num % 1000) / 100;
        everyNum[3] = (num % 10000) / 1000;
        everyNum[4] = num / 10000;
    }
    else if((num >= 100000) && (num < 1000000)){
        everyNum[0] = num % 10;
        everyNum[1] = (num % 100) / 10;
        everyNum[2] = (num % 1000) / 100;
        everyNum[3] = (num % 10000) / 1000;
        everyNum[4] = (num % 100000) / 10000;
        everyNum[5] = num / 100000;
    }
    else if((num >= 1000000) && (num < 10000000)) {
        everyNum[0] = num % 10;
        everyNum[1] = (num % 100) / 10;
        everyNum[2] = (num % 1000) / 100;
        everyNum[3] = (num % 10000) / 1000;
        everyNum[4] = (num % 100000) / 10000;
        everyNum[5] = (num % 1000000) / 100000;
        everyNum[6] = num / 1000000;
    }
    else if((num >= 10000000) && (num < 100000000)) {
        everyNum[0] = num % 10;
        everyNum[1] = (num % 100) / 10;
        everyNum[2] = (num % 1000) / 100;
        everyNum[3] = (num % 10000) / 1000;
        everyNum[4] = (num % 100000) / 10000;
        everyNum[5] = (num % 1000000) / 100000;
        everyNum[6] = (num % 10000000) / 1000000;
        everyNum[7] = num / 1000000;
    }
}