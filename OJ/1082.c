// Created by LinSihan on 2019/10/28.
/************************************
 * 立方和不等式
 * 求满足下方不等式的最大正整数m
 * 1^3 + 2^3 + 3^3 +.....+ m^3 <= n
 ************************************/

#include <stdio.h>
int main(){
    int m,n;
    int Sn;
    scanf("%d", &n);
    for(m = 0, Sn = 0; Sn <= n;){
        m++;
        Sn = Sn + m * m * m;
    }
    m = m - 1;
    printf("%d", m);
    return 0;
}