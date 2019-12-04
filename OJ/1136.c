//
// Created by LinSihan on 2019/11/23.
//
/*********************************************************
    题目描述
    Description
    读入一些字符串，将其中的空格去掉。
    输入描述
    Input
    输入为多行，每行为一个字符串，字符串只由字母、
    数字和空格组成，长度不超过80。输入以“End of file”结束。
    输出描述
    Output
    对于每行输入，输出转换后的字符串。
*********************************************************/

#include <stdio.h>
#include <string.h>
void removeTheSpace(char inputString[], char outputString[]);
int main(){
    char inputString[80] = "\0";
    char outputString[80] = "\0";
    int i = 0;

    while(scanf("%c", &inputString[0]) != EOF) {
        for(i = 1; scanf("%c", &inputString[i]), inputString[i] != '\n'; i++);
        inputString[i] = '\0';
        removeTheSpace(inputString, outputString);
        puts(outputString);
        memset(outputString, '\0', sizeof(outputString));
    }
    return 0;
}

void removeTheSpace(char inputString[], char outputString[]){
    int len, i, j;
    len = strlen(inputString);

    for(j = 0, i = 0; i < len; i++){
        if(inputString[i] != ' '){
            outputString[j] = inputString[i];
            j++;
        }
    }
}