//
// Created by LinSihan on 2019/11/9.
//
/*********************************************************************************
    题目描述
    Description
    佳哥喜欢玩数字游戏，他很喜欢这样的一种数字：这个数字的高位总小于等于低位。如12345。
     佳哥把这种数字叫做有趣的数字。但是有趣的数字太多了，给你一个n，
     你能帮佳哥找到一个尽可能大，但又不会大于n的有趣的数字吗？
    输入描述
    Input
    多组输入，EOF结束
    每组输入一个非负整数 n （n <= 10^9）
    输出描述
    Output
    对于每一组输入，在新的一行输出最大的而且不大于n的有趣的数字
**********************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    char num[50] = "\0";
    char result[50] = "\0";
    int n, i;
    char max;
    while (scanf("%s", num) != EOF) {
        n = strlen(num);
        result[n] = '\0';
        max = num[n - 1];
        for (i = n - 1; i >= 0; i--) {
            if (num[i] != '0') {
                if (i == n - 1) {
                    result[i] = max;
                }
                else {
                    if (max > num[i]) {
                        max = num[i];
                        result[i] = max;
                    }
                    else {
                        result[i] = max;
                    }
                }
            }
            else {
                max = '9';
                for (; i >= 0; i--) {
                    if (i != 0) {
                        result[i] = max;
                    }
                    else {
                        result[i] = num[i] - 1;
                    }
                }
                printf("%s\n", result);
                continue;
            }
        }
        printf("%s\n", result);
    }
    return 0;
}
