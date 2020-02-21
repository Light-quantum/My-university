//
// Created by LinSihan on 2019/12/5.
//
/**************************************************************
    题目描述
    Description
    佳哥为了期末考试，最近在OJ刷题，但是他发现回文串那题的数据有错误，
    想写一个程序测试一下OJ的数据是否正确。
    你能帮帮他吗？请求出字符串S中有多少个不同的且长度均为k的回文串。
    例如 eeabbbacc 则 abbba 是长度为5的回文串
    说明：只要起始位置不同，你应该认为这是不同的回文串。
    输入描述
    Input
    输入只有两部分。
    第一部分，输入一个正整数k（k <=10）。
    第二部分，输入一个字符串S（长度不超过100000，只含小写字母）。
    输出描述
    Output
    输出一个整数，表示长度为k的回文串的个数。
**************************************************************/

#include <stdio.h>
#include <string.h>

int main(){
    int k, k1, i, j, l, len;
    int isPalindromic = 1;
    int count = 0;
    char str[100000] = "\0";
    char cut[11] = "\0";

    scanf("%d\n", &k);
    scanf("%s", str);
    len = strlen(str);

    for(i = 0; i <= len - k; i++){  // i = 0, k = 5, j = 0 1 2 3 4, i+j = 0 1 2 3 4
        for(j = 0; j < k; j++){
            cut[j] = str[i + j];
        }
        isPalindromic = 1;
        k1 = k / 2;
        for(l = 0; l < k1; l++){
            if(cut[l] != cut[k - 1 - l]){
                isPalindromic = 0;
                break;
            }
        }
        if(isPalindromic == 1){
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}