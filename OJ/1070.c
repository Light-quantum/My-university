//
// Created by LinSihan on 2019/11/3.
//
/***************************************
    题目描述
        输入一个字符串,数出其中的字母的个数.
    输入描述
        一个字符串，不包含空格（长度小于100）
    输出描述
        字符串中的字母的个数
**********************************************/

#include <stdio.h>
#include <string.h>

int main(){
    int i, j = 0;
    char list[80] = {' '};
    gets(list);

    for(i = 0; i < strlen(list); i++){
        if((list[i] >= 'a' && list[i] <= 'z') || (list[i] >= 'A' && list[i] <= 'Z')){
            j++;
        }
        else
            continue;
    }
    printf("%d", j);
    return 0;
}
