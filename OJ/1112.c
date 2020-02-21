//
// Created by LinSihan on 2019/12/27.
//
/* **************************************************
    题目描述
    Description
    输入两点坐标（X1,Y1）,（X2,Y2）,计算并输出两点间的距离。
    输入描述
    Input
    输入数据有多组，每组占一行，由4个实数组成，
    分别表示x1,y1,x2,y2,数据之间用空格隔开。
    输出描述
    Output
    对于每组输入数据，输出一行，结果保留两位小数。
***************************************************/
#include <stdio.h>
#include <math.h>

typedef struct coord{
    double x;
    double y;
} COORD;

int main(){
    COORD dot1, dot2;
    double distance;

    while(scanf("%lf %lf %lf %lf", &dot1.x, &dot1.y, &dot2.x, &dot2.y) != EOF){
        distance = sqrt((dot1.x - dot2.x) * (dot1.x - dot2.x) +
                (dot1.y - dot2.y)*(dot1.y - dot2.y));
        printf("%.2lf\n", distance);
    }
    return 0;
}