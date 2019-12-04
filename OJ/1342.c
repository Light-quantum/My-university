//
// Created by LinSihan on 2019/11/14.
//
/**************************************************************
    题目描述
    Description
    给出一个由O和X组成的串（长度为1～80），统计得分。
    每个O的得分为目前连续出现的O的个数，X的得分为0。
    例如，OOXXOXXOOO的得分为1+2+0+0+1+0+0+1+2+3。
    输入描述
    Input
    第一行输入一个整数N，然后接着N行，每行输入一个由O和X组成的字符串
    输出描述
    Output
    对于每个字符串，输出它的得分
 *************************************************************/
#include <stdio.h>
#include <string.h>
int main(){
    int n;
    char list[81];
    int i, len;
    int sumScore, countScore;

    scanf("%d", &n);
    while(n--){
        scanf("%s", list);
        len = strlen(list);
        countScore = 1;
        sumScore = 0;
        for(i = 0; i < len;i++){
            if(list[i] == 'O'){
                sumScore = sumScore + countScore;
                countScore ++;
            }
            else{
                countScore = 1;
            }
        }
        printf("%d\n", sumScore);
    }
}