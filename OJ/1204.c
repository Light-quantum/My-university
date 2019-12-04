//
// Created by LinSihan on 2019/12/4.
//
/********************************************************************
    题目描述
    Description
    速算24点相信绝大多数人都玩过。就是随机给你四张牌，
    包括 A(1),2,3,4,5,6,7,8,9,10,J(11),Q(12),K(13)。
    要求只用'+','-','*','/'运算符以及括号改变运算 顺序，
    使得最终运算结果为24(每个数必须且仅能用一次)。
    游戏很简单，但遇到无解的情况往往让人很郁闷。
    你的任务就是针对每一组随机产生的四张牌，判断 是否有解。
    我们另外规定，整个计算过程中都不能出现小数。
    输入描述
    Input
    输入数据占一行，给定四张牌。
    输出描述
    Output
    如果有解则输出"Y"，无解则输出"N"。
********************************************************************/

#include <stdio.h>
double cal(double n, double m, int symbol);
int main(){
    char list[4] = {'\0'};
    int numList[4] = {0};
    int i, j, k, l;
    int k1, k2, k3, k4;
    double fullPermutation[4] = {0};
    double result = 0;
    int have = 0;

    //得到4张牌
    for(i = 0; i < 4; i++){
        scanf("%c", &list[i]);
        getchar();
    }

    //得到这些牌对应的数字
    for(i = 0; i < 4; i++){
        if(list[i] == 'A'){
            numList[i] = 1;
        }
        else if(list[i] == 'J'){
            numList[i] = 11;
        }
        else if(list[i] == 'Q'){
            numList[i] = 12;
        }
        else if(list[i] == 'K'){
            numList[i] = 13;
        }
        else{
            numList[i] = list[i] - '0';
        }
    }

    //获得数字全排列
    for(i = 0; i < 4; i++){
        fullPermutation[0] = numList[i] * 1.0;
        for(j = 0; j < 4; j++){
            if(j == i){
                continue;
            }
            fullPermutation[1] = numList[j] * 1.0;
            for(k = 0; k < 4; k++){
                if(k == j || k == i){
                    continue;
                }
                fullPermutation[2] = numList[k] * 1.0;
                for(l = 0; l < 4; l++){
                    if(l == j || l == i || l == k){
                        continue;
                    }
                    else{
                        fullPermutation[3] = numList[l] * 1.0;

                        //获得符号全排列
                        for(k1 = 1; k1 <= 4; k1++){
                            for(k2 = 1; k2 <= 4; k2++){
                                if(k2 == k1){
                                    continue;
                                }
                                for(k3 = 1; k3 <= 4; k3++) {
                                    if (k3 == k1 || k3 == k2) {
                                        continue;
                                    }
                                    for (k4 = 1; k4 <= 4; k4++) {
                                        if (k4 == k1 || k4 == k2 || k4 == k3) {
                                            continue;
                                        }

                                        //计算
                                        else{
                                            result = cal(fullPermutation[0], fullPermutation[1], k1);
                                            result = cal(result, fullPermutation[2], k2);
                                            result = cal(result, fullPermutation[3], k3);
                                            if(result == 24){
                                                have = 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(have == 1){
        printf("Y");
    }
    else{
        printf("N");
    }
    return 0;
}

double cal(double n, double m, int symbol){
    switch(symbol){
        case 1: return n + m;
        case 2: return n - m;
        case 3: return n * m;
        case 4: return n / m;
        default: return 0;
    }
}