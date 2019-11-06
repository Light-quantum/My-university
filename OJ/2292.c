//
// Created by LinSihan on 2019/11/2.
//
/********************************************************
 * 输入正整数n<=20,输出一个n层的倒三角形。例如，n=5时输出如下:
    #########
    #######
    #####
    ###
    #
 ********************************************************/

#include <stdio.h>
int main() {
    int i, j, k;
    int n;
    scanf("%d", &n);
    k = n*2-1;
    for (i = 1; i <= n; i++) {

        for (j = 1; j < i; j++) {
            printf(" ");
        }

        for(j = 1; j <= i; j++ ){
            if(j != 1){
                k = k - 2;
            }
        }

        for (j = 1; j <= k ; j++) {
            printf("#");
        }

        for (j = 1; j <= i; j++) {
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}

//更好的做法
/*
#include<stdio.h>
int main(){
    int i, j, n;
     scanf("%d",&n);
     for(i = n; i > 0; i--){

         for(j = 1; j <= n-i ; j++){
            printf(" ");
         }

         for(j = 1; j <= (2*i-1); j++){
            printf("#");
         }

         printf("\n");
     }
     return 0;
}
 */