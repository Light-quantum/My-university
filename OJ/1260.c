//
// Created by LinSihan on 2019/11/10.
//
/********************************************************
    题目描述
    Description
    写一个函数，使给定的一个二维数组（３×３）转置，即行列互换。
    输入描述
    Input
    一个3x3的矩阵(矩阵里面的每个数都是整数，且都在int范围内)
    输出描述
    Output
    转置后的矩阵
********************************************************/

#include <stdio.h>
int main(){
    int list[3][3] = {{0}};
    int result[3][3] = {{0}};
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            scanf("%d", &list[i][j]);
        }
    }
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            result[j][i] = list[i][j];
        }
    }
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}