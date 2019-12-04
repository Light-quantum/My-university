//
// Created by LinSihan on 2019/12/3.
//
/**********************************************************************
    题目描述
    Description
    一个整数，只知道前几位，不知道末二位，
    被另一个整数除尽了，那么该数的末二位该是什么呢
    输入描述
    Input
    输入数据有若干组，每组数据包含二个整数a，b（0＜a＜10000, 10＜b＜100），
    若遇到0 0则处理结束
    输出描述
    Output
    对应每组数据，将满足条件的所有尾数在一行内输出，格式见样本输出。
    同组数据的输出，其每个尾数之间空一格，行末没有空格。
**********************************************************************/

#include <stdio.h>

int main(){
    int a, b;
    int i;
    int guess = 0;
    int isTheFirst = 1;

    while(scanf("%d %d", &a, &b), a != 0 || b != 0){
        guess = 0;
        isTheFirst = 1;
        for(i = 0; i < 100; i++){
            guess = a * 100 + i;
            if(guess % b == 0){
                if(isTheFirst == 1){
                    isTheFirst = 0;
                    printf("%02d", i);
                }
                else{
                    printf(" %02d", i);
                }
            }
        }
        printf("\n");
    }
}