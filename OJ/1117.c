//
// Created by LinSihan on 2019/12/27.
//
/* *********************************************************************
    题目描述
    Description
    7
    3 8
    8 1 0
    2 7 4 4
    4 5 2 6 5
    (图一)
    图一表示一个5行的数字三角形。假设给定一个n行数字三角形,
    计算出从三角形顶至底的一条路径，使该路径经过的数字总和最大。
    每一步只能由当前位置向左下或右下。
    输入描述
    Input
    你的程序要能接受标准输入。第一行包含一个整数T，表示总的测试次数。
    对于每一种情况：第一行包含一个整数N,其中1 < N < 100,表示三角形的行数。
    接下来的N行输入表示三角形的每一行的元素Ai,j，其中0 < Ai,j < 100。
    输出描述
    Output
    输出每次测试的最大值并且占一行。
*********************************************************************/

#include <stdio.h>

int main(){
    int mountain[100][100] = {0};
    int T, N;
    int i, j;

    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        //建山
        for(i = 0; i < N; i ++){
            for (j = 0; j < i+1; j ++){
                scanf("%d", &mountain[i][j]);
            }
        }
        //从山顶开始搜索
        int sum[2] = {0};
        int k = 0;
        int max;
        for(k = 0; k < 2; k++) {
            for (j = 0, i = 0; i < N; i++) {
                sum[k] += mountain[i][j];
                if(i == 0){
                    j = k;
                }
                else {
                    if (mountain[i + 1][j] > mountain[i + 1][j + 1]) {
                        j = j;
                    } else {
                        j = j + 1;
                    }
                }
            }
        }
        sum[0] > sum[1] ? (max = sum[0]) : (max = sum[1]);
        printf("%d\n", max);
    }
    return 0;
}