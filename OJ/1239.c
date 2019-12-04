//
// Created by LinSihan on 2019/11/7.
//
/******************************************************************
    题目描述
    Description
    给出一个整数，要求1、求出它是几位数2、分别输出每一位数字3、按逆序输出各位数字，例如原数为321,应输出123
    输入描述
    Input
    一个数字，数字在int32范围以内.
    输出描述
    Output
    三行
    第一行位数
    第二行用空格分开的每个数字，注意最后一个数字后没有空格
    第三行按逆序输出这个数
    进阶: 你能仅借助于整型变量完成本题吗？
*******************************************************************/
#include <stdio.h>
int main(){
    long long i, count = 0;
    char list[20];
    scanf("%s", list);
    for(i = 0; list[i] != '\0'; i++){
        count++;
    }
    printf("%lld\n", count);
    for(i = 0; i < count; i++){
        if(i == 0){
            printf("%c", list[i]);
        }
        else{
            printf(" %c", list[i]);
        }
    }
    printf("\n");
    for(i = count-1; i >= 0; i--){
        printf("%c", list[i]);
    }
    printf("\n");
    return 0;
}