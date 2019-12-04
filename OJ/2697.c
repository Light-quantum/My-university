//
// Created by LinSihan on 2019/11/15.
//
/****************************************************
    题目描述
    Description
    你真是太喜欢OJ了！你能够输出很多个 I Love OJ 吗？
    输入描述
    Input
    输入只有1行，只有一个整数n，n∈[1,100]
    输出描述
    Output
    在奇数行输出I Love
    在偶数行输出OJ
    一共输出n行
****************************************************/

#include <stdio.h>

int main(){
    int n;
    int i;
    
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        if(i % 2 != 0){
            printf("I Love\n");
        }
        else{
            printf("OJ\n");
        }
    }
    return 0;
}