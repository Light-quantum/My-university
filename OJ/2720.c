//
// Created by LinSihan on 2019/11/15.
//
/*****************************************************************
    题目描述
    Description
    给你一组数据，如果这组数据里没有重复的数字，打印True，否则打印False
    输入描述
    Input
    多组输入，EOF结束。
    每组输入2行
    第一行输入一个正整数n，表示这组数据有n个数据，(n <= 10000)
    第二行输入n个非负整数表示这组数据，数字不会超出int范围
    输出描述
    Output
    对于每组输入，在新的一行输出结果
*******************************************************************/

#include <stdio.h>

int main(){
    int n;
    int list[10000];
    int i, j, same;
    
    while(scanf("%d", &n) != EOF){
        for(i = 0; i < n; i++){
            scanf("%d", &list[i]);
        }
        
        same = 0;
        for(i = 0; i < n; i++){
            for(j = i + 1; j < n; j++){
                if(list[j] == list[i]){
                    same = 1;
                    break;
                }
            }
        }
        if (same == 1){
            printf("False\n");
        }
        else{
            printf("True\n");
        }
    }
    return 0;
}