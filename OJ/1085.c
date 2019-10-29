//
// Created by LinSihan on 2019/10/28.
//
/*
 * 自由落体问题，计算反弹n次经过的路程
 */
#include <stdio.h>
int main(){
    double h = 100.0, s;
    int n, i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        if(i == 1){
            s = h;
        }
        else{
            h = h / 2.0;
            s = s + h * 2;
        }
    }
    printf("%.4f", s);
    return 0;
}
