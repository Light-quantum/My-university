//
// Created by LinSihan on 2019/11/25.
//
/**********************************************************************************
    解密算法：家都知道手机上的字母：
    1--1， abc--2, def--3, ghi--4, jkl--5, mno--6, pqrs--7, tuv--8 wxyz--9, 0--0,
    就这么简单，老王把明文中出现的小写字母都变成对应的数字，数字和其他的符号都不做变换，
    声明：密码中没有空格，而明文中出现的大写字母则变成小写之后往后移一位，
    如：X，先边成小写，再往后移一位，不就是y了嘛，简单吧。记住，z往后移是a哦。
    样本输入
    Input example
    YUANzi1987
    样本输出
    Output example
    zvbo941987
**********************************************************************************/

#include <stdio.h>
#include <string.h>

int main(){
    char proclaim[101] = "\0";
    char cipherText[101] = "\0";
    int i, len;

    while(scanf("%s", proclaim) != EOF) {
        len = strlen(proclaim);
        for (i = 0; i < len; i++) {
            if ((proclaim[i] == '1') || (proclaim[i] == '0')) {
                cipherText[i] = proclaim[i];
            } else if ((proclaim[i] >= 'a') && (proclaim[i] <= 'c')) {
                cipherText[i] = '2';
            } else if ((proclaim[i] >= 'd') && (proclaim[i] <= 'f')) {
                cipherText[i] = '3';
            } else if ((proclaim[i] >= 'g') && (proclaim[i] <= 'i')) {
                cipherText[i] = '4';
            } else if ((proclaim[i] >= 'j') && (proclaim[i] <= 'l')) {
                cipherText[i] = '5';
            } else if ((proclaim[i] >= 'm') && (proclaim[i] <= 'o')) {
                cipherText[i] = '6';
            } else if ((proclaim[i] >= 'p') && (proclaim[i] <= 's')) {
                cipherText[i] = '7';
            } else if ((proclaim[i] >= 't') && (proclaim[i] <= 'v')) {
                cipherText[i] = '8';
            } else if ((proclaim[i] >= 'w') && (proclaim[i] <= 'z')) {
                cipherText[i] = '9';
            } else if ((proclaim[i] >= 'A') && (proclaim[i] <= 'Z')) {
                if (proclaim[i] == 'Z') {
                    cipherText[i] = 'a';
                } else {
                    cipherText[i] = (char) (proclaim[i] + 33);
                }
            } else {
                cipherText[i] = proclaim[i];
            }
        }
        printf("%s\n", cipherText);
        memset(cipherText, '\0', sizeof(cipherText));
    }
    return 0;
}