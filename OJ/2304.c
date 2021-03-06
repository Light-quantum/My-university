//
// Created by LinSihan on 2019/11/14.
//
/************************************************************************************
    题目描述
    Description
    人比人，气死人；鱼比鱼，难死鱼。小鱼最近参加了一个“比可爱”比赛，比的是每只鱼的可爱程度。
    参赛的鱼被从左到右排成一排，头都朝向左边，然后每只鱼会得到一个整数数值，
    表示这只鱼的可爱程度，很显然整数越大，表示这只鱼越可爱，而且任意两只鱼的可爱程度可能一样。
    由于所有的鱼头都朝向左边，所以每只鱼只能看见在它左边的鱼的可爱程度，
    它们心里都在计算，在自己的眼力范围内有多少只鱼不如自己可爱呢。
    请你帮这些可爱但是鱼脑不够用的小鱼们计算一下。
    输入描述
    Input
    第一行输入一个整数n(1<=n<=100)，表示鱼的数目。
    第二行内输入n个整数，用空格间隔，依次表示从左到右每只小鱼的可爱程度。
    输出描述
    Output
    行内输出n个整数，用空格间隔，依次表示每只小鱼眼中有多少只鱼不如自己可爱。
**********************************************************************************/

#include <stdio.h>

int main(){
    int i, j, count;
    int n;
    scanf("%d", &n);
    int prettyNum[n];

    for(i = 0; i < n; i++){
        scanf("%d", &prettyNum[i]);
    }

    for(i= 0; i < n; i++){
        count = 0;
        for(j = 0; j <= i; j++){
            if(prettyNum[j] < prettyNum[i]){
                count ++;
            }
        }
        printf("%d ", count);
    }
    return 0;
}