//
// Created by LinSihan on 2019/11/29.
//
/***************************************
    题目描述
    Description
    某君从某年开始每年都举办一次生日party，
    并且每次都要吹熄与年龄相同根数的蜡烛。
    现在算起来，他一共吹熄了236根蜡烛。
    请问，他从多少岁开始过生日party的？
    输入描述
    Input
    输出描述
    Output
    开始过生日时的年龄
****************************************/

#include <stdio.h>
int main(){
    int starPart_age = 1;
    int candleNum;
    int true = 0;
    int i;

    for(starPart_age = 1; 1; starPart_age++){
        candleNum = 0;
        true = 0;
        for(i = starPart_age; 1; i++){
            candleNum += i;
            if(candleNum == 236){
                true = 1;
                break;
            }
            if(candleNum > 236){
                true = 0;
                break;
            }
        }
        if(true == 1){
            printf("%d\n", starPart_age);
            break;
        }
    }
    return 0;
}