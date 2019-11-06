//
// Created by LinSihan on 2019/11/3.
//
/************************************************************************
    题目描述
    Description
    输入一行电报文字，将字母变成其下一字母（如’a’变成’b’……’z’变成’ａ’其它字符不变）。
    输入描述
    Input
    一行字符
    输出描述
    Output
    加密处理后的字符
**************************************************************************/
#include <stdio.h>
#include <string.h>

int main(){
    char list[80];
    int i;
    gets(list);
    for(i = 0; list[i] != '\0'; i++) {
        if ((list[i] >= 'a' && list[i] <= 'z') || (list[i] >= 'A' && list[i] <= list['Z'])) {
            if (list[i] == 'z') {
                list[i] = 'a';
            } else if (list[i] == 'Z') {
                list[i] = 'A';
            } else {
                list[i] = list[i] + 1;
            }
        }
        else{
            continue;
        }
    }
    puts(list);
    return 0;
}