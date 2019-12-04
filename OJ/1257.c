//
// Created by LinSihan on 2019/11/7.
//
/*********************************************
    题目描述
    Description
    写两个函数，分别求两个整数的最大公约数和最小公倍数，
    用主函数调用这两个函数，并输出结果两个整数由键盘输入。
    输入描述
    Input
    两个数(整数范围[0,10000])
    输出描述
    Output
    最大公约数最小公倍数
*****************************************/

#include <stdio.h>

//函数功能：求最大公约数
int getMaxCommonDivisor(int x, int y){

    //辗转相除法
    int temp = 0;

    if(x < y){
        temp = x;
        x = y;
        y = temp;
    }

    temp = x % y;
    while(temp != 0){
        x = y;
        y = temp;
        temp = x % y;
    }

    return y;
}

//函数功能：求最小公倍数
int getMinCommonMultiple(int x, int y){

    //公式法：两个数的乘积等于这两个数的最大公约数与最小公倍数的积。
    // 即[a，b]（最大公倍数）=a×b（乘积）/ （a, b）(最小公约数)
    int divisor;
    divisor = getMaxCommonDivisor(x, y);

    return (x * y / divisor);
}

int main(){
    int num1, num2;

    scanf("%d %d", &num1, &num2);
    printf("%d %d",
            getMaxCommonDivisor(num1, num2),
            getMinCommonMultiple(num1, num2));
    return 0;
}