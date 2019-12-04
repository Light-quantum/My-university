//
// Created by LinSihan on 2019/11/15.
//
/**********************************************************
    题目描述
    Description
    求[X,Y]内被除3余1并且被除5余3的整数的和
    输入描述
    Input
    输入两个正整数X,Y
    输出描述
    Output
    求所有满足条件的数的和
***********************************************************/

#include <stdio.h>
int main(){
    int x, y;
    int i;
    long long sum = 0;

    scanf("%d %d", &x, &y);
    for(i = x; i <= y; i++){
        if((i % 3 == 1) && (i % 5 ==3)){
            sum += i;
        }
    }
    printf("%lld", sum);
    return 0;
}