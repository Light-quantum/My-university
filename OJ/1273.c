//
// Created by LinSihan on 2019/11/3.
//
/**************************************************
    题目描述
    Description
    输入三个整数，按由小到大的顺序输出。
    输入描述
    Input
    三个整数
    输出描述
    Output
    由小到大输出成一行，每个数字后面跟一个空格
***************************************************/

#include <stdio.h>

int main(){
    int list[3];
    int i, j, temp;
    for(i = 0; i < 3; i++){
        scanf("%d", &list[i]);
    }

    for(i = 0; i < 2; i++){
        for(j = 0; j < 2 - i; j++){
            if(list[j] > list[j + 1]){
                temp = list[j + 1];
                list[j + 1] = list[j];
                list[j] = temp;
            }
        }
    }

    for(i = 0; i < 3; i++){
        printf("%d ", list[i]);
    }
    return 0;
}
