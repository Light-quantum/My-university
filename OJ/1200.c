//
// Created by LinSihan on 2019/11/17.
//
/***********************************************************
    题目描述
    Description
    有一楼梯共M级，刚开始时你在第一级，若每次只能跨上一级或二级，
    要走上第M级，共有多少种走法？
    输入描述
    Input
    输入数据首先包含一个整数N，表示测试实例的个数，然后是N行数据，
    每行包含一个整数M（1<=M<=40）,表示楼梯的级数。
    输出描述
    Output
    对于每个测试实例，请输出不同走法的数量
************************************************************/

#include <stdio.h>
void jump(int sumLadder, int ladder, int way[]);
int main() {
    int n, sumLadder, way[1];
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &sumLadder);
        way[0] = 0;
        jump(sumLadder, 1, way);
        printf("%d\n", way[0]);
    }
    return 0;
}

void jump(int sumLadder, int ladder, int way[]) {
    int i;
    for (i = 1; i <= 2; i++) {
        if (ladder == sumLadder) {
            way[0]++;
            break;
        }
        else if (ladder < sumLadder) {
            jump(sumLadder, ladder + i, way);
        }
    }
}