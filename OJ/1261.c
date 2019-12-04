//
// Created by LinSihan on 2019/11/10.
//
/**************************************************
    题目描述
    Description
    写一函数，使输入的一个字符串按反序存放，
    在主函数中输入输出反序后的字符串。
    输入描述
    Input
    一行字符
    输出描述
    Output
    逆序后的字符串
***************************************************/

#include <stdio.h>
#include <string.h>
int main(){
    char list[1000] = {'\0'};
    int n, i;
    char temp;

    scanf("%s", list);
    n = strlen(list);
    if(n % 2 == 0){
        for(i = 0; i < (n / 2); i++){
            temp = list[i];
            list[i] = list[n - 1 - i];
            list[n - 1 - i] = temp;
        }
    }
    else{
        for(i = 0; i < (n - 1) / 2; i++){
            temp = list[i];
            list[i] = list[n - 1 - i];
            list[n - 1 - i] = temp;
        }
    }
    puts(list);
}