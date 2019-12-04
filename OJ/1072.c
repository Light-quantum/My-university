//
// Created by LinSihan on 2019/11/10.
//
// input many numb until -1
// output the max

#include <stdio.h>
int main(){
    int list[1000];
    int max, i = 1;

    scanf("%d", &list[0]);
    max = list[0];
    
    while(list[i] != -1){
        scanf("%d", &list[i]);
        if(list[i] > max && list[i] != -1){
            max = list[i];
        }
    }
    printf("%d", max);
}
