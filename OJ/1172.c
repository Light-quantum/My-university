//
// Created by LinSihan on 2019/11/17.
//
/****************
    求最小公倍数
****************/

#include <stdio.h>
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

int getMinCommonMultiple(int x, int y){

    //公式法：两个数的乘积等于这两个数的最大公约数与最小公倍数的积。
    // 即[a，b]（最大公倍数）=a×b（乘积）/ （a, b）(最小公约数)
    int divisor;
    divisor = getMaxCommonDivisor(x, y);

    return (x * y / divisor);
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", getMinCommonMultiple(a, b));
    return 0;
}