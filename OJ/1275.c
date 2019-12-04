//
// Created by LinSihan on 2019/11/7.
//
/*******************************************************************
    输入10个整数，将其中最小的数与第一个数对换，把最大的数与最后一个数对换。
    写三个函数；①输入10个数；②进行处理；③输出10个数。
    输入描述
    Input
    10个整数
    输出描述
    Output
    整理后的十个数，每个数后跟一个空格。(注意：最后一个数字后面没有空格)
*******************************************************************/

#include <stdio.h>

int main(){
    int list[10];
    int i;
    for(i = 0; i < 10; i++){
        scanf("%d", &list[i]);
    }
    int min, minNub;
    min = list[0];
    minNub = 0;
    for(i = 1; i < 10; i++){
        if(list[i] < min){
            min = list[i];
            minNub = i;
        }
    }

    int max, maxNub;
    max = list[0];
    maxNub = 0;
    for(i = 1; i < 10; i++){
        if(list[i] > max){
            max = list[i];
            maxNub = i;
        }
    }

    int temp;
    //min
    temp = list[0];
    list[0] = list[minNub];
    list[minNub] = temp;

    //max
    temp = list[9];
    list[9] = list[maxNub];
    list[maxNub] = temp;

    for(i = 0; i < 10; i++){
        if(i == 0){
            printf("%d", list[0]);
        }
        else{
            printf(" %d", list[i]);
        }

    }
    return 0;
}

