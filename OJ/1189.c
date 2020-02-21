//
// Created by LinSihan on 2019/12/9.
//
/****************************************************************
    题目描述
    Description
    给定一个日期，输出这个日期是该年的第几天。
    输入描述
    Input
    输入数据有多组，每组占一行，数据格式为YYYY/MM/DD组成，
    具体参见sample input ,另外，可以向你确保所有的输入数据是合法的。
    输出描述
    Output
    对于每组输入数据，输出一行，表示该日期是该年的第几天。
***************************************************************/


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
    while(scanf("%d/%d/%d", &year.year, &year.month, &year.day) != EOF) {
        sumDay = 0;
        for (i = 1; i <= year.month; i++) {
            if (i == year.month) {
                sumDay += year.day;
            } else {
                sumDay += dayEveryMonth(year.year, i);
            }
        }
        printf("%d\n", sumDay);
    }
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