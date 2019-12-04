//
// Created by LinSihan on 2019/11/26.
//
/***********************************************************************
    题目描述
    Description
    ACM公司生产金币的设备出了问题，使得最近生产的10批金币的重量出现了波动：
    本来金币的标准重量是10克，但现在有的可能是11克，有的可能9克，也有可能是10克。
    现在只知道同一批金币的重量是相同的，你的任务是要把每批的单枚金币的重量找出来。
    你的设备有一个电子秤，但只允许称量一次！
    你从第1批中取1枚金币，第2批取3枚，...第i批取3^(i−1)枚...，第10批取3^9枚，
    总共29524枚。将这29524枚金币放在电子秤上，得到了总重量，就交给你的程序去！
    输入描述
    Input
    有多个测试序列，每个测试序列一行，
    包含一个6位的正整数W(265716≤W≤324764)，表示29524枚金币的总重量
    输出描述
    Output
    每个测试序列输出一行，包含10个用空格分开的正整数，
    分别表示10批金币的单枚重量，注意行尾没有空格。
************************************************************************/
//思路：将总质量减去全为9的质量，得到质量差，模于3得到第一批比9的质量，为什么因为不管
//后面几批是比九多1还是多2还是0，他们模于3都为0；因为第二批开始，每一批都是取3的倍数个金币

#include <stdio.h>

int main(){
    int sumWeight, different;
    int i;

    while(scanf("%d", &sumWeight) != EOF){
        different = sumWeight - 265716;
        for(i = 1; i <= 10; i++){
            printf("%d ", 9 + different % 3);
            different /= 3; // 把第二批变为第一批
        }
        printf("\n");
    }
    return 0;
}
