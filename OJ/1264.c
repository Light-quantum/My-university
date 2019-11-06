//
// Created by LinSihan on 2019/11/3.
//
/*****************************************
    题目描述
    Description
    写一函数，输入一个四位数字，要求输出这四个数字字符，但每两个数字间空格。
             如输入1990，应输出"1 9 9 0"。
    输入描述
    Input
    一个四位数
    输出描述
    Output
   增加空格输出
 ****************************************/

#include <stdio.h>
#include <string.h>
int main(){
    char list[5];
    int i;
    gets(list);
    for(i = 0; i < 4; i++){
        printf("%c", list[i]);
        printf(" ");
    }
}