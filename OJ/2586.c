//
// Created by LinSihan on 2019/11/15.
//
/**************************************************
    题目描述
    Description
    给一个由1-n的整数随机排序组成的字符串序列，
    其中丢失了一个整数，找到这个丢失的整数。

    输入描述
    Input
    输入有两行
    第一行为n(n <= 30)
    第二行为字符串序列

    输出描述
    Output
    输出一个整数，为丢失的整数
*****************************************************/
//大于10无法处理

#include <stdio.h>

int main() {
    int n, i, j, temp;
    char list[30] = "\0";
    int numList[30] = {0};

    scanf("%d", &n);
    scanf("%s", list);

    for(i = 0; i < n - 1; i++){
        numList[i] = list[i] - '0';
    }


    for (i = 0; i < n - 2; i++) {
        for (j = 0; j < n - 2 - i; j++) {
            if (numList[j] > numList[j + 1]) {
                temp = numList[j + 1];
                numList[j + 1] = numList[j];
                numList[j] = temp;
            }
        }
    }

    for (i = 1; i <= n; i++) {
        if (i != numList[i-1]) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}