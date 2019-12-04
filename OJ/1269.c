//
// Created by LinSihan on 2019/11/10.
//
/********************************************************
    题目描述
    Description
    给年份year，定义一个宏，以判别该年份是否闰年。
    提示：宏名可以定义为LEAP_YEAR，形参为y，
    既定义宏的形式为#define LEAP_YEAR(y)（读者设计的字符串）
    输入描述
    Input
    一个年份
    输出描述
    Output
    根据是否闰年输出，是输出"L",否输出"N"
********************************************************/

#include <stdio.h>
int main(){
    int year, isLeapYear;
    scanf("%d", &year);
    isLeapYear = 1;
    (year % (year % 100 == 0 ? 400 : 4) == 0) ? isLeapYear : isLeapYear--;
    if(isLeapYear == 1) {
        printf("L");
    }
    else{
        printf("N");
    }
    return 0;
}