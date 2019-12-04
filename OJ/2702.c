//
// Created by LinSihan on 2019/11/7.
//
/**************************************************
    打印 1-1000的有趣的数字，有趣的数字定义为，数字本身可以被自己的每一位数整除，
    例如128就是一个有趣的数字，因为128 % 1 == 0 ，128 % 2 == 0，128 % 8 == 0
    输入描述
    Input
    没有输入
    输出描述
    Output
    输出1-1000的有趣的数字，每个数字用空格隔开
***************************************************/
#include <stdio.h>

int main(){
    int n;
    int divisor1, divisor2, divisor3;
    for(n = 1; n <= 1000; n++){
        if(n <= 9){
            divisor1 = n;
            if( n % divisor1 == 0){
                printf("%d ", n);
            }
        }

        else if(n >= 10 && n <= 99){
            divisor1 = n / 10;
            divisor2 = n % 10;
            if(divisor2 != 0) {
                if (n % divisor1 == 0 && n % divisor2 == 0) {
                    printf("%d ", n);
                }
            }
        }

        else if(n >=100 && n <= 999){
            divisor1 = n / 100;
            divisor2 = (n % 100) / 10;
            divisor3 = (n % 100) % 10;
            if(divisor2 != 0 && divisor3 != 0){
                if (n % divisor1 == 0 && n % divisor2 == 0 && n % divisor3 == 0){
                    printf("%d ", n);
                }
            }
        }
    }
    return 0;
}