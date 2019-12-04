//
// Created by LinSihan on 2019/11/10.
//
// input 4 3 2 1
// output 1 2 3 4
#include <stdio.h>

int main(){
    int result[4];
    int i, j;

    for(i = 0; i < 4; i++){
        scanf("%d", &result[i]);
    }

    //排序
    int temp;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3 - i; j++){
            if(result[j] > result[j + 1]){
                temp = result[j + 1];
                result[j + 1] = result[j];
                result[j] = temp;
            }
        }
    }

    //输出
    for(i = 0; i < 4; i++){
        printf("%d ", result[i]);
    }
}