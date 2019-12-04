//
// Created by LinSihan on 2019/11/14.
//
/*****************************************************************
    题目描述
    Description
    n (1 ≤ n ≤ 10^5) 个数按非升序排序，第k (1 ≤ k ≤ n) 个数是多少呢？
    输入描述
    Input
    多组测试数据。EOF结束。
    第一行为整数n, k (1 ≤ k ≤ n ≤ 10^5)。
    第二行包含n个整数。所有整数的范围在 -10^9 到 10^9之间。
    输出描述
    Output
    输出n (1 ≤ n ≤ 10^5) 个数按非升序排序，第k (1 ≤ k ≤ n) 个数的数值。
******************************************************************/
#include <stdio.h>

int main(){
    int n, k;
    int list[50000];
    int i, j, temp;
    
    while(scanf("%d %d", &n, &k) != EOF){
        for(i = 0; i < n; i++){
            scanf("%d", &list[i]);
        }

        for(i = 0; i < n - 1; i++) {
            for (j = 0; j < n - 1 - i; j++) {
                if (list[j] > list[j + 1]) {
                    temp = list[j + 1];
                    list[j + 1] = list[j];
                    list[j] = temp;
                }
            }
        }
        
        printf("%d\n", list[k - 1]);
    }
    return 0;
}