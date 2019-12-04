//
// Created by LinSihan on 2019/11/15.
//
/************************************************************************
    题目描述
    Description
    给你一个数字n，你能够输出所有满足 a*b=n 的数对(a,b)吗？
    输入描述
    Input
    多组输入，EOF结束
    每组输入1行
    输入一个正整数n，n不会超过40000
    输出描述
    Output
    对于每组输入，都在新的一行输出结果
    排在前面的数对的a的值比排在后面的数对的a的值要小，且最后没有逗号，且 a <= b
*************************************************************************/

#include <stdio.h>

int main(){
    int n;
    int a, b;

    while(scanf("%d", &n) != EOF){
        if(n == 1){
            printf("(1,1)\n");
        }
        else{
            for(a = 1, b = n; a < b; a++){
                if(n % a == 0){
                    b = n / a;
                    if(a == 1){
                        printf("(%d,%d)", a, b);
                    }
                    else{
                        printf(",(%d,%d)", a, b);
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}