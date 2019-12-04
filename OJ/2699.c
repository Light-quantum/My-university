//
// Created by LinSihan on 2019/11/15.
//
/***************************************************************************
    题目描述
    Description
    有一个序列，里面包含了 0 - n 的 n + 1 个数字，每个数字都只出现了1次。
    现在随机的删掉一个数字，并把删掉一个数字后的序列告诉你（这个序列只剩下n个数字），
    你能找出删掉的数字是什么吗？
    注意，这个序列并不一定是有序的！
    输入描述
    Input
    多组输入，EOF结束
    每组输入2行
    第一行输入一个正整数n，n∈[1,999]
    第二行输入n个数字，表示删除了一个数字后的序列

    输出描述
    Output
    对于每组输入，在新的一行输出删除的那个数字
****************************************************************************/

#include <stdio.h>
/*
int main(){
    int n, i, j, temp;

    while(scanf("%d", &n) != EOF){
        int list[1000] = {0};
        for(i = 0; i < n; i++){
            scanf("%d", &list[i]);
        }

        for(i = 0; i < n - 1; i++){
            for(j = 0; j < n - 1 - i; j++){
                if(list[j] > list[j + 1]){
                    temp = list[j + 1];
                    list[j + 1] = list[j];
                    list[j] = temp;
                }
            }
        }

        for(i = 0; i < n; i++){
            if(i != list[i]){
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}*/
int main() {
    int i, n, sum, sum1;
    while (scanf("%d", &n) != EOF) {
        int list[1000] = {0};
        sum = 0;
        sum1 = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &list[i]);
            sum1 += list[i];
        }

        for(i = 0; i <= n; i++){
            sum += i;
        }

        printf("%d\n", sum - sum1);
    }
    return 0;
}