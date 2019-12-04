//
// Created by LinSihan on 2019/11/13.
//
/*******************************************************************************************************
题目描述
Description
Ksusha is a beginner coder.
Today she starts studying arrays.
She has array a1, a2, ..., an,consisting of n positive integers.
Her university teacher gave her a task.
Find such number in the array, that all array elements are divisible by it.
Help her and find the number!
输入描述
Input
The first line contains integer n (1 ≤ n ≤ 10^5), showing how many numbers the array has.
The next line contains integers a1, a2,.., an(1 ≤ ai ≤ 10^9) — the array elements.
输出描述
Output
Print a single integer — the number from the array, such that all array elements are divisible by it.
If such number doesnt exist, print -1.
If there are multiple answers, you are allowed to print any of them.
********************************************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int list[n];
    int i, j;

    for (i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    //get the max in list
    int max;
    max = list[0];
    for (i = 0; i < n; i++) {
        if (list[i] > max) {
            max = list[i];
        }
    }

    //从 2 到 max 检查是否存在一个数是list中所以元素的公约数
    for (i = 2; i <= max; i++) {
        for (j = 0; j < n; j++){  //遍历数组
            if(list[j] % i == 0){
                continue;
            }
            else{
                break;
            }
        }
        if(j == n){  // 如果 j = n 则此次循环的 i 是 list 中所有元素的公约数
            printf("%d", i);
            break;
        }
        else{
            continue;
        }
    }
    if(i > max){
        printf("-1");
    }
}


















