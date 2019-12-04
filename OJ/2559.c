//
// Created by LinSihan on 2019/11/29.
//
/*****************************************************************
    题目描述
    Description
    输入正整数 k，按从小到大的顺序输出所有形如 abcde/fghij=k 的表达式，
    其中 a~j 恰好为数字 0~9 的一个排列（可以有前导0），2≤k≤79。
    输入描述
    Input
    正整数k。（输入以EOF终止）
    输出描述
    Output
    输出所有符合的与abcde/fghij=k相同的式子。（以\n结尾）
*******************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int list[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, k;
    double d;
    while(scanf("%d", &k) != EOF){
        d = 0;
        for(i = 0; i < 10; i++){
            list[i] = i;
        }
        do{
            d = (list[0]*10000.0 + list[1]*1000.0 + list[2]*100.0 + list[3]*10.0 + list[4]*1.0) /
                (list[5]*10000.0 + list[6]*1000.0 + list[7]*100.0 + list[8]*10.0 + list[9]*1.0);

            if(d == k){
                printf("%d%d%d%d%d/%d%d%d%d%d=%d\n", list[0], list[1], list[2], list[3], list[4],
                       list[5], list[6], list[7], list[8], list[9], k);
            }
        }while(next_permutation(list, list+10));
    }
    return 0;
}