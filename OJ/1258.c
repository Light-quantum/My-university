//
// Created by LinSihan on 2019/11/8.
//
/************************************************************************************
    题目描述
    Description
    求一元二次方程的根，用三个函数分别求当b^2-4ac大于0、等于0、和小于0时的根，
    并输出结果。从主函数输入a、b、c的值。
    当b^2-4ac>=0时，输出x1=？ x2=？, 其中x1>=x2
    当b^2-4ac<0时，输出x1= A + Bi, x2 = C + Di,
                  其中A, C分别为x1, x2的实数部分, B, D 分别为x1, x2的虚数部分。其中B>D
    输入描述
    Input
    三个整数a, b, c, 整数与整数之间间隔一个空格。(-10<a,b,c<10)
    输出描述
    Output
    当b^2-4ac>=0时，输出x1=？ x2=？ , 其中x1>=x2
    当b^2-4ac<0时，输出x1= A + Bi, x2 = C + Di,
                  其中A, C分别为x1, x2的实数部分, B, D 分别为x1, x2的虚数部分。其中B>D
***********************************************************************************/

#include <stdio.h>
#include <math.h>
int main(){
    double a, b, c;
    double rootDiscriminant;
    double x1, x2;

    scanf("%lf %lf %lf", &a, &b, &c);
    rootDiscriminant = b * b - (4 * a * c);

    if(rootDiscriminant >= 0){
        x1 = (-b - sqrt(rootDiscriminant)) / (2 * a);
        x2 = (-b + sqrt(rootDiscriminant)) / (2 * a);
        printf("x1=%g x2=%g", x1, x2);
    }
    else{
        rootDiscriminant = -rootDiscriminant;
        x1 =(-b + sqrt(rootDiscriminant)) / (2 * a);
        x2 = (-b - sqrt(rootDiscriminant)) / (2 * a);
        if(x1 == 1 && x2 == 1) {
            printf("x1=i x2=i");
        }
        else if(x1 == 1 && x2 > 1) {
            printf("x1=%gi x2=i", x2);
        }
        else if(x1 == 1 && x2 > 1) {
            printf("x1=%gi x2=i", x2);
        }
        else if(x1 == -1 && x2 == 1) {
            printf("x1=i x2=-i");
        }
        else if(x1 == -1 && x2 == -1) {
            printf("x1=-i x2=-i");
        }
        else{
            printf("x1=%g x2=%g", x1, x2);
        }
    }
}
