//
// Created by LinSihan on 2019/12/9.
//

/***************************************************
    题目描述
    Description
    请统计某个给定范围[L, R]的所有整数中，
    数字 2 出现的次数。
    比如给定范围[2, 22]，数字 2 在数 2 中出现了 1 次，
    在数 12 中出现 1 次，在数 20 中出
    现 1 次，在数 21 中出现 1 次，在数 22 中出现 2 次，
    所以数字 2 在该范围内一共出现了 6
    次。
    输入描述
    Input
    输入共 1 行，为两个正整数 L 和 R，之间用一个空格隔开。
    （1<=L<=R<=500000）
    输出描述
    Output
    输出共 1 行，表示数字 2 出现的次数。
****************************************************/

#include <stdio.h>

int main(){
    int count = 0;
    int r, everyNum;
    int L, R;
    int i;

    scanf("%d %d", &L, &R);
    for(i = L; i <= R; i++){
        r = i;
        while(r){
            everyNum = r % 10;
            if(everyNum == 2){
                count++;
            }
            r = r / 10;
        }
    }
    printf("%d\n", count);
    return 0;
}
