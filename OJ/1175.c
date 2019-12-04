//
// Created by LinSihan on 2019/11/7.
//
/********************************************
    题目描述
    Description
    对于输入的每个字符串，查找其中的最大字母，在该字母后面插入字符串“(max)”。
    输入描述
    Input
    输入数据包括多个测试实例，每个实例由一行长度不超过100的字符串组成，字符串仅由大小写字母及数字构成
    输出描述
    Output
    对于每个测试实例输出一行字符串，输出的结果是插入字符串“(max)”后的结果，
    如果存在多个最大的字母，就在每一个最大字母后面都插入"(max)"。
    .......................................................
    样本输入
    Input example
    abcdefgfedcba
    xxxxx
    样本输出
    Output example
    abcdefg(max)fedcba
    x(max)x(max)x(max)x(max)x(max)
**********************************************************************************/

#include <stdio.h>

int main(){
    char list[100] = "\0";
    char max;
    int i , j;
    while(scanf("%s", list) != EOF){
        char list2[1000] = "\0";
        max = list[0];
        for(i = 1; i < 100; i++){
            if(list[i] >= max){
                max = list[i];
            }
        }
        for(i = 0, j = 0; i < 100; i++, j++){
            list2[j] = list[i];
            if(list[i] == max){
                list2[j + 1] = '(';
                list2[j + 2] = 'm';
                list2[j + 3] = 'a';
                list2[j + 4] = 'x';
                list2[j + 5] = ')';
                j = j + 5;
            }
        }
        printf("%s\n", list2);
    }
}
