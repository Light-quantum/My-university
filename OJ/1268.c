//
// Created by LinSihan on 2019/11/3.
//
/************************************************
 *  题目描述
        三角形面积=SQRT(S*(S-a)*(S-b)*(S-c))，其中S=(a+b+c)/2，a、b、c为三角形的三边。
        定义两个带参的宏，一个用来求area，另一个宏用来求S。写程序，在程序中用带实参的宏名来求面积area。
    输入描述
        abc三角形的三条边,可以是小数。
    输出描述
        三角形面积，保留3位小数
 ***********************************************/

//投机取巧

#include <stdio.h>
#include <math.h>

double getarea(double a, double b, double c) {
    double s, area;
    s = (a + b + c) / 2.0;
    area = sqrt((s * (s - a) * (s - b) * (s - c)));
    return area;
}

int main(){
    double a, b, c;
    double area;
    scanf("%lf %lf %lf", &a, &b, &c);
    area = getarea(a, b, c);
    printf("%.3lf", area);
    return 0;
}