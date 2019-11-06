//
// Created by LinSihan on 2019/11/3.
//
/******************************************************************************
 *题目描述
        编一个程序，输入一个字符串，将组成字符串的所有非英文字母的字符删除后输出。
 *输入描述
        一个字符串，长度不超过80个字符
 *输出描述
        删掉非英文字母后的字符串。
******************************************************************************/

#include <stdio.h>
#include <string.h>

int main(){
    int i, j = 0;
    char list[80] = {' '};
    char list2[80] = {' '};
    gets(list);

    for(i = 0; i < strlen(list); i++){
        if((list[i] >= 'a' && list[i] <= 'z') || (list[i] >= 'A' && list[i] <= 'Z')){
            list2[j] = list[i];
            j++;
        }
        else
            continue;
    }

    puts(list2);
    return 0;
}