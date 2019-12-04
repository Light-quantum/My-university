//
// Created by LinSihan on 2019/11/26.
//
/******************************************************************
    题目描述
    Description
    最近Kingly对编码很感兴趣，于是从网上找了一些编码原则来对字符串做实验。
    因为Kingly一直很忙，所以希望你这位编程高手来替他解决这个问题。
    下面是编码原则：
    （1） 如果访问到字符A，W，F就转化成I；
    （2） 如果访问到字符C，M，S就分别转化成L，o，v；
    （3） 如果访问到字符D，P，G，B就转化成e；
    （4） 如果访问到字符L，X就分别转化成Y，u；
    （5） 其他字符均保持不变；
    （6） 遇到END就结束！（注意数据含有空格）
*****************************************************************/
#include <string.h>
#include <stdio.h>

int main(){
    char trueForm[1000] = {'\0'};
    char tranForm[1000] = {'\0'};
    int i, len;

    while(gets(trueForm)){
        memset(tranForm, '\0', sizeof(tranForm));
        len = strlen(trueForm);

        //遇到END就结束
        if(strcmp(trueForm, "END") == 0){
            break;
        }

        for(i = 0; i < len; i++){

            //如果访问到字符A，W，F就转化成I
            if(trueForm[i] == 'A' || trueForm[i] == 'W' || trueForm[i] == 'F' ){
                tranForm[i] = 'I';
            }

            //如果访问到字符D，P，G，B就转化成e；
            else if(trueForm[i] == 'D' || trueForm[i] == 'P' || trueForm[i] == 'G' || trueForm[i] == 'B' ){
                tranForm[i] = 'e';
            }

            //如果访问到字符C，M，S就分别转化成L，o，v；
            else if(trueForm[i] == 'C'){
                tranForm[i] = 'L';
            }
            else if(trueForm[i] == 'M'){
                tranForm[i] = 'o';
            }
            else if(trueForm[i] == 'S'){
                tranForm[i] = 'v';
            }

            //如果访问到字符L，X就分别转化成Y，u；
            else if(trueForm[i] == 'L'){
                tranForm[i] = 'Y';
            }
            else if(trueForm[i] == 'X'){
                tranForm[i] = 'u';
            }

            //其他情况不变
            else{
                tranForm[i] = trueForm[i];
            }
        }
        printf("%s\n", tranForm);
    }
}
