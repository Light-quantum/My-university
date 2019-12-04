//
// Created by LinSihan on 2019/12/3.
//
/*********************************************************
    题目描述
    Description
    用1,2,3, ... , 9 组成3个三位数 abc, def 和 ghi，
    每个数字恰好使用一次，要求 abc : def : ghi = 1 : 2 : 3。
    按照 "abc def ghi" 格式输出所有解，每行一个解。
    提示 ： 不必太动脑筋。
    输入描述
    Input

    输出描述
    Output
*********************************************************/
//思路： 1：2：3 放大为3位数，判断是否是 1 到 9 的数字
#include <stdio.h>

void int_turn_to_char(int specificValue[3], char list[3][3]){
    int i = 0, j = 0;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            list[i][j] = specificValue[i] % 10 + '0';
            specificValue[i] /= 10;
        }
    }
}

int main(){
    int specificValue[3] = {1, 2, 3};
    int i;
    char result[3][3] = {"\0"};
    char result_linear[9] = "\0";
    int j, k, m;
    for(i = 192; i <= 333; i++) {
        if(i == 267){
            continue;
        }
        m = 0;
        specificValue[0] = 1;
        specificValue[1] = 2;
        specificValue[2] = 3;

        specificValue[0] *= i;
        specificValue[1] *= i;
        specificValue[2] *= i;

        int_turn_to_char(specificValue, result);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                result_linear[m] = result[j][k];
                m++;
            }
        }

        int same = 0;
        char theSameElement;
        for(k = 0; k < 9; k++){
            theSameElement = result_linear[k];
            for(j = k + 1; j < 9; j++){
                if(result_linear[j] == theSameElement){
                    same = 1;
                    break;
                }
            }
            if(same == 1){
                break;
            }
        }

        if(same == 0){
            printf("%c%c%c ", result[0][2], result[0][1], result[0][0]);
            printf("%c%c%c ", result[1][2], result[1][1], result[1][0]);
            printf("%c%c%c ", result[2][2], result[2][1], result[2][0]);
            printf("\n");
        }
    }
    return 0;
}