// Created by LinSihan on 2019/10/30.

/************************************************************
    该程序作用：根据用户输入的年月打印出对应的日历；
    function: according to the user entered a year and month
              to print out the corresponding calendar；
                                  by SihanLin 19-10-30 00:37
 ***********************************************************/
// 思路：
// 输入year，month
// 计算 该月有多少天
// 计算 该月第一天是星期几
// 循环打印1到该月最后一天
// 逢周六换行

#include <stdio.h>
#include "util.h"

int main(){
    int year, month, days, w;
    scanf("%d %d", &year, &month); //输入年，月

    days = getDays(month, year); //获得该月天数
    w = getWeek(year, month); //使用蔡勒公式计算该月1号是星期几

    getCalendar(w, days); //打印出日历
    return 0;
}