//
// Created by LinSihan on 2019/11/13.
//
/******************************************************************************************
    题目描述
    Description
    输入一行数字，如果我们把这行数字中的‘5'都看成空格，
    那么就得到一行用空格分割的若干非负整数（可能有些整数以‘0'开头，
    这些头部的‘0'应该被忽略掉，除非这个整数就是由若干个‘0'组成的，这时这个整数就是0）。

    你的任务是：对这些分割得到的整数，依从小到大的顺序排序输出。
    输入描述
    Input
    输入包含多组测试用例，每组输入数据只有一行数字（数字之间没有空格），这行数字的长度不大于1000。
    输入数据保证：分割得到的非负整数不会大于100000000；输入数据不可能全由‘5’组成。
    输出描述
    Output
    对于每个测试用例，输出分割得到的整数排序的结果，相邻的两个整数之间用一个空格分开，每组输出占一行。
*********************************************************************************************/

#include <stdio.h>
#include <string.h>
//231465132151351313123212300000050000000321315315
//23146 1321 13 13131232130000000 000000032131 31

int main (){
    char list[1001] = "\0";
    char result[1001] = "\0";
    int i, j = 0;
    int len, isNum;
    while(scanf("%s", list) != EOF){
        len  = strlen(list);
        for(i = 0; i < len; i++){
            if(list[i] == '5'){
                result[i] = ' ';
            }
            else{
                result[i] = list[i];
            }
        }
        len = strlen(result);
        isNum = 0;
        //123 123 000 00036
        //暂无法解决输出问题
        for(i = 0; i < len; i = i + j){
            for(j = i; result[j] != ' '; j++){
                if(list[i] != '0'){
                    isNum = 1;
                }
            }
            if(isNum = )
        }
    }
    return 0;
}












