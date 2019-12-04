//
// Created by LinSihan on 2019/11/23.
//
/************************************************************
    题目描述
    Description
    设A和B是两个字符串。我们要用最少的字符操作次数，
    将字符串A转换为字符串B。这里所说的字符操作共有三种：
        1. 删除一个字符；
        2. 插入一个字符；
        3. 将一个字符改为另一个字符。
    对任给的两个字符串A和B，
    计算出将字符串A变换为字符串B所用的最少字符操作次数。
    输入描述
    Input
    第一行为字符串A；第二行为字符串B；字符串A和B的长度均小于200。
    输出描述
    Output
    只有一个正整数，为最少字符操作次数。
***********************************************************/
//思路：先比较长度，先增加或者删减，然后比较不相同元素有几个，然后改几个

#include <stdio.h>
#include <string.h>
int main(){
    int len1, len2, max, min;
    int sumKind = 0, deleteOrAdd = 0;
    char string1[201] = "\0";
    char string2[201] = "\0";

    scanf("%s", string1);
    scanf("%s", string2);

    len1 = strlen(string1);
    len2 = strlen(string2);
    (len1 > len2) ? (max = len1, min = len2) : (max = len2, min = len1);
    deleteOrAdd = max - min;

    int i, j, pace = 0, haveSame = 0;
    for(i = 0; i < len1; i++){
        haveSame = 0;
        for(j = pace; j < len2; j++){
            if(string1[i] == string2[j]){
                haveSame = 1;
                pace = j;
                break;
            }
        }
        if(haveSame == 0){
            sumKind += 1;
        }
    }
    printf("%d", sumKind / 2 - deleteOrAdd);
    return 0;
}