//
// Created by LinSihan on 2019/11/25.
//
/************************************************************
    题目描述
    Description
     对一堆混乱的日期进行排序。
    输入描述
    Input
    输入第一行有一个数n表示需要排序的个数(n < 20)。
    接下来的n行每一行有一组日期，日期按照按照月/日/年的格式输入。
    输出描述
    Output
    将已排序的日期按小到大的顺序有序输出。
*************************************************************/

#include <stdio.h>

struct date{
    int year;
    int month;
    int day;
};

int main(){
    int n, i, j;
    struct date dates[20], temp;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d/%d/%d", &dates[i].month, &dates[i].day, &dates[i].year);
    }

    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - 1 - i; j++){
            if(dates[j].year > dates[j + 1].year){
                temp = dates[j];
                dates[j] = dates[j + 1];
                dates[j + 1] = temp;
            }
            else if(dates[j].year == dates[j + 1].year){
                if(dates[j].month > dates[j + 1].month){
                    temp = dates[j];
                    dates[j] = dates[j + 1];
                    dates[j + 1] = temp;
                }
                else if(dates[j].month ==dates[j + 1].month){
                    if(dates[j].day > dates[j + 1].day){
                        temp = dates[j];
                        dates[j] = dates[j + 1];
                        dates[j + 1] = temp;
                    }
                }
            }
        }
    }
    for(i = 0; i < n; i++){
        printf("%02d/%02d/%04d\n", dates[i].month, dates[i].day, dates[i].year);
    }
    return 0;
}