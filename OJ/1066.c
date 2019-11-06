//
// Created by LinSihan on 2019/11/3.
//
/*******************************************
    题目描述
        所给字符串正序和反序连接，形成新串并输出
    输入描述
        任意字符串（长度<=50）
    输出描述
        字符串正序和反序连接所成的新字符串
**********************************************/

#include <stdio.h>
#include <string.h>
int main(){
    char list[100];
    char list2[50];
    int i, len;
    char temp;
    gets(list2);
    strcpy(list, list2);
    len = strlen(list2); // len = 4
    if(len % 2 == 0){
        for(i = 0; i < len / 2; i++){  // i < 2 i = 0 1
            temp = list2[i];
            list2[i] = list2[len - 1 - i];
            list2[len - 1 - i] = temp;
        }
    }
    else{
        for(i = 0; i < (len - 1) / 2; i++){  // i < 2 i = 0 1
            temp = list2[i];
            list2[i] = list2[len - 1 - i];
            list2[len - 1 - i] = temp;
        }
    }
    strcat(list, list2);
    puts(list);
}