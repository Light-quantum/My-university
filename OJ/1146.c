//
// Created by LinSihan on 2019/11/21.
//
/*********************************************
    字符串倒置
*********************************************/

#include <stdio.h>
#include <string.h>

int main(){
    char msg[256] = "\0", temp;
    int len, i;

    scanf("%s", msg);
    len = strlen(msg);

    for(i = 0; i < len / 2; i++){
        temp = msg[i];
        msg[i] = msg[len - i - 1];
        msg[len - 1 - i] = temp;
    }
    puts(msg);
}