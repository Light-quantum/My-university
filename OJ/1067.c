//
// Created by LinSihan on 2019/11/5.
//
/************************************************************************
    题目描述
    Description
    验证尼科彻斯定理，即：任何一个正整数m的立方都可以写成m个连续奇数的和。
    输入描述
    Input
    任一正整数
    输出描述
    Output
    该数的立方分解为m个连续奇数的和
**************************************************************************/

#include <stdio.h>
int main(){
    int m, i, j, temp = 1, star;
    int sum = 0;
    scanf("%d", &m);
    while(sum != m * m * m){
        sum = 0;
        j = temp;
        for(i = 1; i <= m; i++){
            sum += j;
            j += 2;
        }
        temp = (j - (2 * (m - 1)));
    }
    printf("%d*%d*%d=", m, m, m);
    star = (temp - (2 * (m - 1)));
    for(i = 1; i <= m; i++){
        printf("%d", star);
        star += 2;
    }
}