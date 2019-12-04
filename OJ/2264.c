//
// Created by LinSihan on 2019/11/14.
//
/***********************************************************************************
    题目描述
    Description
    给你一些打乱顺序的学号，请你将它们按照 字典非降序 排序后输出
    字典顺序是指 ASCII码的排序，例如字母'a'的ASCII码为97，'A'为65，'0' 为48
    则 'a' > 'A' > '0' ，
    这里要注意的是'a' 和 'A' 是有区别的，'0' 也和 数字0 有区别，一个是字符0，一个是数字0
    为了比较字符串大小，这里引用了一个函数 strcmp(), 当字符串A > 字符串B的时候，
    strcmp(A,B) 会返回一个正整数，A<B的时候返回负整数，相等则返回0，可以利用这个性质来排序
    举例："AB" > "AA" > "A"
    输入描述
    Input
    多组输入，EOF表示结束
    每组两行
    第一行有一个正整数n表示有n个学号（n <= 100）
    第二行有n个学号其中学号可能含有英文字母和数字
    (例如：STU001,GPNU002）每一个学号的字符长度不会超过10
    输出描述
    Output
    对于每一组输入，在新的一行输出结果
 ***********************************************************************************/
#include <stdio.h>
#include <string.h>
int main() {
    int n;
    int i, j;
    int ret;
    char temp[11] = "\0";
    while (scanf("%d", &n) != EOF) {
        char studentNum[n][11];
        for(i = 0; i < n; i++){
            scanf("%s", studentNum[i]);
        }
        for(i = 0; i < n-1; i++){
            for(j = 0; j < n - 1 - i; j++){
                ret = strcmp(studentNum[j], studentNum[j+1]);
                if(ret > 0){
                    strcpy(temp, studentNum[j + 1]);
                    strcpy(studentNum[j + 1], studentNum[j]);
                    strcpy(studentNum[j], temp);
                }
            }
        }
        for(i = 0; i < n; i++) {
            printf("%s ", studentNum[i]);
        }
        printf("\n");
    }
    return 0;
}