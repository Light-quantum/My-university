// Created by LinSihan on 2019/10/27.
/****************
 * 最大公约数问题
 ***************/

#include <stdio.h>
int main(){
    int a, b, i, divisor;
    scanf("%d %d", &a, &b);
    for (i = 1; i <= a; i++){
        if (a % i == 0){
            if(b % i == 0){
                divisor = i;
            }
        }
    }
    printf("%d", divisor);
    return 0;
}