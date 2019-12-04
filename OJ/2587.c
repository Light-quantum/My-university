//
// Created by LinSihan on 2019/11/14.
//
/***************************************************************
    题目描述
    Description
    给出两个长度分别为n，m的正整数列，A和B
    请由小到大输出——在 数 列 B 中 出 现 次 数 为 k 的 A 数 列 元 素。
    输入描述
    Input
    输入有三行。
    第一行有三个整数分为 n m k；
    （0<n,m<=10^6）
    第二三行分别为数列A，B;
    输出描述
    Output
    输出有一个或多个整数，用空格隔开。
    如果B中没有出现次数为k的A数列元素则输出-1；
    重复元素不重复输出。
****************************************************************/

#include <stdio.h>

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int A[n];
    int B[m];
    int count[10000] = {0};
    int i, j;

    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    for(i = 0; i < m; i++){
        scanf("%d", &B[i]);
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(A[i] == B[j]){
                count[i]++;
            }
        }
    }
    int have = 0;
    for(i = 0; i < n; i++){
        if(count[i] == k){
            printf("%d ", A[i]);
            have = 1;
        }
    }
    if(have == 0){
        printf("-1");
    }
}