//
// Created by LinSihan on 2019/11/10.
//
/**************************************************************
    题目描述
    Description
    写一函数，将一个字符串中的元音字母复制到另一个字符串，然后输出。
    输入描述
    Input
    一行字符串
    输出描述
    Output
    顺序输出其中的元音字母（aeiuo）
**************************************************************/

#include <stdio.h>
#include <string.h>

int main(){
    int i, j;
    char msg[1000] = "\0";
    char result[1000] = "\0";
    int n;

    scanf("%s", msg);
    n = strlen(msg);

    for(i = 0, j = 0; i < n; i++){
        if( msg[i] == 'a' || msg[i] == 'e' || msg[i] == 'i' || msg[i] == 'o' || msg[i] == 'u'){
            result[j] = msg[i];
            j++;
        }
    }
    puts(result);
    return 0;
}