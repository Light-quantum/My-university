//
// Created by LinSihan on 2019/11/11.
//
/**************************************************************************************
    题目描述
    Description
    相传韩信才智过人，从不直接清点自己军队的人数，
    只要让士兵先后以三人一排、五人一排、七人一排地变换队形,
    而他每次只掠一眼队伍的排尾就知道总人数了。输入包含多组数据，
    每组数据包含3个非负整数a,b,c ，表示每种队形排尾的人数（a<3,b<5,c<7），
    输出总人数的最小值（或报告无解）。已知总人数不小于10，不超过100 。
    输入到文件结束为止
    输入描述
    Input
    输入包含多组数据，每组数据包含3个非负整数a,b,c ，表示每种队形排尾的人数（a<3,b<5,c<7）。
    输出描述
    Output
    输出总人数的最小值（或报告无解）。已知总人数不小于10，不超过100 。输入到文件结束为止
**************************************************************************************/

#include <stdio.h>
int main(){
    int headcount = 0;
    int a, b, c;
    int i, j = 1;

    while(scanf("%d %d %d", &a, &b, &c) != EOF){
        for(i = 1; 1; i++){
            headcount = i * 7 + c;
            if(headcount % 5 == b && headcount <= 100 && headcount >= 10){
                if(headcount % 3 == a){
                    printf("Case %d: %d\n", j, headcount);
                    break;
                }
                else{
                    continue;
                }
            }
            else if(headcount < 10){
                continue;
            }
            else if(headcount > 100){
                printf("Case %d: No answer\n", j);
                break;
            }
            else{
                continue;
            }
        }
        j++;
    }
}