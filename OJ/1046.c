//
// Created by LinSihan on 2019/11/17.
//
/************************************************************************************************************
    题目描述
    Description

    有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”
    答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，
    喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。
    然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。
    如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？
    输入描述
    Input
    输入文件最多包含100000组测试数据，每个数据占一行，仅包含一个正整数n（1<=n<=10^9），
    表示小张手上的空汽水瓶数。n=0表示输入结束，你的程序不应当处理这一行。
    输出描述
    Output
    对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。
***********************************************************************************************************/

#include <stdio.h>
int getCanDrinkNum(int emptyBottlesNum);
int main(){
    int emptyBottlesNum;
    while(scanf("%d", &emptyBottlesNum), emptyBottlesNum != 0){
        if(emptyBottlesNum == 1){
            printf("0\n"); // 没得喝
        }
        else{
            printf("%d\n", getCanDrinkNum(emptyBottlesNum));
        }
    }
    return 0;
}

int getCanDrinkNum(int emptyBottlesNum) {
    int CanDrinkNum = 0;
    int fullBottles = 0;
    while (emptyBottlesNum / 3 != 0) {
        fullBottles = emptyBottlesNum / 3; //老板给你汽水;
        emptyBottlesNum %= 3;  // 空瓶给老板
        CanDrinkNum += fullBottles; //喝喝喝
        emptyBottlesNum += fullBottles; //喝完变空瓶
    }
    if(emptyBottlesNum == 2){
        return CanDrinkNum += 1; //给老板借一瓶
    }
    else{
        return CanDrinkNum;
    }
}




















