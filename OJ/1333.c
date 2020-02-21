//
// Created by LinSihan on 2019/12/7.
//
/**********************************************************************************
    题目描述
    Description
    求一元二次方程的根，用三个函数分别求当b^2-4ac大于0、等于0、和小于0时的根，并输出结果。
    从主函数输入a、b、c的值。
    当b^2-4ac>=0时，输出x1=？ x2=？, 其中x1<=x2
    当b^2-4ac<0时，输出x1= A + Bi, x2 = C + Di,
    其中A, C分别为x1, x2的实数部分, B, D 分别为x1, x2的虚数部分。其中B<D
    提示：A,B,C,D用double存储，输出时的标识符为%lg，对虚数部分（1i）不合法
    输入描述
    Input
    三个整数a, b, c, 整数与整数之间间隔一个空格。(-10<a,b,c<10)
    输出描述
    Output
    当b^2-4ac>=0时，输出x1=？ x2=？ , 其中x1<=x2
    当b^2-4ac<0时，输出x1= A + Bi, x2 = C + Di,
    其中A, C分别为x1, x2的实数部分, B, D 分别为x1, x2的虚数部分。其中B<D
    提示：A,B,C,D用double存储，输出时的标识符为%lg，对虚数部分（1i）不合法
************************************************************************************/

#include <stdio.h>
#include <math.h>
int main(){
    double a, b, c;
    double rootDiscriminant;
    double A, B;
    double x1, x2;
    while(scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
        rootDiscriminant = b * b - (4 * a * c);
        if (rootDiscriminant >= 0) {
            x1 = (-b + sqrt(rootDiscriminant)) / (2 * a);
            x2 = (-b - sqrt(rootDiscriminant)) / (2 * a);
            if(x2 == 0 && x1 != 0){
                printf("x1=%lg x2=0\n", x1);
            }
            else if(x1 == 0 && x2 != 0){
                printf("x1=0 x2=%lg\n", x2);
            }
            else if(x1 == 0 && x2 == 0){
                printf("x1=0 x2=0\n");
            }
            else {
                printf("x1=%lg x2=%lg\n", x1, x2);
            }
        } else {
            rootDiscriminant = -rootDiscriminant;
            A = (-b) / (2.0 * a);
            B = sqrt(rootDiscriminant) / (2 * a);
            if (B == 1 && A == 0) {
                printf("x1=-i x2=+i\n");
            } else if (B == 1) {
                printf("x1=%lg-i x2=%lg+i\n", A, A);
            } else {
                if (B < 0) {
                    B = -B;
                }
                printf("x1=%lg-%lgi x2=%lg+%lgi\n", A, B, A, B);
            }
        }

    }
    return 0;
}