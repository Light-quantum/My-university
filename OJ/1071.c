//
// Created by LinSihan on 2019/10/27.
//
/*
 * 斐波那契数列问题
 * 1 1 2 3 5 8 13 ......
 * 关键在如何相加还能继续输出下去
 * 用an1，an2分别代表前一个和后一个数，然后不断将an2的值给an1，然后an2得到新值
 */
#include <stdio.h>
int main(){
    int n, an1 = 0, an2 = 0, an3, m;
    scanf("%d", &m);
    for(n = 1; n <= m; n++){
        if (n == 1){
            an1 = an2;
            an2 = 1;
            printf("%d ", an2);
        }
        else{
            an3 = an1 + an2;
            an1 = an2;
            an2 = an3;
            printf("%d ", an2);
        }
    }
    return 0;
}
