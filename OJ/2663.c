//
// Created by LinSihan on 2019/11/2.
//
/************************************
    多组输入，EOF表示结束
每组输入一行，只有一个正整数n （n <= 10）
 ...................................
 输入：
    1
    2
    3
 输出：
     *

    -*-
    ***
    -*-

    --*--
    -***-
    *****
    -***-
    --*--
*************************************/

#include <stdio.h>
int main(){
    int n;
    int i, j;
    while(scanf("%d", &n) != EOF) {
        for (i = 1; i <= n * 2 - 1; i++) {  // n=3  i <= 5 i= 1 2 3 4 5
            if (i <= n) {
                for (j = 1; j <= n - i; j++) {
                    printf("-");
                }

                for (j = 1; j <= i * 2 - 1; j++) {
                    printf("*");
                }

                for (j = 1; j <= n - i; j++) {
                    printf("-");
                }
                printf("\n");
            } else {
                for (j = 1; j <= i - n; j++) {
                    printf("-");
                }

                for (j = 1; j <= (n - (i - n)) * 2 - 1; j++) {
                    printf("*");
                }

                for (j = 1; j <= i - n; j++) {
                    printf("-");
                }
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
