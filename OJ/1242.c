//
// Created by LinSihan on 2019/11/7.
//
/****************************************************************************
    题目描述
    Description
    输入一行字符，分别统计出其中英文字母、数字、空格的个数。（这行最多10000个字符）
    输入描述
    Input
    一行字符
    输出描述
    Output
    统计值
******************************************************************************/

#include <stdio.h>
#include <string.h>
int main(){
    char list[10000];
    gets(list);
    int i;
    int letter = 0, number = 0, space = 0;
    for(i = 0; list[i] != '\0'; i++){
        if((list[i] >= 'A' && list[i] <= 'Z')||(list[i] >= 'a' && list[i] <= 'z')){
            letter ++;
        }
        else if(list[i] >= '0' && list[i] <= '9'){
            number ++;
        }
        else if(list[i] == 32){
            space ++;
        }
    }
    printf("%d %d %d\n", letter, number, space);
    return 0;
}