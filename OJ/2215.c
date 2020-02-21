//
// Created by LinSihan on 2019/12/10.
//

/******************************************************************
    题目描述
    Description
    很多小学生在学习加法时，发现“进位”特别容易出错，
    你的任务是计算两个整数在相加时需要多少进位。
    你的编制应该处理多组数据，直到读到两个0（这时结束程序）。
    输入的整数不超过9个数字。
    输入描述
    Input
    1、多行输入，每行包括两个整数，之间用空格隔开，每个整数不超过9位数
    2、输入0 0，结束程
    输出描述
    Output
    每行输出一个整数，代表进位多少
******************************************************************/

#include <stdio.h>
#include <string.h>


/******************************************************************
    函数功能：模拟加法，但不求结果， 只获得进位次数， 使用字符串模拟加法
。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    输入：两个字符串类型的加数
    输出：进位次数
******************************************************************/
int count_of_carry(char addend1[], char addend2[]){
    int count = 0;
    int len1, len2;
    int sum, carry = 0;

    len1 = strlen(addend1);
    len2 = strlen(addend1);

    int max;
    max = (len1 > len2) ? len1 : len2;

    int i , j;

    if(strcmp(addend1, addend2) > 0) {   //  以下为第一个加数大于第二个加数
        j = len2;
        carry = 0;
        for (i = max; i >= 0; i--) { // 加法运算次数为大的加数的长度
            if(j >= 0) {  // 小的加数还没加完
                sum = (addend1[i] - '0') + (addend2[j] - '0') + carry;
                carry = 0;
                if (sum >= 10) {
                    carry++;
                    count++;
                }
                j--;
            }
            else{  // 小的加数加完了
                sum = (addend1[i] - '0') + carry;
                carry = 0;
                if (sum >= 10) {
                    carry++;
                    count++;
                }
            }
        }
    }
    else{  // 同理， 以下为第二个加数大于或等于第一个加数的情况
        j = len1;
        carry = 0;
        for (i = max; i >= 0; i--) {
            if(j >= 0) {
                sum = (addend1[j] - '0') + (addend2[i] - '0') + carry;
                carry = 0;
                if (sum >= 10) {
                    carry++;
                    count++;
                }
                j--;
            }
            else{
                sum = (addend2[i] - '0') + carry;
                carry = 0;
                if (sum >= 10) {
                    carry++;
                    count++;
                }
            }
        }
    }
    return count;
}

int main(){
    char addend1[10] = "\0";
    char addend2[10] = "\0";
    while(1){
        scanf("%s", addend1);
        getchar(); // 吃掉用于分隔的空格
        scanf("%s", addend2);
        if(addend1[0] == '0' && addend2[0] == '0'){
            break;
        }
        else{
            printf("%d\n", count_of_carry(addend1, addend2));
        }
    }
    return 0;
}