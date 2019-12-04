//
// Created by LinSihan on 2019/12/3.
//
/*****************************************************************
    题目描述
    Description
    求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个一位的整数。
    例如2+22+222+2222+22222(此时共有5个数相加)
    输入描述
    Input
    整数a和n（n个数相加，1<= n, a<=9）,注意两个数之间用逗号分隔开
    输出描述
    Output
    s的值
******************************************************************/
//思路：数组：按下标加法， 高精度；

#include <stdio.h>

int main(){
    int result[11] = {0};
    int addend[11] = {0};
    int a, n, i, j = 0, carry = 0, highest = 0;

    scanf("%d,%d", &a, &n);

    for(i = 0; i < n; i++){
        addend[i] = a;
    }

    for(i = 0; i < n; i++){
        for(j = 0; j <= i; j++){
            result[j] = result[j] + addend[j] + carry;
            carry = 0;
            if (result[j] >= 10){
                carry = 1;
                result[j] -= 10;
            }
        }
    }
    if(carry == 1){
        result[j]++;
    }

    n = (a == 9 ? 9: n-1);
    for(i = n; i >= 0; i--){
        printf("%d", result[i]);
    }
    printf("\n");
    return 0;
}
