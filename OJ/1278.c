//
// Created by LinSihan on 2019/11/3.
//
/**************************************
    题目描述
    Description
    有一字符串，包含n个字符。写一函数，将此字符串中从第m个字符开始的全部字符复制成为另一个字符串。(下标从0开始)
    输入描述
    Input
    数字n一行字符串数字m
    输出描述
    Output
    从m开始的子串
***************************************/

#include <stdio.h>
#include <string.h>

int main(){
    int n, m;
    scanf("%d\n", &n); //scanf()里面有啥要原封不动的输入；
    char c[n];
    char c2[n];
    int i, j;
    //getchar();
    for(i = 0; i < n; i++){ // 0 1 2 3 4 5 6
        scanf("%c", &c[i]);
    }
    c[i] = '\0';

    scanf("%d", &m);


    for(j = 0, i = m; c[i] != '\0'; i++, j++){
        c2[j] = c[i];
    }
    c2[j] = '\0';

    printf("%s", c2);
    return 0;
}