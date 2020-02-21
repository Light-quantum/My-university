//
// Created by LinSihan on 2019/12/12.
//
/* ***********************************************************************
    题目描述
    Description
    给定A,B,C三根足够长的细柱，在A柱上放有2n个中间有空的圆盘，共有n个不同的尺寸，
    每个尺寸都有两个相同的圆盘，注意这两个圆盘是不加区分的(下图为n=3的情形）。
    现要将 这些国盘移到C柱上，在移动过程中可放在B柱上暂存。要求:
    (1)每次只能移动一个圆盘；
    (2) A、B、C三根细柱上的圆盘都要保持上小下大的顺序；
    任务:设An为2n个圆盘完成上述任务所需的最少移动次数，对于输入的n，输出An。
***********************************************************************/

// (2 ^ n - 1) * 2 高精度

#include <stdio.h>
void bigMul(int n, long long result[]);
int main(){
    long long result[100] = {1};
    int n;

    scanf("%d", &n);
    bigMul(n, result);
    return 0;
}

// large number multiply
void bigMul(int n, long long result[]){
    long long carry = 0;
    int i, j = 0, high = 0;

    for(i = 0; i <= n; i++){
        carry = 0;
        for(j = 0; j <= high; j++){
            result[j] = result[j] * 2 + carry;
            carry = 0;
            if(result[j] > 10000000000000){
                carry ++;
                result[j] = result[j] - 10000000000000;
                if(j == high){
                    high++;
                }
            }
        }
    }

    result[0] -= 2;
    for(i = high; i >= 0; i--) {
        if (i == high) {
            printf("%lld", result[i]);
        }
        else{
            printf("%013lld", result[i]);
        }
    }
    printf("\n");
}