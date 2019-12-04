//
// Created by LinSihan on 2019/12/3.
//
/******************************************************
    题目描述
    Description
    输出7和7的倍数，
    还有包含7的数字例如（17，27，37...70，71，72，73...）
    输入描述
    Input
    一个整数N。(N不大于30000)
    输出描述
    Output
    统计出不大于N的与7有关的数字的个数。
    如20以内与7有关的数为7、14、17共3个。
*******************************************************/

#include <stdio.h>
void int_turn_to_char(char list[], int n);
int main(){
    int i = 7;
    int N;
    int count = 0, k;
    char number[5] = "\0";

    scanf("%d", &N);
    for(i = 7; i <= N; i++){
        if(i % 7 == 0){
            count++;
        }
        else{
            int_turn_to_char(number, i);
            for(k = 0; k < 5; k++){
                if(number[k] == '7'){
                    count++;
                    break;
                }
            }
        }
    }
    printf("%d\n", count);
}

void int_turn_to_char(char list[], int n){
    int i = 0;
    while(n){
        list[i] = (n % 10) + '0';
        n = n / 10;
        i++;
    }
}








