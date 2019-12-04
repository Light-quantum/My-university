//
// Created by LinSihan on 2019/11/17.
//
/*****************************************************************************
    题目描述
    Description
    正整数的各位数字之和被Tom称为Tom数。求输入数（<2^32）的Tom数!
    输入描述
    Input
    每行一个整数(<2^32).
    输出描述
    Output
    每行一个输出,对应该数的各位数之和.
*****************************************************************************/
#include <string.h>
#include <stdio.h>
void getEveryNum(char list[], int everyNum[]);
int main(){
    char num[15] = "\0";
    int everyNum[15] = {0};
    int len, i, TomNub = 0;

    while(scanf("%s", num) != EOF) {
        TomNub = 0;
        len = strlen(num);
        getEveryNum(num, everyNum);
        for (i = 0; i < len; i++) {
            TomNub += everyNum[i];
        }
        printf("%d\n", TomNub);
    }
    return 0;
}

void getEveryNum(char list[], int everyNum[]){
    int len = strlen(list);
    int i;

    for(i = len; i >=0; i--){
        everyNum[i] = list[i] - '0';
    }
}