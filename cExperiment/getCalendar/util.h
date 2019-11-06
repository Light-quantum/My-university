// Created by LinSihan on 2019/10/30.


#ifndef CALENDAR_UTIL_H
#define CALENDAR_UTIL_H

#endif //CALENDAR_UTIL_H

#include <stdio.h>
/*************************************************************
    函数功能：get the number of days in this month; 获得每月天数
。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    输入：month; 月份
    输出：the number of day in this month; 该月天数
                                    by SihanLin 19-10-30 00:14
**************************************************************/
int isLeapYear(int year);
int getDays(int year, int month){
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return (isLeapYear(year)) ? 29 : 28;
        default:
            return 0;
    }
}



/*************************************************************
    函数功能：judge whether the input year is a leap year？
             判断输入的年份是否为闰年
。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    输入：year; 年份
    输出：Whether it is a leap year, is 1, no is 0;
         是否为闰年，是为1，否为0；
                                    by SihanLin 19-10-30 00:36
**************************************************************/
int isLeapYear(int year){
    return year % (year % 100 == 0 ? 400 : 4) == 0;
}



/*************************************************************
    函数功能：使用蔡勒公式计算每月一号对应星期几
。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    输入：year，month，day = 1；
    输出：输入[0, 6],对应周日到周一
                                    by SihanLin 19-10-30 00:47
**************************************************************/
int getWeek(int year, int month) {
    int day = 1;
    int c, y, m, d, w;

    //计算前预处理
    if (month <= 2) {
        y = year - 1;
        m = 12 + month;
    } else {
        y = year;
        m = month;
    }
    d = day;
    c = y / 100;
    y = y % 100;


    //开始计算
    w = ((y + (y / 4) + (c / 4) - 2 * c + (26 * (m + 1) / 10) + d - 1) % 7 + 7) % 7;

    return w;
}


/*************************************************************
    函数功能：打印日历
。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    输入：蔡勒公式计算结果w，该月天数days
    输出：打印出日历
                                    by SihanLin 19-10-30 10:59
*************************************************************/
int getCalendar(int w, int days, int year, int month){
    int w1;
    w1 = w;
    printf("---------------万年历（%4d年%2d月）------------------------\n\n", year, month);
    printf("日\t一\t二\t三\t 四\t 五\t 六\n");
    printf("\n ");
    while(w1--){
        printf("\t");
    }
    int i, j;
    for(i = 1; i <= days; i++){
        printf("%2d\t", i);
        j = i + w;
        if(j % 7 == 0){
            printf("\n ");
            printf("\n ");
        }
    }
    printf("\n");
    printf("----------------------------------------------------\n");
    printf("按上下箭头切换年份，按左右箭头切换月份（Esc退出）");
    return 1;
}