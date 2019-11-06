//
// Created by LinSihan on 2019/11/1.
//
/*******************************************
    程序功能：计算两个数的最大公约数和最小公倍数；
    。。。。。。。。。。。。。。。。。。。。。。。
    输入：两个数m，n；
    输出：最大公约数，最小公倍数；
*********************************************/

#include <stdio.h>
int main(){//1 2
    long long max, min, temp,i;
    long long divisor, multiple;

    while (scanf("%lld %lld", &max, &min) != EOF){
        if(min > max){  //2>1
            temp = max;  //temp = 1
            max = min;   // max = min = 2
            min = temp;  // min = temp =1
        }

/*
        for (i = 1; i <= min; i++){
            if (min % i == 0){
                if(max % i == 0){
                    divisor = i;
                }
            }
        }
*/

//欧里几德最大公约数算法
        long long max1 = max, min1 = min;
        while(1){
            temp = max1 % min1;
            if(temp == 0){
                divisor = min1;
                break;
            }
            else{
                max1 = min1;
                min1 = temp;
            }

        }
//公式法算最小公倍数
        multiple = max * min / divisor;

        printf("%lld %lld\n", divisor, multiple);
    }

    return 0;
}