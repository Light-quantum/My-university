//
// Created by LinSihan on 2019/11/21.
//
/***************************************************************
    题目描述
    Description
    将C程序代码中的双斜杠注释去掉。
    输入描述
    Input
    输入数据中含有一些符合C++语法的代码行。需要说明的是，
    为了方便编程，规定双斜杠注释内容不含有双引号,源程序中没空行。
    输出描述
    Output
    输出不含有双斜杠注释的C++代码，除了注释代码之外，原语句行格式不变。
***************************************************************/

#include <stdio.h>
#include <string.h>

int main(){
    char code[10000] = "\0";
    char finalCode[10000] = "\0";
    int i = 0, j = 0, len, isAnnotation = 0;

    while(scanf("%c", &code[i]) != EOF){
        i++;
    }  //输入


    len = strlen(code);
    for(i = 0; i < len; i++){
        if(code[i] == '/'){
            if(code[i + 1] == '/'){
                isAnnotation = 1;
            }
        }  //如果是注释那么 isAnnotation 变为1
        if((isAnnotation == 1) && (code[i] == '\n')){
            isAnnotation = 0;
        }  //如果是注释那么记录 是注释的变量 直到回车才变回0
        if(isAnnotation == 0){
            finalCode[j] = code[i];
            j++;
        }  //如果是代码那就存起来，有个问题就是注释的回车会被存起来，那么打印的时候会出现空行
    }

    len = strlen(finalCode);
    int canPrint = 1;
    for(i = 0; i < len; i++){
        if((i == 0) && (finalCode[i] == '\n')){
            continue;
        }//开头是回车则跳过
        else if((i != 0) && (finalCode[i]) == '\n'){
            if(finalCode[i - 1] == '\n'){
                continue;
            }//如果是连续换行则跳过
            else{
                printf("%c", finalCode[i]);
            }
        }
        else{
            printf("%c", finalCode[i]);
        }
    }
    return 0;
}