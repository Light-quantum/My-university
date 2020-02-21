//
// Created by LinSihan on 2019/12/7.
//
/****************************************************
    题目描述
    Description
    定义一个结构体变量（包括年、月、日）。
    计算该日在本年中是第几天，注意闰年问题。
    输入描述
    Input
    年月日
    输出描述
    Output
    当年第几天
***************************************************/

#include <stdio.h>

struct Year{
    int year;
    int month;
    int day;
};

int isLeapYear(int year);
int dayEveryMonth(int year, int month);
int main(){
    int i;
    int sumDay = 0;
    struct Year year;
    scanf("%d %d %d", &year.year, &year.month, &year.day);
    for(i = 1; i <= year.month; i++){
        if(i == year.month){
            sumDay += year.day;
        }
        else{
            sumDay += dayEveryMonth(year.year, i);
        }
    }
    printf("%d\n", sumDay);
    return 0;

}

int isLeapYear(int year) {
    return (year % 100 == 0) ? (year % 400 == 0) : (year % 4 == 0);
}
int dayEveryMonth(int year, int month){
    int day = 0;
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: day = 31; break;
        case 4:
        case 6:
        case 9:
        case 11: day = 30; break;
        case 2: {
            if(isLeapYear(year)){
                day = 29;
            }
            else{
                day = 28;
            }
        } break;
        default: return 0;
    }
    return day;
}