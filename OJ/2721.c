//
// Created by LinSihan on 2019/11/15.
//
/********************************************************************
    题目描述
    Description
    现在有n个人在玩一个派对游戏，规则如下。
    每个人在纸上偷偷写下一个数字，写完后全部亮出来，
    数字在所有人里属于第三大的那个人将接受惩罚，
    如果没有第三大的数字，则写了最大的数字的所有人受惩罚。
    输入描述
    Input
    多组输入，EOF结束
    每组输入两行
    第一行有一个正整数n，表示有n个人玩游戏。n<=10000
    第二行有n个整数，分别表示这n个人的数字，数字范围不会超出int范围
    输出描述
    Output
    对于每组输出，在新的一行输出写了哪个数字的人将接受惩罚
*********************************************************************/

#include <stdio.h>

int main(){
    int n, i, j, temp, isThird, max;
    int list[10000];

    while(scanf("%d", &n) != EOF){
        for(i = 0; i < n; i++){
            scanf("%d", &list[i]);
        }

        for(i = 0; i < n - 1; i++){
            for(j = 0; j < n - 1 - i; j++){
                if(list[j] < list[j + 1]){
                    temp = list[j + 1];
                    list[j + 1] = list[j];
                    list[j] = temp;
                }
            }
        }

        isThird = 1;
        max = list[0];
        for(i = 1; i < n; i++){
            if(list[i] < max){
                isThird++;
                max = list[i];
                if(isThird == 3){
                    break;
                }
            }
        }
        if(isThird < 3){
            printf("%d\n", list[0]);
        }
        else{
            printf("%d\n", max);
        }
    }
    return 0;
}