//
// Created by LinSihan on 2019/11/17.
//
/***********************************************************
    变形悟空吃桃，老汉过一个收费站，收费员收他一半的羊又还给他一只,
    过了 n 个收费站，老汉到市场只剩下3只羊
************************************************************/

#include <stdio.h>

int main(){
    int n, N;
    int sum, i;

    scanf("%d", &N);
    while(N--){
        sum = 3;
        scanf("%d", &n);
        for(i = 1; i <= n; i++){
            sum = (sum - 1) * 2;
        }
        printf("%d\n", sum);
    }
    return 0;
}