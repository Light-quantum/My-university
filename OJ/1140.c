//
// Created by LinSihan on 2019/11/3.
//
/****************************************************
    题目描述
    Description
    回文串是从左到右或者从右到左读起来都一样的字符串，试编程判别一个字符串是否为回文串。
   （使用scanf输入 ，题目不出现有空格的情况）
    输入描述
    Input
    输入一个字符串。串长度<255.
    输出描述
    Output
    判别输入的字符串是否为回文串，是输出"Y",否则输出"N"。
*****************************************************/

#include <stdio.h>
#include <string.h>
int main(){
    char list[255];
    int i;
    for(i = 0; scanf("%c",&list[i]), list[i] != '\n'; i++);
    list[i] = '\0';
    int len;
    len = strlen(list);
    char list2[len + 1];
    strncpy(list2, list, len);
    list2[len] = '\0';

    int judge = 1;
    if(len % 2 == 0){
        for(i = 0; i < len / 2; i++) {
            if (list2[i] == list2[len - 1 - i]) {
                judge = 1;
            } else {
                judge = 0;
                break;
            }
        }
    }
    else{
        for(i = 0; i < (len - 1) / 2; i++) {
            if (list2[i] == list2[len - 1 - i]) {
                judge = 1;
            } else {
                judge = 0;
                break;
            }
        }
    }
    if(judge == 1){
        printf("Y");
    }
    else{
        printf("N");
    }
}