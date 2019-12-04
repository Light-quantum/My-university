//
// Created by LinSihan on 2019/11/14.
//
/**************************************************************
    题目描述
    Description
    输入m个数，请你对m个数升序排序后输出
    输入描述
    Input
    有多组数据。每组数据第一行为m(1<=m<=1000),代表有m个数，
    第二行为m个数，范围为-1000000000到1000000000.结束标记为m=0
    输出描述
    Output
    对于每组数据，输出升序排序后的结果
 **************************************************************/
#include <stdio.h>

int main(){
    int m, i, j;
    int list[1000];
    int temp;
    while(scanf("%d", &m), m != 0){
        for(i = 0; i < m; i++){
            scanf("%d", &list[i]);
        }

        for(i = 0; i < m - 1; i++) {
            for (j = 0; j < m - 1 - i; j++) {
                if (list[j] > list[j + 1]) {
                    temp = list[j + 1];
                    list[j + 1] = list[j];
                    list[j] = temp;
                }
            }
        }

        for(i = 0; i < m; i++){
            printf("%d ", list[i]);
        }
        printf("\n");
    }
    return 0;
}