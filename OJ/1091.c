//
// Created by LinSihan on 2019/11/1.
//
/**********************************
    程序功能：计算N的阶乘；
**********************************/

#include <stdio.h>
int main(){
    int N, i, sum = 1;
    scanf("%d", &N);
    
    for(i = 1; i <= N; i++ ){
        sum = sum * i;
    }
    printf("%d", sum);
    return 0;
}