//
// Created by LinSihan on 2019/11/1.
//
/**************************************
    程序功能：计算 t=1+1/2+1/3+...+1/n
    输入：int n
    输出： t
 **************************************/

#include <stdio.h>
int main(){
    int n, i;
    double t = 1.0;

    scanf("%d", &n);
    for(i = 2; i <= n; i++){
        t += 1.0 / i;
    }
    printf("%.6f", t);
    return 0;
}