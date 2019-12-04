//
// Created by LinSihan on 2019/11/7.
//
/* 10个数小到大排序 */

#include <stdio.h>
int main(){
    int list[10];
    int i, j;
    int temp;
    for(i = 0; i < 10; i++){
        scanf("%d", &list[i]);
    }
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9 - i; j++){
            if(list[j] > list[j + 1]){
                temp = list[j + 1];
                list[j + 1] = list[j];
                list[j] = temp;
            }
        }
    }
    for(i = 0; i < 10; i++){
        printf("%d\n", list[i]);
    }
    return 0;
}
