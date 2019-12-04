//
// Created by LinSihan on 2019/11/7.
//
/************************************************************************************
    题目描述
    Description
    求Sn=a+aa+aaa+…+aa…aaa (有n个a) 的值。
    例如：键入5 2 ( 意思是n=5, a = 2) , 那么Sn = 2+22+222+2222+22222，n和a的值均由键盘输入。
    输入描述
    Input
    数据有多组, 每组数据仅含两个正整数n, a(1<=n<=1000, 1<=a<=9). 输入以EOF结束.
    输出描述
    Output
    对于每组数据, 输出Sn的和.
********************************************************************************/

#include <stdio.h>

int main(){
    int n, a;
    while(scanf("%d %d", &n, &a) != EOF) {
        int list[n];
        int list2[2000] = {0};
        int i, j;
        for (i = 0; i < n; i++) {
            list[i] = a;
        }
        int carry = 0;

        for (i = 1; i <= n; i++) { //1 2
            carry = 0;
            for (j = 0; j < i; j++) { //1
                list2[j] = list[j] + list2[j];
                carry = 0;
                if (list2[j] >= 10) {
                    list2[j] %= 10;
                    carry = 1;
                }
                if(carry >= 1)
                    list2[j + 1] = list2[j + 1] + carry;
            }
        }

        if (list2[n] != 0) {
            for (i = n; i >= 0; i--) {
                printf("%d", list2[i]);
            }
            printf("\n");
        }
        else {
            for (i = n - 1; i >= 0; i--) {
                printf("%d", list2[i]);
            }
            printf("\n");
        }
    }
}