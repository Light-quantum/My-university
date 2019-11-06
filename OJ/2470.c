//
// Created by LinSihan on 2019/11/2.
//
/*******************************
 * 打印一个菱形
 * 。。。。。。。。。。。。。。。。。
 * 输入：正整数n
 * 输出：菱形
 *****************************/

#include <stdio.h>
int main(){
    int n;
    int i, j;
    scanf("%d", &n);
    for(i = 1; i <= n*2-1; i++){  // n=3  i <= 5 i= 1 2 3 4 5
        if(i <= n){
            for(j = 1; j <= n - i; j++){
                printf(" ");
            }

            for (j = 1; j <= i*2-1; j++) {
                printf("*");
            }
            printf("\n");
        }
        else{
            for(j = 1; j <= i - n; j++){
                printf(" ");
            }

            for(j = 1; j <= (n-(i - n))*2-1; j++){
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}