//
// Created by LinSihan on 2019/11/2.
//
/***************************
 * 自由落体问题：
 *  输入：M米高度落下， 第N次反弹；
 *  输出：反弹高度，共经过多少米；
 ****************************/

#include <stdio.h>
int main(){
    int n, i;
    double h, s;

    scanf("%lf %d", &h, &n);
    for(i = 1; i <= n; i++){
        if(i == 1){
            s = h;
            h = h / 2.0;
        }
        else{
            s = s + h * 2;
            h = h / 2.0;
        }
    }
    printf("%.2lf %.2lf", h, s);
    return 0;
}

