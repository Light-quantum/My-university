//
// Created by LinSihan on 2019/11/7.
//
/* 输入百分制成绩， 输出成绩等级*/

#include <stdio.h>
int main(){
    int score;
    scanf("%d", &score);
    if(score >= 90){
        printf("A");
    }
    else if(score >= 80 && score < 90){
        printf("B");
    }

    else if(score >= 70 && score < 80) {
        printf("C");
    }

    else if(score >= 60 && score < 70) {
        printf("D");
    }

    else{
        printf("E");
    }
    return 0;
}