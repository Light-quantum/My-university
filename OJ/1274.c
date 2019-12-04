//
// Created by LinSihan on 2019/11/7.
//
/******************************************
    题目描述
    Description
    输入三个字符串，按由小到大的顺序输出
    输入描述
    Input
    3行字符串
    输出描述
    Output
    按照从小到大输出成3行
**********************************************/

#include <stdio.h>
#include <string.h>

int main(){
    char str1[100];
    char str2[100];
    char str3[100];
    char temp[100];
    scanf("%s %s %s", str1, str2, str3);
    int ret;
    ret = strcmp(str1, str2);
    if(ret > 0){
        strcpy(temp, str2);
        strcpy(str2, str1);
        strcpy(str1, temp);
    }
    ret = strcmp(str2, str3);
    if(ret > 0){
        strcpy(temp, str3);
        strcpy(str3, str2);
        strcpy(str2, temp);
    }
    ret = strcmp(str1, str2);
    if(ret > 0){
        strcpy(temp, str2);
        strcpy(str2, str1);
        strcpy(str1, temp);
    }
    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);
    return 0;
}