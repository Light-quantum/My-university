//
// Created by LinSihan on 2019/12/11.
//
/***************************************************************
    题目描述
    Description
    在桌面上有一排硬币，共N枚，每一枚硬币均为正面朝上。
    现在要把所有的硬币翻转成反面朝上，规则是每次可翻转任意N-1枚硬币
    （正面向上的被翻转为反面向上，反之亦然）。
    求一个最短的操作序列（将每次翻转N-1枚硬币成为一次操作）。
    输入描述
    Input
    输入只有一行，包含一个自然数N（N为不大于100的偶数）。
    输出描述
    Output
    输出文件的第一行包含一个整数S，表示最少需要的操作次数。
    接下来的S行每行分别表示每次操作后桌上硬币的状态
    （一行包含N个整数（0或1），
    表示每个硬币的状态：0――正面向上，和1――反面向上，
    不允许出现多余空格）。
    对于有多种操作方案的情况，则只需字典序最小输出一种。
***************************************************************/
// 思路: 第一个不动，其余翻，第二个不动，其余翻；直到最后一个不动；

#include <stdio.h>

void turn_over(int coin[], int len, int not_turn_over);
int main(){
    int coin[100] = {0};
    int n, i, j;

    scanf("%d", &n);

    printf("%d\n", n);
    for(i = 0; i < n; i++){
        turn_over(coin, n, i);
        for(j = 0; j < n; j++){
            printf("%d", coin[j]);
        }
        printf("\n");
    }
    return 0;
}

void turn_over(int coin[], int len, int not_turn_over){
    int i;

    for(i = 0; i < len; i++){
        if(i == not_turn_over){
            continue;
        }
        else{
            coin[i] = coin[i] ? 0 : 1;
        }
    }
}