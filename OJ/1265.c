//
// Created by LinSihan on 2019/11/10.
//
/********************************************************************************
    题目描述
    Description
    编写一函数，由实参传来一个字符串，
    统计此字符串中字母、数字、空格和其它字符的个数，在主函数中输入字符串以及输出上述结果。
    只要结果，别输出什么提示信息。(字符串最多10000字符)
    输入描述
    Input
    一行字符串
    输出描述
    Output
    统计数据，4个数字，空格分开。（注意行末不应该有空格）
**********************************************************************************/

#include <stdio.h>
#include <string.h>


int main(){
    int i;
    char list[10001];  // 0 到 9999
    int result[4] = {0};
    gets(list);

    for(i = 0; list[i] != '\0'; i++){ //  9999 != '\0'
        if((list[i] >= 'a' && list[i] <= 'z') || (list[i] >= 'A' && list[i] <= 'Z')){
            result[0]++;
        }
        else if((list[i] >= '0' && list[i] <= '9')){
            result[1]++;
        }

        else if(list[i] == ' '){
            result[2]++;
        }
        else{
            result[3]++;
        }
    }
    for(i = 0; i < 4; i++){
        if(i == 0){
            printf("%d", result[i]);
        }
        else{
            printf(" %d", result[i]);
        }
    }
    return 0;
}