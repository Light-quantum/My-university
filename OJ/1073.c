//
// Created by LinSihan on 2019/10/27.
//
/*
 * 求1到n的阶乘数之和；
 * 两层嵌套循环
 * 外层n循环
 * 内层阶乘循环
 */
#include <stdio.h>
int main(){
    int n, i, j , sum = 0, factorial;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        j = i;
        factorial = 1;
        while(j >= 1){
            factorial = factorial * j;
            j--;
        }
        sum = sum + factorial;
    }
    printf("%d", sum);
    return 0;
}
