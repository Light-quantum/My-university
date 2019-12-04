//
// Created by LinSihan on 2019/11/13.
//
/*********************************************************
    题目描述
    Description
    有留意过Excel表格的列序号吗？它不是数字排列而是字母的排列，
    例如第一列对应A，第二列对应B，你能够输出第n列的列序号吗？
    输入描述
    Input
    多组输入，EOF结束
    每组输入一行，只有一个正整数n，输入保证n在int范围之内
    输出描述
    Output
    对于每组输入，在新的一行输出第n列的序号
 *******************************************************/
#include <stdio.h>
int main(){
    int n, i, j = 0;
    char list[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                   'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int carry[20] = {0}; // 用来存进了几次位比如[1,2,3] ==> CBA

    while(scanf("%d", &n) != EOF){
        //每次循环前初始化
        for(i = 0; i < 20; i++){
            carry[i] = 0;
        }
        carry[0]= n;
        j = 0;
        // 打印结果
        if(carry[0] <= 26){
            printf("%c\n", list[n-1]);
        }
        else{
            for(i = 0; i <= j; i++){
                if(carry[i] > 26){
                    if(carry[i] % 26 != 0) {
                        carry[i + 1] += carry[i] / 26;
                        carry[i] = carry[i] % 26;
                    }
                    else{
                        carry[i + 1] += ((carry[i] / 26) - 1);
                        carry[i] = 26;
                    }
                    j++; // 用于记录进位，进到了第几位
                }
            }
            for(i = j; i >= 0; i--){ // 从高位开始打印
                printf("%c", list[carry[i] - 1]);  // 1 对应的是字母列表中的A，而A在字母列表中是第0位
            }
            printf("\n");
        }
    }
    return 0;
}