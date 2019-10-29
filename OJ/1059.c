//
// Created by LinSihan on 2019/10/27.
//
/*
 * 水仙花数问题1
 */
#include <stdio.h>
int main(){
    int n,judge;
    int a, b, c;
    scanf("%d", &n);
    a = n / 100;  // 997  a = 9
    b = (n - a * 100) / 10; // 997 - 900 = 97
    c = (n - (n / 10) * 10);
    if (a*a*a + b*b*b + c*c*c == n){
        judge = 1;
    }
    else{
        judge = 0;
    }
    printf("%d", judge);
    return 0;
}