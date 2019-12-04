//
// Created by LinSihan on 2019/11/14.
//
/***************************************************************
    题目描述
    Description
    输入描述
    Input
    有T组测试数据，每组包含N（N<1000）个数，对这N个数排序。
    输出描述
    Output
    每组测试数据输出一行，从小到大排序输出，每个数之间有一个空格。
***************************************************************/

#include <stdio.h>

int main(){
    int n, m;
    int i, j;
    int list[1000];
    int temp;

    scanf("%d", &m);
    while(m--){
        scanf("%d", &n);
        for(i = 0; i < n; i++ ){
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

        for(i = 0; i < n; i++){
            printf("%d ", list[i]);
        }
        printf("\n");
    }
    return 0;
}