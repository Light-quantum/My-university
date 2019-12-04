//
// Created by LinSihan on 2019/11/10.
//

/**************************************************************
    题目描述
    Description
    有n(n<=100)个整数，已经按照从小到大顺序排列好，
    现在另外给一个整数x，请将该数插入到序列中，并使新的序列仍然有序。
    输入描述
    Input
    输入数据包含多个测试实例，每组数据由两行组成，
    第一行是n和m，第二行是已经有序的n个数的数列。
    n和m同时为0标示输入数据的结束，本行不做处理。
    输出描述
    Output
    对于每个测试实例，输出插入新的元素后的数列。
    数与数之间有一个空格，最后一个数字后没有空格
************************************************************/

#include <stdio.h>
int main(){
    int list[100];
    int result[100];
    int i, j;
    int n, m;

    while(scanf("%d %d", &n, &m), n != 0 && m != 0){
        for(i = 0; i < n; i++){
            scanf("%d", &list[i]);
        }

        for(i = 0, j = 0; i < n; i++, j++){
            if(list[i] < m && list[i + 1] > m){
                result[j] = list[i];
                j++;
                result[j] = m;
            }
            else{
                result[j] = list[i];
            }
        }

        for(i = 0; i <= n; i++){
            if(i == 0){
                printf("%d", result[i]);
            }
            else{
                printf(" %d", result[i]);
            }
        }
        printf("\n");
    }
    return 0;
}