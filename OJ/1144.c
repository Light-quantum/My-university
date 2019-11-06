//
// Created by LinSihan on 2019/11/3.
//
/*****************************************************
    题目描述
    Description
    读入一些字符串，将其中的小写字母转成大写字母（其他字符不变）。
    输入描述
    Input
    输入为多行，每行为一个字符串，字符串只由字母和数字组成，长度不超过80。
    输出描述
    Output
    对于每行输入，输出转换后的字符串。
******************************************************/

#include <stdio.h>

int main(){
    char list[80];
    int i = 0;
    while(scanf("%c", &list[0]) != EOF) {
        for (i = 1; scanf("%c", &list[i]), list[i] != '\n'; i++);
        list[i] = '\0';

        for (i = 0; list[i] != '\0'; i++) {
            (list[i] >= 'a' && list[i] <= 'z') ? list[i] = list[i] - 32 : list[i];
        }

        printf("%s\n", list);
    }
        return 0;
}