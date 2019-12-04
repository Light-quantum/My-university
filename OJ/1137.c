//
// Created by LinSihan on 2019/11/15.
//
/******************************************************************************************
    题目描述
    Description
    作为吉大的老师，最盼望的日子就是每月的9号了，因为这一天是发工资的日子，养家糊口就靠它了，呵呵
    但是对于学校财务处的工作人员来说，这一天则是很忙碌的一天，
    财务处的小胡老师最近就在考虑一个问题：如果每个老师的工资额都知道，
    最少需要准备多少张人民币，才能在给每位老师发工资的时候都不用老师找零呢？
    这里假设老师的工资都是正整数，单位元，人民币一共有100元、50元、10元、5元、2元和1元六种。
    输入描述
    Input
    输入数据包含多个测试实例，每个测试实例的第一行是一个整数n（n<100），
    表示老师的人数，然后是n个老师的工资。
    n=0表示输入的结束，不做处理。
    输出描述
    Output
    对于每个测试实例输出一个整数x,表示至少需要准备的人民币张数。每个输出占一行。
******************************************************************************************/

#include <stdio.h>

int main() {
    int teacherNum;
    int amount, i;

    while (scanf("%d", &teacherNum), teacherNum != 0) {
        amount = 0;
        int everyTeacherMoney[teacherNum];
        int everyTeacherNeedPieceNum[teacherNum];
        for (i = 0; i < teacherNum; i++) {
            scanf("%d", &everyTeacherMoney[i]);
        }

        for (i = 0; i < teacherNum; i++) {
            everyTeacherNeedPieceNum[i] = everyTeacherMoney[i] / 100;
            everyTeacherMoney[i] %= 100;
            everyTeacherNeedPieceNum[i] += everyTeacherMoney[i] / 50;
            everyTeacherMoney[i] %= 50;
            everyTeacherNeedPieceNum[i] += everyTeacherMoney[i] / 10;
            everyTeacherMoney[i] %= 10;
            everyTeacherNeedPieceNum[i] += everyTeacherMoney[i] / 5;
            everyTeacherMoney[i] %= 5;
            everyTeacherNeedPieceNum[i] += everyTeacherMoney[i] / 2;
            everyTeacherMoney[i] %= 2;
            everyTeacherNeedPieceNum[i] += everyTeacherMoney[i];
        }

        for(i = 0; i < teacherNum; i++){
            amount += everyTeacherNeedPieceNum[i];
        }
        printf("%d\n", amount);
    }
    return 0;
}

























