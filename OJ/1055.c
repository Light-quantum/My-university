//
// Created by LinSihan on 2019/11/26.
//
/**********************************************************************
    题目描述
    Description
    在基于Internet的程序中，我们常常需要判断一个IP字符串的合法性。
    合法的IP是这样的形式：
    A.B.C.D
    其中A、B、C、D均为位于[0, 255]中的整数。注意，A，B，C，D可能有前导0哦。
    现在，请你来完成这个判断程序吧^_^
    输入描述
    Input
    输入由多行组成，每行是一个字符串，输入由“End of file”结束。
    字符串长度最大为30，且不含空格和不可见字符
    输出描述
    Output
    对于每一个输入，单独输出一行
    如果该字符串是合法的IP，输出Y，否则，输出N
**********************************************************************/

//无法处理 225.32a.ad.ddd

#include <stdio.h>
#include <string.h>
int main(){
    char ip[30] = "\0";
    int i, j, len, isTheFirst = 1;
    int count[4], space = 0;

    while(scanf("%s", ip) != EOF){
        len = strlen(ip);
        space = 0;
        count[0] = 0;
        count[1] = 0;
        count[2] = 0;
        count[3] = 0;
        j = 100;
        isTheFirst = 1;

        for(i = 0; i < len; i++){
            if((ip[i] < '0' || ip[i] > '9') && (ip[i] != '.')){
                printf("N\n");
                break;
            }
            else{
                if(ip[i] == '.'){
                    space++;
                    isTheFirst = 1;
                    j = 100;
                }
                else if(space == 0){
                    count[0] += (ip[i] - '0') * 100;
                    if(isTheFirst == 1 && ip[i] > 0){
                        isTheFirst = 0;
                    }
                    if(isTheFirst == 0){
                        j /= 10;
                    }
                }

                else if(space == 1){
                    count[1] += (ip[i] - '0') * 100;
                    if(isTheFirst == 1 && ip[i] > 0){
                        isTheFirst = 0;
                    }
                    if(isTheFirst == 0){
                        j /= 10;
                    }
                }

                else if(space == 2){
                    count[2] += (ip[i] - '0') * 100;
                    if(isTheFirst == 1 && ip[i] > 0){
                        isTheFirst = 0;
                    }
                    if(isTheFirst == 0){
                        j /= 10;
                    }
                }

                else if(space == 3){
                    count[3] += (ip[i] - '0') * 100;
                    if(isTheFirst == 1 && ip[i] > 0){
                        isTheFirst = 0;
                    }
                    if(isTheFirst == 0){
                        j /= 10;
                    }
                }

            }
        }
        if((count[0] >= 0 && count[0] <= 255) && (count[1] >= 0 && count[1] <= 255) &&
                (count[2] >= 0 && count[2] <= 255) && (count[3] >= 0 && count[3] <= 255)){
            printf("Y\n");
        }
        else{
            printf("N\n");
        }
    }
    return 0;
}