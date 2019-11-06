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
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include "util.h"

int main(){
    int year, month, days, w, c;

    time_t nowtime;
    struct tm *timeinfo;
    time( &nowtime ); //获取当前时间
    timeinfo = localtime( &nowtime ); //转为当地时间
    year = timeinfo->tm_year + 1900; //从1900年开始算起
    month = timeinfo->tm_mon + 1;

    do{
        days = getDays(year, month); //获得该月天数
        w = getWeek(year, month); //使用蔡勒公式计算该月1号是星期几
        getCalendar(w, days, year, month); //打印出日历
        c = getch();
        if(c == 75 ){
            if(month == 1){
                month = 12;
                year = year - 1;
            }
            else
                month = month - 1;
        }
        else if(c == 77){
            if(month == 12){
                month = 1;
                year = year + 1;
            }
            else
                month = month + 1;
        }

        else if(c == 72){
            year = year - 1;
        }
        else if(c == 80){
            year = year + 1;
        }
        system("cls");

    }while(c != 27);
    return 0;
}