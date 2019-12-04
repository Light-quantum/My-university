//
// Created by LinSihan on 2019/11/10.
//
/******************************************
    题目描述
    Description
    写一函数，将两个字符串连接
    输入描述
    Input
    两行字符串
    输出描述
    Output
    链接后的字符串
******************************************/

#include <stdio.h>
#include <string.h>
int main(){
    char a[2000] = "\0";
    char b[1000] = "\0";
    scanf("%s", a);
    scanf("%s", b);
    strcat(a, b);
    puts(a);
    return 0;
}
