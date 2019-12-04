//
// Created by LinSihan on 2019/11/18.
//
/****************************************************
    题目描述
    Description
    某人有四张3分的邮票和三张5分的邮票，
    用这些邮票中的一张或若干张可以得到多少种不同的邮资？
    输入描述
    Input

    输出描述
    Output
    可得到多少种
*****************************************************/

#include <stdio.h>

int main(){
    int num_of_three, num_of_five;
    int sumMoney, kind = 0, specificMoney[30] = {1};
    int same = 0, i, k = 0;

    for(num_of_three = 1; num_of_three <= 4; num_of_three++) {
        for (num_of_five = 1; num_of_five <= 3; num_of_five++) {
            sumMoney = num_of_three * 3 + num_of_five * 5;
            specificMoney[k] = sumMoney;
            kind++;
            k++;
        }
    }

    for(num_of_three = 1; num_of_three <= 4; num_of_three++) {
        sumMoney = num_of_three * 3;
        same = 0;
        for (i = 0; specificMoney[i]; i++) {
            if (sumMoney == specificMoney[i]) {
                same = 1;
                break;
            }
        }
        if (same == 0) {
            specificMoney[k] = sumMoney;
            kind++;
            k++;
        }
    }

    for(num_of_five = 1; num_of_five <= 3; num_of_five++) {
        sumMoney = num_of_five * 5;
        same = 0;
        for (i = 0; specificMoney[i]; i++) {
            if (sumMoney == specificMoney[i]) {
                same = 1;
                break;
            }
        }
        if (same == 0) {
            specificMoney[k] = sumMoney;
            kind++;
            k++;
        }
    }
    printf("%d\n", kind);
    return 0;
}