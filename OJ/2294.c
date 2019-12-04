//
// Created by LinSihan on 2019/11/22.
//
/********************************************************************
    题目描述
    Description
    输入正整数a,b,c,输出a/b的小数形式,精确到小数点后c位.a,b<=10^6,c<=100.
    输入包含多组数据,结束标记为a=b=c=0
    输入描述
    Input
    输入包含多组数据,每组数据包含三个正整数a,b,c，结束标记为a=b=c=0
    输出描述
    Output
    对于每组数据，输出a/b的小数形式，精确到小数点后c位。
    注意，每组输出与每组输出之间间隔一行。
*********************************************************************/

#include <stdio.h>

int main(){
    int dividend, divisor;
    int intPart;
    int remainder;
    int i, c, j = 1, carry, isAllZero;

   while(scanf("%d %d %d", &dividend, &divisor, &c), dividend != 0 || divisor != 0 || c != 0) {
        int decimalPart[101] = {0};
        isAllZero = 0;

        //计算
        intPart = dividend / divisor;
        remainder = dividend % divisor;
        if (remainder == 0) {
            printf("Case %d: %d\n", j, intPart);
            j++;
        }
        else {
            dividend = remainder;
            for (i = 0; (i <= c) && (dividend != 0); i++) {
                if (dividend < divisor) {
                    dividend *= 10;
                    decimalPart[i] = dividend / divisor;
                    dividend = dividend % divisor;
                } else {
                    decimalPart[i] = dividend / divisor;
                    dividend = dividend % divisor;
                }
            }

            //进位处理
            if (decimalPart[c] >= 5) {
                carry = 1;
                i = 1;
                while ((carry == 1) && (i <= c)) {
                    decimalPart[c - i]++;
                    if (decimalPart[c - i] <= 9) {
                        carry = 0;
                    } else {
                        decimalPart[c - i] -= 10;
                        carry = 1;
                    }
                    i++;
                }
                if ((i > c) && (carry == 1)) {
                    intPart++;
                }
            }

            //print
            printf("Case %d: %d.", j, intPart);
            for (i = 0; i < c; i++) {
                printf("%d", decimalPart[i]);
            }
            printf("\n");
            j++;

        }
        printf("\n");
    }
    return 0;
}