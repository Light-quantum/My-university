//
// Created by LinSihan on 2019/11/26.
//
/******************************************************
    题目描述
    Description
    有2n+1个数，其中有n对数字是成双出现的，
    有且仅有1个数字只有它自己一个。请你找出这个孤单数。
    输入描述
    Input
    第一行有且只有一个正整数n(n<=500000)
    第二行有2n+1个数ai(-10^9<=ai<=10^9)
    输出描述
    Output
    有且只有一个数，输出这个孤单数。
*******************************************************/
#include <stdio.h>
/* 垃圾算法太慢了
int main(){
    int n;
    int i, j, temp;

    scanf("%d", &n);
    int number[2 * n + 1];
    int len = 2 * n + 1;

    for(i = 0; i < len; i++){
        scanf("%d", &number[i]);
    }

    for(i = 0; i < len - 1; i++){
        for(j = 0; j < len - 1 - i; j++){
            if(number[j] > number[j + 1]){
                temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
            }
        }
    }

    for(i = 0; i < len;){
        if((number[i] ^ number[i + 1]) == 0){
            i = i + 2;
            continue;
        }
        else {
            printf("%d\n", number[i]);
            break;
        }
    }
    return 0;
}
 */

int main(){
    int n, i, len;
    int a, b;
    scanf("%d", &n);
    len = 2 * n + 1;

    scanf("%d", &a);
    for(i = 1; i < len; i++){
        scanf("%d", &b);
        a = a ^ b;
    }
    printf("%d", a);
}