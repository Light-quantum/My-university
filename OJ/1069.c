//
// Created by LinSihan on 2019/11/10.
//
// input ten number
// output from big to small
#include <stdio.h>

int main(){
    int result[10];
    int i, j;

    for(i = 0; i < 10; i++){
        scanf("%d", &result[i]);
    }

    //排序
    int temp;
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9 - i; j++){
            if(result[j] < result[j + 1]){
                temp = result[j + 1];
                result[j + 1] = result[j];
                result[j] = temp;
            }
        }
    }

    //输出
    for(i = 0; i < 10; i++) {
        if(i == 0) {
            printf("%d", result[i]);
        }
        else{
            printf(" %d", result[i]);
        }
    }
}

